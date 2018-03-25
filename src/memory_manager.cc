#include "memory_manager.h"

#include <iostream>
#include <stdexcept>
#include "integral_types.h"


MemManager::MemManager(){
	cardMem = CardMemAllocator();
	hostMem = HostMemAllocator();
	pcieDriver = PCIeDriver();
}

MemManager::~MemManager(){
}

Tensor* MemManager::allocateTensorOnDevice(HostMem* pointer, uint64 size){
	// If the tensor size is lower than the card max size, It proceed to allocate the tensor
	// If It is going to allocate the tensor, It will check if there are much free memory for the tensor.
	// If there are free memory, It will allocate the Tensor, if not, It will transfer all the allocated tensors to the host and then allocate the tensor.
	// If exceeds the memory of the host, it will throw an out of memory exception.
	Tensor *tensor = cardMem.allocateTensor(size);
	return tensor;
}

void MemManager::readTensorFromDevice(Tensor* tensor, uint64 size, HostMem* dest_pointer){
	//If the free memory of the host is lower than the size of the tensor, will throw an out of exception error.
	pcieDriver.readData(tensor, size, dest_pointer);
}

void MemManager::needInDevice(Tensor* tensor1, Tensor* tensor2, Tensor* tensor3){
	// If the size of the tensors is higher than the max size of the card, throws an out of memory exception
	uint64 totalSizes = tensor1->getSize() + tensor2->getSize() + tensor3->getSize();
	if(totalSizes > cardMem.TOTAL_SIZE){
		MemManager::throwOutOfMemory();
	}
	//If the memory of the tensors to allocate are higher than the free memory of the card.
	//It requests to the PCIe to transfer all the allocated of the card to the host.
	//Then write the tensors to the card.
	//When the data is going to be transfered to the host and the host is out of free memory, It throws an out of memory exception.
}

void MemManager::updateTensor(Tensor* tensor){
	// The tensor is updated
}

void MemManager::throwOutOfMemory(){
	//Throw out of memory exception.
	throw std::bad_alloc();
}
