#ifndef PCIE_DRIVER_H_
#define PCIE_DRIVER_H_

#include "host_mem.h"
#include "card_mem.h"
#include "integral_types.h"


class PCIeDriver{
public:
	PCIeDriver();
	~PCIeDriver();
	void writeData(HostMem* orig, uint64 size, CardMem* dest);
	void readData(CardMem* orig, uint64 size, HostMem* dest);
};

#endif  // PCIE_DRIVER_H_
