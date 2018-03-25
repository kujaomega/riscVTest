#include "risc_v_dnn.h"

#include <iostream>
#include "tensor.h"
#include "host_mem.h"

RiscVDNN::RiscVDNN() {
	memManager = MemManager();
	pcieDriver = PCIeDriver();
}

RiscVDNN::~RiscVDNN() {
}

Tensor* RiscVDNN::allocateTensorOnDevice(HostMem* pointer, uint64 size) {
	// Memory manager allocate memory to the card for a tensor
	// To improve the performance of this method, if the data to allocate is small, we can create batches of data to allocate
	return memManager.allocateTensorOnDevice(pointer, size);
}

void RiscVDNN::writeTensorToDevice(HostMem* dest_pointer, uint64 size, Tensor* orig_pointer) {
	// Memory manager write from host memory to an already allocated tensor in the card destination pointer.
	pcieDriver.writeData(dest_pointer, size, orig_pointer);
}

void RiscVDNN::readTensorFromDevice(Tensor* orig_pointer, uint64 size, HostMem* dest_pointer){
	// Memory manager read from card and write contents to host
	// To improve the performance of this method, we can create batches of data to read
	memManager.readTensorFromDevice(orig_pointer, size, dest_pointer);
}

void RiscVDNN::needInDevice(Tensor* pointer1, Tensor* pointer2, Tensor* pointer3){
	// Process something in the accelerator. Requests to memory manager that are actually in the card
	memManager.needInDevice(pointer1, pointer2, pointer3);
}

void RiscVDNN::tensorUpdated(Tensor* pointer){
	// Execute operation on already allocated tensor pointer, contents tensor modified
	memManager.updateTensor(pointer);
}
