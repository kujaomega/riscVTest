#include "pcie_driver.h"

#include <iostream>

PCIeDriver::PCIeDriver(){
}

PCIeDriver::~PCIeDriver(){
}

void PCIeDriver::writeData(HostMem* orig, uint64 size, CardMem* dest){
	// PCIe Driver is copying the data from host to the card
}


void PCIeDriver::readData(CardMem* orig, uint64 size, HostMem* dest){
	// PCIe Driver is copying the data from the card to the host
}
