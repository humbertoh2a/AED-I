#include <stdio.h>
#include <stdlib.h>

int insertion(int n) {

  int ccmp = 0;
  int ctrc = 0;

  printf("I %d ", n);

  int t;
  int vetor[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    vetor[i] = t;
  }
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int x = vetor[i];

    ctrc++;
    
    while (j >= 0) {
      
      ccmp++;
      if(vetor[j] <= x) break ;

        ctrc++;
        vetor[j+1] = vetor[j];
        j--;
    }
    ctrc++;
    vetor[j+1] = x;
  }

  printf("%d %d\n", ctrc, ccmp);
}

int main(void) {
  int q;

  scanf("%d", &q);

  int n[q];

  for (int i = 0; i < q; i++) {
    scanf("%d", &n[i]);
  }
  for (int i = 0; i < q; i++) {
    insertion(n[i]); 
  }


}