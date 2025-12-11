#include <stdio.h>

void heapify(int arr[], int n, int i)
{
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;

  if (esquerda < n && arr[esquerda] > arr[maior])
    maior = esquerda;

  if (direita < n && arr[direita] > arr[maior])
    maior = direita;

  if (maior != i)
  {
    int temp = arr[i];
    arr[i] = arr[maior];
    arr[maior] = temp;
    heapify(arr, n, maior);
  }
}

void heapSort(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}

int buscaBinaria(int arr[], int n, int alvo)
{
  int esquerda = 0;
  int direita = n - 1;

  while (esquerda <= direita)
  {
    int meio = esquerda + (direita - esquerda) / 2;

    if (arr[meio] == alvo)
      return 1;
    else if (arr[meio] < alvo)
      esquerda = meio + 1;
    else
      direita = meio - 1;
  }

  return 0;
}

int main()
{
  int N;
  scanf("%d", &N);

  int V[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &V[i]);
  }

  heapSort(V, N);

  int K;
  scanf("%d", &K);

  for (int i = 0; i < K; i++)
  {
    int num;
    scanf("%d", &num);

    printf("%d\n", buscaBinaria(V, N, num));
  }

  return 0;
}