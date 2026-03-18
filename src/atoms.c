#include "../headers/atoms.h"

// Atomes

/*
@requires 0 <= n <= 255 
@assigns acc
@ensures Sets acc to the atom of index n
*/
void atom(value *acc, int n, value** arr_atomes) {
    *acc = (value) arr_atomes[n];
}

/*
@requires s a well formed stack, 0 <= n <= 255 
@assigns s, acc
@ensures Pushes acc to the stack s, then sets acc to the atom of index n
*/
void pushatom(Stack* s, value *acc, int n, value** arr_atomes) {
    push(s,*acc);
    atom(acc,n,arr_atomes);
}

void atomes(Stack* s, int* codes, value* acc, int* index, int inst, value** arr_atomes) {
    switch (inst) {
        case 58:
            atom(acc,0,arr_atomes);
            break;
        case 59:
            atom(acc,codes[*index + 1],arr_atomes);
            *index += 1;
            break;
        case 60:
            pushatom(s,acc,0,arr_atomes);
            break;
        case 61:
            pushatom(s,acc,codes[*index + 1],arr_atomes);
            *index += 1;
            break;
    }
}