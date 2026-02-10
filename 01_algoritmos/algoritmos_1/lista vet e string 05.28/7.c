#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, j;
    float A[10], B[15]; //n pd ser preenchido inteiro

    printf("Será pedido para digitar 10 valores:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%dº número: ", i + 1);
        scanf("%f%*c", &A[i]);
    }

    //n pd ser menor ou igual a 0
    for (i = 0, j = 0; i < 10; i++)
    {
        if (A[i] > 0)
        {
            B[j] = A[i];
            j++;
        }
    }

    printf("\nO vetor sem os valores menores ou iguais a 0 é:\n");
    for (i = 0; i < j; i++)
    {
        printf("[%d] = %.3f\n", i, B[i]);
    }

    return 0;
}