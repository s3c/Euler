#include <stdio.h>

#define MAXVAL 1000

int main(void){
	int loop3 = 3, loop5 = 5, loop15 = 15, sum = 0;

	while(loop3 < MAXVAL){
		if(loop3 < MAXVAL){
			sum += loop3;
			loop3 += 3;
		}
		if(loop5 < MAXVAL){
			sum += loop5;
			loop5 += 5;
		}
		if(loop15 < MAXVAL){
			sum -= loop15;
			loop15 += 15;
		}
	}

	printf("Sum to %d is: %d\n", MAXVAL, sum);

	return 0;
}
