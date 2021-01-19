#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
	Pilha *p = pilha_cria();
	
	if(pilha_vazia(p)) {
		printf("Pilha vazia\n");
	} else {
		printf("Pilha nao vazia\n");
	}
	
	//até 3 elementos
	pilha_push(p, 5);
	pilha_push(p, 8);
	pilha_push(p, 6);
	
	pilha_imprime(p);
	
	if(pilha_vazia(p)) {
		printf("Pilha vazia\n");
	} else {
		printf("Pilha nao vazia\n");
	}
	
	return 0;
}
