//ex 2

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j;
    int vet[10];

    for (i = 0, j = 1; i < 10; i++, j += 2)
    {
        vet[i] = j;
    }

    for (i = 0; i < 10; i++)
    {
        printf("[%d]\t  =  %d\n", i, vet[i]);
    }

    return 0;
}

/* //jeito complicado de idiota
    j = 0;
    for (i = 0; i < 10; i++) //preencher o vetor
    {
        while (1) //rodar enquanto não preencher a posição do vetor
        {
            if (j % 2 != 0)
            {
                vet[i] = j;
                j++;
                break;
            }
            j++;
        }
    }
*/