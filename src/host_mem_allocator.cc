#include "host_mem_allocator.h"

#include <iostream>
#include "integral_types.h"


const uint64 HostMemAllocator::TOTAL_SIZE = 64*1024*1024*1024;

HostMemAllocator::HostMemAllocator(){
	usedMemory = 0;
}

HostMemAllocator::~HostMemAllocator(){
}

uint64 HostMemAllocator::getUsedMemory(){
	return usedMemory;
}

uint64 HostMemAllocator::getFreeMemory(){
	return usedMemory - HostMemAllocator::TOTAL_SIZE;
}

Tensor* HostMemAllocator::allocateTensor(uint64 size){
	//Get a direction where to allocate the Tensor;
	Tensor tensor = Tensor();
	return &tensor;
}
