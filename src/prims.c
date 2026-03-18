#include "../headers/prims.h"
#include <stdio.h>
#include <stdlib.h>

// Primitives

/*
@requires m >= 3
@assigns nothing
@ensures returns an allocated tab of n element (m is the encoding of n) and sets each value of the tab to e
*/
value prim_15(value m, value e) {
    value n = decode(m);
    value* tab = malloc(n*sizeof(value));
    for (int i = 0 ; i < n ; i++) 
        tab[i] = e;
    return (value) tab;
}

/*
@requires nothing
@assigns nothing
@ensures flush f, and returns 1
*/
int prim_288(FILE* f) {
    fflush(f);
    return 1;
} 

/*
@requires nothing
@assigns nothing
@ensures read a character on f and returns its code
*/
int prim_293(FILE* f) {
    char* c = malloc(1);
    fread(c,1,1,f);
    int x = *c;
    free(c);
    return encode(x);
}

/*
@requires n = 1
@assigns nothing
@ensures if n = 1, returns the adress of stdin
*/
value prim_302(value n) {
    if (n == 1)
        return (value) stdin;
    return (value) NULL;
}

/*
@requires n = 3 or n = 5
@assigns nothing
@ensures if n = 3, returns the adress of stdout, if n = 5, returns the adress of stdout
*/
value prim_304(value n) {
    if (n == 3)
        return (value) stdout;
    else if (n == 5)
        return (value) stderr;
    return (value) NULL;
}

/*
@requires elem the ASCII code of a character
@assigns nothing
@ensures write the character which code is elem in f
*/
void prim_310(FILE* f, value elem) {
    value n = decode(elem);
    char *c = malloc(1);
    *c = n;
    fwrite(c,1,1,f);
    free(c);
}

void c_call1(int n, value* acc) {
    switch (n) {
        case 288:
            *acc = prim_288((FILE*) *acc);
            break;
        case 293:
            *acc = prim_293((FILE*) *acc);
            break;
        case 302:
            *acc = prim_302(*acc);
            break;
        case 304:
            *acc = prim_304(*acc);
            break;
    }
}

void c_call2(int n, value v, value* acc) {
    switch (n) {
        case 15:
            *acc = prim_15(*acc,v);
            break;
        case 310:
            prim_310((FILE*) *acc,v);
    }
}