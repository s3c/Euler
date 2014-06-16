#include <stdio.h>
#include <stdint.h>

void initprime(void);
void genprime(uint32_t primecount);

extern uint32_t *primevals, numprimes;

int main(void){

	initprime();
	genprime(10001-2);

	printf("Prime number 10001: %d", primevals[numprimes-1]);

	return 0;
}
