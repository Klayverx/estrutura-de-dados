typedef struct pilha Pilha;

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
