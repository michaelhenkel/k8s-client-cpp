package main

// #include <stdint.h>
// typedef void (*client_watch_callback_fn)(uintptr_t watchKey, int watchType, void* objBytes, int objSize);
// void client_watch_callback_wrapper(uintptr_t callbackFn, uintptr_t callbackContext, int watchType, void* objBytes, int objSize) {
// 	((client_watch_callback_fn)callbackFn)(callbackContext, watchType, objBytes, objSize);
// }
import "C"

func bla() {

}
