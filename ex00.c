#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 41 //inclui o '\0'
#define MAX_ALUNOS 50
#define NUM_NOTAS 3

typedef struct 
{
  char nome[TAM_NOME];
  float notas[NUM_NOTAS];
  float media;
} Aluno;


void limparBuffer() {
  char c;
  while (((c = getchar()) != '\n') && (c != EOF));
} 

void addAluno(Aluno alunos[], int *contadorAlunos) {


   if (*contadorAlunos == MAX_ALUNOS) {
    printf("Número máximo já foi atingido\n");
    return;
  }

  Aluno novo;

  printf("Digite o nome do aluno: ");

  fgets(novo.nome, TAM_NOME, stdin);
  
  size_t len = strlen(novo.nome);
  if (len > 0 && novo.nome[len-1] == '\n') {
    novo.nome[len-1] = '\0';
  }

  novo.media = 0;

  for (int i = 0; i < NUM_NOTAS; i++) {
    printf("Digite a %d nota:\n", i+1);
    scanf("%f", &novo.notas[i]);
    novo.media += novo.notas[i];
    limparBuffer();
  }

  novo.media = novo.media / NUM_NOTAS;

  alunos[*contadorAlunos] = novo;
  (*contadorAlunos)++;
}

void listarAlunos(Aluno alunos[], int *contadorAlunos) {

  if (*contadorAlunos == 0) {
    printf("Sem alunos");
    return;
  }
  for (int i = 0; i < *contadorAlunos; i++) {
    printf("Nome: %s, Media: %.2f", alunos[i].nome, alunos[i].media);
  }
}

void maiorMedia(Aluno alunos[], int *contadorAlunos) {
  if (*contadorAlunos == 0) {
    printf("Sem alunos");
    return;
  }

  char melhorAlunoNome[TAM_NOME];
  float melhorMedia = 0;
  int melhorID = 0;

  for (int i = 0; i < *contadorAlunos; i++) {
    if (alunos[i].media > melhorMedia) {
      strcpy(melhorAlunoNome, alunos[i].nome);
      melhorMedia = alunos[i].media;
      melhorID = i;
    }
  }

  printf("O melhor aluno foi %s, com media de %.2f.", melhorAlunoNome, melhorMedia);
}

int main(void) {

  int opcao;
  Aluno alunos[MAX_ALUNOS];
  int contadorAlunos = 0;

  do {
      printf("1. Add aluno\n");
      printf("2. Listar alunos\n");
      printf("3. Mostrar aluno com a maior média\n");
      printf("0. Sair\n");
      printf("Escolha opção: ");
      scanf("%d", &opcao);
      limparBuffer();
      // menu
      switch (opcao) {
        case 1:
          // adicionar aluno
          addAluno(alunos, &contadorAlunos);
          break;
        case 2:
          // listar alunos
          listarAlunos(alunos, &contadorAlunos);
          break;
        case 3:
          maiorMedia(alunos, &contadorAlunos);
          // mostrar o aluno com a maior nota
          break;
        case 0:
          printf("Terminando execução\n");
          break;
        default:
          printf("Entrada inválida\n");
          break;
      }
    } while (opcao != 0);
}