#include <stdio.h>
#include <stdlib.h>  //funcoes
#include "pilha.h"

#define MAX 3

typedef struct pilha {
	int n;
	int v[MAX];
} Pilha;

/*Função que cria uma pilha.*/
Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	
	if(p==NULL) {
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	p->n = 0;   //n é o contador da pilha
	
	return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	if(p->n==MAX) {   //verificando se a pilha está cheia
		printf("Capacidade da Pilha Estourou!!!\n");
		exit(1);
	}
	
	p->v[p->n]= info;   //vetor p na posição escalar n
	
	p->n = p->n + 1;   //incrementando o contador
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	int i;
	//n é o índice da posição acima do topo (posição "livre")
	for(i = p->n-1; i>=0; i--){    //imprime do topo para a base
		printf("%f\n", p->v[i]);
	}
}

/*Libera o espaço alocado para uma pilha.*/
//foi criada dinamicamente
void pilha_libera(Pilha *p){
	free(p);
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->n==0;   //retorno lógico
}

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
	int a;
	
	if(pilha_vazia(p)){   //verificando se a pilha está vazia
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	
	a = p->v[p->n-1];   //elemento do topo
	
	p->n--;   //decrementando o contador
	
	return a;   //retornando o valor que foi "retirado"
}	

