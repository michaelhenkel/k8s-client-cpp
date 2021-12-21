package main

import (
	"fmt"

	"k8s.io/client-go/discovery"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
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
	discoveryClient := discovery.NewDiscoveryClient(clientset.RESTClient())
	_, apiResourceList, err := discoveryClient.ServerGroupsAndResources()
	if err != nil {
		fmt.Println(err)
	}
	var arMap = make(map[string]bool)
	for _, apiResource := range apiResourceList {
		if apiResource.GroupVersion == "core.contrail.juniper.net/v1alpha1" {
			for _, ar := range apiResource.APIResources {
				arMap[ar.Kind] = ar.Namespaced
			}
		}
	}
	for k, v := range arMap {
		fmt.Printf("%s:%v\n", k, v)
	}
}
