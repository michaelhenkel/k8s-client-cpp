package main

import (
	"encoding/json"
	"fmt"
	"reflect"
	"unsafe"

	v1alpha1PB "github.com/michaelhenkel/k8s-client-cpp/pkg/apis/v1alpha1"
	"google.golang.org/protobuf/proto"
	v1 "k8s.io/api/core/v1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/apimachinery/pkg/watch"
	v1alpha1 "ssd-git.juniper.net/contrail/cn2/contrail/pkg/apis/core/v1alpha1"
)

// #include <stdlib.h>
// #include <stdint.h>
// typedef void (*client_watch_callback_fn)(uintptr_t watchKey, int watchType, void* objBytes, int objSize);
// extern void client_watch_callback_wrapper(uintptr_t callbackFn, uintptr_t callbackContext, int watchType, void* objBytes, int objSize);
import "C"

type resource interface {
	objList(C.uintptr_t, string, metav1.ListOptions) (*v1alpha1PB.Resources, error)
	objWatch(C.uintptr_t, string, metav1.ListOptions) (watch.Interface, error)
	getType() reflect.Type
}

func cr(kind *C.char) resource {
	var cr resource
	switch C.GoString(kind) {
	case "VirtualNetwork":
		res := &VirtualNetwork{}
		cr = res
	case "FloatingIP":
		res := &FloatingIP{}
		cr = res
	case "RouteTarget":
		res := &RouteTarget{}
		cr = res
	case "VirtualNetworkRouter":
		res := &VirtualNetworkRouter{}
		cr = res
	case "FirewallPolicy":
		res := &FirewallPolicy{}
		cr = res
	case "FirewallRule":
		res := &FirewallRule{}
		cr = res
	case "GlobalVrouterConfig":
		res := &GlobalVrouterConfig{}
		cr = res
	case "InstanceIP":
		res := &InstanceIP{}
		cr = res
	case "TagType":
		res := &TagType{}
		cr = res
	case "VirtualMachine":
		res := &VirtualMachine{}
		cr = res
	case "AddressGroup":
		res := &AddressGroup{}
		cr = res
	case "GlobalSystemConfig":
		res := &GlobalSystemConfig{}
		cr = res
	case "Subnet":
		res := &Subnet{}
		cr = res
	case "VirtualMachineInterface":
		res := &VirtualMachineInterface{}
		cr = res
	case "BGPRouter":
		res := &BGPRouter{}
		cr = res
	case "RoutingInstance":
		res := &RoutingInstance{}
		cr = res
	case "Tag":
		res := &Tag{}
		cr = res
	case "VirtualRouter":
		res := &VirtualRouter{}
		cr = res
	case "ApplicationPolicySet":
		res := &ApplicationPolicySet{}
		cr = res
	case "BGPAsAService":
		res := &BGPAsAService{}
		cr = res
	case "Namespace":
		res := &Namespace{}
		cr = res
	}
	return cr
}

func convertObject(o interface{}) (*v1alpha1PB.Resource, error) {
	var resByte []byte
	var err error
	switch o := o.(type) {
	case *v1alpha1.VirtualNetwork:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.FloatingIP:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.RouteTarget:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.VirtualNetworkRouter:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.FirewallPolicy:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.FirewallRule:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.GlobalVrouterConfig:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.InstanceIP:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.TagType:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.VirtualMachine:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.AddressGroup:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.GlobalSystemConfig:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.Subnet:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.VirtualMachineInterface:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.BGPRouter:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.RoutingInstance:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.Tag:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.VirtualRouter:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.ApplicationPolicySet:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1alpha1.BGPAsAService:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	case *v1.Namespace:
		res := o
		resByte, err = json.Marshal(res)
		if err != nil {
			return nil, err
		}
	default:
		fmt.Println("resource unknown")
		return nil, nil
	}
	return &v1alpha1PB.Resource{
		Resource: resByte,
	}, nil
}

//export client_list
func client_list(clientsetKey C.uintptr_t, kind *C.char, ns *C.char, optsBytes unsafe.Pointer, optsSize C.int, oBytes *unsafe.Pointer, oSize *C.int) *C.char {
	listOptions := metav1.ListOptions{}
	listOptions.Unmarshal(no_copy_slice_from_c_array(optsBytes, optsSize))
	objList, err := cr(kind).objList(clientsetKey, C.GoString(ns), listOptions)
	if err != nil {
		return C.CString(err.Error())
	}
	resultProto, err := proto.Marshal(objList)
	if err != nil {
		return C.CString(err.Error())
	}
	*oBytes = C.CBytes(resultProto)
	*oSize = C.int(len(resultProto))
	return nil
}

type watchHandlerFunc struct {
	callbackFn      C.uintptr_t
	callbackContext C.uintptr_t
}

func (h *watchHandlerFunc) HandleEvent(eventType int, o interface{}) error {
	res, err := convertObject(o)
	if err != nil {
		return err
	}
	if res != nil {
		objProto, err := proto.Marshal(res)
		if err != nil {
			return err
		}
		objBytes := C.CBytes(objProto)
		objSize := C.int(len(objProto))
		C.client_watch_callback_wrapper(C.uintptr_t(h.callbackFn), C.uintptr_t(h.callbackContext), C.int(eventType), objBytes, objSize)
		C.free(objBytes)
	}
	return nil
}

//export client_watch
func client_watch(clientsetKey C.uintptr_t, kind *C.char, ns *C.char, optsBytes unsafe.Pointer, optsSize C.int,
	callbackFn C.uintptr_t, callbackContext C.uintptr_t) *C.char {
	listOptions := metav1.ListOptions{}
	listOptions.Unmarshal(no_copy_slice_from_c_array(optsBytes, optsSize))
	listOptions.ResourceVersion = "0"
	watch, err := cr(kind).objWatch(clientsetKey, C.GoString(ns), listOptions)
	if err != nil {
		return C.CString(err.Error())
	}

	watchMu.Lock()
	defer watchMu.Unlock()
	stopCh := make(chan struct{})
	watchMap[callbackContext] = stopCh

	go watchHandler(watch, cr(kind).getType(), &watchHandlerFunc{callbackFn, callbackContext}, stopCh)

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
