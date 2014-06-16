#include <stdio.h>
#include <stdint.h>

void initprime(void);
void genprime(uint32_t primecount);

extern uint32_t *primevals, numprimes;

//#define PMAXVAL 10
#define PMAXVAL 2000000

int main(void){
	uint64_t sum = 0;
	uint32_t loop;

	initprime();
	while(primevals[numprimes-1] < PMAXVAL)
		genprime(128);

	for(loop = 0; primevals[loop] < PMAXVAL; loop++){
		//printf("- %d\n", primevals[loop]);
		sum += primevals[loop];
	}

	printf("Sum of primes to %Ld: %Ld\n", PMAXVAL, sum);

	return 0;
}
