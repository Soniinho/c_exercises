#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");

    return 0;
}

//% Matrizes, (é muito importante)
/* 
    &   int m[3][3];       //cabe 9
    &   int b[3][3][3];    //27
    &   int c[3][3][3][3]; //cabe 3 x 3 x 3 x 3

    *   problema é que, além de difícil da manipular, tem muita variável
    *   num int[10][10][10][10], tem 10 mil variáveis

    @   para ler matriz, usa um [for] dentro de outro / uma repetição dentro da outra

    ~   na diagonal principal, o "i" e o "j" tem os mesmos valores
*/

/* //^ programa de diagonal principal e tal
    int i, j;
    int b[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d%*c", &b[i][j]);
        }
    }

    printf("\n\n");

    for (i = 0, j = 0; i < 3; i++, j++)
    {
        printf("%d ", b[i][j]);
    }

    printf("\n\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                printf("%d  ", b[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
*/

/*  //# preencher matriz bidimensional e tirar \n
    int i;
    char nome[4][100];

    for (i = 0; i < 4; i++)
    {
        printf("Digite uma frase:\n");
        fgets(nome[i], 100, stdin);

        nome[i][strlen(nome[i]) - 1] = '\0'; //@uwu
    }
*/

/*  //+matriz transposta
    int i, j, m[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            m[i][j] = i;
        }
    }

    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", m[j][i]);
        }
        printf("\n");
    }
*/
