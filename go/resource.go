package main

import (
	//apiv1 "k8s.io/api/core/v1"
	"unsafe"

	"k8s.io/client-go/discovery"
	"k8s.io/client-go/kubernetes"

	resourcePb "github.com/michaelhenkel/k8s-client-cpp/resourcepb"
)

// #include <stdint.h>
import "C"

//export k8s_client_contrail_get_group_resources
func k8s_client_contrail_get_group_resources(clientsetKey C.uintptr_t, ns *C.char, optsBytes unsafe.Pointer, optsSize C.int, oBytes *unsafe.Pointer, oSize *C.int) *C.char {
	clientset := clientsetMap[clientsetKey].(*kubernetes.Clientset)
	discoveryClient := discovery.NewDiscoveryClient(clientset.RESTClient())
	_, apiResourceList, err := discoveryClient.ServerGroupsAndResources()
	if err != nil {
		return C.CString(err.Error())
	}
	for _, apiResource := range apiResourceList {
		if apiResource.GroupVersion == "core.contrail.juniper.net/v1alpha1" {
			resourcePb.ApiResource{}
			resultProto, _ := apiResource.Marshal()
			*oBytes = C.CBytes(resultProto)
			*oSize = C.int(len(resultProto))
			break
		}
	}
	return nil
}
