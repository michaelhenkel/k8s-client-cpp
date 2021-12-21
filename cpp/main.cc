

#include "k8s.io/api/core/v1/generated.pb.h"
#include "pkg/apis/v1alpha1/apiresources.pb.h"
#include "k8s-client/clientset.h"

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



int main()
{
	std::map<const char*, uintptr_t> resourceMap;

	ClientSet contrailClientSet("", "/Users/mhenkel/.kube/config", "core.contrail.juniper.net/v1alpha1");
	ClientSet kubernetesClientSet("", "/Users/mhenkel/.kube/config", "v1");

	const char* namespaceKind = "Namespace";	
	auto watchH = kubernetesClientSet.contrail().Watch(metav1::ListOptions(), [namespaceKind](int watchType, const v1alpha1::Resource* resource){
			Document d;
			d.Parse(resource->resource().c_str());
			assert(d.IsObject());
			assert(d.HasMember("metadata"));
    		assert(d["metadata"].IsObject());
			Value::MemberIterator md = d.FindMember("metadata");
			assert(md->value.HasMember("name"));
			Value::MemberIterator md_name = md->value.FindMember("name");
			printf("watchType: %d, kind: %s,  name: %s\n", watchType, namespaceKind, md_name->value.GetString());
	},namespaceKind, "");

	auto apiResourceList = kubernetesClientSet.apiResource().List("core.contrail.juniper.net/v1alpha1");
	for (auto it = apiResourceList.kinds().begin(); it != apiResourceList.kinds().end(); ++it) {
		printf("apiResource: %s -> namespaced: %d\n", it->name().c_str(), it->namespaced());
		const char* kind = it->name().c_str();
		auto watchH = contrailClientSet.contrail().Watch(metav1::ListOptions(), [kind](int watchType, const v1alpha1::Resource* resource){
			Document d;
			d.Parse(resource->resource().c_str());
			assert(d.IsObject());
			assert(d.HasMember("metadata"));
    		assert(d["metadata"].IsObject());
			Value::MemberIterator md = d.FindMember("metadata");
			assert(md->value.HasMember("name"));
			Value::MemberIterator md_name = md->value.FindMember("name");
			printf("watchType: %d, kind: %s,  name: %s\n", watchType, kind, md_name->value.GetString());
	
		},it->name().c_str(),"");
		resourceMap.insert(std::pair<const char*, uintptr_t>(it->name().c_str(), watchH));
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(24*3600*1000));
/*
	clientset.coreV1().Nodes().StopWatch(nodeWatchH);
*/

	return 0;
}
