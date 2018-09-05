khuang18
Kai Huang

Lab10 Writeup

User Notes: 
Change the input boolean expression in main.c to whatever your heart desires!
Careful, this program LOVES heap size (because it's poorly optimized at least 
in its current state), so if you're trying to run a 8-variable boolean expression, 
please allocate at least 30000 bytes. Theoretically, this program is able to go up 
to 100 variables, as it's being limited by the size of each binary character array. 
Also, it seems to only output on UART2 for me, so try UART1&2 please!

Background:
This program aims to solve boolean expressions, and can be run on our PIC32, as well
as on UNIX (with a few modifications). Given an n-variable boolean expression, this
program will print out a truth table of all binary values and their respective 
results.

Methods:
Creating a stack data structure with char elements, I'm able to use the Shunting-Yard
algorithm to convert my infix boolean expression input into postfix notation, which
makes it more simple to parse for evaluation. After converting to postfix, I 
replaced all alphabetic characters in the input with a binary char string, generated
by a recursive function, a very similar function is used to print the truth table
in main. After evaluating for all n-digit binary number (n being # of variables), 
I store the result of the boolean expression in an integer array, and then print
the truth table recursively along with its respective result. 
To debug, I wrote a not-very-thorough stack test, and I utilized a ton of print
statements in order to correctly parse the char arrays numerous times in my
program. 

Results:
This is the result of a boolean expression with 5-variables. This is pretty self-
explanatory, it's functional! It'll iterate truth tables, up to the char array 
holding each binary number, and since its length is 100, my program can support 
100 variables as long as the user provides enough memory and can bare with long 
CPU processing time.

Conclusion:
I needed to leave Santa Cruz early on Thursday, so I had to return my PIC32 and
microcontroller, and I wasn't able to test it on the actual board. Originally,
I planned to use the user inputted boolean expression, and print out the results
on Coolterm. Now, in order to run the program with your desired boolean expression,
you need to first edit the char array in the first few lines of main.c. 
I became very comfortable with dynamic allocation and overall C just made more
logical sense to me. By drawing out the steps and thinking through every problem,
I was able to solve them with less effort and create elegant solutions. For example,
when generating binary values, I originally used several nested for loops, however
I was later able to create a more elegant (easier to read, but same runtime) solution. 
Thanks Max, I enjoyed this class and I'm a lot more comfortable with C now. 

References:
Infix to Postfix psuedo-code, referenced for char Stack
https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

