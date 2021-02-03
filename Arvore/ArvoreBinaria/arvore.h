typedef struct arv Arv;

/*Função que cria uma Árvore Binária Vazia.*/
Arv* arv_cria_vazia(void);

/*Função que cria um nó em uma Árvore Binária.*/
Arv* arv_cria_no(char c, Arv *sae, Arv *sad);

/*Testa se uma Árvore Binária é vazia.*/
int arv_vazia(Arv *a);

/*Função que imprime os elementos de uma Árvore Binária.*/
void arv_imprime(Arv *a);

/*Função que determina se um caractere pertence à Árvore.*/
int arv_pertence(Arv *a,char c);

/*Libera o espaço alocado para uma Árvore Binária.*/
void arv_libera(Arv *a);

/*Função quer retorna o tamanho de uma Árvore.*/
int arv_altura(Arv *a);
