#ifndef HOST_MEM_H_
#define HOST_MEM_H_

#include "integral_types.h"

class HostMem{
public:
	HostMem();
	~HostMem();
	uint64 getMemoryDirection();
};

#endif  // HOST_MEM_H_
