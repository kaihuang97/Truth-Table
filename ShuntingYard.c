/*
 *   Kai Huang
 *   ShuntingYard.c
 *   Converts infix to postfix notation
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ShuntingYard.h"

void removeWhiteSpace(char* arr);
int precedence(char input);

// infix to postfix
// used shuntingYard psuedocode found on GeeksforGeeks as reference
int shuntingYard(char* arr, int numVariables)
{
    int i = 0, k = 0;
    // create stack length of expression
    struct Stack* stack = createStack(strlen(arr));
    if (stack == NULL) return 0; // check for failed malloc

    // remove spaces from input to prevent parsing errors
    removeWhiteSpace(arr);

    // iterate through stack
    while (arr[i]) {
        if (isLetter(arr[i])) { // if input is letter, add to output
            arr[k++] = arr[i];
            numVariables++;
        } else if (arr[i] == '(') { // if '(' push to stack
            push(stack, arr[i]);
        } else if (arr[i] == ')') { // if ')' pop everything until '(' is encountered
            while (!isEmpty(stack) && next(stack) != '(') {
                arr[k++] = pop(stack); // output      
            }
            if (!isEmpty(stack) && next(stack) != '(') return -1;
            else pop(stack);
        } else { // operator is found
            // while precedence of operator is greater than precedence of the next in stack
            // push otherwise pop
            while (!isEmpty(stack) && precedence(arr[i]) <= precedence(next(stack))) {
                arr[k++] = pop(stack);
            }
            push(stack, arr[i]);
        }
        i++;
    }

    // pop operators from stack
    while (!isEmpty(stack)) {
        arr[k++] = pop(stack);
    }

    // null-terminating char
    arr[k++] = '\0';

    free(stack->array);
    free(stack);
    
    return numVariables;
}

// is input a letter else is operand
int isLetter(char input)
{
    return (input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z');
}

// remove whitespace of input
void removeWhiteSpace(char* arr)
{
    char* noSpace = arr;
    int i = 0, j = 0;
    while (i < strlen(arr)) {
        if (arr[i] != ' ') noSpace[j] = arr[i];
        else j--;
        i++;
        j++;
    }
    noSpace[j] = 0;
}

// higher int = higher precedence = more importance
int precedence(char input)
{
    switch (input) {
    case '+': // bitwise or
    case '|':
        return 1;
    case '^': // bitwise xor
        return 2;
    case '&': // bitwise and
        return 3;
    case '~': // bitwise not
    case '!':
        return 4;
    }
    return -1;
}
