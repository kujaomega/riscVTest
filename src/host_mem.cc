#include "host_mem.h"

#include <iostream>
#include "integral_types.h"

HostMem::HostMem(){
}

HostMem::~HostMem(){
}

uint64 HostMem::getMemoryDirection(){
	// Its the memory direction of the host, example 1
	return 1;
}
