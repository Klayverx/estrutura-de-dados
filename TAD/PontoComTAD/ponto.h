typedef struct ponto Ponto;

/*Funcao que cria um Ponto com as coordenadas (x,y)*/
Ponto* pto_cria(float x, float y);

/*Funcao que libera a memória de um ponto criado*/
void pto_libera(Ponto *p);

/*Funcao que acessa as coordenadas de um ponto*/
void pto_acessa(Ponto *p, float *x, float *y);

/*Funcao que atribui novos valores as coordenadas(x,y)*/
void pto_atribui(Ponto *p, float x, float y);

/*Funcao que calcula a distancia entre dois pontos*/
float pto_distancia(Ponto *p1, Ponto *p2);
