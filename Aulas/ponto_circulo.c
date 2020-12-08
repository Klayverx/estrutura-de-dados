#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
  float x;
  float y;
} Ponto;

typedef struct circulo {
  Ponto p;
  float r;
} Circulo;

// ponto externo ou interno ao círculo
void capturaPonto(Ponto *pp){
  printf("Digite os valores de x e y do ponto:\n");
  scanf("%f %f", &pp->x, &pp->y);
}

// captura das coordenadas do ponto central e do raio do círculo
void capturaCirculo(Circulo *pc){
  printf("Digite os valores de x, y e o raio:\n");
  scanf("%f %f %f", &pc->p.x, &pc->p.y, &pc->r);
}

// calcula a distância do ponto central do circulo e o ponto externo
float distancia(Ponto *p1, Ponto *p2) {
  return sqrt ((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

// verifica a distancia dos pontos com o raio
int interior (Circulo *c, Ponto *p) {
  float d = distancia(&c->p, p);
  return (d < c->r);
}

int main(void) {

  Ponto p;
  Circulo c;

  capturaPonto(&p);
  capturaCirculo(&c);

  if(interior(&c, &p)) {
    printf("Dentro do circulo\n");
  } else {
    printf("Fora do circulo\n");
  }

  return 0;
}