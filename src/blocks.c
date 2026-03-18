#include <stdio.h>
#include <stdlib.h>
#include "../headers/blocks.h"

// Creation de blocs

/*
@requires n > 0
@assigns s, acc
@ensures allocate a tab of n element with the accumulator and n-1 values poped from the stack
Sets acc to the adress of this tab
*/
void makeblock(Stack* s, int n, value* acc) {
    value* tab = malloc(sizeof(value)*n);
    tab[0] = *acc;
    value v;
    for (int i = 1 ; i < n ; i++) {
        v = pop(s);
        tab[i] = v;
    }
    *acc = (value) tab;

}

void blocks_creation(Stack* s, int* codes, value* acc, int* index, int inst) {
    int n;
    if (inst != 62)
        n = inst-62;
    else {
        n = codes[*index + 1];
        *index += 1;
    }
    makeblock(s,n,acc);
    *index += 1;
}

// Accès-écriture blocs

/*
@requires 0 <= n < length(tab)
@assigns acc
@ensures sets acc to the element of index n of tab (his adress is given by acc)
*/
void getfield(value* acc, int n) {
    value adress = *acc;
    value* tab = (value*) adress;
    *acc = tab[n];
}

/*
@requires s a well formed stack, 0 <= n < length(tab)
@assigns acc
@ensures sets the element of index n of tab (his adress is given by acc) to an element poped from the stack
Sets acc to 1
*/
void setfield(Stack* s, value* acc, int n) {
    value m = pop(s);
    value adress = *acc;
    value* tab = (value*) adress;
    tab[n] = m;
    *acc = 1;
}

/*
@requires s a well formed stack
@assigns s, acc
@ensures Pops a value m from the stack, which is the encoding of n 
sets acc to the element of index n of tab (his adress is given by acc)
*/
void getvectitem(Stack* s, value* acc) {
    value m = pop(s);
    value n = decode(m);
    value adress = *acc;
    value* tab = (value*) adress;
    *acc = tab[n];
}

/*
@requires s a well formed stack
@assigns s, acc
@ensures Pops a value m from the stack, which is the encoding of n 
Pops a value v from the stack
Sets the element of index n of tab (his adress is given by acc) to v
Sets acc to 1
*/
void setvectitem(Stack* s, value* acc) {
    value m = pop(s);
    value n = decode(m);
    value v = pop(s);
    value adress = *acc;
    value* tab = (value*) adress;
    tab[n] = v;
    *acc = 1;
}

/*
@requires 0 <= n < length(values)
@assigns acc
@ensures values[n] is the adress of tab
Sets acc to tab[p]
*/
void getglobalfield(value* values, value* acc, int n, int p) {
    value adress = values[n];
    value* tab = (value*) adress;
    *acc = tab[p];
}

/*
@requires s a well formed stack, 0 <= n < length(values)
@assigns s, acc
@ensures Pushes acc to the stack s
values[n] is the adress of tab
Sets acc to tab[p]
*/
void pushgetglobalfield(Stack* s, value* values, value* acc, int n, int p) {
    push(s,*acc);
    getglobalfield(values,acc,n,p);
}

/*
@requires nothing
@assigns acc
@ensures acc is the adress of tab
m is the encoding of tab[0]
Sets tab[0] to the encoding of n + m
Sets acc to 1
*/
void offsetref(value* acc, int n) {
    value adress = *acc;
    value* tab = (value*) adress;
    value res_code = decode(tab[0]) + n;
    tab[0] = encode(res_code);
    *acc = 1;
}

void acces_blocs(Stack* s, int* codes, value* values, int* index, value* acc, int inst) {
    int n;
    if (inst >= 67 && inst <= 71) {
        if (inst != 71)
            n = inst-67;
        else {
            n = codes[*index + 1];
            *index += 1;
        }
        getfield(acc,n);
    }
    else if (inst >= 73 && inst <= 77) {
        if (inst != 77)
            n = inst-73;
        else {
            n = codes[*index + 1];
            *index += 1;
        }
        setfield(s,acc,n);
    }
    else if (inst == 80)
        getvectitem(s,acc);
    else if (inst == 81)
        setvectitem(s,acc);
    else if (inst == 55) {
        n = codes[*index + 1];
        int p = codes[*index + 2];
        *index += 2;
        getglobalfield(values,acc,n,p);
    }
    else if (inst == 128) {
        n = codes[*index + 1];
        *index += 1;
        offsetref(acc,n);
    }
}