#include "risc_v_dnn.h"

#include <iostream>
#include "tensor.h"
#include "host_mem.h"

RiscVDNN::RiscVDNN() {
	memManager = MemManager();
}

int RiscVDNN::getRandomString() {
	return 34;
}

Tensor* RiscVDNN::allocateTensorOnDevice(HostMem* pointer, uint64 size) {
	// Memory manager allocate memory to the card for a tensor
	Tensor tensor = Tensor();
	return &tensor;
}

void RiscVDNN::writeTensorToDevice(HostMem* dest_pointer, uint64 size, Tensor* orig_pointer) {
	// Memory manager write from host memory to an already allocated tensor in the card destination pointer.

}

void readTensorFromDevice(Tensor* orig_pointer, uint64 size, HostMem* dest_pointer){
	// Memory manager read from card and write contents to host
}

void needInDevice(Tensor* pointer1, Tensor* pointer2, Tensor* pointer3){
	// Process something in the accelerator. Requests to memory manager that are actually in the card

}

void tensorUpdated(Tensor* pointer){
	// execute operation on already allocated tensor pointer, contents tensor modified

}
