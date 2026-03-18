#include "stack.h"
#ifndef INTS_H
#define INTS_H

/*
@requires s a well formed stack and *index < length(codes)
@assigns s, acc, index
@ensures execute the instruction inst (integers section)
*/
void entiers(Stack *s, value* acc, int* index, int* codes, int inst);

#endif