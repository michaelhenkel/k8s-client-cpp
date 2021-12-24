package main

import "flag"

// #include <stdlib.h>
// #include <stdint.h>
import "C"

func init() {
	flag.Parse()
	//flag.Lookup("v").Value.Set("6")
}

func main() {
	var callbackFn C.uintptr_t = 1
	var callbackContext C.uintptr_t = 1
	var done = make(chan bool)
	go func() {
		client_watch(callbackFn, callbackContext)
	}()
	<-done

}
