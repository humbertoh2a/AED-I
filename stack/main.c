#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Stack.h"

int main()
{
  Stack *s = create_stack();

  char linha[256];
  fgets(linha, sizeof(linha), stdin);

  // Remove o '\n'
  linha[strcspn(linha, "\n")] = '\0';

  char buf[256];
  strncpy(buf, linha, sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0';

  char *tok = strtok(buf, " ");
  while (tok != NULL)
  {
    if (isdigit(tok[0]))
    {
      int valor = atoi(tok);
      push(s, valor);
    }
    else
    {
      int a, b;
      pop(s, &a);
      pop(s, &b);
      int resultado;
      switch (tok[0])
      {
      case '+':
        resultado = b + a;
        break;
      case '-':
        resultado = b - a;
        break;
      case '*':
        resultado = b * a;
        break;
      case '/':
        resultado = b / a;
        break;
      }
      push(s, resultado);
    }
    tok = strtok(NULL, " ");
  }

  int resultado;
  pop(s, &resultado);
  printf("%d\n", resultado);

  return 0;
}
