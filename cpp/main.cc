

//#include "pkg/apis/v1alpha1/apiresources.pb.h"


#include <string>
#include <memory>
#include <chrono>
#include <thread>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

#include <k8sclient/k8sclient.h>

//#include "k8s-client/k8sclient.h"
//#include "../go/go.h"

using namespace rapidjson;

void cbFn(int watchType, rapidjson::Document* d)
{
	Value::MemberIterator md = d->FindMember("metadata");
	Value::MemberIterator md_name = md->value.FindMember("name");
	Value::MemberIterator knd = d->FindMember("kind");
	Value::MemberIterator rv = md->value.FindMember("resourceVersion");
	printf("watchType: %d, kind: %s,  name: %s, rv: %s\n", watchType, knd->value.GetString(), md_name->value.GetString(), rv->value.GetString());
}

int main()
{
	K8SClient k8sclient = K8SClient(cbFn);
	k8sclient.Watch();
	std::this_thread::sleep_for(std::chrono::seconds(10));
	k8sclient.Stop();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	k8sclient.Watch();
	while(1){};
	return 0;
}
