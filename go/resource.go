package main

import (
	"encoding/json"
	"fmt"
	"path/filepath"
	"strings"
	"sync"
	"time"

	v1alpha1PB "github.com/michaelhenkel/k8s-client-cpp/pkg/apis/v1alpha1"
	"google.golang.org/protobuf/proto"
	"k8s.io/apimachinery/pkg/apis/meta/v1/unstructured"
	"k8s.io/apimachinery/pkg/runtime/schema"
	"k8s.io/client-go/dynamic"
	"k8s.io/client-go/dynamic/dynamicinformer"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/rest"
	"k8s.io/client-go/tools/cache"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
	contrailClient "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/clientset_generated/clientset"
)

// #include <stdlib.h>
// #include <stdint.h>
// typedef void (*client_watch_callback_fn)(uintptr_t watchKey, int watchType, void* objBytes, int objSize);
// extern void client_watch_callback_wrapper(uintptr_t callbackFn, uintptr_t callbackContext, int watchType, void* objBytes, int objSize);
import "C"

const (
	Closed   = 0
	Added    = 1
	Modified = 2
	Deleted  = 3
	Error    = -1
)

func getClientSets() (*contrailClient.Clientset, *kubernetes.Clientset, dynamic.Interface, error) {
	var err error
	var kconfig string
	config, _ := rest.InClusterConfig()
	if config == nil {
		if home := homedir.HomeDir(); home != "" {
			kconfig = filepath.Join(home, ".kube", "config")
		}
		config, err = clientcmd.BuildConfigFromFlags("", kconfig)
		if err != nil {
			return nil, nil, nil, err
		}
	}

	contrailClientSet, err := contrailClient.NewForConfig(config)
	if err != nil {
		return nil, nil, nil, err
	}
	kubernetesClientSet, err := kubernetes.NewForConfig(config)
	if err != nil {
		return nil, nil, nil, err
	}

	dynamicClientSet, err := dynamic.NewForConfig(config)
	if err != nil {
		return nil, nil, nil, err
	}
	return contrailClientSet, kubernetesClientSet, dynamicClientSet, nil
}

type WatchEventHandler interface {
	HandleEvent(eventType int, res *v1alpha1PB.Resource) error
}

var watchMu sync.Mutex
var watchMap = map[C.uintptr_t]chan struct{}{}

func NewSharedInformerFactory(kubernetesClientSet *kubernetes.Clientset, contrailClientSet *contrailClient.Clientset, dynamicClientSet dynamic.Interface, callbackFn C.uintptr_t, callbackContext C.uintptr_t) (dynamicinformer.DynamicSharedInformerFactory, error) {

	sif := dynamicinformer.NewDynamicSharedInformerFactory(dynamicClientSet, time.Minute*10)

	namespaceGVR := schema.GroupVersionResource{
		Group:    "",
		Version:  "v1",
		Resource: "namespaces",
	}
	namespaceInformer := sif.ForResource(namespaceGVR)
	namespaceInformer.Informer().AddEventHandler(resourceEventHandler(&watchHandlerFunc{callbackFn, callbackContext}))

	contrailResources, err := contrailClientSet.DiscoveryClient.ServerResourcesForGroupVersion("core.contrail.juniper.net/v1alpha1")
	if err != nil {
		return nil, err
	}
	for _, contrailResource := range contrailResources.APIResources {
		resourceNameList := strings.Split(contrailResource.Name, "/status")
		gvr := schema.GroupVersionResource{
			Group:    "core.contrail.juniper.net",
			Version:  "v1alpha1",
			Resource: resourceNameList[0],
		}
		dynamicInformer := sif.ForResource(gvr)
		dynamicInformer.Informer().AddEventHandler(resourceEventHandler(&watchHandlerFunc{callbackFn, callbackContext}))
	}

	return sif, nil
}

func convert(obj interface{}) (*v1alpha1PB.Resource, error) {
	switch k := obj.(type) {
	case *unstructured.Unstructured:
		objByte, err := json.Marshal(k)
		if err != nil {
			return nil, err
		}
		res := &v1alpha1PB.Resource{
			Resource: objByte,
		}
		return res, nil
	default:
		fmt.Println("resource unkown")
		return nil, fmt.Errorf("")
	}
}

func resourceEventHandler(handler WatchEventHandler) cache.ResourceEventHandler {
	return cache.ResourceEventHandlerFuncs{
		AddFunc: func(obj interface{}) {
			fmt.Println("add")
			res, err := convert(obj)
			if err == nil {
				handler.HandleEvent(Added, res)
			}
		},
		UpdateFunc: func(oldObj interface{}, newObj interface{}) {
			fmt.Println("update")
			res, err := convert(newObj)
			if err == nil {
				handler.HandleEvent(Modified, res)
			}
		},
		DeleteFunc: func(obj interface{}) {
			res, err := convert(obj)
			if err == nil {
				handler.HandleEvent(Deleted, res)
			}
		},
	}
}

type watchHandlerFunc struct {
	callbackFn      C.uintptr_t
	callbackContext C.uintptr_t
}

func (h *watchHandlerFunc) HandleEvent(eventType int, res *v1alpha1PB.Resource) error {
	objProto, err := proto.Marshal(res)
	if err != nil {
		return err
	}
	objBytes := C.CBytes(objProto)
	objSize := C.int(len(objProto))
	C.client_watch_callback_wrapper(C.uintptr_t(h.callbackFn), C.uintptr_t(h.callbackContext), C.int(eventType), objBytes, objSize)
	C.free(objBytes)

	return nil
}

//export client_watch
func client_watch(callbackFn C.uintptr_t, callbackContext C.uintptr_t) *C.char {
	contrailClientSet, kubernetesClientSet, dynamicClientSet, _ := getClientSets()
	stopCh := make(chan struct{})
	sif, _ := NewSharedInformerFactory(kubernetesClientSet, contrailClientSet, dynamicClientSet, callbackFn, callbackContext)
	sif.Start(stopCh)
	sif.WaitForCacheSync(stopCh)
	watchMu.Lock()
	defer watchMu.Unlock()
	watchMap[callbackContext] = stopCh
	return nil
}

//export client_stop_watch
func client_stop_watch(watchH C.uintptr_t) C.int {
	watchMu.Lock()
	defer watchMu.Unlock()
	if stopCh, ok := watchMap[watchH]; ok {
		close(stopCh)
		delete(watchMap, watchH)
		return 0
	}
	return 1
}
