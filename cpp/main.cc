

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

void cbFn(int watchType, rapidjson::Document* d)
{
	Value::MemberIterator md = d->FindMember("metadata");
	Value::MemberIterator md_name = md->value.FindMember("name");
	Value::MemberIterator knd = d->FindMember("kind");
	printf("watchType: %d, kind: %s,  name: %s\n", watchType, knd->value.GetString(), md_name->value.GetString());
}

int main()
{
	WatchManager* wm = new WatchManager();

	ClientSet* contrailClientSet = new ClientSet("", "/Users/mhenkel/.kube/config", "core.contrail.juniper.net/v1alpha1");
	ClientSet* kubernetesClientSet = new ClientSet("", "/Users/mhenkel/.kube/config", "v1");


	const char* namespaceKind = "Namespace";	
	wm->Add(namespaceKind, kubernetesClientSet);
	wm->Start(namespaceKind, cbFn);

/*
	auto apiResourceList = kubernetesClientSet->apiResource().List("core.contrail.juniper.net/v1alpha1");
	for (auto it = apiResourceList.kinds().begin(); it != apiResourceList.kinds().end(); ++it) {
		const char* kind = it->name().c_str();	
		wm->Add(kind, contrailClientSet);
		wm->Start(kind, cbFn);
	}
*/


/*
	const char* kind = "Namespace";
	printf("waiting 5 sec %s\n", kind);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	printf("done waiting 5 sec %s\n", kind);
	wm->Status(kind);
	printf("waiting 3 sec %s\n", kind);
	std::this_thread::sleep_for(std::chrono::seconds(3));

	printf("stopping watch for kind %s\n", kind);
	wm->Stop(kind);

	printf("waiting 3 sec %s\n", kind);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	printf("starting watch again %s\n", kind);
	wm->Start(kind, cbFn);
*/
	while(1){};

	return 0;
}
