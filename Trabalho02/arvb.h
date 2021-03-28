typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c);

/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*Função que imrpime uma Árvore Binária de Busca.*/
void arvb_imprime(ArvB *a);

/*Função que verifica a altura de uma Árvore Binária de Busca.*/
int arvb_altura(ArvB *a);

/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a);

/* ======= Funções ======= */

// Retorna a quantidade de folhas divisiveis por n
int folhas_div_n(ArvB* a, int n);

// Verifica se uma árvore é degenerada
int isdegenerada(ArvB* a);

// Quantidade de nós que tem o balanceamento igual a n
int nos_fb_n(ArvB* a, int n);

// Imprime os elementos em comum entre 2 arvores
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

// Imprime os elementos de uma arvore por niveis
void impressao_arv_niveis(ArvB* a);
