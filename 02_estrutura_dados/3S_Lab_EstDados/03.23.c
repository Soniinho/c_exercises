#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int retorna_mm(float *vetor, int tam_vet, float *maior, float *menor);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, tam;
    float *vetor = NULL, maior, menor;

    printf("Digite o tamanho de um vetor: ");
    scanf("%d%*c", &tam);
    printf("\n");

    vetor = (float *)malloc(sizeof(float) * tam);
    if (vetor == NULL)
    {
        return 1; // retorna erro
    }

    for (i = 0; i < tam; i++)
    {
        printf("Digite um valor para posição [%d]: ", i + 1);
        scanf("%f%*c", &vetor[i]);
    }

    retorna_mm(vetor, tam, &maior, &menor);

    printf("\nO maior valor é %.2f e o menor %.2f.", maior, menor);

    free(vetor);
    return 0;
}

int retorna_mm(float *vetor, int tam_vet, float *maior, float *menor)
{
    int i;

    *maior = vetor[0];
    *menor = vetor[0];
    for (i = 1; i < tam_vet; i++)
    {
        if (*maior < vetor[i])
        {
            *maior = vetor[i];
        }
        else if (*menor > vetor[i])
        {
            *menor = vetor[i];
        }
    }

    return 0;
}
