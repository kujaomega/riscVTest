#include <iostream>
#include "risc_v_dnn.h"
#include "card_mem.h"


int main()
{
	RiscVDNN *riscVDNN = new RiscVDNN();
	CardMem *cardMem = new CardMem();
	std::cout << " The solution is " << cardMem->TOTAL_SIZE;
}
