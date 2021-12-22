#ifndef CLIENTSET_H_
#define CLIENTSET_H_


#include <string>
#include <memory>

#include "apiresource.h"
#include "resource.h"
#include "../go/go.h"

class ClientSet {
public:
	ClientSet(const std::string& masterUrl, const std::string& kubeconfigPath, const std::string& apiGroup) {
		auto err = client_new_from_kubeconfig((char*)masterUrl.data(), (char*)kubeconfigPath.data(),(char*)apiGroup.data(), &clientsetH);
		if (err != NULL) {
			auto errStr = std::string(err);
			free(err);
			throw errStr;
		}
	}
	~ClientSet() {
		if (clientsetH != 0) client_delete(clientsetH);
	}


	Resource resource() {
		return Resource(clientsetH);
	}

	ApiResource apiResource() {
		return ApiResource(clientsetH);
	}
	
public:
	uintptr_t clientsetH;
};
#endif // CLIENTSET_H_