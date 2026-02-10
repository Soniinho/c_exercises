#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int vet[16], i, aux;

    for (i = 0; i < 16; i++)
    {
        vet[i] = i;
    }

    for (i = 0; i < 8; i++)
    {
        aux = vet[i];
        vet[i] = vet[i + 8];
        vet[i + 8] = aux;
    }
    
    printf("\n\n");
    for (i = 0; i < 16; i++)
    {
        printf("%d\n", vet[i]);
    }

    return 0;
}