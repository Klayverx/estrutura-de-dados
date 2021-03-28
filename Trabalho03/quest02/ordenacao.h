typedef struct fila Fila;

void imprimeVetor(int *v, int n);

/* BUBBLE SORT */
void bubbleSort(int *v, int n);

/* INSERTION SORT */
void insertionSort(int* v, int n);

/* QUICK SORT */
void quickSort (int* v, int n);

/* MERGE SORT */
void mergeSort(int *v, int n);

void mergeSort_ordena(int *v, int esq, int dir);

void mergeSort_intercala(int *v, int esq, int meio, int dir);

/* HEAP SORT */
int left_son (int i);

int right_son (int i);

void max_heapify(int *v, int n, int maior);

void buid_max_heap (int* v, int n);

void heapSort (int* v, int n);

