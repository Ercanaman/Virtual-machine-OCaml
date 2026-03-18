#include "stack.h"
#ifndef MEM_H
#define MEM_H

/*
@requires *index < length(codes)
@assigns s, acc, index
@ensures execute the instruction inst (global memory section)
*/
void memory(Stack*, int*, value*, value*, int*, int);

#endif