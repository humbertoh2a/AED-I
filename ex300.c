#include <stdio.h>
#include <stdlib.h>


int fatorial(int n) {
  
  int resultado;

  printf("Entrando em fatorial(%d)\n", n);

  if(n < 2) {
    printf("Caso base atingido: fatorial(%d) = 1\n", n);
    return 1;
  }
  
  resultado = n * fatorial(n-1);

  printf("Retornando de fatorial(%d) = %d\n", n, resultado);

  return resultado;
}


int main() {
  int fac;
  scanf("%d", &fac);
  printf("Calculando fatorial de %d...\n", fac);
  int resultado = fatorial(fac);
  printf("Resultado final: %d", resultado);
}