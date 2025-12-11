
#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

int main()
{
  LSE *l = lse_cria();
  int op = 0;
  while (1)
  {
    if (scanf("%d", &op) != 1)
      break;
    if (op == 9)
      break;
    switch (op)
    {
    case 1:
    {
      int x;
      scanf("%d", &x);
      int r = lse_insere_final(l, x);
      printf("%d\n", r == 1 ? 1 : 0);
      break;
    }
    case 2:
    {
      int p, x;
      scanf("%d %d", &p, &x);
      int r = lse_insere_pos(l, p, x);
      printf("%d\n", r == 1 ? 1 : 0);
      break;
    }
    case 3:
    {
      int p, v;
      scanf("%d", &p);
      int r = lse_remove_pos(l, p, &v);
      if (r == 1)
        printf("%d\n", v);
      else
        printf("ERRO\n");
      break;
    }
    case 4:
    {
      int p, v;
      scanf("%d", &p);
      int r = lse_consulta_pos(l, p, &v);
      if (r == 1)
        printf("%d\n", v);
      else
        printf("ERRO\n");
      break;
    }
    case 5:
    {
      int x, pos;
      scanf("%d", &x);
      int r = lse_busca(l, x, &pos);
      if (r == 1)
        printf("%d\n", pos);
      else
        printf("-1\n");
      break;
    }
    case 6:
      printf("%d\n", lse_tamanho(l));
      break;
    case 7:
      lse_imprime(l);
      break;
    case 8:
      lse_limpa(l);
      break;
    default:
      break;
    }
  }
  lse_destroi(&l);
  return 0;
  return 0;
}