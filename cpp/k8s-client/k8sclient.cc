#include "k8sclient.h"
#include <string>
#include <memory>

#include "apiresources.pb.h"
//#include "../go/go.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

void K8SClient::Watch(){
    WatchCallbackFn cbFn = callbackFn; 
    watch = watcher([cbFn](int watchType, const v1alpha1::Resource* resource){		
        Document d;
   	    d.Parse(resource->resource().c_str());
        cbFn(watchType, &d);
    });           
}

void K8SClient::Stop(){
	auto ret = client_stop_watch(watch);
}