#ifndef RISCVDNN_H_
#define RISCVDNN_H_

#include "tensor.h"
#include "host_mem.h"
#include "memory_manager.h"
#include "integral_types.h"

class RiscVDNN {
public:
	RiscVDNN();
	~RiscVDNN();
	Tensor* allocateTensorOnDevice(HostMem* pointer, uint64 size);
	void writeTensorToDevice(HostMem* dest_pointer, uint64 size, Tensor* orig_pointer);
	void readTensorFromDevice(Tensor* orig_pointer, uint64 size, HostMem* dest_pointer);
	void needInDevice(Tensor* pointer1, Tensor* pointer2, Tensor* pointer3);
	void tensorUpdated(Tensor* pointer);
private:
	MemManager memManager;
	PCIeDriver pcieDriver;
};

#endif  // RISCVDNN_H_
