package main

import (
	"sync"
	"unsafe"

	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"

	contrailClient "ssd-git.juniper.net/contrail/cn2/contrail/pkg/client/clientset_generated/clientset"
)

// #include <stdint.h>
import "C"

var clientsetMu sync.Mutex
var clientsetMap = map[C.uintptr_t]kubernetes.Interface{}

var contrailClientsetMu sync.Mutex
var contrailClientsetMap = map[C.uintptr_t]contrailClient.Interface{}

//export k8s_client_new_from_kubeconfig
func k8s_client_new_from_kubeconfig(masterUrl, kubeconfigPath *C.char, oClientsetH *C.uintptr_t) *C.char {
	config, err := clientcmd.BuildConfigFromFlags(C.GoString(masterUrl), C.GoString(kubeconfigPath))
	if err != nil {
		return C.CString(err.Error())
	}
	clientset, err := kubernetes.NewForConfig(config)
	if err != nil {
		return C.CString(err.Error())
	}

	clientsetMu.Lock()
	defer clientsetMu.Unlock()
	*oClientsetH = C.uintptr_t(uintptr((unsafe.Pointer(clientset))))
	clientsetMap[*oClientsetH] = clientset
	return nil
}

//export contrail_client_new_from_kubeconfig
func contrail_client_new_from_kubeconfig(masterUrl, kubeconfigPath *C.char, oClientsetH *C.uintptr_t) *C.char {
	config, err := clientcmd.BuildConfigFromFlags(C.GoString(masterUrl), C.GoString(kubeconfigPath))
	if err != nil {
		return C.CString(err.Error())
	}
	clientset, err := contrailClient.NewForConfig(config)
	if err != nil {
		return C.CString(err.Error())
	}

	contrailClientsetMu.Lock()
	defer contrailClientsetMu.Unlock()
	*oClientsetH = C.uintptr_t(uintptr((unsafe.Pointer(clientset))))
	contrailClientsetMap[*oClientsetH] = clientset
	return nil
}

//export k8s_client_delete
func k8s_client_delete(clientsetH C.uintptr_t) {
	clientsetMu.Lock()
	defer clientsetMu.Unlock()
	delete(clientsetMap, clientsetH)
}

//export contrail_client_delete
func contrail_client_delete(clientsetH C.uintptr_t) {
	contrailClientsetMu.Lock()
	defer contrailClientsetMu.Unlock()
	delete(contrailClientsetMap, clientsetH)
}
