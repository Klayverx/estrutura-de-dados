#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvb.h"

typedef struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
} ArvB;

ArvB* arvb_cria_vazia(void){
	return NULL;
}

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a){
	return a == NULL;
}

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir, c);
	else if(a->info > c)
		return arvb_busca(a->esq, c);
	else //(a->info == c)
		return a;
}

/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int num){
	if(a == NULL){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = num;
		a->esq = NULL;
		a->dir = NULL;
	} 
	else if (a->info > num)
		a->esq = arvb_insere(a->esq, num);
	else if (a->info < num)
		a->dir = arvb_insere(a->dir, num);
	else
		printf("\nElemento Ja Pertence a Arvore");
		
	return a;
}

/*Função que imrpime uma Árvore Binária de Busca.*/
void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ", a->info);
		arvb_imprime(a->dir);
	}
}

/*Função que verifica a altura de uma Árvore Binária de Busca.*/
int arvb_altura(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		
		if(hSAE > hSAD)
			return 1+hSAE;
		else
			return 1+hSAD;
	}
}

/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		
		free(a);
	}
}

// Retorna a quantidade de folhas divisiveis por n
int folhas_div_n(ArvB* a, int n) {	
	if(arvb_vazia(a))   // se vazia, retorna 0
		return 0;
	
	//se for uma folha e divisível por n, chama a função com incremento
	if(a->dir == NULL && a->esq == NULL && a->info % n == 0)
		return folhas_div_n(a->esq, n) + folhas_div_n(a->dir, n) + 1;
		
	return folhas_div_n(a->esq, n) + folhas_div_n(a->dir, n);		
}

// Verifica se uma árvore é degenerada
// 1 – verdadeiro, 0 – falso
int isdegenerada(ArvB* a) {
	if (a->esq == NULL){
		if(a->dir == NULL){ //se chegar até o final da arvore
			return 1;
		} else {
			return isdegenerada(a->dir);
		}
	} else if (a->dir == NULL) {
		return isdegenerada(a->esq);
	} else {
		return 0;
	}
}

// Quantidade de nós que tem o balanceamento igual a n
int nos_fb_n(ArvB* a, int n) {
	if(arvb_vazia(a))
	    return 0;
	
	// calculo do fator de balanceamento
	int fator = arvb_altura(a->dir) - arvb_altura(a->esq);
	
	if (fator == n)  //se for igual a "n", retorna incrementado
	    return nos_fb_n(a->esq, n) + nos_fb_n(a->dir, n) + 1;
	
	return nos_fb_n(a->esq, n) + nos_fb_n(a->dir, n);
}

// Imprime os elementos em comum entre 2 arvores
void impressao_arv_elem_comuns(ArvB* a, ArvB* b) {
	if(a != NULL){
		int *igual = arvb_busca(b, a->info); //verifica se contém o elemento de uma em outra
		
		if(igual != NULL)
			printf("%d\n", *igual);
		
		impressao_arv_elem_comuns(a->esq, b);
		impressao_arv_elem_comuns(a->dir, b);
	}
}

// Imprime os elementos de uma arvore por niveis
void impressao_arv_niveis(ArvB* a) {
	
	ArvB *elemento;
	int *fila, ini, fim, qnt_elementos, nivel = 0;
	int nivel_current = 0, altura = arvb_altura(a);
	
	qnt_elementos = pow(2, altura + 1) - 1;
	
	fila = (ArvB*)malloc(qnt_elementos * sizeof (ArvB));
	
	fila[0] = a;
	ini = 0; fim = 1;
	
	printf("nivel %d: ", nivel_current);
	
	while (fim > ini) {
		//claculo do nível
		nivel = floor(log10(ini+1) / log10(2));  // log2(x)
		
		if(nivel > altura)
			break;
		
		elemento = (ArvB *)fila[ini++];
		
		//impressão do nível
		if (nivel != nivel_current) {
			nivel_current = nivel;
			printf("\nnivel %d: ", nivel_current);
		}
		
		//impressão dos elementos do nível
		if (elemento != NULL)
			printf("%d ", elemento->info);
		
		if (elemento == NULL && nivel != altura)  //caso para nós nulos
			fila[fim++] = NULL;
		else if (elemento == NULL && nivel == altura)  //caso para folhas nulas
			continue;
		else if (elemento->esq != NULL)  	//caso para filhos de nós != de nulos
			fila[fim++] = elemento->esq;
		else   								//demais casos
			fila[fim++] = NULL;
		
		if (elemento == NULL && nivel != altura)
			fila[fim++] = NULL;
		else if (elemento == NULL && nivel == altura)
			continue;
		else if (elemento->dir != NULL)
			fila[fim++] = elemento->dir;
		else
			fila[fim++] = NULL;
	}
	
	puts("\n");
		
	free(fila);
}

