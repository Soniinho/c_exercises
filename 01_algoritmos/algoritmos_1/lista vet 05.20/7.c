//ex 7

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j, k;
    int vet1[6], vet2[6], vet3[12];

    printf("Primeiro vetor:\n");
    for (i = 0; i < 6; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%d%*c", &vet1[i]);
    }

    printf("\nSegundo vetor:\n");
    for (i = 0; i < 6; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%d%*c", &vet2[i]);
    }

    for (i = 0, j = 0, k = 0; i < 12; i++)
    {
        if (i % 2 == 0)
        {
            vet3[i] = vet1[j];
            j++;
        }
        else
        {
            vet3[i] = vet2[k];
            k++;
        }
    }

    system("cls");

    printf("O novo vetor será:\n");
    for (i = 0; i < 12; i++)
    {
        printf("%d\n", vet3[i]);
    }

    return 0;
}