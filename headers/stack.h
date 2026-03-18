#ifndef STACK_H
#define STACK_H

typedef long value;

value encode(value);
value decode(value);


typedef struct Cell* Stack;

/*
@requires nothing
@assigns nothing
@ensures returns an empty stack
*/
Stack* initialiser_pile(void);

/*
@requires nothing
@assigns nothing
@ensures free the allocated memory for the stack s
*/
void free_stack(Stack s);

/*
@requires nothing
@assigns nothing
@ensures checks if s is empty
*/
int est_vide(Stack s);

/*
@requires s a well formed stack
@assigns s
@ensures add elem at the head of the stack
*/
void push(Stack* s, value elem);

/*
@requires s a well formed stack
@assigns s
@ensures removes the head element of s
*/
value pop(Stack* s);

/*
@requires s a well formed stack
@assigns nothing
@ensures returns the number of elements in the stack s
*/
int length_stack(Stack s);

/*
@requires n >= 0 and n < length(s)
@assigns nothing
@ensures returns the element at index of the stack
*/
value stack_nth(Stack s, int n);

/*
@requires n >= 0 and n < length(s)
@assigns nothing
@ensures modify the the element at index of the stack to val
*/
void set_stack_nth(Stack s, value val, int n);

/*
@requires s a well formed stack
@assigns nothing
@ensures display the content of s
*/
void print_stack(Stack s);

#endif