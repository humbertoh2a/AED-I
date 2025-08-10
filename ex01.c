#include <stdio.h>
#include <stdlib.h>

void addValor(int *contador, int **valores) {

  (*contador)++;
  int *novoValores = (int*) realloc(*valores, (*contador) * sizeof(int));

  if(novoValores == NULL) {
    return;
  }

  *valores = novoValores;

  int valor;
  scanf("%d", &valor);

  (*valores)[*contador-1] = valor;
}

void removeValor(int *contador, int **valores) {

  if((*contador) == 0) return;

  (*valores)[*contador] = 0;
  (*contador)--;
  int *novoValores = (int*) realloc(*valores, (*contador) * sizeof(int));

  if(novoValores == NULL) {
    return;
  }

  *valores = novoValores;
}

void listaValores(int *contador, int **valores) {

  if((*contador) == 0) return;

  for(int i = 0; i < (*contador); i++) {
    printf("%d ", (*valores)[i]);
  }
  printf("\n");
}

void calcula(int *contador, int **valores) {

  if((*contador) == 0) return;

  int soma = 0;
  for(int i = 0; i < (*contador); i++) {
    soma += (*valores)[i];
  }
  float media = (float)soma / (*contador);

  printf("Soma = %d, Média = %.2f", soma, media);
  printf("\n");
}

void ordena(int *contador, int **valores) {

  if((*contador) == 0) return;

  for(int i = 0; i < (*contador); i++) {
    int s = (*valores)[i];
    int sID = i;
    for(int j = i + 1; j < (*contador); j++) {
      if(s > (*valores)[j]) {
        s = (*valores)[j];
        sID = j;
      }
    }
    int temp = (*valores)[i];
    (*valores)[i] = (*valores)[sID];
    (*valores)[sID] = temp;
  }
}


void main() {
  int opcao;
  int contador = 0;

  int *valores = (int *) malloc(sizeof(int));

  if(valores == NULL) {
    return;
  }

  do {
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      addValor(&contador, &valores);
      break;
    case 2:
      removeValor(&contador, &valores);
      break;
    case 3:
      listaValores(&contador, &valores);
      break;
    case 4:
      calcula(&contador, &valores);
      break;
    case 5:
      ordena(&contador, &valores);
      break;
    default:
      break;
    }

  } while  (opcao != 6);
}