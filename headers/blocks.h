#include "stack.h"
#ifndef BLOCKS_H
#define BLOCKS_H

/*
@requires *index < length(codes)
@assigns s, acc, index
@ensures execute the instruction inst (blocks creation section)
*/
void blocks_creation(Stack* s, int* codes, value* acc, int* index, int inst);

/*
@requires *index < length(codes)
@assigns s, acc, index
@ensures execute the instruction inst (blocks access section)
*/
void acces_blocs(Stack* s, int* codes, value* values, int* index, value* acc, int inst);

#endif