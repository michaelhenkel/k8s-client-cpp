package main

import (
	"encoding/json"
	"fmt"
	"path/filepath"
	"sync"
	"time"

	v1alpha1PB "github.com/michaelhenkel/k8s-client-cpp/pkg/apis/v1alpha1"
	"google.golang.org/protobuf/proto"
	v1 "k8s.io/api/core/v1"
	"k8s.io/client-go/informers"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/rest"
	"k8s.io/client-go/tools/cache"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
	v1alpha1 "ssd-git.juniper.net/contrail/cn2/contrail/pkg/apis/core/v1alpha1"
	contrailClient "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/clientset_generated/clientset"
	contrailInformers "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/informers_generated/externalversions"
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

func getClientSets() (*contrailClient.Clientset, *kubernetes.Clientset, error) {
	bla()
	var err error
	var kconfig string
	config, _ := rest.InClusterConfig()
	if config == nil {
		if home := homedir.HomeDir(); home != "" {
			kconfig = filepath.Join(home, ".kube", "config")
		}
		config, err = clientcmd.BuildConfigFromFlags("", kconfig)
		if err != nil {
			return nil, nil, err
		}
	}

	contrailClientSet, err := contrailClient.NewForConfig(config)
	if err != nil {
		return nil, nil, err
	}
	kubernetesClientSet, err := kubernetes.NewForConfig(config)
	if err != nil {
		return nil, nil, err
	}
	return contrailClientSet, kubernetesClientSet, nil
}

type WatchEventHandler interface {
	HandleEvent(eventType int, res *v1alpha1PB.Resource) error
}

var watchMu sync.Mutex
var watchMap = map[C.uintptr_t]chan struct{}{}

type sharedInformerFactory struct {
	contrailSharedInformerFactory   contrailInformers.SharedInformerFactory
	kubernetesSharedInformerFactory informers.SharedInformerFactory
}

func NewSharedInformerFactory(kubernetesClientSet *kubernetes.Clientset, contrailClientSet *contrailClient.Clientset, callbackFn C.uintptr_t, callbackContext C.uintptr_t) (*sharedInformerFactory, error) {
	sif := &sharedInformerFactory{
		contrailSharedInformerFactory:   contrailInformers.NewSharedInformerFactory(contrailClientSet, 10*time.Minute),
		kubernetesSharedInformerFactory: informers.NewSharedInformerFactory(kubernetesClientSet, 10*time.Minute),
	}
	namespaceInformer := sif.kubernetesSharedInformerFactory.Core().V1().Namespaces()
	namespaceInformer.Informer().AddEventHandler(resourceEventHandler("Namespace", &watchHandlerFunc{callbackFn, callbackContext}))

	contrailResources, err := contrailClientSet.DiscoveryClient.ServerResourcesForGroupVersion("core.contrail.juniper.net/v1alpha1")
	if err != nil {
		return nil, err
	}
	for _, contrailResource := range contrailResources.APIResources {
		addResourceEventHandler(contrailResource.Kind, sif.contrailSharedInformerFactory, callbackFn, callbackContext)
	}
	return sif, nil
}

func addResourceEventHandler(kind string, contrailSharedInformerFactory contrailInformers.SharedInformerFactory, callbackFn C.uintptr_t, callbackContext C.uintptr_t) {
	switch kind {
	case "VirtualNetwork":
		informer := contrailSharedInformerFactory.Core().V1alpha1().VirtualNetworks()
		informer.Informer().AddEventHandler(resourceEventHandler(kind, &watchHandlerFunc{callbackFn, callbackContext}))
	}
}

type metaObj struct {
	Kind string
}

func convert(kind string, obj interface{}) (*v1alpha1PB.Resource, error) {
	var resource interface{}
	switch kind {
	case "VirtualNetwork":
		resourceObj := obj.(*v1alpha1.VirtualNetwork)
		resourceObj.Kind = kind
		resource = resourceObj
	case "Namespace":
		resourceObj := obj.(*v1.Namespace)
		resourceObj.Kind = kind
		resource = resourceObj
	}
	res, err := toResource(resource)
	if err != nil {
		return nil, err
	}
	return res, nil
}

func toResource(obj interface{}) (*v1alpha1PB.Resource, error) {
	objByte, err := json.Marshal(obj)
	if err != nil {
		return nil, err
	}
	res := &v1alpha1PB.Resource{
		Resource: objByte,
	}
	return res, nil

}

func resourceEventHandler(kind string, handler WatchEventHandler) cache.ResourceEventHandler {
	return cache.ResourceEventHandlerFuncs{
		AddFunc: func(obj interface{}) {
			res, err := convert(kind, obj)
			if err == nil {
				handler.HandleEvent(Added, res)
			}
		},
		UpdateFunc: func(oldObj interface{}, newObj interface{}) {
			fmt.Println("update")
			res, err := convert(kind, newObj)
			if err == nil {
				handler.HandleEvent(Modified, res)
			}
		},
		DeleteFunc: func(obj interface{}) {
			res, err := convert(kind, obj)
			if err == nil {
				handler.HandleEvent(Deleted, res)
			}
		},
	}
}

func (s *sharedInformerFactory) start(stopCh chan struct{}) {
	s.contrailSharedInformerFactory.Start(stopCh)
	s.contrailSharedInformerFactory.WaitForCacheSync(stopCh)
	s.kubernetesSharedInformerFactory.Start(stopCh)
	s.kubernetesSharedInformerFactory.WaitForCacheSync(stopCh)
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
	contrailClientSet, kubernetesClientSet, _ := getClientSets()
	stopCh := make(chan struct{})
	sif, _ := NewSharedInformerFactory(kubernetesClientSet, contrailClientSet, callbackFn, callbackContext)
	sif.start(stopCh)
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
