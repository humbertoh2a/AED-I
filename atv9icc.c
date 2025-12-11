#include <stdio.h>
#include <stdlib.h>

#define VAZIO -1
#define REMOVIDO -2

int main()
{
  int M;
  scanf("%d", &M);

  int *tabela = (int *)malloc(M * sizeof(int));

  // inicializa tabela
  for (int i = 0; i < M; i++)
  {
    tabela[i] = VAZIO;
  }

  // inserções
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    int num;
    scanf("%d", &num);

    int pos = num % M;

    // verifica se já existe
    int existe = 0;
    int aux = pos;
    while (tabela[aux] != VAZIO)
    {
      if (tabela[aux] == num)
      {
        existe = 1;
        break;
      }
      aux = (aux + 1) % M;
      if (aux == pos)
        break;
    }

    if (!existe)
    {
      // insere
      while (tabela[pos] != VAZIO && tabela[pos] != REMOVIDO)
      {
        pos = (pos + 1) % M;
      }
      tabela[pos] = num;
    }
  }

  // remoções
  int D;
  scanf("%d", &D);

  for (int i = 0; i < D; i++)
  {
    int num;
    scanf("%d", &num);

    int pos = num % M;
    int inicio = pos;

    while (tabela[pos] != VAZIO)
    {
      if (tabela[pos] == num)
      {
        tabela[pos] = REMOVIDO;
        break;
      }
      pos = (pos + 1) % M;
      if (pos == inicio)
        break;
    }
  }

  // buscas
  int B;
  scanf("%d", &B);

  for (int i = 0; i < B; i++)
  {
    int num;
    scanf("%d", &num);

    int pos = num % M;
    int inicio = pos;
    int encontrado = 0;

    while (tabela[pos] != VAZIO)
    {
      if (tabela[pos] == num)
      {
        printf("%d", pos);
        encontrado = 1;
        break;
      }
      pos = (pos + 1) % M;
      if (pos == inicio)
        break;
    }

    if (!encontrado)
    {
      printf("-1");
    }

    if (i < B - 1)
      printf(" ");
  }
  printf("\n");

  free(tabela);
  return 0;
}           