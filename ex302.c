#include <stdio.h>

int recursivo(int vetor[], int n, int soma) {
  // printf("soma: %d vetor[n]: %d\n", soma, vetor[n]);
  if(n == 0) {
    if(vetor[n] % 2 == 0) {
      soma += vetor[n];
      // printf("somando %d\n", vetor[n]);
      return soma;
    } else {
      return soma;
    }
  }
  if(vetor[n] % 2 == 0) {
    soma += vetor[n];
    return recursivo(vetor, n-1, soma);
  } else {
    return recursivo(vetor, n-1, soma);
  }
}

int main(void) {
  int n, temp;
  scanf("%d", &n);
  int vetor[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    vetor[i] = temp;
  }
  int soma = 0;
  printf("Soma dos pares: %d", recursivo(vetor, n-1, soma));
}