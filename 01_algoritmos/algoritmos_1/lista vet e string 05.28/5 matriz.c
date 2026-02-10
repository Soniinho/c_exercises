#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>
#define N 10

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    char produtos[N][30];
    int cod_prod[N];
    float preco_prod[N];

    for (i = 0; i < N; i++)
    {
        printf("Nome do %dº produto: ", i + 1);
        fgets(produtos[i], 30, stdin);
        produtos[i][strlen(produtos[i]) - 1] = 0;

        printf("Digite o código deste produto: ");
        scanf("%d%*c", &cod_prod[i]);

        printf("Digite o preço deste produto: ");
        scanf("%f%*c", &preco_prod[i]);
        printf("\n");
    }

    for (i = 0; i < N; i++)
    {
        if (cod_prod[i] % 2 == 0 && preco_prod[i] > 1000)
        {
            preco_prod[i] += 0.2 * preco_prod[i];
        }
        else if (cod_prod[i] % 2 == 0)
        {
            preco_prod[i] += 0.15 * preco_prod[i];
        }
        else if (preco_prod[i] > 1000)
        {
            preco_prod[i] += 0.1 * preco_prod[i];
        }
    }
    system("cls");

    for (i = 0; i < N; i++)
    {
        printf("[%dº]\nNome: %s\nCódigo: %d\nPreço: %.2f\n\n", i + 1, produtos[i], cod_prod[i], preco_prod[i]);
    }

    return 0;
}