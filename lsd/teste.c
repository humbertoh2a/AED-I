#include <stdio.h>

void soma(int *a, int *b) {
  printf("%d", *a + *b);
}

int main() {
  int a, b;
  a = 5;
  b = 3;
  soma(&a, &b);
}