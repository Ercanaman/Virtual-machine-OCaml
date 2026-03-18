#include "stack.h"

#ifndef BASE_H
#define BASE_H

/*
@requires s a well formed stack and *index < length(codes)
@assigns s, acc, index
@ensures execute the instruction inst (base section)
*/
void base(Stack *s, value* acc, int* index, int* codes, int inst);

#endif