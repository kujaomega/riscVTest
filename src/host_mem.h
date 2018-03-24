#ifndef HOST_MEM_H_
#define HOST_MEM_H_

#include "integral_types.h"

class HostMem{
public:
	HostMem();
	uint64 getUsedMemory();
	static const uint64 TOTAL_SIZE;
private:
	uint64 usedMemory;
};

#endif  // HOST_MEM_H_
