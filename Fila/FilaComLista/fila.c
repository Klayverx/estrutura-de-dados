#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"
#include "fila2.h"

typedef struct lista Lista;
typedef struct fila Fila;

// estrutura de uma celula da fila
struct lista {
	int info;
	Lista *prox;
};

// estrutuca com ponteiros para o inicio e fim da fila
struct fila {
	Lista *ini;
	Lista *fim;
};

/*Funcao cria uma fila.*/
Fila* fila_cria(void) {
	Fila *f = (Fila*)malloc(sizeof(Fila));  //cria dinamicamente e coloca o endereco em f
	
	if(f==NULL) {
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	f->ini = NULL;  //estrutura/celula inicial da fila
	
	f->fim = NULL;  //estrutura/celula inicial da fila
	
	return f;
}

/*Função para inserir um elemento em uma fila.*/
void fila_insere(Fila *f, int info) {
	// celula de base
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l==NULL) {
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	l->info = info;
	
	l->prox = NULL;
	
	if(!fila_vazia(f))  //verifica se esta vazia
		f->fim->prox = l;   //caso a estrutura já exista
	else
		f->ini = l;  //ini aponta para a primeira estrutura criada (se for a primeira insercao)
	
	f->fim = l;
}

/*Função para verificar se a fila esta vazia.*/
int fila_vazia(Fila *f){
	return f->ini==NULL;
}

/*Função para remover um elemento da fila.*/
int fila_remove(Fila *f){
	Lista *l; int a;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	
	l = f->ini;
	
	f->ini = f->ini->prox;
	
	free(l);
	
	if(fila_vazia(f))
		f->fim = NULL;
	
	return a;
}

/*Função que imprime os elementos de uma fila.*/
void fila_imprime(Fila *f) {
	Lista *lAux = f->ini;
	
	while(lAux != NULL) {
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma fila.*/
void fila_libera(Fila *f) {
	Lista* l = f->ini;
	
	Lista* lAux;
	
	while(l != NULL) {
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	
	free(f);
}
