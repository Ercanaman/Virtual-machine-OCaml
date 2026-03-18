#include "stack.h"

#ifndef BRANCHS_H
#define BRANCHS_H

/*
@requires *index < length(codes)
@assigns acc, index
@ensures execute the instruction inst (branchs section)
*/
void branchements(value* acc, int* index, int* codes, int inst);

#endif