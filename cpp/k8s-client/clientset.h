#ifndef CLIENTSET_H_
#define CLIENTSET_H_


#include <string>
#include <memory>

#include "corev1.h"
#include "apiresource.h"
#include "contrail.h"
#include "../go/go.h"

class ClientSet {
public:
	ClientSet(const std::string& masterUrl, const std::string& kubeconfigPath) {
		auto err = k8s_client_new_from_kubeconfig((char*)masterUrl.data(), (char*)kubeconfigPath.data(), &clientsetH);
		if (err != NULL) {
			auto errStr = std::string(err);
			free(err);
			throw errStr;
		}
	}
	~ClientSet() {
		if (clientsetH != 0) k8s_client_delete(clientsetH);
	}

	CoreV1 coreV1() {
		return CoreV1(clientsetH);
	}

	ApiResource apiResource() {
		return ApiResource(clientsetH);
	}


	
public:
	uintptr_t clientsetH;
};

class ContrailClientSet {
public:
	ContrailClientSet(const std::string& masterUrl, const std::string& kubeconfigPath) {
		auto err = contrail_client_new_from_kubeconfig((char*)masterUrl.data(), (char*)kubeconfigPath.data(), &contrailclientsetH);
		if (err != NULL) {
			auto errStr = std::string(err);
			free(err);
			throw errStr;
		}
	}
	~ContrailClientSet() {
		if (contrailclientsetH != 0) contrail_client_delete(contrailclientsetH);
	}


	Contrail contrail() {
		return Contrail(contrailclientsetH);
	}
	
public:
	uintptr_t contrailclientsetH;
};
#endif // CLIENTSET_H_