#ifndef CARD_MEM_H_
#define CARD_MEM_H_

#include "integral_types.h"

class CardMem{
public:
	CardMem();
	uint64 getUsedMemory();
	static const uint64 TOTAL_SIZE;
private:
	uint64 usedMemory;
};

#endif  // CARD_MEM_H_
