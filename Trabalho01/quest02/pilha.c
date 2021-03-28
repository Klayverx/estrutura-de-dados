#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

typedef struct lista Lista;
typedef struct pilha Pilha;

struct lista {
	int info;
	Lista *prox;
};

struct pilha {
	Lista *prim;
};

/* ============== LISTAS ============== */

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	
	return ln;
}

/* Insere um elemento em ordem na lista.*/
Lista* lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));   //estrutura lista que será inserida
	
	lNew->info = info;   //estrutura recebendo o valor a ser inserido
	
	if(l == NULL){  //se a lista repassada estiver vazia
		lNew->prox = NULL;
		
		return lNew;
		
	} else if(l->info >= info){   //se o primeiro valor da original for maior que o valor a ser inserido
		lNew->prox = l;   //insere antes do primeiro valor
		
		return lNew;
		
	} else {
		Lista *lAnt = l;
		
		Lista *lProx = l->prox;
		
		while(lProx!=NULL && lProx->info < info) {
			lAnt = lProx;
			
			lProx = lProx->prox;
		}
	
		lAnt->prox = lNew;
		
		lNew->prox = lProx;
		
		return l;
	}
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		if(lAux->info == info)
			return lAux;
		
		lAux = lAux->prox;
	}
	
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		
		lAux = lAux->prox;
	}
}

/* Remove um elemento da lista.*/
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
		
		if(l->info==info){
			free(l);
			return lAux;
		} else {
			Lista* lAnt = l;
			
			while(lAux!=NULL ){
				if(lAux->info == info){
					lAnt->prox = lAux->prox;
					free(lAux);
					
					break;
				}else{
					lAnt = lAux;
					lAux = lAux->prox;
				}
			}
		}
	}
	return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
	Lista* lProx;
	
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

/* ============== PILHA ============== */

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
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	l->info = info;   //estrutura recebe o info(valor repassado)
	
	l->prox = p->prim;   //o próximo da estrutura recebe o antigo topo
	
	p->prim = l;   //a nova estrutura se torna o topo
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim == NULL;   //se o elemento do topo é NULL
}

/*Função que remove o elemento do topo de uma pilha.*/
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
	
	while(lAux != NULL) {   //enquanto o auxiliar não chegar na base
		printf("%d\n",lAux->info);
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

/* Retorna o valor do topo de uma pilha.*/
int topo(Pilha* p) {
	return p->prim->info;
}

/* Retorna a quantidade de elementos impares de uma pilha*/
int impares(Pilha* p) {
	Lista *lAux = p->prim;
	int quant = 0;
	
	while(lAux != NULL) {   //enquanto o auxiliar não chegar na base
		if(lAux->info%2 != 0)   //se a divisão por dois não for exata
			quant++;   //quantidade de ímpar aumenta
			
		lAux = lAux->prox;
	}
	
	return quant;
}

/* Empilha elementos em comum em duas listas em uma nova pilha ordenado.*/
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2) {
	Pilha* p2 = pilha_cria();  //pilha que terá os elementos em comum
	
	Lista* l3 = lst_cria();   //lista ordenada dos valores em comum
	
	Lista* lAux = l1;   //lista auxilixar da primeira lista
	
	Lista* lAuxBusca;   //valores das buscas
	
	while(lAux != NULL){   //enquanto não percorrer toda a 1° lista
		lAuxBusca = lst_busca(l2, lAux->info);  //faz-se a busca
		
		if(lAuxBusca != NULL)  //verifica se tem em comum
			l3 = lst_insere_ordenado(l3, lAux->info);  //inserindo ordenado
				
		lAux = lAux->prox;
	}	
	
	//inserindo na pilha ordenado
	while(l3 != NULL) {
		pilha_push(p2, l3->info);
				
		l3 = l3->prox;
	}

	return p2;
}

