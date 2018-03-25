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
	int getRandomString();

//	Allocate memory in the card for a tensor of size bytes.
//	Manager returns where the tensor has been allocated
	Tensor* allocateTensorOnDevice(HostMem* pointer, uint64 size);

//	Request to write from host memory orig_pointer to an already
//	allocated tensor in the card dest_pointer. Need to copy size bytes
	void writeTensorToDevice(HostMem* dest_pointer, uint64 size, Tensor* orig_pointer);

//	Request to read from an already allocated tensor in card orig_pointer and
//	write the contents to host memory dest_pointer. Need to copy size bytes.
	void readTensorFromDevice(Tensor* orig_pointer, uint64 size, HostMem* dest_pointer);

//	Process something in the accelerator. It requests to the memory manager that it guarantees
//	that the already allocated tensors pointer1, pointer2 and pointer3 are actually in the card.
	void needInDevice(Tensor* pointer1, Tensor* pointer2, Tensor* pointer3);

//	Execute an operation to an already allocated tensor pointer.
//	It means that the contents of the tensor has been modified
	void tensorUpdated(Tensor* pointer);
private:
	MemManager memManager;
	PCIeDriver pcieDriver;
};

#endif  // RISCVDNN_H_
