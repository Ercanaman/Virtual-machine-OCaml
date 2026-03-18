#include "stack.h"
#ifndef ATOMS_H
#define ATOMS_H

/*
@requires *index < length(codes)
@assigns s, acc, index
@ensures execute the instruction inst (atoms section)
*/
void atomes(Stack* s, int* codes, value* acc, int* index, int inst, value** arr_atomes);

#endif