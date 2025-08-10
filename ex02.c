#include <stdio.h>
#include <stdlib.h>

void main() {
  int n;
  scanf("%d", &n);

  int *vetor = (int*) malloc(n * sizeof(int));

  if (vetor == NULL) {
    return;
  }

  int number;

  for (int i = 0; i < n; i++) {
    scanf("%d", &number);
    vetor[i] = number;
  }

  int x, p;
  scanf("%d %d", &x, &p);

  int *vetortemp = (int*) realloc(vetor, (n+1) * sizeof(int));

  if(vetortemp == NULL) {
    return;
  }

  vetor = vetortemp;

  for (int i = n; i > p; i--) {
    vetor[i] = vetor[i-1];
  }

  vetor[p] = x;

  for (int i = 0; i < n+1; i++) {
    printf("%d ", vetor[i]);
  }

  free(vetor);
}