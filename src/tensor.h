#ifndef TENSOR_H_
#define TENSOR_H_

#include "card_mem.h"
#include "host_mem.h"
#include "integral_types.h"

class Tensor: public CardMem,  public HostMem{
public:
	Tensor();
	~Tensor();
	uint64 getSize();
};

#endif  // TENSOR_H_
