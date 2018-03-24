#include "pcie_driver.h"

#include <iostream>

PCIeDriver::PCIeDriver(){
}

int PCIeDriver::getRandomInt()
{
	return 0;
}

void PCIeDriver::writeData(HostMem* orig, uint64 size, CardMem* dest){
	// memory manager is requesting pcie to copy data from host to card
}


void PCIeDriver::readData(CardMem* orig, uint64 size, HostMem* dest){
	// memory manager is requesting pcie driver to copy data from card to the host
}
