#include "../headers/ints.h"
#include <stdio.h>
#include <stdlib.h>

// Entiers

/*
@requires nothing
@assigns acc
@ensures set the value of acc to the encoding of n
*/
void constint(value* acc, value n) {
    *acc = encode(n);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pushes acc in the stack, and sets the stack to the encoding of n
*/
void pushconstint(Stack *s, value* acc, value n) {
    push(s,*acc);
    constint(acc,n);
}

/*
@requires nothing
@assigns acc
@ensures if acc is the encoding of n, then sets acc to the encoding of -n
*/
void negint(value* acc) {
    value n = decode(*acc);
    *acc = encode(-n);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n+m
*/
void addint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1+m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n-m
*/
void subint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1-m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n-m
*/
void mulint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1*m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n/m
*/
void divint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    if (m1 == 0) {
        printf("Fatal error: exception Division_by_zero");
        exit(2);
    }
    *acc = encode(n1/m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n%m
*/
void modint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    if (m1 == 0) {
        printf("Fatal error: exception Division_by_zero");
        exit(2);
    }
    *acc = encode(n1%m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n & m
*/
void andint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1 & m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n | m
*/
void orint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1 | m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n ^ m
*/
void xorint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1 ^ m1);
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n << m
*/
void lslint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1 << m1);;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n >> m (logic shift)
*/
void lsrint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode(n1 >> m1);;
}

/*
@requires s a well formed stack
@assigns s, acc
@ensures pop a value which is the encoding of m, if acc is the encoding of n, then sets acc to the encoding of n >> m (arithmetical shift)
*/
void asrint(Stack *s, value* acc) {
    value m = pop(s);
    value n1 = decode(*acc);
    value m1 = decode(m);
    *acc = encode((unsigned long) n1 >> m1);;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc = m, and false else
*/
void eq(Stack *s, value* acc) {
    value m = pop(s);
    if (*acc == m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc != m, and false else
*/
void neq(Stack *s, value* acc) {
    value m = pop(s);
    if (*acc != m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc < m, and false else
*/
void ltint(Stack *s, value* acc) {
    value m = pop(s);
    value n = *acc; 
    if (n < m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc <= m, and false else
*/
void leint(Stack *s, value* acc) {
    value m = pop(s);
    value n = *acc;
    if (n <= m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc > m, and false else
*/
void gtint(Stack *s, value* acc) {
    value m = pop(s);
    value n = *acc;
    if (n > m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc >= m, and false else
*/
void geint(Stack *s, value* acc) {
    value m = pop(s);
    value n = *acc;
    if (n >= m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc < m, and false else (unsigned comparaison)
*/
void ultint(Stack *s, value* acc) {
    unsigned long m = (unsigned long) pop(s);
    unsigned long n = (unsigned long) *acc;
    if (n < m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires s a well formed stack
@assigns s,acc
@ensures pop a value m, and set acc to the encoding of true if acc >= m, and false else (unsigned comparaison)
*/
void ugeint(Stack *s, value* acc) {
    unsigned long m = (unsigned long) pop(s);
    unsigned long n = (unsigned long) *acc;
    if (n >= m) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires nothing
@assigns acc
@ensures if acc is the encoding of n, then sets acc to the encoding of n + ofs
*/
void offsetint(value ofs, value* acc) {
    value n = decode(*acc);
    *acc = encode(n + ofs);
}

/*
@requires nothing
@assigns acc
@ensures sets acc to the encoding of true if acc is odd, and false else
*/
void isint(value* acc) {
    if (*acc % 2 == 1) 
        *acc = 3;
    else
        *acc = 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if n = m, and false else
*/
int beq(value m, value n) {
    if (n == m) 
        return 3;
    else
        return 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if n != m, and false else
*/
int bneq(value m, value n) {
    if (n != m) 
        return 3;
    else
        return 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if m < n, and false else
*/
int bltint(value m, value n) {
    if (m < n) 
        return 3;
    else
        return 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if m <= n, and false else
*/
int bleint(value m, value n) {
    if (m <= n) 
        return 3;
    else
        return 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if m > n, and false else
*/
int bgtint(value m, value n) {
    if (m > n) 
        return 3;
    else
        return 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if m >= n, and false else
*/
int bgeint(value m, value n) {
    if (m >= n) 
        return 3;
    else
        return 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if m < n, and false else (unsigned comparaison)
*/
int bultint(value m, value n) {
    unsigned long m1 = (unsigned long) m;
    unsigned long n1 = (unsigned long) n;
    if (m1 < n1) 
        return 3;
    else
        return 1;
}

/*
@requires nothing
@assigns nothing
@ensures returns the encoding of true if n >= m, and false else (unsigned comparaison)
*/
int bugeint(value m, value n) {
    unsigned long m1 = (unsigned long) m;
    unsigned long n1 = (unsigned long) n;
    if (m1 >= n1) 
        return 3;
    else
        return 1;
}

/*
@requires nothing, and inst the instruction which corresponds to a beq, bneq...
@assigns index
@ensures sets index to index + (c-1) if m and n check the comparaison that corresponds to inst
*/
void bcomparaisons(value acc, value m, int c, int inst, int* index) {
    value n = decode(acc);
    int res = 1;
    switch (inst) {
        case 131:
            res = beq(m,n);
            break;
        case 132:
            res = bneq(m,n);
            break;
        case 133:
            res = bltint(m,n);
            break;
        case 134:
            res = bleint(m,n);
            break;
        case 135:
            res = bgtint(m,n);
            break;
        case 136:
            res = bgeint(m,n);
            break;
        case 139:
            res = bultint(m,n);
            break;
        case 140:
            res = bugeint(m,n);
            break;
    }
    if (res == 3)
        *index += (c-1);
}

void entiers(Stack *s, value* acc, int* index, int* codes, int inst) {

    // CONST
    if (inst <= 103) {
        int n;
        if (inst != 103)
            n = inst-99;
        else {
            n = codes[(*index) + 1];
            *index += 1;
        }
        constint(acc,n);
    }

    // PUSHCONST
    else if (inst <= 108) {
        int n;
        if (inst != 108) 
            n = inst-104;
        else {
            n = codes[*index + 1];
            *index += 1;
        }
        pushconstint(s, acc, n);
    }
    else {
        switch (inst) {
            case 109: 
                negint(acc);
                break;
            case 110:
                addint(s,acc);
                break;
            case 111:
                subint(s,acc);
                break;
            case 112:
                mulint(s,acc);
                break;
            case 113:
                divint(s,acc);
                break;
            case 114:
                modint(s,acc);
                break;
            case 115:
                andint(s,acc);
                break;
            case 116:
                orint(s,acc);
                break;
            case 117:
                xorint(s,acc);
                break;
            case 118:
                lslint(s,acc);
                break;
            case 119:
                lsrint(s,acc);
                break;
            case 120:
                asrint(s,acc);
                break;
            case 121:
                eq(s,acc);
                break;
            case 122:
                neq(s,acc);
                break;
            case 123:
                ltint(s,acc);
                break;
            case 124:
                leint(s,acc);
                break;
            case 125:
                gtint(s,acc);
                break;
            case 126:
                geint(s,acc);
                break;
            case 137:
                ultint(s,acc);
                break;
            case 138:
                ugeint(s,acc);
                break;
            case 127:
                offsetint(codes[*index + 1],acc);
                *index += 1;
                break;
            case 129:
                isint(acc);
                break;
            default: // BEQ, BNEQ .....
                int m = codes[*index + 1];
                int c = codes[*index + 2];
                *index += 2;
                bcomparaisons(*acc,m,c,inst,index);
        }
    }
}