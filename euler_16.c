//215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//What is the sum of the digits of the number 21000?

//Sum of exponent digits: 1366

#include <stdio.h>
#include <string.h>
#include <gmp.h>

#define BASE 2
#define EXPONENT 1000

int main(void){
	int fanswer, floop;
	char *strresult;
	mpz_t result, base;

	mpz_init(result);
	mpz_init(base);
	mpz_set_ui(base, BASE);

	mpz_pow_ui(result, base, EXPONENT);
	strresult = mpz_get_str(NULL, 10, result);

	for(floop = 0, fanswer = 0; floop < strlen(strresult); floop++)
		fanswer += strresult[floop] - '0';

	printf("Sum of exponent digits: %d\n", fanswer);

	mpz_clear(result);
	mpz_clear(base);
	return 1;
}
