#include "stack.h"
#ifndef PRIMS_H
#define PRIMS_H

/*
@requires nothing
@assigns acc
@ensures execute the primitive n with acc as argument
*/
void c_call1(int n,value* acc);

/*
@requires s a well formed stack
@assigns s, acc
@ensures pop an element v from s and execute the primitive n with acc and v as arguments
*/
void c_call2(int n,value v,value* acc);

#endif