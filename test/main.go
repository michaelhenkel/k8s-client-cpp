package main

import (
	"fmt"
	"log"
	"path/filepath"
	"strings"
	"time"

	"k8s.io/apimachinery/pkg/apis/meta/v1/unstructured"
	"k8s.io/apimachinery/pkg/runtime/schema"
	"k8s.io/apimachinery/pkg/util/wait"
	"k8s.io/client-go/dynamic"
	"k8s.io/client-go/dynamic/dynamicinformer"
	"k8s.io/client-go/rest"
	"k8s.io/client-go/tools/cache"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
	contrailClient "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/clientset_generated/clientset"
)

func main() {
	var err error
	var kconfig string
	config, _ := rest.InClusterConfig()
	if config == nil {
		if home := homedir.HomeDir(); home != "" {
			kconfig = filepath.Join(home, ".kube", "config")
		}
		config, err = clientcmd.BuildConfigFromFlags("", kconfig)
		if err != nil {
			fmt.Println(err)
		}
	}

	clusterClient, err := dynamic.NewForConfig(config)
	if err != nil {
		log.Fatalln(err)
	}

	contrailClientSet, err := contrailClient.NewForConfig(config)
	if err != nil {
		log.Fatalln(err)
	}

	var gvrList []schema.GroupVersionResource

	gvrList = append(gvrList, schema.GroupVersionResource{
		Group:    "",
		Version:  "v1",
		Resource: "namespaces",
	})

	contrailResources, err := contrailClientSet.DiscoveryClient.ServerResourcesForGroupVersion("core.contrail.juniper.net/v1alpha1")
	if err != nil {
		log.Fatalln(err)
	}
	for _, contrailResource := range contrailResources.APIResources {
		resourceNameList := strings.Split(contrailResource.Name, "/status")
		gvrList = append(gvrList, schema.GroupVersionResource{
			Group:    "core.contrail.juniper.net",
			Version:  "v1alpha1",
			Resource: resourceNameList[0],
		})
	}
	factory := dynamicinformer.NewDynamicSharedInformerFactory(clusterClient, 10*time.Minute)

	for _, gvr := range gvrList {
		informer := factory.ForResource(gvr).Informer()
		informer.AddEventHandler(resourceEventHandler())
	}
	var stop = make(chan bool)

	go func() {

		//for _, factory := range sifList {
		factory.Start(wait.NeverStop)
		factory.WaitForCacheSync(wait.NeverStop)
		//}
	}()
	<-stop

}

func resourceEventHandler() cache.ResourceEventHandlerFuncs {
	return cache.ResourceEventHandlerFuncs{
		AddFunc: func(obj interface{}) {
			u := obj.(*unstructured.Unstructured)
			name, namefound, err := unstructured.NestedString(u.Object, "metadata", "name")
			if err != nil {
				fmt.Println(err)
			}

			rv, rvfound, err := unstructured.NestedString(u.Object, "metadata", "resourceVersion")
			if err != nil {
				fmt.Println(err)
			}

			kind, kindfound, err := unstructured.NestedString(u.Object, "kind")
			if err != nil {
				fmt.Println(err)
			}
			if namefound && kindfound && rvfound {
				fmt.Println("add", kind, name, rv)
			}
		},
		UpdateFunc: func(oldObj, newObj interface{}) {
			uold := oldObj.(*unstructured.Unstructured)
			u := newObj.(*unstructured.Unstructured)
			name, namefound, err := unstructured.NestedString(u.Object, "metadata", "name")
			if err != nil {
				fmt.Println(err)
			}

			rv, rvfound, err := unstructured.NestedString(u.Object, "metadata", "resourceVersion")
			if err != nil {
				fmt.Println(err)
			}

			oldrv, oldrvfound, err := unstructured.NestedString(uold.Object, "metadata", "resourceVersion")
			if err != nil {
				fmt.Println(err)
			}

			kind, kindfound, err := unstructured.NestedString(u.Object, "kind")
			if err != nil {
				fmt.Println(err)
			}
			if namefound && kindfound && rvfound && oldrvfound {
				fmt.Println("update", kind, name, rv, oldrv)
			}
		},
		DeleteFunc: func(obj interface{}) {},
	}
}
