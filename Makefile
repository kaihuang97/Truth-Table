# Kai Huang
# Makefile
# Makefile for Truth Table Calculator

all : main StackTest

main : main.o TruthTable.o ShuntingYard.o Stack.o
	gcc -o main main.o TruthTable.o ShuntingYard.o Stack.o -lm

StackTest : StackTest.o Stack.o
	gcc -o StackTest StackTest.o Stack.o

main.o : main.c TruthTable.h ShuntingYard.h Stack.h
	gcc -c -std=c99 -Wall main.c

ShuntingYard.o : ShuntingYard.c ShuntingYard.h
	gcc -c -std=c99 -Wall ShuntingYard.c

TruthTable.o : TruthTable.c TruthTable.h ShuntingYard.h
	gcc -c -std=c99 -Wall TruthTable.c

Stack.o : Stack.c Stack.h
	gcc -c -std=c99 -Wall Stack.c

StackTest.o : StackTest.c Stack.h
	gcc -c -std=c99 -Wall StackTest.c

clean :
	rm -f main StackTest main.o StackTest.o ShuntingYard.o TruthTable.o Stack.o

run :
	main

leak : 
	valgrind main

test :
	StackTest