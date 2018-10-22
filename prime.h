#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sieve(int input) {


	//find size (slightly larger than the prime looked for / 2)
	int size = (int) input * (.575 * log(input)); //want to divide by 8

	//BITWISE OPERATORS (Not Done)
	
	//NO EVEN NUMBERS (Done)

	//all numbers set to true (0)
	_Bool * nums = calloc(sizeof(_Bool),size); //want to divide by 8

	//printf("%d\n",size);

	//where to stop early 
	int stop = (int) sqrt((double)size);

	//since 2 is going to be skipped it must be accounted for
	input--;

	//         i:  0 1 2 3 4
	//2i + 1       | | | | |          
	//start at 3: [1,3,5,7,9...]
	int i = 1;

	//to record largest prime found
	int prime = 2;

	//printf("%d\n",stop);

	//run through all odd numbers < sqrt(size) to eliminate multiples
	for (;i-stop;i++) {

		//if it is prime (0)
		if(!nums[i]) {

			//printf("%d\n",i*2 + 1);

			input--;

			//j is set to the current position
			int j = i;

			//for all multiples of this number (2i + 1)
			for(; j < size; j+= 2*i + 1) {

				//multiples are composite/false (1)

				//if it is already labeled composite (1), don't bother
				if(!nums[j]) nums[j]++;
			}

		}

	}

	//run through remiaining numbers
	//which should be correctly soreted into prime and composite
	for (;i-size;i++) {

		//if it is prime (0)
		if(!nums[i]) {

			//printf("%d\n", 2*i + 1 );

			//set this value to the new largest prime
			prime = 2*i + 1;

			//goal prime # countdown!
			input--;
		}

		//when input is 0 we have reached the desired prime
		if (!input) {
			free(nums);
			return prime;
		}
	}

	//if we dont get to the desired prime, print the laregst one we've found
	free(nums);
	return prime;

}