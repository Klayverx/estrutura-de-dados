typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria();

/* Testa se uma lista eh vazia.*/
int lst_vazia(Lista *l);

/* Insere um elemento no inicio da lista.*/
Lista* lst_insere(Lista *l, int info);

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);

/* Imprime uma lista.*/
void lst_imprime(Lista *l);

/* Imprime uma lista invertida recursivamente.*/
void lst_imprime_invertida_rec(Lista* l);

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);

/* Remove um elemento de uma lista recursivamente.*/
Lista* lst_remove_rec(Lista *l, int info);

/* Libera o espaco alocado por uma lista.*/
void lst_libera(Lista *l);

/* Calcula o numero de nos de uma lista.*/
int comprimento(Lista* l);

/* Verifica a quantidade de nos com valores menor que n.*/
int menores(Lista* l, int n);

/* Soma os valores de todos os nos de uma lista.*/
int soma(Lista* l);

/* Verifica a quantidade de nos com valores primos.*/
int primos(Lista* l);

/* Cria uma nova lista concatenando 2 listas.*/
Lista* lst_conc(Lista* l1, Lista* l2);

/* Retira de uma lista o que contem na outra.*/
Lista* lst_diferenca(Lista* l1, Lista* l2);






