//ex 8

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    float vet[10];

    for (i = 0; i < 10; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%f%*c", &vet[i]);
    }

    for (i = 1; i < 10; i++)
    {
        vet[i] += vet[i - 1];
    }

    system("cls");

    printf("\nO vetor será:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%.2f\n", vet[i]);
    }

    return 0;
}

/*
    int j;
    /for (i = 1; i < 10; i++)
    {
        for (j = i; j >= 0; j--)
        {
            vet[i] += vet[j];
        }
    }
*/