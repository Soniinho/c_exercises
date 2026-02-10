#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// A função recebe vetores crescentes v[p..q-1] e v[q..r-1] e rearranja v[p..r-1] em ordem crescente.

static void intercala(int p, int q, int r, int v[])
{
    int *w;
    w = malloc((r - p) * sizeof(int));
    int i = p, j = q;
    int k = 0;

    while (i < q && j < r)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
        w[k++] = v[i++];
    while (j < r)
        w[k++] = v[j++];
    for (i = p; i < r; ++i)
        v[i] = w[i - p];
    free(w);
}

// A função mergesort rearranja o vetor v[p..r-1] em ordem crescente.
void mergesort(int p, int r, int v[])
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

#define R 11
int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    int vet[12] = {9, 6, 7, 1, 5, 8, 10, 2, 4, 11, 3, 0}; // 12 valores

    printf("Vetor não ordenado:");
    for (i = 0; i < R + 1; i++)
    {
        printf(" %d,", vet[i]);
    }

    mergesort(0, R + 1, vet); // o r tem q ser 1 posição a mais

    printf("\n\nVetor ordenado:");
    for (i = 0; i < R + 1; i++)
    {
        printf(" %d,", vet[i]);
    }

    return 0;
}

//%-----------------------------------------------------------------------------------------------%//

// Esta função recebe vetores crescentes v[p..q-1] e v[q..r-1] e rearranja v[p..r-1] em ordem crescente.
static void intercala2(int p, int q, int r, int v[])
{
    int i, j, *w;
    w = malloc((r - p) * sizeof(int));

    for (i = p; i < q; ++i)
        w[i - p] = v[i];
    for (j = q; j < r; ++j)
        w[r - p + q - j - 1] = v[j];
    i = 0;
    j = r - p - 1;
    for (int k = p; k < r; ++k)
        if (w[i] <= w[j])
            v[k] = w[i++];
        else
            v[k] = w[j--];
    free(w);
}

// Esta função rearranja o vetor v[0..n-1] em ordem crescente.
void mergesort_i(int n, int v[])
{
    int b = 1;
    while (b < n)
    {
        int p = 0;
        while (p + b < n)
        {
            int r = p + 2 * b;
            if (r > n)
                r = n;
            intercala(p, p + b, r, v);
            p = p + 2 * b;
        }
        b = 2 * b;
    }
}
