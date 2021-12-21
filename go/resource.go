package main

import (
	//apiv1 "k8s.io/api/core/v1"

	"unsafe"

	v1alpha1PB "github.com/michaelhenkel/k8s-client-cpp/pkg/apis/v1alpha1"
	"google.golang.org/protobuf/proto"
	"k8s.io/client-go/discovery"
	"k8s.io/client-go/kubernetes"
)

// #include <stdint.h>
import "C"

//export k8s_client_contrail_get_group_resources
func k8s_client_contrail_get_group_resources(clientsetKey C.uintptr_t, groupVersion *C.char, oBytes *unsafe.Pointer, oSize *C.int) *C.char {
	clientset := clientsetMap[clientsetKey].(*kubernetes.Clientset)
	discoveryClient := discovery.NewDiscoveryClient(clientset.RESTClient())
	_, apiResourceList, err := discoveryClient.ServerGroupsAndResources()
	if err != nil {
		return C.CString(err.Error())
	}
	apiResourceListProto := &v1alpha1PB.ApiResource{
		GroupVersion: C.GoString(groupVersion),
		Kinds:        []*v1alpha1PB.Kind{{}},
	}

	var arMap = make(map[string]bool)
	for _, apiResource := range apiResourceList {
		if apiResource.GroupVersion == apiResourceListProto.GroupVersion {
			for _, ar := range apiResource.APIResources {
				arMap[ar.Kind] = ar.Namespaced
			}
		}
	}
	kindList := []*v1alpha1PB.Kind{}
	for k, v := range arMap {
		kindList = append(kindList, &v1alpha1PB.Kind{
			Name:       k,
			Namespaced: v,
		})
	}

	if len(kindList) > 0 {
		apiResourceListProto.Kinds = kindList
		resultProto, _ := proto.Marshal(apiResourceListProto)
		//resultProto, _ := apiResource.Marshal()
		*oBytes = C.CBytes(resultProto)
		*oSize = C.int(len(resultProto))
	}
	return nil
}
