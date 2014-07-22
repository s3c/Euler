
/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

//user@debian:~/Euler$ time ./euler_14 
//837799 - 525
//
//real	0m0.086s
//user	0m0.084s
//sys	0m0.000s

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAXNUMCHECK	1000000

//#define CACHESIZE 268435456 //gig
//#define CACHESIZE	4286786812 //full
#define CACHESIZE	1000000 //partial, ehh, works best for some reason
uint32_t cachechain[CACHESIZE];

uint32_t collatzchainlen(uint32_t checkval){
	uint32_t chainlen;

	if(checkval < CACHESIZE && cachechain[checkval])
		return cachechain[checkval];

	if(checkval & 1)
		chainlen = collatzchainlen(3 * checkval + 1) + 1;
	else
		chainlen = collatzchainlen(checkval / 2) + 1;
		
	if(checkval < CACHESIZE)
		cachechain[checkval] = chainlen;
		
	return chainlen;
}

int main(void){
	uint32_t checkval, checkvalmax, tempchainmax, chainlenmax = 0;
	
	memset(cachechain, 0, sizeof(uint32_t) * CACHESIZE);
	cachechain[2] = 2;
	
	for(checkval = 2; checkval < MAXNUMCHECK; checkval++){
		if((tempchainmax = collatzchainlen(checkval)) > chainlenmax){
			checkvalmax = checkval;
			chainlenmax = tempchainmax;
		}
	}
	
	printf("%d - %d\n", checkvalmax, chainlenmax);
		
	return 0;
}
