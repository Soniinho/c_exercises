//ex 3

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define V 16

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j;
    float vet[V], aux1, aux2;

    for (i = 0; i < V; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%f%*c", &vet[i]);
        //vet[i] = i;
    }

    for (i = 0, j = (V / 2); i < (V / 2); i++, j++)
    {
        aux1 = vet[i];
        aux2 = vet[j];

        vet[j] = aux1;
        vet[i] = aux2;
    }

    system("cls");

    for (i = 0; i < V; i++)
    {
        printf("Vetor[%d]\t= %.2f\n", i, vet[i]);
    }

    return 0;
}

/*
    for (i = 0; i < (V/2); i++)
    {
        aux1 = vet[i];        
        vet[i] = vet[i + (V / 2)];
        vet[i + (V / 2)] = aux1;        
    }
*/

/*
    for (i = 0, j = (V - 1); i < (V / 2); i++, j--) //se rodar as 16 vezes ele volta cm tava antes
    {
        aux1 = vet[i];
        aux2 = vet[j];

        vet[i] = aux2;
        vet[j] = aux1;
    }
*/