#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};

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

/* Busca um elemento em uma lista (retorna o endereço ou NULL).*/
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
	
	while(lAux != NULL){
		printf("Info = %d\n",lAux->info);
		
		lAux = lAux->prox;
	}
}

/* Imprime uma lista invertida recursivamente.*/
void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else {
		lst_imprime_invertida_rec(l->prox);
		printf("Info = %d\n",l->info);
	}
}

/* Remove um elemento de uma lista.*/
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

/* Remove um elemento de uma lista recursivamente.*/
Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l))
		if(l->info==info){
			Lista* lAux = l;
			l = l->prox;
			free(lAux);
		} else {	
			l->prox = lst_remove_rec(l->prox,info);
		}
		
	return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
	Lista* lProx;
	
	while(l != NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

/* Calcula o numero de nos de uma lista.*/
int comprimento(Lista* l) {
	Lista* lAux = l;
	int quant = 0;
	
	while(lAux != NULL){
		quant++;
		
		lAux = lAux->prox;
	}
	
	return quant;
}

/* Verifica a quantidade de nos com valores menor que n.*/
int menores(Lista* l, int n) {
	Lista* lAux = l;
	int quant = 0;
	
	while(lAux != NULL){
		if (lAux->info < n)
			quant++;
		
		lAux = lAux->prox;
	}
	
	return quant;
}

/* Soma os valores de todos os nos de uma lista.*/
int soma(Lista* l) {
	Lista* lAux = l;
	int soma = 0;
	
	while(lAux != NULL){
		soma += lAux->info;
		
		lAux = lAux->prox;
	}
	
	return soma;
}

/* Verifica a quantidade de nos com valores primos.*/
int primos(Lista* l) {
	Lista* lAux = l;
	int quant = 0, cont, cont_div;
	
	while(lAux != NULL){
		cont_div = 0;
		
		if (lAux->info <= 1)
			continue;
		
		for (cont = 2; cont < lAux->info; cont++)
	    	if (lAux->info % cont == 0)  //verifica se a divisão eh exata
	       		cont_div++;
 		
 		if(cont_div == 0)  //se não existir divisão exata entre 2 e n, é primo
 			quant++;
		
		lAux = lAux->prox;
	}
	
	return quant;
}

/* Cria uma nova lista concatenando 2 listas.*/
Lista* lst_conc(Lista* l1, Lista* l2) {
	Lista* lAuxInv = lst_cria();  //lista auxiliar para desinverter o "problema" da funcao insere
	Lista* lAux = l2;  //para percorrer as listas (comecando com a lista 2 para a invertida)
	Lista* l3 = lst_cria();
	
	while (lAux != NULL) {
		lAuxInv = lst_insere(lAuxInv, lAux->info);
		
		lAux = lAux->prox;
	}
	
	lAux = lAuxInv;
	//passando para l3 desinvertida
	while (lAux != NULL) {
		l3 = lst_insere(l3, lAux->info);
		
		lAux = lAux->prox;
	}
	
	//processo com a primeira lista
	lAux = l1;
	lAuxInv = NULL;
	
	while (lAux != NULL) {
		lAuxInv = lst_insere(lAuxInv, lAux->info);
		
		lAux = lAux->prox;
	}
	
	lAux = lAuxInv;
	
	//passando para l3 desinvertida
	while (lAux != NULL) {
		l3 = lst_insere(l3, lAux->info);
		
		lAux = lAux->prox;
	}
	
	return l3;
}

/* Retira de uma lista o que contem na outra.*/
Lista* lst_diferenca(Lista* l1, Lista* l2) {
	Lista* lAux;  //estrutura auxiliar de busca
	Lista* lAuxl1 = l1;  //para percorrer l1

	while(lAuxl1 != NULL){   //enquanto não chegar no fim da "primeira lista"
		lAux = lst_busca(l2, lAuxl1->info);   //retorna o endereço encontrado ou nulo
		lAuxl1 = lAuxl1->prox;
		
		if (lAux != NULL ){ //enquanto for diferente de NULL
			l1 = lst_remove(l1, lAux->info);  //remove o elemento da lista original
		}
		
	}
	return l1;
}



