#ifndef K8SCLIENT_H_
#define K8SCLIENT_H_


#include <string>
#include <memory>

//#include "pkg/apis/v1alpha1/apiresources.pb.h"
//#include "../go/go.h"

#include "apiresources.pb.h"
#include "go.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;

typedef std::function<void(int watchType, rapidjson::Document* d)> WatchCallbackFn;
typedef std::function<void(int watchType, const v1alpha1::Resource*)> CallbackFn;

class K8SClient{
public:
	K8SClient(WatchCallbackFn callbackFn): callbackFn(callbackFn) {}
    
    void Watch();
	void Stop();
private:
	uintptr_t watch;
	WatchCallbackFn callbackFn;
    static void WatchCallback(uintptr_t callbackContext, int watchType, void* objBytes, int objSize) {
	    v1alpha1::Resource obj;
	    obj.ParseFromArray(objBytes, objSize);
	    (*(CallbackFn*)callbackContext)(watchType, &obj);
    }
    uintptr_t watcher(CallbackFn callback) {
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
    };    
};

#endif // K8SCLIENT_H_