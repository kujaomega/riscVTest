#include "memory_manager.h"

#include <iostream>
#include "pcie_driver.h"


MemManager::MemManager(){
	cardMem = CardMem();
	hostMem = HostMem();
}

int MemManager::getRandomInt()
{
	return 0;
}
