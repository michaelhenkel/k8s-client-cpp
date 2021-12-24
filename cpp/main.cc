

#include "pkg/apis/v1alpha1/apiresources.pb.h"


#include <string>
#include <memory>
#include <chrono>
#include <thread>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

#include "../go/go.h"

using namespace rapidjson;

void cbFn(int watchType, rapidjson::Document* d)
{
	Value::MemberIterator md = d->FindMember("metadata");
	Value::MemberIterator md_name = md->value.FindMember("name");
	Value::MemberIterator knd = d->FindMember("kind");
	Value::MemberIterator rv = md->value.FindMember("resourceversion");
	printf("watchType: %d, kind: %s,  name: %s, rv: %s\n", watchType, knd->value.GetString(), md_name->value.GetString(), rv->value.GetString());
}

typedef std::function<void(int watchType, rapidjson::Document* d)> WatchCallbackFn;
typedef std::function<void(int watchType, const v1alpha1::Resource*)> CallbackFn;

static void WatchCallback(uintptr_t callbackContext, int watchType, void* objBytes, int objSize) {
	v1alpha1::Resource obj;
	obj.ParseFromArray(objBytes, objSize);
	(*(CallbackFn*)callbackContext)(watchType, &obj);
}

uintptr_t Watch(CallbackFn callback) {
	CallbackFn *callbackP = new CallbackFn(callback);	
	auto callbackFn = uintptr_t(WatchCallback);
	auto callbackContext = uintptr_t(callbackP);
	auto err = client_watch(callbackFn, callbackContext);
	if (err != NULL) {
		auto errStr = std::string(err);
		free(err);
		throw errStr;
	}
	return callbackContext;
}

void Start(WatchCallbackFn callbackFn){
    WatchCallbackFn cbFn = callbackFn;
    Watch([cbFn](int watchType, const v1alpha1::Resource* resource){
		//printf("resource %s\n", resource->resource().c_str());
		
        Document d;
       	d.Parse(resource->resource().c_str());
        cbFn(watchType, &d);
		
    });
};





int main()
{
	Start(cbFn);
	while(1){};

	return 0;
}
