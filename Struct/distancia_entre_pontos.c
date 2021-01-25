#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto{
  float x;
  float y;
} Ponto;

void captura(Ponto *pp){
  printf("Digite os valores de x e y:\n");
  scanf("%f %f", &pp->x, &pp->y);
}

float distancia(Ponto *p1, Ponto *p2) {
  return sqrt ((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

int main(void) {

  Ponto p1, p2;
  captura(&p1);
  captura(&p2);
  printf("Distancia entre pontos %.1f\n", distancia(&p1, &p2));

  return 0;
}
