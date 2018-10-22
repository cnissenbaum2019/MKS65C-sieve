make: prime.c primeComp.h
	gcc prime.h
	gcc prime.c -lm

run: a.out
	./a.out
