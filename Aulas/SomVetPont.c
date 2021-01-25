// somatorio de um vetor por ponteiros
#include <stdio.h>
#include <stdlib.h>

float somatorio(int tam, float v[]){ 
  int i; float s = 0.0F;

  for(i = 0; i < tam; i++)
    s += v[i];
  
  return s;
}

int main (void) {
  int tam; int i; float *v; float s;

  scanf("%d", &tam);
  // O operador sizeof retorna o número de bytes de um tipo
  v = (float*) malloc(tam*sizeof(float));

  for(i=0; i<tam; i++)
    scanf("%f",&v[i]);
  
  s = somatorio(tam, v);

  printf("somatorio=%.1f, media=%.1f", s, s/tam);

  return 0;
}