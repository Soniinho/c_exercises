//ex 1

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    int x, y;
    float vet[12], soma;

    for (i = 0; i < 12; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%f%*c", &vet[i]);
    }

    printf("\nDigite 2 posições desejadas do vetor(entre 0 e 11):\n");
    printf("Posição 1: ");
    scanf("%d%*c", &x);
    printf("Posição 2: ");
    scanf("%d%*c", &y);

    while (x > 11 || y > 11)
    {
        if (x > 11)
        {
            printf("Digite novamente a 1ª posição desejada(entre 0 e 11): ");
            scanf("%d%*c", &x);
        }
        if (y > 11)
        {
            printf("Digite novamente a 2ª posição desejada(entre 0 e 11): ");
            scanf("%d%*c", &y);
        }
    }

    soma = vet[x] + vet[y];
    printf("A soma dos vetores nas posições %d e %d é %.2f", x, y, soma);

    return 0;
}