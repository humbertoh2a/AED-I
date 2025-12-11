#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main(void)
{
  float p1x, p1y, p2x, p2y;
  
  if (scanf("%f %f %f %f", &p1x, &p1y, &p2x, &p2y) != 4) return 1;

  Ponto *P1 = criaPonto(p1x, p1y);
  Ponto *P2 = criaPonto(p2x, p2y);

  int opcao = 0;

  while (opcao != 9)
  {
    if(scanf("%d", &opcao) != 1) return 1;
    switch (opcao)
    {
    case 1:
      imprimePonto(P1);
      printf("\n");
      break;
    case 2:
      imprimePonto(P2);
      printf("\n");
      break;
    case 3:
      printf("%.3f\n", distancia(P1, P2));
      break;
    case 4:
      printf("%.3f\n", distanciaOrigem(P1));
      break;
    case 5:
      printf("%.3f\n", distanciaOrigem(P2));
      break;
    case 6:
    {
      float x, y;
      if(scanf("%f %f", &x, &y) != 2) return 1;
      atribuiPonto(P1, x, y);
      break;
    }
    case 7:
    {
      float x, y;
      if(scanf("%f %f", &x, &y) != 2) return 1;
      atribuiPonto(P2, x, y);
      break;
    }
    case 8:
      printf("%d\n", pontosIguais(P1, P2));
      break;
    case 9:
      break;
    default:
      break;
    }
  }
  liberaPonto(P1);
  liberaPonto(P2);
  return 0;
}