#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

void imprimeVetor(int *v, int n) {
	int cont;
	for(cont = 0; cont < n; cont++)
		printf("\t%d", v[cont]);
	
	printf("\n");
}

/* BUBBLE SORT */
void bubbleSort(int *v, int n) {
	int i, j, temp;
	
	for(i = n-1; i >= 1; i--){
		for (j = 0; j < i; j++){
			if (v[j] > v[j+1]) {
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}	
}

/* INSERTION SORT */
void insertionSort(int* v, int n) { 
    int i, j, chave;
    
    for (i = 1; i < n; i++) { 
        chave = v[i]; 
        j = i - 1; 
 
        while (j >= 0 && v[j] > chave) { 
            v[j+1] = v[j]; 
            j = j - 1; 
        } 
        
        v[j+1] = chave;
    }
} 

/* QUICK SORT */
void quickSort(int* v, int n) {
	if(n > 1){
		int x = v[0];
		int a =1; 
		int b = n-1;
		
		while (1) {
			while(a < n && v[a] <= x) 
				a++;
				
			while(v[b] > x)
				b--;
			
			if (a < b) {
				int temp = v[a];
				
				v[a] = v[b];
				v[b] = temp;
				a++; b--;
				
			} else
				break;
		}
		
		v[0] = v[b];
		v[b] = x;
		
		quickSort(v, b);
		quickSort(&v[a], n-a);
	}
}

/* MERGE SORT */
void mergeSort(int *v, int n) {
	mergeSort_ordena(v, 0, n-1);
}

void mergeSort_ordena(int *v, int esq, int dir) {
	if (esq == dir)
		return;
	
	int meio = (esq + dir) / 2;
	
	mergeSort_ordena(v, esq, meio);
	mergeSort_ordena(v, meio+1, dir);
	mergeSort_intercala(v, esq, meio, dir);
}

void mergeSort_intercala(int *v, int esq, int meio, int dir) {
	int i, j, k;
	int a_tam = meio-esq+1;
	int b_tam = dir-meio;
	int *a = (int*) malloc(sizeof(int) * a_tam);
	int *b = (int*) malloc(sizeof(int) * b_tam);

	for (i = 0; i < a_tam; i++)
		a[i] = v[i+esq];
		
	for (i = 0; i < b_tam; i++)
		b[i] = v[i+meio+1];
	
	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam)
			v[k] = b[j++];
		else if (j == b_tam)
			v[k] = a[i++];
		else if (a[i] < b[j])
			v[k] = a[i++];
		else 
			v[k] = b[j++];
	}

	free(a);
	free(b);
}

/* HEAP SORT */
int left_son (int i) {
	return (2*i)+1;
}

int right_son (int i) {
	return (2*i)+2;
}

void max_heapify(int *v, int n, int i) {
	int l = left_son(i);
	int r = right_son(i);
	int maior = i;
	
	if (l < n && v[l] > v[i])
		maior = l;
	
	if (r < n && v[r] > v[maior]) 
		maior = r;
	
	if (maior != i) {
		int troca = v[i];
		v[i] = v[maior];
		v[maior] = troca;
		
		max_heapify(v, n, maior);
	}
}

void buid_max_heap (int* v, int n) {
	int i;
	
	for (i = n / 2 - 1; i >= 0; i--) {
		max_heapify(v, n, i);
	}
}

void heapSort (int* v, int n) {
	int i, troca;
	
	buid_max_heap (v, n);
	
	for (i = n - 1; i > 0; i--) {
		troca = v[0];
		v[0] = v[i];
		v[i] = troca;
			
		max_heapify(v, i, 0);
	}
}

