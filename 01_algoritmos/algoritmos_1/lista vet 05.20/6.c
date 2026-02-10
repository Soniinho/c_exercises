//ex 6

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define V 40

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    float vet[V];

    for (i = 0; i < V; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%f%*c", &vet[i]);
    }

    for (i = 0; i < V; i++)
    {
        if (vet[i] < 0)
        {
            vet[i] = 0;
        }
    }

    system("cls");
    printf("O novo vetor será:\n");

    for (i = 0; i < V; i++)
    {
        printf("[%d]\t= %.2f\n", i, vet[i]);
    }

    return 0;
}