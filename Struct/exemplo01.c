#include <stdio.h>

struct ponto{
	float x;
	float y;
};

int main (void) {
	struct ponto p;
	
	printf("Digite as coordenadas do ponto(x,y):\n");
	scanf("%f %f",&p.x,&p.y);
	
	printf("Ponto(%.2f,%.2f):\n",p.x,p.y);
	
	return 0;
}
