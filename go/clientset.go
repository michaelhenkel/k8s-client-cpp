package main

import (
	"fmt"
	"path/filepath"
	"sync"
	"unsafe"

	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/rest"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"

	contrailClient "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/clientset_generated/clientset"
)

// #include <stdint.h>
import "C"

var clientsetMu sync.Mutex
var clientsetMap = map[C.uintptr_t]kubernetes.Interface{}

var contrailClientsetMu sync.Mutex
var contrailClientsetMap = map[C.uintptr_t]contrailClient.Interface{}

var kconfig string

//export client_new_from_kubeconfig
func client_new_from_kubeconfig(masterUrl, kubeconfigPath *C.char, apiGroup *C.char, oClientsetH *C.uintptr_t) *C.char {
	var err error
	var kconfig string
	config, _ := rest.InClusterConfig()
	if config == nil {
		if home := homedir.HomeDir(); home != "" {
			kconfig = filepath.Join(home, ".kube", "config")
		}
		config, err = clientcmd.BuildConfigFromFlags("", kconfig)
		if err != nil {
			return C.CString(err.Error())
		}
	}

	switch C.GoString(apiGroup) {
	case "core.contrail.juniper.net/v1alpha1":
		clientset, err := contrailClient.NewForConfig(config)
		if err != nil {
			return C.CString(err.Error())
		}

		contrailClientsetMu.Lock()
		defer contrailClientsetMu.Unlock()
		*oClientsetH = C.uintptr_t(uintptr((unsafe.Pointer(clientset))))
		contrailClientsetMap[*oClientsetH] = clientset
	case "v1":
		clientset, err := kubernetes.NewForConfig(config)
		if err != nil {
			return C.CString(err.Error())
		}

		clientsetMu.Lock()
		defer clientsetMu.Unlock()
		*oClientsetH = C.uintptr_t(uintptr((unsafe.Pointer(clientset))))
		clientsetMap[*oClientsetH] = clientset
	}

	return nil
}

//export client_delete
func client_delete(clientsetH C.uintptr_t) {
	fmt.Println("destructor called")
	/*
		if _, ok := contrailClientsetMap[clientsetH]; ok {
			contrailClientsetMu.Lock()
			defer contrailClientsetMu.Unlock()
			delete(contrailClientsetMap, clientsetH)
		}
		if _, ok := clientsetMap[clientsetH]; ok {
			clientsetMu.Lock()
			defer clientsetMu.Unlock()
			delete(clientsetMap, clientsetH)
		}
	*/
}
