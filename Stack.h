/*
 *   Kai Huang
 *   Stack.h
 *   Stack Data Structure for chars (header file)
 */

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Stack data structure 
struct Stack {
    unsigned max;
    int* array;
    int top;
};

// allocate memory for stack
struct Stack* createStack(unsigned max);

// is stack empty, helper
int isEmpty(struct Stack* stack);

// push onto the top of stack
void push(struct Stack* stack, char token);

// pop the top of stack off
char pop(struct Stack* stack);

// next in stack, helper
char next(struct Stack* stack);

#endif // STACK_H