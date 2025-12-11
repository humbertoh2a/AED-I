#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void)
{
  LinkedList *list1 = create_linked_list();
  LinkedList *list2 = create_linked_list();

  int op;

  while (scanf("%d", &op) == 1)
  {
    if(op == 9) break;
    switch (op)
    {
    case 1:
    {
      int x, p;
      scanf("%d %d", &x, &p);
      insert_node(list1, p, x);
      break;
    }
    case 2:
    {
      int x, p;
      scanf("%d %d", &x, &p);
      insert_node(list2, p, x);
      break;
    }
    case 3:
    {
      int p;
      scanf("%d", &p);
      remove_node(list1, p, NULL);
      break;
    }
    case 4:
    {
      int p;
      scanf("%d", &p);
      remove_node(list2, p, NULL);
      break;
    }
    case 5:
    {
      int size = size_list(list2);
      for (int i = 0; i < size; i++)
      {
        int value;
        get_node(list2, 0, &value);
        insert_node(list1, size_list(list1), value);
        remove_node(list2, 0, NULL);
      }
      break;
    }
    case 6:
    {
      int size = size_list(list1);
      for (int i = 0; i < size; i++)
      {
        int value;
        get_node(list1, 0, &value);
        insert_node(list2, size_list(list2), value);
        remove_node(list1, 0, NULL);
      }
      break;
    }
    case 7:
    {
      printf("[");
      int size = size_list(list1);
      for (int i = 0; i < size; i++)
      {
        int value;
        get_node(list1, i, &value);
        printf("%d", value);
        if (i < size - 1)
        {
          printf(" ");
        }
      }
      printf("]\n");
      break;
    }
    case 8:
    {
      printf("[");
      int size = size_list(list2);
      for (int i = 0; i < size; i++)
      {
        int value;
        get_node(list2, i, &value);
        printf("%d", value);
        if (i < size - 1)
        {
          printf(" ");
        }
      }
      printf("]\n");
      break;
    }
    case 9:
      break;
    }
  }
  return 0;
}