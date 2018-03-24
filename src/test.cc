#include <iostream>
#include "risc_v_dnn.h"


int main()
{
	RiscVDNN *riscVDNN = new RiscVDNN();
	std::cout << " The solution is " << riscVDNN->getRandomString();
}
