/*
 *   khuang18
 *   Kai Huang
 *   Lab10
 *   ShuntingYard.h
 *   Converts infix to postfix notation (header file)
 */

#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Stack.h"

// infix to postfix
// used shuntingYard psuedocode found on GeeksforGeeks as reference
int shuntingYard(char* arr, int numVariables);

// returns 1 for alphabetic input
int isLetter(char input);

#endif // SHUNTINGYARD_H