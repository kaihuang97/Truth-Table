/*
 *   Kai Huang
 *   StackTest.c
 *   Test Harness for Stack.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Stack.h"

int main()
{
    printf("Starting Stack Tests:\n");

    char testArr[] = "hello";
    
    struct Stack* stack = createStack(strlen(testArr));

    printf("is stack empty? %s\n", isEmpty(stack) ? "yes" : "no");

    printf("reverse push and pop %d times:\n", (int)strlen(testArr));
    int i;
    for (i = 0; i < strlen(testArr); i++) {
        push(stack, testArr[i]);
    }

    for (i = 0; i < strlen(testArr); i++) {
        printf("	popped off: %c\n", pop(stack));
        if (i != strlen(testArr) - 1) {
            printf("		next char: %c\n", next(stack));
        }
    }

    printf("additional pop returns NULL? %s\n", pop(stack) == '$' ? "yes" : "no");

    printf("in order push and pop:\n");

    for (i = strlen(testArr) - 1; i >= 0; i--) {
        push(stack, testArr[i]);
    }

    for (i = 0; i < strlen(testArr); i++) {
        printf("	popped off: %c\n", pop(stack));
        if (i != strlen(testArr) - 1) {
            printf("		next char: %c\n", next(stack));
        }
    }

    printf("additional pop returns NULL? %s\n", pop(stack) == '$' ? "yes" : "no");

    free(stack->array);
    free(stack);

    printf("\n\n");

    char exp[] = "A + B + C & D & E";
    stack = createStack(strlen(exp));

    printf("is stack empty? %s\n", isEmpty(stack) ? "yes" : "no");

    printf("reverse push and pop:\n");

    for (i = 0; i < strlen(exp); i++) {
        push(stack, exp[i]);
    }

    for (i = 0; i < strlen(exp); i++) {
        printf("	popped off: %c\n", pop(stack));
        if (i != strlen(exp) - 1) {
            printf("		next char: %c\n", next(stack));
        }
    }

    printf("additional pop returns NULL? %s\n", pop(stack) == '$' ? "yes" : "no");

    printf("in order push and pop:\n");

    for (i = strlen(exp) - 1; i >= 0; i--) {
        push(stack, exp[i]);
    }

    for (i = 0; i < strlen(exp); i++) {
        printf("	popped off: %c\n", pop(stack));
        if (i != strlen(exp) - 1) {
            printf("		next char: %c\n", next(stack));
        }
    }

    printf("additional pop returns NULL? %s\n", pop(stack) == '$' ? "yes" : "no");

    free(stack->array);
    free(stack);

    return 0;
}