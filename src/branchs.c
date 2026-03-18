#include "../headers/branchs.h"

// Branchements

/*
@requires nothing
@assigns ind
@ensures sets ind to ind + (n-1)
*/
void branch(int n, int* ind) {
    *ind += n-1;
}

/*
@requires nothing
@assigns ind
@ensures sets ind to ind + (n-1) if acc is not the encoding of false
*/
void branchif(value acc, int n, int* ind) {
    if (acc != 1) {
        *ind += n-1;
    }
}

/*
@requires nothing
@assigns ind
@ensures sets ind to ind + (n-1) if acc is the encoding of false
*/
void branchifnot(value acc, int n, int* ind) {
    if (acc == 1) {
        *ind += n-1;
    }
}

/*
@requires nothing
@assigns ind
@ensures if acc is the encoding of i, then checks the i-th number in codes after n, and adds it to ind 
*/
void switch_n(int n, value acc, int* codes, int* ind) {
    *ind += codes[*ind + 2 + decode(acc)];
}

/*
@requires acc the encoding of true or false
@assigns acc
@ensures sets acc to the encoding of false if it's the encoding of true, and sets it to the encoding of true else
*/
void boolnot(value* acc) {
    if (*acc == 3)
        *acc = 1;
    else
        *acc = 3;
}

void branchements(value* acc, int* index, int* codes, int inst) {
    int n;
    switch (inst) {
        // BRANCH
        case 84:
            n = codes[*index+1];
            *index += 1;
            branch(n,index);
            break;

        // BRANCHIF
        case 85:
            n = codes[*index+1];
            *index += 1;
            branchif(*acc,n,index);
            break;

        // BRANCHIFNOT
        case 86:
            n = codes[*index+1];
            *index += 1;
            branchifnot(*acc,n,index);
            break;

        // SWITCH
        case 87:
            n = codes[*index+1];
            switch_n(n,*acc,codes,index);
            *index += 1;
            break;

        // BOOLNOT
        case 88:
            boolnot(acc);
            break;
    }
}