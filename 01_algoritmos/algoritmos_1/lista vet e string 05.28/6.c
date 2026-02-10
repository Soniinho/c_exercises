#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

/*  
    O primeiro vetor resultante será composto pela soma de cada número par 
    do primeiro vetor somado a todos os números do segundo vetor.
    
    O segundo vetor resultante será composto pela quantidade de divisores que cada número 
    ímpar do primeiro vetor tem no segundo vetor.
*/

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, j, k, l;                 //variável auxiliar de loop
    int num_1[10], num_2[5];        //vetores iniciais
    int result_1[10], result_2[10]; //vetores resutantes
    int aux_soma_num2;              //resultado da soma dos valores do vetor num_2

    printf("Será pedido para digitar 10 números para um vetor.\n");
    for (i = 0; i < 10; i++)
    {
        printf("%dº número: ", i + 1);
        scanf("%d%*c", &num_1[i]);
    }

    printf("\nSerá pedido para digitar 5 números para outro vetor.\n");
    for (i = 0; i < 5; i++)
    {
        printf("%dº número: ", i + 1);
        scanf("%d%*c", &num_2[i]);
    }

    //criar o valor auxiliar do vetor num_2
    for (i = 0, aux_soma_num2 = 0; i < 5; i++)
    {
        aux_soma_num2 += num_2[i];
    }

    //primeiro vetor resultante
    i = 0;
    j = 0; //variável aux do 1° vet resultante
    while (i < 10)
    {
        if (num_1[i] % 2 == 0)
        {
            result_1[j] = num_1[i]+ aux_soma_num2;
            j++;
        }
        i++;
    }

    //zerar o vetor resultante 2
    for (i = 0; i < 10; i++)
    {
        result_2[i] = 0;
    }

    //segundo vetor resultante
    i = 0;
    k = 0; //variável aux do 2° vet resultante
    while (i < 10)
    {
        if (num_1[i] % 2 != 0)
        {
            for (l = 0; l < 5; l++)
            {
                if (num_1[i] % num_2[l] == 0)
                {
                    result_2[k]++;                    
                }
            }
            k++;
        }
        i++;
    }

    printf("\nO 1º vetor resultante é:\n");
    for (i = 0; i < j; i++)
    {
        printf("[%d]: %d\n", i, result_1[i]);
    }
    printf("\nO 2º vetor resultante é:\n");
    for (i = 0; i < k; i++)
    {
        printf("[%d]: %d\n", i, result_2[i]);
    }

    return 0;
}