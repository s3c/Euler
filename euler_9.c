//a < b < c
//a + b + c = 1000
//a^2 + b^2 = c^2
//a*b*c=?

//1 < 1 < 998

//1 < 2 < 997
///2 < 1 < 997
//1 < 3 < 996

//200, 375, 425 - 31875000

#include <stdio.h>

#define MAXVAL 1000

int main(void){
	int a, b, c;

	for(a = 1; a < (MAXVAL-a)/2; a++){
		for(b = a + 1; b < (MAXVAL-a)/2; b++){
			c = MAXVAL - a - b;
			if(a*a + b*b == c*c){
				printf("%d %d %d - %d\n", a, b, c, a*b*c);
				return 0;
			}
		}
	}

	return 1;
}
