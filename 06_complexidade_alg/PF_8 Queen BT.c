#include <stdio.h>
#include <stdlib.h>

// =========================================== imprime nao solucao em Backtracking
void ImprimeNaoSolucao_BT(int linhas[], int k)
{
    char tabuleiro[8][8];
    int i, j;
    int x, y;
    static int nsols = 0;

    nsols++;
    system("cls");

    printf("\n******** TENTATIVA: %d \n\n", nsols);

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            tabuleiro[i][j] = '.';

    for (i = 0; i <= k; i++)
    {
        x = i;
        y = linhas[i];
        tabuleiro[y][x] = 'R';
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("  %c  ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
    // Sleep(50);
}

// ============================================ imprime solução
void ImprimeSolucao(int linhas[])
{
    char tabuleiro[8][8];
    int i, j;
    int x, y;
    static int nsols = 0;

    nsols++;

    system("cls");
    printf("\n******** Solucao: %d \n\n", nsols);

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            tabuleiro[i][j] = '.';

    for (i = 0; i < 8; i++)
    {
        x = i;
        y = linhas[i];
        tabuleiro[y][x] = 'R';
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("  %c  ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
    system("pause");
}

int valida(int k, int rainhas[])
{

    int i;
    for (i = 0; i < k; i++)
        /* se duas rainhas na mesma coluna ou duas rainhas na mesma diagonal  */
        if ((rainhas[i] == rainhas[k]) || (k - i == abs(rainhas[i] - rainhas[k]))) //absoluto
            return 0; /* solução invalida */
    return 1;         /* solução valida */
}

void nRainhas(int k, int n, int rainhas[])
{
    int i;
    if (k == n) /* solução completa */ 
        ImprimeSolucao(rainhas);
    else
        /* posiciona a rainha k + 1 */
        for (i = 0; i < n; i++)
        {
            rainhas[k] = i; //v[i][k]
            if (valida(k, rainhas))
                nRainhas(k + 1, n, rainhas);
            ImprimeNaoSolucao_BT(rainhas, k);
        }
}

void Solucoes8Rainhas_BT()
{ /* BT - Backtracking */
    int linhas[8];
    int i;
    // inicializa posicao das rainhas - um cada linha
    for (i = 0; i < 8; i++)
        linhas[i] = i;
    /*
    ImprimeNaoSolucao_BT(linhas, 7);
    system("pause");
    */
    nRainhas(0, 8, linhas);
}

void main()
{
    Solucoes8Rainhas_BT(); // backtracking
}
