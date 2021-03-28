/* ======= Lista Encadeada ======= */

typedef struct lista Lista;
typedef struct fila Fila;

/*Função que cria uma Fila.*/
Fila* fila_cria(void);

/*Testa se uma Fila é vazia.*/
int fila_vazia(Fila *f);

/*Função que adiciona um elemento em uma Fila.*/
void fila_insere(Fila *f, int info);

/*Função que remove um elemento de uma Fila.*/
int fila_remove(Fila *f);

/*Função que imprime os elementos de uma Fila.*/
void fila_imprime(Fila *f);

/*Libera o espaço alocado para uma Fila.*/
void fila_libera(Fila *f);

/* Retora a quantidade de elementos maior que n de uma Fila.*/
int qtd_maior(Fila* f, int n);

/* Cria uma nova fila com ordem inversa.*/
Fila* inverte(Fila* f);

/* Quantidade de elementos pares de uma fila.*/
int pares(Fila* f);
