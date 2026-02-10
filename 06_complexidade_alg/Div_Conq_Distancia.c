#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//TODO
/* Exercício
03 06 09 19 25 40 43 55 58 71 73 79 82 84 90 96 100
Tipo mergesort

qnd voltar, se for par, calcula a distancia do meio
qnd for impar, calcula as 2 distancias do meio
*/

// A função recebe vetores crescentes v[p..q-1] e v[q..r-1] e rearranja v[p..r-1] em ordem crescente.

static void intercala(int inicio, int meio_percorre, int dps_fim, int vetor[])
{
    int i = inicio, j = meio_percorre;
    int k = 0;

    int *vet_auxiliar;
    vet_auxiliar = malloc((dps_fim - inicio) * sizeof(int));

    while (i < meio_percorre && j < dps_fim)
    {
        if (vetor[i] <= vetor[j])
        {
            vet_auxiliar[k++] = vetor[i++];
        }
        else
        {
            vet_auxiliar[k++] = vetor[j++];
        }
    }

    while (i < meio_percorre)
    {
        vet_auxiliar[k++] = vetor[i++];
    }

    while (j < dps_fim)
    {
        vet_auxiliar[k++] = vetor[j++];
    }

    for (i = inicio; i < dps_fim; ++i)
    {
        vetor[i] = vet_auxiliar[i - inicio];
    }
    free(vet_auxiliar);
}

// A função mergesort rearranja o vetor v[p..r-1] em ordem crescente.
void mergesort(int inicio, int dps_fim, int vetor[])
{
    if (inicio < dps_fim - 1)
    {
        int meio_percorre = (inicio + dps_fim) / 2;
        mergesort(inicio, meio_percorre, vetor);
        mergesort(meio_percorre, dps_fim, vetor);
        intercala(inicio, meio_percorre, dps_fim, vetor);
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