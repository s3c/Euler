//No use in doing 99*98 and 98*99
//Should test largest numbers first

//Urgh, attempt at testing highest numbers first misses it initially, only shows up later so have to run through the entire list anyway.
//Ha, loop around always generates higher new palindrome, if we ever hit looparound higher we have max
//Great, if the loop around thing doesn't happen we can't depend on hitting one

//Setting a lower bound once we find one but not sure how we should calculate this, suspect sqrt

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define PVALMAX 999
#define PVALMIN 100

int main(void){
	uint32_t loop1, loop2, tried = 0, pospal, pospaltmp, pospalrev, largest = 0, lowerbound = 0;

	for(loop1 = PVALMAX; loop1 >= PVALMIN && loop1 >= lowerbound; loop1--){
		for(loop2 = PVALMAX; loop2 >= loop1; loop2--){
			pospal = pospaltmp = loop1 * loop2;
			tried++;
			pospalrev = 0;
			while(pospaltmp){
				pospalrev = (pospalrev * 10) + (pospaltmp % 10);
				pospaltmp /= 10;
			}
			if(pospal == pospalrev){
				if(pospal > largest && largest){
					printf("Largest palindrome: %d (%d, %d - %d)\n", pospal, loop1, loop2, tried);
					return 0;
				}else if(pospal > largest){
					printf("New largest: %d (%d, %d)\n", pospal, loop1, loop2);
					largest = pospal;
					lowerbound = sqrt(loop1); //uhh, not sure what to set this to, guessing here
				}
			}
		}
	}

	printf("Largest palindrome: %d (%d)\n", largest, tried);

	return 0;
}
