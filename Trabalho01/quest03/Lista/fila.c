#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

/* ======= Lista Encadeada ======= */

struct lista{
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	f->ini = NULL;
	f->fim = NULL;
	
	return f;
}

void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	l->info = info;
	l->prox = NULL;
	
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
	
	f->fim = l;
}

int fila_vazia(Fila *f){
	return f->ini == NULL;
}

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
void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma fila.*/
void fila_libera(Fila *f){
	Lista* l = f->ini;
	Lista* lAux;
	
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	
	free(f);
}

/* Retora a quantidade de elementos maior que n de uma Fila.*/
int qtd_maior(Fila* f, int n) {
	Lista *lAux = f->ini;  //estutura auxiliar iniciando no começo da fila
	int quant = 0;  //quantidade de elementos
	
	while(lAux != NULL) {
		if (lAux->info > n)  //verificando se é maior que n
			quant++;
		
		lAux = lAux->prox;
	}
	
	return quant;
}

/* Função interna para inserir recursivamente.*/
Fila* fila_insere_invertida_rec(Lista* l, Fila* f_inv){
	if(l == NULL)  //verifica se o campo está vazio
		return;
	else{
		fila_insere_invertida_rec(l->prox, f_inv);  //chamando a função recursivamente
		fila_insere(f_inv, l->info);   //inserindo o elemento na nova lista
	}
	
	return f_inv;
}

/* Cria uma fila com ordem inversa.*/
Fila* inverte(Fila* f) {
	Fila* f_inv = fila_cria();   //fila que será a invertida
	Lista *lAux = f->ini;   //estrutura auxiliar
	
	f_inv = fila_insere_invertida_rec(lAux, f_inv);  //chamada da função interna
	
	return f_inv;	
}

/* Quantidade de elementos pares de uma fila.*/
int pares(Fila* f) {
	Lista *lAux = f->ini;  //estutura auxiliar iniciando no começo da fila
	int quant = 0;  //quantidade de elementos
	
	while(lAux != NULL) {
		if (lAux->info % 2 == 0)  //verificando a divisao por 2
			quant++;
		
		lAux = lAux->prox;
	}
	
	return quant;
}

