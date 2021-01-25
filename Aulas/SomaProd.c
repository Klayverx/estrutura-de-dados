//Soma e produto por vetor
#include <stdio.h>

void somaprod(int n1, int n2, int *ps, int *pp){
  *ps = n1 + n2;
  *pp = n1 * n2;
}

int main (void){
  int s, p;

  somaprod(3, 5, &s, &p);

  printf("soma = %d, prod = %d" , s, p);

  return 0;
}