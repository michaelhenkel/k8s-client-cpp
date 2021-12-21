proto:
	protoc -I. --go_out=../../.. pkg/apis/v1alpha1/apiresources.proto
	protoc -I. --cpp_out=../../../github.com/michaelhenkel/k8s-client-cpp/cpp  pkg/apis/v1alpha1/apiresources.proto

build_go: proto
	cd go && go build -buildmode=c-archive -o go.a

build_cpp: build_go
	cd cpp && make