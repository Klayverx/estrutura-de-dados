#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ordenacao.h"

int main() {
	int potencia = 5;
	int TAM_VETOR = pow(10, potencia);
	int MAX = 1000;
	
	double media;
	clock_t inicio, fim;

	int* vetor1 = malloc(TAM_VETOR * sizeof(int));
	int* vetor2 = malloc(TAM_VETOR * sizeof(int));
	int* vetor3 = malloc(TAM_VETOR * sizeof(int));
	int* vetor4 = malloc(TAM_VETOR * sizeof(int));
	int* vetor5 = malloc(TAM_VETOR * sizeof(int));
	
	int cont, numero;
	
	srand(time(NULL));
	
	for(cont = 0; cont < TAM_VETOR; cont++){
		numero = rand()%MAX;
		vetor1[cont] = numero;
		vetor2[cont] = numero;
		vetor3[cont] = numero;
		vetor4[cont] = numero;
		vetor5[cont] = numero;
	}
	
	printf("Tamanho dos vetores igual a 10^%d\n\n", potencia);
	
	inicio = clock();
	bubbleSort(vetor1, TAM_VETOR);
	fim = clock();
				
    printf("bubbleSort: \t%.0lf ms\n", (double)(fim - inicio));

	inicio = clock();
	insertionSort(vetor2, TAM_VETOR);
	fim = clock();
				
    printf("insertionSort: \t%.0lf ms\n", (double)(fim - inicio));

	inicio = clock();
    quickSort(vetor3, TAM_VETOR);
	fim = clock();
			
    printf("quickSort: \t%.0lf ms\n", (double)(fim - inicio));

	inicio = clock();
	mergeSort(vetor4, TAM_VETOR);
	fim = clock();
				
    printf("mergerSort: \t%.0lf ms\n", (double)(fim - inicio));

	inicio = clock();
	heapSort(vetor5, TAM_VETOR);
	fim = clock();
				
    printf("heapSort: \t%.0lf ms\n", (double)(fim - inicio));
    
    free(vetor1);
    free(vetor2);
    free(vetor3);
    free(vetor4);
    free(vetor5);
	
	return 0;
}
