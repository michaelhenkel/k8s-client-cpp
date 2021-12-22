

#include "k8s.io/api/core/v1/generated.pb.h"
#include "pkg/apis/v1alpha1/apiresources.pb.h"
#include "k8s-client/clientset.h"
#include "k8s-client/watcher.h"

#include <string>
#include <memory>
#include <chrono>
#include <thread>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

namespace apiv1 = k8s::io::api::core::v1;
namespace metav1 = k8s::io::apimachinery::pkg::apis::meta::v1;
using namespace rapidjson;

/*
void callbackFn(int watchType, const v1alpha1::Resource* resource, const char* kind)
{
	//printf("%s\n",resource->resource().c_str());
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
	auto watchH = clientSet.resource().Watch(metav1::ListOptions(), [kind](int watchType, const v1alpha1::Resource* resource){
		callbackFn(watchType, resource, kind);
	},kind, "");
	watchit = watchMap.find(kind);
	if (watchit == watchMap.end())
	{
		//watchit->second->AddWatch(watchH);
	}
}
*/

int main()
{
	WatchManager* wm = new WatchManager();

	ClientSet contrailClientSet("", "/Users/mhenkel/.kube/config", "core.contrail.juniper.net/v1alpha1");
	ClientSet kubernetesClientSet("", "/Users/mhenkel/.kube/config", "v1");


	const char* namespaceKind = "Namespace";	
	wm->Add(namespaceKind, kubernetesClientSet);
	wm->Start(namespaceKind);
/*
	const char* kind = "VirtualNetwork";	
	wm->Add(kind, contrailClientSet);
	wm->Start(kind);
*/
/*
	auto apiResourceList = kubernetesClientSet.apiResource().List("core.contrail.juniper.net/v1alpha1");
	for (auto it = apiResourceList.kinds().begin(); it != apiResourceList.kinds().end(); ++it) {		
		const char* kind = it->name().c_str();
		wm->Add(kind, contrailClientSet);
		wm->Start(kind);
	}
*/
	std::this_thread::sleep_for(std::chrono::milliseconds(24*3600*1000));
/*
	clientset.coreV1().Nodes().StopWatch(nodeWatchH);
*/

	return 0;
}
