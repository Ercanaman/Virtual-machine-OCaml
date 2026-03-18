#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"

struct Cell {
    value val;
    Stack next;
};

/*
@requires nothing
@assigns nothing
@ensures returns the code of integer n (2*n + 1)
*/
value encode(value n) {
    return 2*n + 1;
}

/*
@requires n an odd integer 
@assigns nothing
@ensures returns the integer m which code is n (m = (n-1)/2)
*/
value decode(value n) {
    return (n - 1)/2;
}

/* Fonctions sur les piles */

Stack* initialiser_pile() {
    Stack *s = malloc(sizeof(struct Cell));
    *s = NULL;
    return s;
}

void free_stack(Stack s) {
    while (s != NULL) {
        Stack next = s->next;
        free(s);
        s = next;
    }
}

int est_vide(Stack s) {
    if (s == NULL)
        return 1;
    return 0;
}

void push(Stack* s, value elem) {
    Stack new_cell = malloc(sizeof(struct Cell));
    new_cell->val = elem;
    new_cell->next = *s;
    *s = new_cell;
}

value pop(Stack* s) {
    Stack tmp = *s;
    value elem = tmp->val;
    *s = tmp->next;
    free(tmp);
    return elem;
}

value stack_nth(Stack s, int n) {
    while (n != 0) {
        s = s-> next;
        n--;
    }

    return s->val;
}

void set_stack_nth(Stack s, value val, int n) {
    while (n != 0) {
        s = s-> next;
        n--;
    }

    s->val = val;
}

void print_stack(Stack s) {
    while (s != NULL) {
        printf("%ld\n",s->val);
        s = s->next;
    }
}