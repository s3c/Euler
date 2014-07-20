#include <stdio.h>
#include <stdint.h>
#include "primelib.c"

int main(void){
  int loop, stopval;

  initprime();
  stopval = genprimeto(40);

  for(loop = 0; loop <= stopval; loop++)
    printf("%d (%d)\n", primevals[loop], loop);
  printf("\n");

  return 0;
}
