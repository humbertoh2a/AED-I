#include <stdio.h>
#include <stdlib.h>
#include "LSD.h"

int main()
{
  LSD *lista = lsd_cria();
  int op;
  while (scanf("%d", &op) == 1)
  {
    if (op == 9)
      break;
    switch (op)
    {
    case 1:
    {
      int x;
      scanf("%d", &x);
      int res = lsd_insere_final(lista, x);
      printf("%d\n", res == 1 ? 1 : 0);
      break;
    }
    case 2:
    {
      int p, x;
      scanf("%d %d", &p, &x);
      int res = lsd_insere_pos(lista, p, x);
      printf("%d\n", res == 1 ? 1 : 0);
      break;
    }
    case 3:
    {
      int p;
      scanf("%d", &p);
      LSD_Tipo removido;
      int res = lsd_remove_pos(lista, p, &removido);
      if (res == 1)
      {
        printf("%d\n", removido);
      }
      else
      {
        printf("ERRO\n");
      }
      break;
    }
    case 4:
    {
      int p;
      scanf("%d", &p);
      LSD_Tipo elem;
      int res = lsd_consulta_pos(lista, p, &elem);
      if (res == 1)
      {
        printf("%d\n", elem);
      }
      else
      {
        printf("ERRO\n");
      }
      break;
    }
    case 5:
    {
      int x;
      scanf("%d", &x);
      int pos;
      lsd_busca(lista, x, &pos);
      printf("%d\n", pos);
      break;
    }
    case 6:
    {
      int t = lsd_tamanho(lista);
      printf("%d\n", t);
      break;
    }
    case 7:
    {
      lsd_imprime(lista);
      break;
    }
    case 8:
    {
      lsd_limpa(lista);
      break;
    }
    }
  }
  lsd_destroi(&lista);
  return 0;
}