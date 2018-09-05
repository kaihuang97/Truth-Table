/*
 *   khuang18
 *   Kai Huang
 *   Lab10
 *   TruthTable.h
 *   Evaluates truth table values given postfix expression (header file)
 */

#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Stack.h"

// iterate through each binary input
// recursive function to generate numVariables-digit binary numbers
void truthTable(char* arr, int* output, int index, int numVariables);

// convert from variables to binary input to parse in evaluate()
void parseVariables(char* arr, char* binary);

// postfix evaluation of binary values and operators
// used postfix evaluation psuedocode from GeeksforGeeks as reference
void evaluate(char* arr, int* output, int index);

#endif // TRUTHTABLE_H