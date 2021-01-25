#include <stdio.h>

typedef struct ponto {
  float x;
  float y;
} Ponto;

void main(void) {
  // ultima "palavra" substitui o tipo que precede
  typedef float Real;
  typedef struct ponto *PPonto;

  Real r = 10.5;
  Ponto p; p.x = 10.0;
  PPonto pp = &p;
  pp->x = 12.0;
}
