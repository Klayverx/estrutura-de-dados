#include "ponto.h"

typedef struct circulo Circulo;

/*Fun��o que cria e retorna um c�rculo com centro (x,y) e
raio r */
Circulo* circ_cria (float x, float y, float r);

/* Fun��o que libera a mem�ria de um c�rculo previamente
criado */
void circ_libera (Circulo* c);

/* Fun��o que calcula o valor da �rea do c�rculo */
float circ_area (Circulo* c);

/* Fun��o que verifica se um dado ponto p est� dentro do
c�rculo */
int circ_interior (Circulo* c, Ponto* p);
