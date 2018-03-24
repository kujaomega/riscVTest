#include "host_mem.h"

#include <iostream>
#include "integral_types.h"

HostMem::HostMem(){
	usedMemory = 0;
}

uint64 HostMem::getUsedMemory(){
	return usedMemory;
}

const uint64 HostMem::TOTAL_SIZE = 64*1024*1024*1024;
