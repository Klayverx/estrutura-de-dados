#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
	
	//criando a estrutura inicial
	Fila *f = fila_cria();
	
	//inserindo elementos
	fila_insere(f, 5);
	fila_insere(f, 6);
	fila_insere(f, 7);
	fila_insere(f, 8);
	fila_insere(f, 9);
	
	fila_remove(f);
	
	fila_imprime(f);
	
	fila_libera(f);
	
	return 0;
}
