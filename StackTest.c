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

    char arr[5] = "hello";
    struct Stack* stack = createStack(strlen(arr));

    printf("is stack empty? %s\n", isEmpty(stack) ? "yes" : "no");

    printf("reverse push and pop:\n");
    int i;
    for (i = 0; i < strlen(arr); i++) {
        push(stack, arr[i]);
    }

    for (i = 0; i < strlen(arr); i++) {
        printf("	popped off: %c\n", pop(stack));
        if (i != strlen(arr) - 1) {
            printf("		next char: %c\n", next(stack));
        }
    }

    printf("additional pop returns NULL? %s\n", pop(stack) == NULL ? "yes" : "no");

    printf("in order push and pop:\n");

    for (i = strlen(arr) - 1; i >= 0; i--) {
        push(stack, arr[i]);
    }

    for (i = 0; i < strlen(arr); i++) {
        printf("	popped off: %c\n", pop(stack));
        if (i != strlen(arr) - 1) {
            printf("		next char: %c\n", next(stack));
        }
    }

    printf("additional pop returns NULL? %s\n", pop(stack) == NULL ? "yes" : "no");

    printf("\n\n");

    char exp[17] = "A + B + C & D & E";

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

    printf("additional pop returns NULL? %s\n", pop(stack) == NULL ? "yes" : "no");

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

    printf("additional pop returns NULL? %s\n", pop(stack) == NULL ? "yes" : "no");

    while (1);
}