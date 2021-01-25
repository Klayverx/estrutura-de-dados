#include <stdio.h>

typedef struct aluno{
  char nome[81];
  float ira;
} Aluno;

#define MAX 100
#define SEMALUNO -1 // Valor qd aluno inexistente no vetor

void inicializa(int n, Aluno alunos[]){
  int i;
  for (i = 0; i < n; i++)
    // Significa que nao tem aluno, mas esta existindo a estrutura
    // Utiliza "." pq eh a propria estrutura
    alunos[i].ira = SEMALUNO;
};

void atualiza(int n, Aluno alunos[], int i){
  float ira;

  // verificando a posicao do aluno repassada
  if (i < 0 || i >= n)
  {
    printf("Indice fora do limite do vetor!!!\n");
    exit(1);
  }

  printf("Entre com o nome do aluno\n");
  // %[^\n] -> aceita quaisquer caracteres que esteja dentro dos colchetes
  // No caso, o \n
  scanf(" %[^\n]", alunos[i].nome);

  while (1){
    printf("Entre com o IRA do aluno\n");
    scanf(" %f", &ira);

    if (ira < 0 || ira > 100)
      printf("IRA pertence ao intervalo [0.0, 100.0]\n");
    else
      break;
  }

  alunos[i].ira = ira;
};
void imprime(int n, Aluno alunos[], int i){
  // verificando a posição do aluno repassada
  if (i < 0 || i >= n){
    printf("Indice fora do limite do vetor!!!\n");
    exit(1);
  }

  // Verificando se o ira é != de -1
  // Se existe aluno
  if (alunos[i].ira != SEMALUNO){
    printf("Nome: %s\n", alunos[i].nome);
    printf("Ira: %.2f\n", alunos[i].ira);
  }
};

void imprime_todos(int n, Aluno alunos[]){
  int i;
  printf("Listagem de Alunos\n");

  for (i = 0; i < n; i++)
    imprime(n, alunos, i);
};

void exclui(int n, Aluno alunos[], int i);

int main(void){
  Aluno *alunos;
  int n, i;
  
  printf("Entre com o numero de alunos:\n");
  scanf("%d", &n);
  
  alunos = (Aluno *)malloc(n * sizeof(Aluno));
  
  if (alunos == NULL){
    printf("Memoria Insuficiente!!!\n");
    exit(1);
  }
  
  inicializa(n, alunos);
  
  for (i = 0; i < n; i++)
    atualiza(n, alunos, i);

  imprime_todos(n, alunos);
  
  free(alunos);
  
  return 0;
}
