// somatorio de um vetor
#include <stdio.h>

float somatorio(int tam, float v[]){
  int i; float s = 0.0F;

  for(i = 0; i < tam; i++)
    s += v[i];
  
  return s;
}

int main (void) {
  float v[] = {2.0, 3.0, 4.0};

  float s = somatorio(3, v);

  printf("somatorio = %.1f, media = %.1f", s, s/3);

  return 0;
}