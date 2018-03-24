#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_

#include "card_mem.h"
#include "host_mem.h"

class MemManager{
public:
	MemManager();
	int getRandomInt();
private:
	CardMem cardMem;
	HostMem hostMem;
};

#endif  // MEMORY_MANAGER_H_
