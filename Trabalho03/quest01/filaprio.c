#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "filaprio.h"

#define MAX 7   //tamanho maximo do vetor

typedef struct filap {
	int t_heap;   //tamanho do heap
	int v[MAX];   //vetor que guarda os elementos da fila
} FilaP;

// cria uma fila de prioridade vazia
FilaP* filap_cria(void){
	FilaP *f = (FilaP*)malloc(sizeof(FilaP));
	
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	f->t_heap = -1;
	
	return f;
}

// devolve o elemento de maior prioridade na fila
int heap_maximum(FilaP* f) {
	return f->v[0];
}

//indice do filho esquerdo
int left_son (int i) {
	return (2*i)+1;
}

//indice do filho direito
int right_son (int i) {
	return (2*i)+2;
}

void max_heapify(FilaP* f, int i) {
	int l = left_son(i);
	int r = right_son(i);
	int maior;
	
	if (l <= f->t_heap && f->v[l] > f->v[i]) {
		maior = l;
	} else {
		maior = i;
	}
	
	if (r <= f->t_heap && f->v[r] > f->v[maior]) {
		maior = r;
	}
	
	if (maior != i) {
		int troca = f->v[i];
		f->v[i] = f->v[maior];
		f->v[maior] = troca;
		
		max_heapify(f, maior);
	}
}

// devolve o elemento de maior prioridade e o retira da fila
int heap_extract_max(FilaP* f) {
	int max;
	
	if(f->t_heap < 0) {
		printf("nova chave é menor que a chave atual");
	} else {
		max = f->v[0];
		f->v[0] = f->v[f->t_heap];
		f->t_heap = f->t_heap - 1;
		
		max_heapify(f, 0);
		
		return max;
	}
}

//indice do pai
int parent(int i) {
	return floor(i/2);
}

// modifica a prioridade de determinado elemento no índice ind na fila (apenas se chave for maior)
void heap_increase_key(FilaP* f, int ind, int chave) {
	if(chave < f->v[ind]) {
		printf("nova chave eh menor que a chave atual\n");
	} else {
		f->v[ind] = chave;
	
		while (ind > 0 && f->v[parent(ind)] < f->v[ind]) {
			
			int troca = f->v[parent(ind)];
			f->v[parent(ind)] = f->v[ind];
			f->v[ind] = troca;
			
			ind = parent(ind);
		}
	}	
}

// insere um novo elemento na fila com prioridade chave
void max_heap_insert(FilaP* f, int chave) {
	f->t_heap = f->t_heap + 1;
	f->v[f->t_heap] = -1;
	heap_increase_key(f, f->t_heap, chave);
}

