#ifndef CARD_MEM_ALLOCATOR_H_
#define CARD_MEM_ALLOCATOR_H_

#include "integral_types.h"
#include "tensor.h"

class CardMemAllocator{
public:
	CardMemAllocator();
	~CardMemAllocator();
	uint64 getUsedMemory();
	uint64 getFreeMemory();
	Tensor* allocateTensor(uint64 size);
	static const uint64 TOTAL_SIZE;
private:
	uint64 usedMemory;
};

#endif  // CARD_MEM_ALLOCATOR_H_
