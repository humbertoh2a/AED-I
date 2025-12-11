#include <stdio.h>
#include "Queue.h"

int main()
{
  Queue *fila1 = create_queue();
  Queue *fila2 = create_queue();

  int op, valor;

  while (1)
  {
    if (scanf("%d", &op))
    {

      switch (op)
      {
      case 0:
        return 0;
      case 1:
        scanf("%d", &valor);
        enqueue(fila1, valor);
        break;
      case 2:
        scanf("%d", &valor);
        enqueue(fila2, valor);
        break;
      case 3:
        if (dequeue(fila2, &valor))
        {
          printf("%d\n", valor);
        }
        else if (dequeue(fila1, &valor))
        {
          printf("%d\n", valor);
        }

        if (dequeue(fila2, &valor))
        {
          printf("%d\n", valor);
        }
        else if (dequeue(fila1, &valor))
        {
          printf("%d\n", valor);
        }

        if (dequeue(fila1, &valor))
        {
          printf("%d\n", valor);
        }
        else if (dequeue(fila2, &valor))
        {
          printf("%d\n", valor);
        }
        break;
      }
    }
  }

  return 0;
}
