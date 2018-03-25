#ifndef HOST_MEM_ALLOCATOR_H_
#define HOST_MEM_ALLOCATOR_H_

#include "integral_types.h"
#include "tensor.h"

class HostMemAllocator{
public:
	HostMemAllocator();
	~HostMemAllocator();
	uint64 getUsedMemory();
	uint64 getFreeMemory();
	Tensor* allocateTensor(uint64 size);
	static const uint64 TOTAL_SIZE;
private:
	uint64 usedMemory;
};

#endif  // HOST_MEM_ALLOCATOR_H_
