#include <stdio.h>
#include <stdlib.h>


int fibonacci(int n) {
  
  int resultado;

  printf("Entrando em fibonacci(%d)\n", n);

  if(n == 0) {
    printf("Caso base atingido: fibonacci(%d) = 0\n", n);
    return 0;
  } else if(n == 1) {
    printf("Caso base atingido: fibonacci(%d) = 1\n", n);
    return 1;
  }
  
  resultado = fibonacci(n-1) + fibonacci(n-2);

  printf("Retornando de fibonacci(%d) = %d\n", n, resultado);

  return resultado;
}


int main() {
  int fib;
  scanf("%d", &fib);
  printf("Calculando fibonacci de %d...\n", fib);
  int resultado = fibonacci(fib);
  printf("Resultado final: %d", resultado);
}