#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_

#include "card_mem_allocator.h"
#include "host_mem_allocator.h"
#include "host_mem.h"
#include "pcie_driver.h"

class MemManager{
public:
	MemManager();
	~MemManager();
	Tensor* allocateTensorOnDevice(HostMem* pointer, uint64 size);
	void readTensorFromDevice(Tensor* tensor, uint64 size, HostMem* dest_pointer);
	void needInDevice(Tensor* tensor1, Tensor* tensor2, Tensor* tensor3);
	void updateTensor(Tensor* tensor);
private:
	CardMemAllocator cardMem;
	HostMemAllocator hostMem;
	PCIeDriver pcieDriver;
	void throwOutOfMemory();
};

#endif  // MEMORY_MANAGER_H_
