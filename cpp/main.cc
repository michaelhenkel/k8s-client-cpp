

#include "k8s.io/api/core/v1/generated.pb.h"
#include "pkg/apis/v1alpha1/apiresources.pb.h"
#include "k8s-client/clientset.h"
#include "k8s-client/watcher.h"

#include <string>
#include <memory>
#include <chrono>
#include <thread>


namespace apiv1 = k8s::io::api::core::v1;
namespace metav1 = k8s::io::apimachinery::pkg::apis::meta::v1;



int main()
{
	WatchManager* wm = new WatchManager();

	ClientSet* contrailClientSet = new ClientSet("", "/Users/mhenkel/.kube/config", "core.contrail.juniper.net/v1alpha1");
	ClientSet* kubernetesClientSet = new ClientSet("", "/Users/mhenkel/.kube/config", "v1");


	const char* namespaceKind = "Namespace";	
	wm->Add(namespaceKind, kubernetesClientSet);
	wm->Start(namespaceKind);

	const char* kind = "VirtualNetwork";	
	wm->Add(kind, contrailClientSet);
	wm->Start(kind);

	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	wm->Status(kind);

	std::this_thread::sleep_for(std::chrono::milliseconds(24*3600*1000));
/*
	clientset.coreV1().Nodes().StopWatch(nodeWatchH);
*/

	return 0;
}
