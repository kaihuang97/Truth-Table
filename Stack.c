/*
 *   Kai Huang
 *   Stack.c
 *   Stack Data Structure for chars
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Stack.h"

// allocate memory for stack, initialize variables
struct Stack* createStack(unsigned max)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof (struct Stack));
    if (stack == NULL) return NULL; // malloc error
    stack->max = max;
    stack->array = (int*) malloc(sizeof (int) * stack->max);
    stack->top = -1;
    return stack;
}

// is stack empty, helper
int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}

// push onto the top of stack
void push(struct Stack* stack, char token)
{
    stack->array[++stack->top] = token;
}

// pop the top of stack off
char pop(struct Stack* stack)
{
    if (!isEmpty(stack)) {
        return (stack->array[stack->top--]);
    } else {
        return '$';
    }
}

// next in stack, helper
char next(struct Stack* stack)
{
    return (stack->array[stack->top]);
}