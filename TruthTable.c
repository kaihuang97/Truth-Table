/*
 *   khuang18
 *   Kai Huang
 *   Lab10
 *   TruthTable.c
 *   Evaluates truth table values given postfix expression
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ShuntingYard.h"
#include "TruthTable.h"

char binaryInput[100];
int parsedIndex = 0;

int isBinary(char input);
int isOperator(char input);
void copyArray(char* dst, char* src);

// iterate through each binary input
// recursive function to generate numVariables-digit binary numbers
void truthTable(char* arr, int* output, int index, int numVariables)
{
    if (index == numVariables) {
        // dynamically allocated char array for parsed input (plugging in binary)
        // char parsed[strlen(arr)];
        char* parsed = (char*) calloc(sizeof(arr), sizeof(arr));
        copyArray(parsed, arr);

        // plug in binary values
        parseVariables(parsed, binaryInput);

        // evaluate boolean expression 
        evaluate(parsed, output, parsedIndex++);

        free(parsed);

        return;
    } else {
        // generate binary values
        binaryInput[index] = '0';
        truthTable(arr, output, index + 1, numVariables);
        binaryInput[index] = '1';
        truthTable(arr, output, index + 1, numVariables);
    }
}

// convert from variables to binary input to parse in evaluate()
void parseVariables(char* arr, char* binary)
{
    int i = 0, j = 0;
    while (arr[i] != '\0') {
        // replace binary if variable is alphabetic
        if (isLetter(arr[i])) {
            arr[i] = binary[j++];
        }
        i++;
    }
    arr[i] = '\0';
}

// postfix evaluation of binary values and operators
void evaluate(char* arr, int* output, int index)
{
    // Create a stack of max equal to expression size
    struct Stack* stack = createStack(strlen(arr));

    int i = 0;
    int first, second, result;

    // iterate through expression
    while (arr[i]) {
        // if binary, push on stack
        if (isBinary(arr[i])) {
            push(stack, arr[i] - 48); // convert ascii to int
            // if operator, pop two numbers and push result on stack
        } else if (isOperator(arr[i])) {
            first = pop(stack);
            second = pop(stack);
            switch (arr[i]) {
            case '+': case '|':
                result = second | first;
                break;
            case '^':
                result = second ^ first;
                break;
            case '&':
                result = second & first;
                break;
            case '~': case '!':
                push(stack, second);
                result = ~first & 0x1;
                break;
            }
            push(stack, result);
        }
        i++;
    }

    // last element is evaluated boolean expression result
    output[index] = pop(stack);

    free(stack->array);
    free(stack);
}


// returns 1 for binary input
int isBinary(char input)
{
    return (input == '0' || input == '1');
}

// returns 1 for bitwise operator input
int isOperator(char input)
{
    return (input == '+' || input == '|' || input == '^'
            || input == '&' || input == '~' || input == '!');
}

// copies data from source (src) to destination (dst) array
void copyArray(char* dst, char* src) 
{
    int i;
    for (i = 0; i < strlen(src); i++) {
        dst[i] = src[i];
    }
    dst[i] = '\n';
}