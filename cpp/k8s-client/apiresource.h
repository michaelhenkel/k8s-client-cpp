#ifndef APIRESOURCE_H_
#define APIRESOURCE_H_


#include <string>
#include <memory>

#include "pkg/apis/v1alpha1/apiresources.pb.h"
#include "../go/go.h"

//namespace apiv1 = k8s::io::api::core::v1;
//namespace metav1 = k8s::io::apimachinery::pkg::apis::meta::v1;

//namespace v1alpha1;

class ApiResource {
public:
	ApiResource(uintptr_t clientsetH): clientsetH(clientsetH) {}

	v1alpha1::ApiResource List(const std::string& groupVersion) {
		void *objListBytes = NULL;
		int objListSize = 0;
		auto err = k8s_client_contrail_get_group_resources(clientsetH, (char*)groupVersion.data(), &objListBytes, &objListSize);
		if (err != NULL) {
			auto errStr = std::string(err);
			free(err);
			throw errStr;
		}

		v1alpha1::ApiResource objList;
		objList.ParseFromArray(objListBytes, objListSize);
		free(objListBytes);
		return objList;
	}

private:
	std::string groupVersion;
	uintptr_t clientsetH;
};


#endif // APIRESOURCE_H_