typedef struct pilha Pilha;
typedef struct lista Lista;

/*Função que cria uma pilha.*/
Pilha* pilha_cria(void);

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p);

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info);

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p);

/*Função que imprime os elementos de uma pilha;*/
void pilha_imprime(Pilha *p);

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p);

/* Retorna o topo de uma pilha.*/
int topo(Pilha* p);

/* Retorna a quantidade de elementos impares de uma pilha*/
int impares(Pilha* p);

/* Empilha elementos em comum em duas listas em uma nova pilha ordenado.*/
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2);
