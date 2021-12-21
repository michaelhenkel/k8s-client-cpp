package main

import (
	"context"
	"encoding/json"
	"reflect"

	v1alpha1PB "github.com/michaelhenkel/k8s-client-cpp/pkg/apis/v1alpha1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/apimachinery/pkg/watch"
	v1alpha1 "ssd-git.juniper.net/contrail/cn2/contrail/pkg/apis/core/v1alpha1"
)

// #include <stdlib.h>
// #include <stdint.h>
import "C"

type BGPAsAService struct {
}

func (r *BGPAsAService) objList(clientsetKey C.uintptr_t, ns string, listOptions metav1.ListOptions) (*v1alpha1PB.Resources, error) {
	objList, err := contrailClientsetMap[clientsetKey].CoreV1alpha1().BGPAsAServices(ns).List(context.Background(), listOptions)
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

func (r *BGPAsAService) objWatch(clientsetKey C.uintptr_t, ns string, listOptions metav1.ListOptions) (watch.Interface, error) {
	objWatch, err := contrailClientsetMap[clientsetKey].CoreV1alpha1().BGPAsAServices(ns).Watch(context.Background(), listOptions)
	if err != nil {
		return nil, err
	}
	return objWatch, nil
}

func (r *BGPAsAService) getType() reflect.Type {
	return reflect.TypeOf(&v1alpha1.BGPAsAService{})
}
