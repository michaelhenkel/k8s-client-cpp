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

void callbackFn(int watchType, const v1alpha1::Resource* resource, const char* kind)
{
	printf("%s\n",resource->resource().c_str());
	Document d;
	d.Parse(resource->resource().c_str());
	Value k;
	k.SetString(StringRef(kind));  
	d.AddMember("kind", k, d.GetAllocator());
	Value::MemberIterator md = d.FindMember("metadata");
	Value::MemberIterator md_name = md->value.FindMember("name");
	Value::MemberIterator knd = d.FindMember("kind");
	printf("watchType: %d, kind: %s,  name: %s\n", watchType, knd->value.GetString(), md_name->value.GetString());
}

void watcher(ClientSet clientSet, const char* kind){
    auto watch = clientSet.resource().Watch(metav1::ListOptions(), [kind](int watchType, const v1alpha1::Resource* resource){
	    printf("kind: %s\n",kind);
        callbackFn(watchType, resource, kind);
    },kind, "");
}

class Watcher{
public:
	Watcher(ClientSet clientSet, const char* kind): clientSet(clientSet), kind(kind) {}
    void Start(){
        printf("starting watcherThread for kind %s\n", kind);
        threadPtr = std::make_shared<std::thread>(watcher,clientSet, kind);
    };
private:
    ClientSet clientSet;
    const char* kind;
	std::shared_ptr<std::thread> threadPtr;
	uintptr_t watch;
};


class WatchManager {
public:
	WatchManager() {
        watchMap.clear();
    }
	void Add(const char* kind, ClientSet clientSet){
        printf("add watcher for kind %s\n", kind);
		watchit = watchMap.find(kind);
		if (watchit == watchMap.end())
		{
            Watcher* watcher = new Watcher(clientSet, kind);
            watchMap.insert(std::pair<const char*, Watcher*>(kind, watcher));
		}		

	};
    void Start(const char* kind){
        printf("searching for kind %s\n", kind);
        watchit = watchMap.find(kind);
		if (watchit != watchMap.end())
		{  
            printf("%s found\n", kind);
            watchit->second->Start();
        } else {
            printf("%s not found\n", kind);
        }
    };
    void Stop(const char* kind){
        watchit = watchMap.find(kind);
		if (watchit != watchMap.end())
		{  
        }
    };
private:
	std::map<const char*, Watcher*> watchMap;
	std::map<const char*, Watcher*>::iterator watchit;
	const char* kind;
};

#endif // WATCHER_H_