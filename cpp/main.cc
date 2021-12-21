

#include "k8s.io/api/core/v1/generated.pb.h"
#include "pkg/apis/v1alpha1/apiresources.pb.h"
#include "k8s-client/clientset.h"

#include <string>
#include <memory>
#include <chrono>
#include <thread>

namespace apiv1 = k8s::io::api::core::v1;
namespace metav1 = k8s::io::apimachinery::pkg::apis::meta::v1;
//namespace v1alpha1;


int main()
{
	ClientSet clientset("", "/Users/mhenkel/.kube/config");

/*
	auto podList = clientset.coreV1().Pods("").List(metav1::ListOptions());
	for (auto it = podList.items().begin(); it != podList.items().end(); ++it) {
		printf("pod: %s/%s\n", it->metadata().namespace_().c_str(), it->metadata().name().c_str());
	}
	auto rcList = clientset.coreV1().ReplicationControllers("").List(metav1::ListOptions());
	for (auto it = rcList.items().begin(); it != rcList.items().end(); ++it) {
		printf("rc: %s/%s\n", it->metadata().namespace_().c_str(), it->metadata().name().c_str());
	}
	auto nodeList = clientset.coreV1().Nodes().List(metav1::ListOptions());
	for (auto it = nodeList.items().begin(); it != nodeList.items().end(); ++it) {
		printf("nodes: %s\n", it->metadata().name().c_str());
	}
*/
	auto apiResourceList = clientset.apiResource().List("core.contrail.juniper.net/v1alpha1");
	for (auto it = apiResourceList.kinds().begin(); it != apiResourceList.kinds().end(); ++it) {
		printf("apiResource: %s -> namespaced: %d\n", it->name().c_str(), it->namespaced());
	}

	/*

	auto podWatchH = clientset.coreV1().Pods("").Watch(metav1::ListOptions(), [](int watchType, const apiv1::Pod* pod){
		printf("watchType: %d, pod: %s/%s, resourceVersion: %s\n", watchType, pod->metadata().namespace_().c_str(), pod->metadata().name().c_str(), pod->metadata().resourceversion().c_str());
	});
	auto rcWatchH = clientset.coreV1().ReplicationControllers("").Watch(metav1::ListOptions(), [](int watchType, const apiv1::ReplicationController* rc){
		printf("watchType: %d, rc: %s/%s, resourceVersion: %s\n", watchType, rc->metadata().namespace_().c_str(), rc->metadata().name().c_str(), rc->metadata().resourceversion().c_str());
	});
	auto nodeWatchH = clientset.coreV1().Nodes().Watch(metav1::ListOptions(), [](int watchType, const apiv1::Node* node){
		printf("watchType: %d, node: %s, resourceVersion: %s\n", watchType, node->metadata().name().c_str(), node->metadata().resourceversion().c_str());
	});
	std::this_thread::sleep_for(std::chrono::milliseconds(24*3600*1000));
	clientset.coreV1().Pods("").StopWatch(podWatchH);
	clientset.coreV1().Pods("").StopWatch(podWatchH);
	clientset.coreV1().Nodes().StopWatch(nodeWatchH);
*/

	return 0;
}
