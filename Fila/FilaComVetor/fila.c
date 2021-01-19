#include<stdio.h>
#include<stdlib.h>
#include "fila.h"
	
#define MAX 3   //tamanho máximo da fila

typedef struct fila {
	int n;   //quantidade de elementos que a fila possui no momento (0 até o máximo)
	int ini;   //indice do primeiro elemento da fila
	int v[MAX];   //vetor que guarda os elementos da fila
} Fila;

/*Função cria uma fila.*/
Fila* fila_cria(void) {
	Fila *f = (Fila*)malloc(sizeof(Fila));
	
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	f->n = 0;   //tamanho 0
	
	f->ini = 0;
	
	return f;
}

/*Função insere um elemento em uma fila.*/
void fila_insere(Fila *f, int info) {
	int fim;   //índice do fim da fila
	
	if(f->n == MAX){   //verificando se a fila já está cheia
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	
	fim = (f->ini + f->n) % MAX;   //setando o fim da fila
	
	f->v[fim] = info;
	
	f->n++;
}

/*Testa se uma fila é vazia.*/
int fila_vazia(Fila *f) {
	return f->n==0;
}

/*Função que remove um elemento de uma fila.*/
int fila_remove(Fila *f) {
	int a;
	
	if(fila_vazia(f)) {
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	
	a = f->v[f->ini];   //elemento a ser removido é o do inicio da fila
	
	f->ini = (f->ini+1) % MAX;  //incrementando o ini (novo inicio)
	
	f->n--;  //quantidade de elementos diminui
	
	return a;
}

/*Função que imprime uma fila.*/
void fila_imprime(Fila *f) {
	int i; int k;
	
	for(i = 0; i < f->n; i++) {
		k = (f->ini+i) % MAX;
		printf("%d\n", f->v[k]);
	}
}

/*Função que libera uma fila.*/
void fila_libera(Fila *f) {
	free(f);
}

