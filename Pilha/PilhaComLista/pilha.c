#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct lista Lista;
typedef struct pilha Pilha;

struct lista {
	int info;
	Lista *prox;
};

struct pilha {
	Lista *prim;
};

/*Função que cria uma pilha.*/
Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	p->prim = NULL;
	
	return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){	
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	l->info = info;   //estrutura recebe o info(valor repassado)
	
	l->prox = p->prim;   //o próximo da estrutura recebe o topo
	
	p->prim = l;   //a nova estrutura se torna o topo
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	if(p->n==MAX) {
		printf("Capacidade da Pilha Estourou!!!\n");
		exit(1);
	}
	
	p->v[p->n]= info;
	
	p->n = p->n + 1;
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;   //se o elemento do topo é NULL
}

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p) {
	int a;
	
	Lista *l;   //estrutura auxiliar
	
	if(pilha_vazia(p)) {
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	
	l = p->prim;  //estrutura recebe o topo
	
	a = l->info;   //a recebe o conteudo do topo
	
	p->prim = l->prox;   //prim recebe o valor abaixo do topo
	
	free(l);   //libera o topo
	
	return a;   //retorna o valor "excluido"
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p) {
	Lista *lAux = p->prim;
	
	while(lAux!=NULL) {   //enquanto o auxiliar não chegar na base
		printf("%f\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p){
	Lista* l = p->prim;   //l recebe o topo da lista
	
	Lista* lAux;
	
	while(l!=NULL) {   //enquanto o topo nao chegar na base
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	
	free(p);
}
