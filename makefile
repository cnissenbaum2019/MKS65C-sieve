make: prime.c prime.h
	gcc prime.h
	gcc prime.c -lm

run: a.out
	./a.out
