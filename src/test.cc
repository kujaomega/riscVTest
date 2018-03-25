#include <iostream>
#include "risc_v_dnn.h"
#include "card_mem_allocator.h"


int main()
{
	RiscVDNN *riscVDNN = new RiscVDNN();
	CardMemAllocator *cardMem = new CardMemAllocator();
	std::cout << " The solution is " << cardMem->TOTAL_SIZE;
}
