#include <stdio.h>

#define FMAXVAL 4000000

int main(void){
	int prepre, pre = 1, cur = 2, sum = 2;
	
	do{
		prepre = pre;
		pre = cur;
		cur = prepre + pre;
	}while(cur < FMAXVAL && ((cur%2)?1:(sum+=cur)));
	
	printf("Sum to %d is: %d\n", FMAXVAL, sum);
	
	return 0;
}
