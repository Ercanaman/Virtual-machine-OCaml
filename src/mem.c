#include "../headers/mem.h"

// Memoire globale

/*
@requires n < length(values)
@assigns acc
@ensures sets acc to values[n]
*/
void getglobal(int n, value* acc, value* values) {
    *acc = values[n];
}

/*
@requires n < length(values)
@assigns s, acc
@ensures push acc to s, then sets acc to values[n]
*/
void pushgetglobal(Stack *s, int n, value* acc, value* values) {
    push(s,*acc);
    getglobal(n,acc,values);
}

/*
@requires n < length(values)
@assigns acc
@ensures sets values[n] to acc, then sets acc to 1
*/
void setglobal(int n, value* acc, value* values) {
    values[n] = *acc;
    *acc = 1;
}

void memory(Stack *s, int* codes, value* values, value* acc, int* index, int inst) {
    int n = codes[*index + 1];
    switch (inst) {
        case 53: 
            getglobal(n,acc,values);
            break;
        case 54:
            pushgetglobal(s,n,acc,values);
            break;
        case 57:
            setglobal(n,acc,values);
            break;
    }
}