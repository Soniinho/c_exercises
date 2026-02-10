#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define L 15 //15 10
#define P 10

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, j;
    int logica[L], prog[P];
    int qtd_igual = 0;

    printf("Digite as matrículas dos alunos de Lógica:\n");
    for (i = 0; i < L; i++)
    {
        printf("%d°: ", i + 1);
        scanf("%d%*c", &logica[i]);
    }

    printf("\nDigite as matrículas dos alunos de Linguagem de Programação:\n");
    for (i = 0; i < P; i++)
    {
        printf("%d°: ", i + 1);
        scanf("%d%*c", &prog[i]);
    }

    for (j = 0; j < P; j++)
    {
        i = 0;
        while (logica[i] != prog[j] && i < L)
        {
            i++;
        }
        if (i < L)
        {
            qtd_igual++;
        }
    }

    printf("\n");
    printf("Há %d alunos cursando as 2 diciplinas.", qtd_igual);
    return 0;
}