#ifndef RESOURCE_H_
#define RESOURCE_H_


#include <string>
#include <memory>

#include "pkg/apis/v1alpha1/apiresources.pb.h"
#include "k8s.io/apimachinery/pkg/apis/meta/v1/generated.pb.h"
#include "../go/go.h"

namespace metav1 = k8s::io::apimachinery::pkg::apis::meta::v1;

class Resource {
public:
	Resource(uintptr_t clientsetH): clientsetH(clientsetH) {}

	v1alpha1::Resources List(const metav1::ListOptions& listOptions, const std::string& kind, const std::string& ns) {
		std::uint8_t listOptionsBytes[listOptions.ByteSize()];
		listOptions.SerializeToArray(listOptionsBytes, sizeof(listOptionsBytes));
		void *objListBytes = NULL;
		int objListSize = 0;
		auto err = client_list(clientsetH, (char*)kind.data(), (char*)ns.data(), listOptionsBytes, sizeof(listOptionsBytes), &objListBytes, &objListSize);
		if (err != NULL) {
			auto errStr = std::string(err);
			free(err);
			throw errStr;
		}

		v1alpha1::Resources objList;
		objList.ParseFromArray(objListBytes, objListSize);
		free(objListBytes);
		return objList;
	}

	typedef std::function<void(int watchType, const v1alpha1::Resource*)> WatchCallbackFn;
	uintptr_t Watch(const metav1::ListOptions& listOptions, WatchCallbackFn callback, const std::string& kind, const std::string& ns) {
		std::uint8_t listOptionsBytes[listOptions.ByteSize()];
		listOptions.SerializeToArray(listOptionsBytes, sizeof(listOptionsBytes));
		WatchCallbackFn *callbackP = new WatchCallbackFn(callback);
		auto callbackFn = uintptr_t(Resource::WatchCallback);
		auto callbackContext = uintptr_t(callbackP);
		auto err = client_watch(clientsetH, (char*)kind.data(), (char*)ns.data(), listOptionsBytes, sizeof(listOptionsBytes), callbackFn, callbackContext);
		if (err != NULL) {
			auto errStr = std::string(err);
			free(err);
			throw errStr;
		}
		return callbackContext;
	}

	void StopWatch(uintptr_t watchH) {
		if (client_stop_watch(watchH)) {
			delete (WatchCallbackFn*)watchH;
		}
	}

private:
	static void WatchCallback(uintptr_t callbackContext, int watchType, void* objBytes, int objSize) {
		v1alpha1::Resource obj;
		obj.ParseFromArray(objBytes, objSize);
		(*(WatchCallbackFn*)callbackContext)(watchType, &obj);
	}

private:
	std::string ns;	
	std::string kind;
	uintptr_t clientsetH;
};


#endif // RESOURCE_H_