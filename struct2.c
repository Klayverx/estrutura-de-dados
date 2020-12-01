#include <stdio.h>

struct ponto {
  float x;
  float y;
};

int main() {
  struct ponto p;
  struct ponto *pp;
  pp = &p;

  pp->x = 10.0;
  printf("%f", pp->x);
  
  return 0;
}