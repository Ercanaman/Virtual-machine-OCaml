#include "../headers/base.h"

// Base
void acc_n(Stack s, value* acc, int n) {
    *acc = stack_nth(s,n);
}

void pushacc(Stack* s, value* acc, int n) {
    push(s,*acc);
    acc_n(*s,acc,n);
}

void pop_n(Stack *s, int n) {
    for (int i = 0 ; i < n ; i++)
        pop(s);
}

void assign(Stack s, value* acc, int n) {
    set_stack_nth(s,*acc,n);
    *acc = 1;
}

void base(Stack *s, value* acc, int* index, int* codes, int inst) {
        //ACC
        if (inst <= 8) {
            int n;
            if (inst == 8) {
                *index += 1;
                n = codes[*index];
            }
            else 
                n = inst;
            acc_n(*s,acc,n);
        }

        //PUSH
        else if (inst == 9)
            push(s,*acc);

        //PUSHACC
        else if (inst >= 10 && inst <= 18) {
            int n;
            if (inst == 18) {
                *index += 1;
                n = codes[*index];
            }
            else
                n = inst-10;
            pushacc(s,acc,n);
        }

        //ASSIGN
        else if (inst == 20) {
            *index += 1;
            int n = codes[*index];
            assign(*s,acc,n);
        }

        //POP
        else if (inst == 19) {
            *index += 1;
            int n = codes[*index];
            pop_n(s,n);
        }
}