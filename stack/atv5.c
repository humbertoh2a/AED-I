#include <stdio.h>
#include <stdlib.h>

int operacoes;

void shell(int v[], int n)
{
    int gap = 1;
    while (gap <= n)
    {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int x = v[i];
            operacoes++;
            int j = i - gap;
            while (j >= 0 && v[j] > x)
            {
                operacoes++; 
                v[j + gap] = v[j];
                operacoes++;
                j -= gap;
            }
            if (j >= 0)
            {
                operacoes++;
            }
            v[j + gap] = x;
            operacoes++;
        }
        gap /= 2;
    }
}

void quick(int v[], int f, int l)
{
    if (f >= l)
    {
        return;
    }
    int m = (l + f) / 2;
    int pivot = v[m];
    operacoes++;
    int i = f;
    int j = l;
    while (1)
    {
        while (v[i] < pivot)
        {
            operacoes++;
            i++;
        }
        operacoes++; // compara quando para

        while (v[j] > pivot)
        {
            operacoes++;
            j--;
        }
        operacoes++; // compara quando para dnv

        if (i >= j)
        {
            break;
        }
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        operacoes += 3; // 3 atribuicoes
        i++;
        j--;
    }
    quick(v, f, j);
    quick(v, j + 1, l);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int tam = 1; tam <= n; tam++)
    {
        int *vshell = malloc(tam * sizeof(int));
        int *vquick = malloc(tam * sizeof(int));

        for (int i = 0; i < tam; i++)
        {
            vshell[i] = vetor[i];
            vquick[i] = vetor[i];
        }

        operacoes = 0;
        shell(vshell, tam);
        int shellops = operacoes;

        operacoes = 0;
        quick(vquick, 0, tam - 1);
        int quickops = operacoes;

        if (quickops < shellops)
        {
            printf("Q ");
        }
        else if (shellops < quickops)
        {
            printf("S ");
        }
        else
        {
            printf("- ");
        }

    }
    return 0;
}