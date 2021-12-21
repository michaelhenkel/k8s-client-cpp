package main

import (
	"context"
	"encoding/json"
	"fmt"
	"reflect"
	"unsafe"

	v1alpha1PB "github.com/michaelhenkel/k8s-client-cpp/pkg/apis/v1alpha1"
	"google.golang.org/protobuf/proto"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/apimachinery/pkg/watch"
	v1alpha1 "ssd-git.juniper.net/contrail/cn2/contrail/pkg/apis/core/v1alpha1"
)

// #include <stdlib.h>
// #include <stdint.h>
// typedef void (*k8s_client_watch_callback_fn)(uintptr_t watchKey, int watchType, void* objBytes, int objSize);
// extern void k8s_client_watch_callback_wrapper(uintptr_t callbackFn, uintptr_t callbackContext, int watchType, void* objBytes, int objSize);
import "C"

type contrailResource interface {
	objList(C.uintptr_t, string, metav1.ListOptions) (*v1alpha1PB.Resources, error)
	objWatch(C.uintptr_t, string, metav1.ListOptions) (watch.Interface, error)
	getType() reflect.Type
}

func cr(kind *C.char) contrailResource {
	var cr contrailResource
	switch C.GoString(kind) {
	case "VirtualNetwork":
		res := &VirtualNetwork{}
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

	default:
		fmt.Println("resource unknown")
	}
	return &v1alpha1PB.Resource{
		Resource: resByte,
	}, nil
}

type VirtualNetwork struct {
}

func (r *VirtualNetwork) objList(clientsetKey C.uintptr_t, ns string, listOptions metav1.ListOptions) (*v1alpha1PB.Resources, error) {
	objList, err := contrailClientsetMap[clientsetKey].CoreV1alpha1().VirtualNetworks(ns).List(context.Background(), listOptions)
	if err != nil {
		return nil, err
	}
	resourceList := &v1alpha1PB.Resources{
		Resources: []*v1alpha1PB.Resource{},
	}
	for _, obj := range objList.Items {
		objByte, err := json.Marshal(&obj)
		if err != nil {
			return nil, err
		}
		resourceList.Resources = append(resourceList.Resources, &v1alpha1PB.Resource{
			Resource: objByte,
		})
	}
	return resourceList, nil
}

func (r *VirtualNetwork) objWatch(clientsetKey C.uintptr_t, ns string, listOptions metav1.ListOptions) (watch.Interface, error) {
	objWatch, err := contrailClientsetMap[clientsetKey].CoreV1alpha1().VirtualNetworks(ns).Watch(context.Background(), listOptions)
	if err != nil {
		return nil, err
	}
	return objWatch, nil
}

func (r *VirtualNetwork) getType() reflect.Type {
	return reflect.TypeOf(&v1alpha1.VirtualNetwork{})
}

//export k8s_client_contrail_list
func k8s_client_contrail_list(clientsetKey C.uintptr_t, kind *C.char, ns *C.char, optsBytes unsafe.Pointer, optsSize C.int, oBytes *unsafe.Pointer, oSize *C.int) *C.char {
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

type contrailWatchHandlerFunc struct {
	callbackFn      C.uintptr_t
	callbackContext C.uintptr_t
}

func (h *contrailWatchHandlerFunc) HandleEvent(eventType int, o interface{}) error {
	res, err := convertObject(o)
	if err != nil {
		return err
	}
	objProto, err := proto.Marshal(res)
	if err != nil {
		return err
	}
	objBytes := C.CBytes(objProto)
	objSize := C.int(len(objProto))
	C.k8s_client_watch_callback_wrapper(C.uintptr_t(h.callbackFn), C.uintptr_t(h.callbackContext), C.int(eventType), objBytes, objSize)
	C.free(objBytes)
	return nil
}

//export k8s_client_contrail_watch
func k8s_client_contrail_watch(clientsetKey C.uintptr_t, kind *C.char, ns *C.char, optsBytes unsafe.Pointer, optsSize C.int,
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

	go watchHandler(watch, cr(kind).getType(), &contrailWatchHandlerFunc{callbackFn, callbackContext}, stopCh)

	return nil
}

//export k8s_client_contrail_stop_watch
func k8s_client_contrail_stop_watch(watchH C.uintptr_t) C.int {
	watchMu.Lock()
	defer watchMu.Unlock()
	if stopCh, ok := watchMap[watchH]; ok {
		close(stopCh)
		delete(watchMap, watchH)
		return 0
	}
	return 1
}
