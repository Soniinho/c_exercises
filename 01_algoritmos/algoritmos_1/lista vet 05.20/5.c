//ex 5

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define V 40

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    int vet[V], qtd = 0;

    for (i = 0; i < V; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%d%*c", &vet[i]);
    }

    for (i = 0; i < V; i++)
    {
        if (vet[i] % 2 == 0)
        {
            qtd++;
        }
    }

    printf("\nHá %d números pares no vetor.", qtd);
    return 0;
}