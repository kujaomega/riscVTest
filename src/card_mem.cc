#include "card_mem.h"

#include <iostream>
#include "integral_types.h"

CardMem::CardMem(){
	usedMemory = 0;
}

uint64 CardMem::getUsedMemory(){
	return usedMemory;
}

const uint64 CardMem::TOTAL_SIZE = 1*1024*1024*1024;
