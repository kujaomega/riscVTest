RiscVDNNTest

# Test requeriments

RiscVDNN interface:
 - Tensor allocateTensorOnDevice(HostMem* pointer, uint64 size): Allocate memory in the card for a tensor of size bytes. Manager returns where the tensor has been allocated.

 - void writeTensorToDevice(HostMem* dest_pointer, uint64 size, Tensor* orig_pointer): Request to write from host memory orig_pointer to an already allocated tensor in the card dest_pointer. Need to copy size bytes.

 - void readTensorFromDevice(Tensor* orig_pointer, uint64 size, HostMem* dest_pointer): Request to read from an already allocated tensor in card orig_pointer and write the contents to host memory dest_pointer. Need to copy size bytes.

 - void needInDevice(Tensor* pointer1, Tensor* pointer2, Tensor* pointer3): Process something in the accelerator. It requests to the memory manager that it guarantees that the already allocated tensors pointer1, pointer2 and pointer3 are actually in the card.

 - void tensorUpdated(Tensor* pointer): Execute an operation to an already allocated tensor pointer. It means that the contents of the tensor has been modified.


PCIe Driver Interface:
 - void writeData(HostMem* orig, uint64 size, CardMem* dest): Memory manager is requesting PCIe driver to copy data from host to the cart (size bytes).

 - void readData(CardMem* orig, uint64 size, HostMem* dest): Memory manager is requesting PCIe driver to copy data from card to the host(size bytes).


Memory Manager constraints:
 - The card has only 1GB of main memory, the host has 64GB main memory. It is possible that riscVDNN library allocates at same time more than 1GB of tensor data. It is the manager responsibility to swap in and out tensors from the card transparently.

 - Memory Manager can only report "run out of memory" when:
	-It tries to allocate memory in the host and malloc fails
	-The 3 tensors of a needInDevice call require more than 1GB


Performance features of the Memory Manager:
 - Reduce the amount of reads and writes done from/o the card.
