typedef struct arvb ArvB;

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB *a);

/*Fun��o que busca a sub-�rvore que cont�m um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c);

/*Fun��o que insere um inteiro em uma �rvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*Fun��o que imrpime uma �rvore Bin�ria de Busca.*/
void arvb_imprime(ArvB *a);

/*Fun��o que verifica a altura de uma �rvore Bin�ria de Busca.*/
int arvb_altura(ArvB *a);

/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(ArvB *a);

/* ======= Fun��es ======= */

// Retorna a quantidade de folhas divisiveis por n
int folhas_div_n(ArvB* a, int n);

// Verifica se uma �rvore � degenerada
int isdegenerada(ArvB* a);

// Quantidade de n�s que tem o balanceamento igual a n
int nos_fb_n(ArvB* a, int n);

// Imprime os elementos em comum entre 2 arvores
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

// Imprime os elementos de uma arvore por niveis
void impressao_arv_niveis(ArvB* a);
