#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
	//criando fila
	Fila* f = fila_cria();
	
	//inserindo elementos
	fila_insere(f, 3);
	fila_insere(f, 4);
	fila_insere(f, 5);
	
	//retirando elementos
	fila_remove(f);
	
	//imprimindo fila
	fila_imprime(f);
	
	//liberando fila
	fila_libera(f);
	
	return 0;
}
