/*
 *   khuang18
 *   Kai Huang
 *   Lab10
 *   main.c
 *   Evalutes boolean expression to truth table output
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "TruthTable.h"
#include "ShuntingYard.h"

void binaryPrint(int numVariables, int* binaryArray);
void truthTablePrint(int index, int numVariables, int* binaryArray);

int binaryArray[100];
int truthTableIndex = 0;

int main()
{
    int numVariables = 0;

    // testing custom boolean expression input

    // char truthTableInput[] = "(!A + !B) & (!C + !D) | ((!E + !F) & (!G + !H)) + I + J + K";
    char truthTableInput[] = "(!A + !B) & (!C + !D) | ((!E + !F) & (!G + !H))";
    // char truthTableInput[] = "A + B & !C & D + !E";
    // char truthTableInput[] = "(!A + !B) & (!C + !D)";
    // char truthTableInput[] = "A + B & !C";
    // char truthTableInput[] = "A ^ B";
    
    printf("%s\n", truthTableInput);

    // find number of variables after converting infix to postfix
    numVariables = shuntingYard(truthTableInput, numVariables);

    int* truthTableOutput = (int*) malloc((int) pow(2, numVariables) * sizeof (int));

    // generate truth table result, outputs to int array truthTableOutput
    truthTable(truthTableInput, truthTableOutput, 0, numVariables);

    // recursively print binary truth table with evaluated result
    truthTablePrint(0, numVariables, truthTableOutput);

    free(truthTableOutput);

    return 0;
}

// prints out numVariables-digit binary number
// followed by respective truth table value
void binaryPrint(int numVariables, int* truthTableArray)
{
    int i;
    for (i = 0; i < numVariables; i++) {
        printf("%d", binaryArray[i]);
    }
    printf("  %d\n", truthTableArray[truthTableIndex++]);
}

// recursive function to generate numVariables-digit binary numbers
// identical runtime compared to nested for-loop
void truthTablePrint(int index, int numVariables, int* truthTableArray)
{
    if (index == numVariables) {
        binaryPrint(numVariables, truthTableArray);
        return;
    } else {
        binaryArray[index] = 0;
        truthTablePrint(index + 1, numVariables, truthTableArray);
        binaryArray[index] = 1;
        truthTablePrint(index + 1, numVariables, truthTableArray);
    }
}
