#ifndef WATCHER_H_
#define WATCHER_H_


#include <string>
#include <memory>

#include "pkg/apis/v1alpha1/apiresources.pb.h"
#include "k8s.io/apimachinery/pkg/apis/meta/v1/generated.pb.h"
#include "../go/go.h"
#include "clientset.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;

namespace metav1 = k8s::io::apimachinery::pkg::apis::meta::v1;

class Watcher{
public:
	Watcher(ClientSet* clientSet, const char* kind): clientSet(clientSet), kind(kind) {}
    typedef std::function<void(int watchType, const v1alpha1::Resource*, const char* kind)> WatchCallbackFn;
    void Start(WatchCallbackFn callbackFn){
        const char* k = kind;
        WatchCallbackFn cbFn = callbackFn;
        watch = clientSet->resource().Watch(metav1::ListOptions(), [k,cbFn](int watchType, const v1alpha1::Resource* resource){
            cbFn(watchType, resource, k);
        }, kind, "");
    };
    void Status(){
        if (watch){
            printf("watch is running\n");
        } else {
            printf("watch is not running\n");
        }
    };
    void Stop(){
        if (watch){
            printf("stopping watch\n");
            clientSet->resource().StopWatch(watch);
        } else {
            printf("cannot stop, watch not found\n");
        }
    };
private:
    ClientSet* clientSet;
    const char* kind;
	uintptr_t watch;
};

class WatchManager {
public:
	WatchManager() {
        watchMap.clear();
    }
	void Add(const char* kind, ClientSet* clientSet){
        printf("add watcher for kind %s\n", kind);
		watchit = watchMap.find(kind);
		if (watchit == watchMap.end())
		{
            Watcher* watcher = new Watcher(clientSet, kind);
            watchMap.insert(std::pair<const char*, Watcher*>(kind, watcher));
		}		

	};
    typedef std::function<void(int watchType, const v1alpha1::Resource*, const char* kind)> WatchCallbackFn;
    void Start(const char* kind, WatchCallbackFn callbackFn){
        printf("searching for kind %s\n", kind);
        watchit = watchMap.find(kind);
		if (watchit != watchMap.end())
		{  
            printf("%s found\n", kind);
            watchit->second->Start(callbackFn);
        } else {
            printf("%s not found\n", kind);
        }
    };
    void Stop(const char* kind){
        printf("calling stop\n");
        watchit = watchMap.find(kind);
		if (watchit != watchMap.end())
		{  
            watchit->second->Stop();
        }
    };
    void Status(const char* kind){
        watchit = watchMap.find(kind);
		if (watchit != watchMap.end())
		{  
            watchit->second->Status();
        }
    };
private:
	std::map<const char*, Watcher*> watchMap;
	std::map<const char*, Watcher*>::iterator watchit;
	const char* kind;
};

#endif // WATCHER_H_