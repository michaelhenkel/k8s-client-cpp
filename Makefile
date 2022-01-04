# Declaration of variables
CC = g++
CC_FLAGS = -I cpp/ -std=c++11
AR = ar
AR_FLAGS = rvs

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

# File names
EXEC = k8s-cpp-client

go_proto:
	protoc -I. --go_out=../../.. pkg/apis/v1alpha1/apiresources.proto

go: go_proto
	cd go && go build -buildmode=c-archive -o ../cpp/k8s-client/go.a

apiresources:
	protoc -I. --cpp_out=../../../github.com/michaelhenkel/k8s-client-cpp/cpp  pkg/apis/v1alpha1/apiresources.proto
	$(CC) -c $(CC_FLAGS) cpp/pkg/apis/v1alpha1/apiresources.pb.cc -o cpp/k8s-client/apiresources.pb.o
	$(AR) $(AR_FLAGS) cpp/k8s-client/apiresources.pb.a cpp/k8s-client/apiresources.pb.o
	mv cpp/pkg/apis/v1alpha1/apiresources.pb.h cpp/k8s-client

k8sclient: apiresources go
	$(CC) -c $(CC_FLAGS) cpp/k8s-client/k8sclient.cc -o cpp/k8s-client/k8sclient.o
	$(AR) $(AR_FLAGS) cpp/k8s-client/k8sclient.a cpp/k8s-client/k8sclient.o


install: k8sclient
	install -d $(PREFIX)/lib/k8sclient
	install -d $(PREFIX)/include/k8sclient
	install -m 644 cpp/k8s-client/k8sclient.a $(PREFIX)/lib/k8sclient
	install -m 644 cpp/k8s-client/k8sclient.h $(PREFIX)/include/k8sclient
	install -m 644 cpp/k8s-client/go.a $(PREFIX)/lib/k8sclient
	install -m 644 cpp/k8s-client/go.h $(PREFIX)/include/k8sclient
	install -m 644 cpp/k8s-client/apiresources.pb.a $(PREFIX)/lib/k8sclient
	install -m 644 cpp/k8s-client/apiresources.pb.h $(PREFIX)/include/k8sclient

# To remove generated files
clean:
	find cpp/ -name "*.o" -delete
	find cpp/ -name "*.a" -delete
	rm cpp/k8s-client/apiresources.pb.h
	rm cpp/k8s-client/go.h
	rm -rf $(PREFIX)/lib/k8sclient
	rm -rf $(PREFIX)/include/k8sclient

$(EXEC): install
	g++ -std=c++11 cpp/main.cc $(PREFIX)/lib/k8sclient/k8sclient.a $(PREFIX)/lib/k8sclient/go.a $(PREFIX)/lib/k8sclient/apiresources.pb.a  -lprotobuf -lpthread -framework CoreFoundation -framework Security -o $(EXEC)