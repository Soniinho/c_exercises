#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    
    return 0;
}

/* exemplo 1
    int lin, col, x = 1;
        int m[3][3]; //declaração de matriz

        for (lin = 0; lin < 3; lin++)
        {
            for (col = 0; col < 3; col++)
            {
                m[lin][col] = x;
                x++;
                //*   ++x; //incrementa na linha de uso
                //*   x++; //incrementa na prox linha de cod
            }
        }

        for (lin = 0; lin < 3; lin++)
        {
            for (col = 0; col < 3; col++)
            {
                printf("%d, ", m[lin][col]);
            }
            printf("\n");
        }
*/

/* ex 1
#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j;
    float m[3][5], x = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            m[i][j] = x;
            x += 0.5;
        }
    }

    printf("Matriz a seguir:\n");
    for (i = 0; i < 3; i++)
    {
        printf("| ");
        for (j = 0; j < 5; j++)
        {
            printf("%.1f | ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

/* ex 2 mas ta feio
#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j, linha, coluna;
    float x = 0;

    do
    {
        printf("Digite um valor entre 2 a 5 para ser as linhas da matriz: ");
        scanf("%d%*c", &linha);
        if (linha < 2 || linha > 5)
        {
            printf("Número inválido, digite novamente.\n");
        }
    } while (linha < 2 || linha > 5);

    printf("\n");
    
    do
    {
        printf("Digite um valor entre 2 a 5 para ser as colunas da matriz: ");
        scanf("%d%*c", &coluna);
        if (coluna < 2 || coluna > 5)
        {
            printf("Número inválido, digite novamente.\n");
        }
    } while (coluna < 2 || coluna > 5);

    system("cls");
    float m[linha][coluna]; //definir a matriz, mas ta feio

    //preencher a matriz
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            m[i][j] = x;
            x += 0.5;
        }
    }

    printf("Matriz resultante é:\n");
    for (i = 0; i < linha; i++)
    {
        printf("| ");
        for (j = 0; j < coluna; j++)
        {
            printf("%.1f | ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

/* exemp 3
    int l, c;
    int a[3][3];

    printf("Digite 9 números:\n");
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            scanf("%d%*c", &a[l][c]);
        }
    }

    system("cls");
    printf("\nPares e suas posições:\n");
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (a[l][c] % 2 == 0)
            {
                printf("Valor:[%d] e Posição:(%d, %d)\n", a[l][c], l, c);
            }
        }
    }

    printf("\nÍmpares e suas posições:\n");
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (a[l][c] % 2 != 0)
            {
                printf("Valor:[%d] e Posição:(%d, %d)\n", a[l][c], l, c);
            }
        }
    }

*/

/* exemp 4
    int l, c;
    char letras[3][3];

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            scanf("%c%*c", &letras[l][c]);
        }
    }

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if ((letras[l][c] == 'x') || (letras[l][c] == '0'))
            {
                printf("[%c] (%c, %c)\n", letras[l][c]);
            }
            //printf("\n%c", letras[l][c]);
        }
    }

*/
