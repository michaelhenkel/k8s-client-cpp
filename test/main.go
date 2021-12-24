package main

import (
	"encoding/json"
	"fmt"
	"time"

	"k8s.io/apimachinery/pkg/util/wait"
	"k8s.io/client-go/informers"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/cache"
	"k8s.io/client-go/tools/clientcmd"
	contrailClient "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/clientset_generated/clientset"
	contrailInformers "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/informers_generated/externalversions"
)

func main() {
	config, err := clientcmd.BuildConfigFromFlags("", "/Users/mhenkel/.kube/config")
	if err != nil {
		fmt.Println(err)
	}

	clientset, err := kubernetes.NewForConfig(config)
	if err != nil {
		fmt.Println(err)
	}

	cn2Clientset, err := contrailClient.NewForConfig(config)
	if err != nil {
		fmt.Println(err)
	}

	sif, err := NewSharedInformerFactory(clientset, cn2Clientset)
	if err != nil {
		fmt.Println(err)
	}
	sif.start()
	//

	//kubeFactory := informers.NewSharedInformerFactory(clientset, 10*time.Minute)

}

type sharedInformerFactory struct {
	contrailSharedInformerFactory   contrailInformers.SharedInformerFactory
	kubernetesSharedInformerFactory informers.SharedInformerFactory
}

func (s *sharedInformerFactory) start() {
	stopCh := make(chan struct{})
	go func() {
		s.contrailSharedInformerFactory.Start(wait.NeverStop)
		s.contrailSharedInformerFactory.WaitForCacheSync(wait.NeverStop)
		s.kubernetesSharedInformerFactory.Start(wait.NeverStop)
		s.kubernetesSharedInformerFactory.WaitForCacheSync(wait.NeverStop)
	}()
	<-stopCh
}

func NewSharedInformerFactory(kubernetesClientSet *kubernetes.Clientset, contrailClientSet *contrailClient.Clientset) (*sharedInformerFactory, error) {
	sif := &sharedInformerFactory{
		contrailSharedInformerFactory:   contrailInformers.NewSharedInformerFactory(contrailClientSet, 10*time.Minute),
		kubernetesSharedInformerFactory: informers.NewSharedInformerFactory(kubernetesClientSet, 10*time.Minute),
	}
	namespaceInformer := sif.kubernetesSharedInformerFactory.Core().V1().Namespaces()
	namespaceInformer.Informer().AddEventHandler(resourceEventHandler())

	contrailResources, err := contrailClientSet.DiscoveryClient.ServerResourcesForGroupVersion("core.contrail.juniper.net/v1alpha1")
	if err != nil {
		return nil, err
	}
	for _, contrailResource := range contrailResources.APIResources {
		addResourceEventHandler(contrailResource.Kind, sif.contrailSharedInformerFactory)
	}
	return sif, nil
}

func addResourceEventHandler(kind string, contrailSharedInformerFactory contrailInformers.SharedInformerFactory) {
	switch kind {
	case "VirtualNetwork":
		contrailSharedInformerFactory.Core().V1alpha1().VirtualNetworks()
	}
}

func resourceEventHandler(whf watchHandlerFunc) cache.ResourceEventHandler {
	return cache.ResourceEventHandlerFuncs{
		AddFunc: func(obj interface{}) {
			objByte, _ := json.Marshal(obj)
			fmt.Printf("got add %s\n", string(objByte))
		},
		UpdateFunc: func(oldObj interface{}, newObj interface{}) {
			fmt.Println("got update")
		},
		DeleteFunc: func(obj interface{}) {
			fmt.Println("got delete")
		},
	}
}

type watchHandlerFunc struct {
	callbackFn func()
	//callbackContext C.uintptr_t
}
