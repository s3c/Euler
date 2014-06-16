//2520

//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
//                     11 12 13 14 15 16 17 18 19 20

#include <stdio.h>
#include <stdint.h>

#define STARTVAL 2520
#define NUMFOUND 1

int main(void){
	uint32_t valcheck = STARTVAL, checkdiv;

	while(1){
		for(checkdiv = 19; checkdiv >= 11; checkdiv--){
			if(valcheck % checkdiv)
				break;
		}
		if(checkdiv == 10)
			break;
		valcheck += 20;
	}

	printf("Smallest divisible number: %d\n", valcheck);
	return 0;
}
