This is a incomplete experimentation of creating a C++ binding of Kubernetes go client library.

##### Environment
Go
C++ 11
protobuf

##### clone the code
``` bash
git clone https://github.com/michaelhenkel/k8s-client-cpp
```
*Note: All blocks below must be executed from the root of the repository.*

##### get the dependencies
``` bash
make build_cpp
```

#### macOS users
Change the LDFLAGS to:
```
LD_FLAGS = ../go/go.a -lprotobuf -lpthread -framework CoreFoundation -framework Security
```
