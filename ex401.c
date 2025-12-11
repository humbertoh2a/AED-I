#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int l, int r, int m);

void mergeSort(int array[], int l, int r) {

    if(l >= r) return;

    int m = l + (r - l) / 2;

    printf("DIVISAO [%d,%d]\n", l, r);

    mergeSort(array, l, m);
    mergeSort(array, m+1, r);

    merge(array, l, r, m);
}

void merge(int array[], int l, int r, int m) {
    int size = r - l + 1;
    int result[size];
    
    int i = l;
    int j = m + 1;
    int k = 0;
    
    while(i <= m && j <= r) {
        if(array[i] <= array[j]) { 
            result[k] = array[i];
            i++;
        } else {
            result[k] = array[j];
            j++;
        }
        k++;
    }
    
    while(i <= m) {
        result[k] = array[i];
        i++;
        k++;
    }
    
    while(j <= r) {
        result[k] = array[j];
        j++;
        k++;
    }

    for(int counter = 0; counter < size; counter++) {
        array[l + counter] = result[counter];
    }

    printf("INTERCALACAO [%d,%d]: ", l, r);
    for(int i = l; i <= r; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    scanf("%d", &n);
    int array[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    mergeSort(array, 0, n - 1);

    return 0;
}