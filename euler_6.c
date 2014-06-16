//1^2  2^2  3^2  4^2  5^2  6^2  7^2  8^2  9^2  ...
//1    4    9    16   25   36   49   64   81

//http://planetmath.org/squareofsum
//http://formulas.tutorvista.com/math/sum-of-squares-formula.html

//(a+b)^2 = a^2 + b^2                         + 2ab
//(a+b+c)^2 = a^2 + b^2 + c^2     + 2bc + 2ca + 2ab
//(a+b+c+d)^2 = ??

//(a+b+c+d+...+n)^2 = ((n*(n+1))/2)^2
//a^2 + b^2 + c^2 + d^2 ... + n^2 = n*(n+1)(2*n+1)/6

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define SUMTO 100

int main(void){
	uint32_t sumsq, sqsum;

	sumsq = SUMTO*(SUMTO+1)*(2*SUMTO+1)/6;
	sqsum = pow(((SUMTO*(SUMTO+1))/2), 2);

	printf("Sum of sq: %d, Sq of sum: %d, Diff: %d", sumsq, sqsum, sqsum-sumsq);

	return 0;
}
