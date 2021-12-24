package main

import (
	"fmt"
	"log"
	"path/filepath"
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

	factory := dynamicinformer.NewDynamicSharedInformerFactory(clusterClient, time.Minute)

	namespaceResource := schema.GroupVersionResource{Group: "", Version: "v1", Resource: "namespaces"}
	namespaceInformer := factory.ForResource(namespaceResource).Informer()
	namespaceInformer.AddEventHandler(cache.ResourceEventHandlerFuncs{
		AddFunc: func(obj interface{}) {
			u := obj.(*unstructured.Unstructured)
			fmt.Println(u)
		},
		UpdateFunc: func(oldObj, newObj interface{}) {
			u := newObj.(*unstructured.Unstructured)
			fmt.Println(u)
		},
		DeleteFunc: func(obj interface{}) {},
	})

	vnResource := schema.GroupVersionResource{Group: "core.contrail.juniper.net", Version: "v1alpha1", Resource: "virtualnetworks"}
	vnInformer := factory.ForResource(vnResource).Informer()
	vnInformer.AddEventHandler(cache.ResourceEventHandlerFuncs{
		AddFunc: func(obj interface{}) {
			u := obj.(*unstructured.Unstructured)
			fmt.Println(u)
		},
		UpdateFunc: func(oldObj, newObj interface{}) {
			u := newObj.(*unstructured.Unstructured)
			fmt.Println(u)
		},
		DeleteFunc: func(obj interface{}) {},
	})
	var stop = make(chan bool)
	go func() {
		factory.Start(wait.NeverStop)
		factory.WaitForCacheSync(wait.NeverStop)
	}()
	<-stop

}
