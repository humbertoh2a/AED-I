#include <stdio.h>

void hanoi(int n, char origem, char destino, char auxiliar)
{
  if (n == 0) return;
  hanoi(n - 1, origem, auxiliar, destino);
  printf("Mova o disco %d de %c para %c\n", n, origem, destino);
  hanoi(n - 1, auxiliar, destino, origem);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  hanoi(n, 'A', 'C', 'B');
}