#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main()
{
  int n;
  scanf("%d", &n);

  Arvore raiz = NULL;

  for (int i = 0; i < n; i++)
  {
    int valor;
    scanf("%d", &valor);
    raiz = arv_insere(raiz, valor);
  }

  arv_preordem(raiz);
  printf("\n");
  arv_inordem(raiz);
  printf("\n");
  arv_posordem(raiz);
  printf("\n");

  int altura = arv_altura(raiz);
  if (altura == -1)
    altura = 0;
  printf("%d\n", altura+1);

  arv_libera(raiz);

  return 0;
}