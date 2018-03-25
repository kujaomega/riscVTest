#include "card_mem_allocator.h"

#include <iostream>
#include "integral_types.h"


const uint64 CardMemAllocator::TOTAL_SIZE = 1*1024*1024*1024;

CardMemAllocator::CardMemAllocator(){
	usedMemory = 0;
}

CardMemAllocator::~CardMemAllocator(){
}

uint64 CardMemAllocator::getUsedMemory(){
	return usedMemory;
}

uint64 CardMemAllocator::getFreeMemory(){
	return usedMemory - CardMemAllocator::TOTAL_SIZE;
}

Tensor* CardMemAllocator::allocateTensor(uint64 size){
	//Get a direction where to allocate the Tensor;
	Tensor tensor = Tensor();
	return &tensor;
}


