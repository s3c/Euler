#include <stdio.h>
#include <stdint.h>

void initprime(void);
void genprime(uint32_t primecount);

extern uint32_t *primevals, numprimes;

int main(void){
	uint32_t curprime = 0;
	uint64_t testval = 600851475143;
	//uint64_t testval = 13195;

	initprime();

	while(1){
		if(curprime == numprimes)
			genprime(128);
		if(primevals[curprime] > testval)
			break;
		if(!(testval % primevals[curprime])){
			testval /= primevals[curprime];
			printf("Prime Factor: %d\n", primevals[curprime]);
			curprime = 0;
			continue;
		}
		curprime++;
	}


	//for(loop = 0; loop < numprimes; loop++)
	//	printf("%d ", primevals[loop]);

	//printf("Done!");

	return 0;
}

//The prime factors of 13195 are 5, 7, 13 and 29.
