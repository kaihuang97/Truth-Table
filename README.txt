Kai Huang

This program aims to solve boolean expressions. Given an n-variable boolean expression, this program will print out a truth table of all binary values and their respective results. This program performs operations with dynamically allocated arrays, meaning that the number of variables this boolean expression calculator takes is limited by the user's allocated heap space :)

Creating a stack data structure with character elements, I'm able to use the Shunting-Yard algorithm to convert my infix boolean expression input into postfix notation, which makes it more simple to parse for evaluation. After converting to postfix, I replaced all alphabetic characters in the input with their respective binary values, generated by a recursive function. A similar recursive function is used to print the truth table in main. After evaluating for all n-digit binary number (n being # of variables in the input boolean expression), I store the result of the boolean expression in an integer array, and then print the truth table recursively along with its respective result. 


References:
Infix to Postfix psuedo-code, referenced for character Stack
https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

