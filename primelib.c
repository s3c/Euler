// Don't check even numbers
// Only divide by primes
// Up to <= Sqrt(numtocheck)
// Multiples of primes won't be prime
// -- How to use? Keep track of highest prime multiples up to and past current known prime?

//-> Multiple of previous prime? Then not prime.
//-> Not multiple of previous prime? Always prime? Yup

//    # #   #   #        #     #           #     #           #                 #     #                 #           #     #           #                 #                 #
////1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59
//    2   2   2   2   2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2     2
//      3     3     3       3        3        3        3        3        3        3        3        3        3        3        3        3        3        3        3
//          5         5              5              5              5              5              5              5              5              5

// Thought I was so clever, turns out this is called "Sieve of Eratosthenes"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t *primevals, *primefcts, numprimes;

void initprime(void){
	numprimes = 2;

	primevals = malloc(sizeof(uint32_t) * 2);
    primefcts = malloc(sizeof(uint32_t) * 2);

    primevals[0] = primefcts[0] = 2;
    primevals[1] = primefcts[1] = 3;
}

uint8_t testprime(uint32_t potprime){
	uint32_t testto, loop;
	static uint32_t toloc = 0;

	testto = sqrt(potprime);
	while(primevals[toloc] < testto)
		toloc++;
	if(primevals[toloc] > testto)
		toloc--;

	//printf("Test to %d located at %d\n", primevals[toloc], toloc);

	for(loop = 0; loop <= toloc; loop++){
		while(primefcts[loop] < potprime){
			//printf("Updating multiples of %d from %d to ", primevals[loop], primefcts[loop]);
			primefcts[loop] += primevals[loop];
			//printf("%d\n", primefcts[loop]);
		}
		if(primefcts[loop] == potprime){
			//printf("-Multiple of %d (%d)\n\n", primevals[loop], primefcts[loop]);
			return 0;
		}
	}

	//printf("+Prime found: %d\n\n", potprime);

	return 1;
}

void genprime(uint32_t primecount){
	uint32_t primeloop, tocheck;

	primevals = realloc(primevals, sizeof(uint32_t) * (numprimes + primecount));
	primefcts = realloc(primefcts, sizeof(uint32_t) * (numprimes + primecount));

	for(primeloop = 0, tocheck = primevals[numprimes-1] + 2; primeloop < primecount;){

		//printf("[Checking prime: %d]\n", tocheck);

		if(testprime(tocheck)){
				primevals[numprimes] = primefcts[numprimes] = tocheck;
				//printf("Numprimes: %d, primevals[numprimes]: %d, primefcts[numprimes]: %d, lastcheck: %d\n", numprimes, primevals[numprimes], primefcts[numprimes], tocheck);
				numprimes++;
				primeloop++;

		}
		tocheck += 2;
	}
}
