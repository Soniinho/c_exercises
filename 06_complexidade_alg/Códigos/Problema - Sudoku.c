/* Problema:
            SUDOKU
   Solução:
            Força Bruta - usando Backtracking
*/

#include <stdio.h>
#include <stdlib.h>

int cont = 0;

// indica os valores já testados em todas as 81 celulas 9 posições cada- descarta posição 0
struct val { int x[10];
             int proximo;
           };   //indica pegar o seguinte para usar
struct val valores[10][10];

// =============================================================================
int mostra_tabul_A (int mat[10][10])
{
    int i,j;
    cont++;
    printf("-- Tentativa : %d \n",cont);
    printf("-------------------------------------------------\n");
    for (i=1;i<=9;i++)
    {
        printf("|");
        for (j=1;j<=9;j++)
        {
            printf("  %d  ",mat[i][j]);
            if (j%3==0) printf("|");
        }
        if (i%3==0)
            printf("\n-------------------------------------------------\n");
        else
            printf("\n\n");
    }
    //system("pause");
    Sleep(500);
    system("cls");
}

// =============================================================================
int mostra_tabul_B (int mat[10][10]) // nao tem pause no final
{
    int i,j;
    cont++;
    printf("-- Tentativa : %d \n",cont);
    printf("-------------------------------\n");
    for (i=1;i<=9;i++)
    {
        printf("|");
        for (j=1;j<=9;j++)
        {
            printf(" %d ",mat[i][j]);
            if (j%3==0) printf("|");
        }
        if (i%3==0)
            printf("\n-------------------------------\n");
        else
            printf("\n");
    }
}

// =============================================================================
int testa_linha (int mat[10][10], int linha, int valor)
{
    int i;
    for (i=1;i<=9;i++)
        if (mat[linha][i]==valor)
            return 1;               // encontrado valor ja colocado na linha
    return 0;                       // não encontrado
}

// =============================================================================
int testa_coluna (int mat[10][10], int coluna, int valor)
{
    int i;
    for (i=1;i<=9;i++)
        if (mat[i][coluna]==valor)
            return 1;               // encontrado valor ja colocado na coluna
    return 0;                       // não encontrado
}

// =============================================================================
int testa_quadrante (int mat[10][10],int li_sup_esq, int col_sup_esq, int valor)
{
    int i,j;
    for (i=0;i<=2;i++)
        for (j=0;j<=2;j++)
        if (mat[li_sup_esq+i][col_sup_esq+j]==valor)
            return 1;               // encontrado valor ja colocado no quadrante
    return 0;                       // não encontrado
}

// =============================================================================
int escolhe_valor (struct val valores[10][10], int linha, int coluna)
{
    int i,usados=0;  // valores já usados
    int proximo;

    proximo = valores[linha][coluna].proximo;
    for (i=1;i<=9;i++) if (valores[linha][coluna].x[i]!=0) usados++;
    if (usados==9) return 30;
    while (1)
    {   proximo++;
        if (proximo == 10)
        {
             proximo=1;
             valores[linha][coluna].proximo = 1;
        }
        if (valores[linha][coluna].x[proximo]==0)
        {
            //valores[linha][coluna].x[proximo]=1;
            valores[linha][coluna].proximo = proximo;
            return proximo;
        }
    }
    return 10;  // todos usados
}

// =============================================================================
int jogar (int mat[10][10], int mat_fix[10][10],int linha, int coluna)
{
    int i,resp,v,resp_linha, resp_coluna, resp_quadrante, valor;
    int linha_atual=linha, coluna_atual=coluna, passos = 1;

    // ESCOLHE 1o. VALOR
    valor = escolhe_valor (valores,linha,coluna);
    //printf("Escolhido (li=%d co=%d): v=%d\n",linha, coluna, valor); system("pause");
    while (passos < 10)
    {
        // VALIDA VALOR NA POSIÇÃO
        resp_linha = testa_linha (mat,linha_atual, valor);
        resp_coluna = testa_coluna (mat,coluna_atual, valor);
        // testando no quadrante especifico da posição enviada
        if ((linha_atual>=1)&&(linha_atual<=3)&&(coluna_atual>=1)&&(coluna_atual<=3) )
            resp_quadrante = testa_quadrante (mat,1,1, valor);
        if ((linha_atual>=4)&&(linha_atual<=6)&&(coluna_atual>=1)&&(coluna_atual<=3) )
            resp_quadrante = testa_quadrante (mat,4,1, valor);
        if ((linha_atual>=7)&&(linha_atual<=9)&&(coluna_atual>=1)&&(coluna_atual<=3) )
            resp_quadrante = testa_quadrante (mat,7,1, valor);
        if ((linha_atual>=1)&&(linha_atual<=3)&&(coluna_atual>=4)&&(coluna_atual<=6) )
            resp_quadrante = testa_quadrante (mat,1,4, valor);
        if ((linha_atual>=4)&&(linha_atual<=6)&&(coluna_atual>=4)&&(coluna_atual<=6) )
            resp_quadrante = testa_quadrante (mat,4,4, valor);
        if ((linha_atual>=7)&&(linha_atual<=9)&&(coluna_atual>=4)&&(coluna_atual<=6) )
            resp_quadrante = testa_quadrante (mat,7,4, valor);
        if ((linha_atual>=1)&&(linha_atual<=3)&&(coluna_atual>=7)&&(coluna_atual<=9) )
            resp_quadrante = testa_quadrante (mat,1,7, valor);
        if ((linha_atual>=4)&&(linha_atual<=6)&&(coluna_atual>=7)&&(coluna_atual<=9) )
            resp_quadrante = testa_quadrante (mat,4,7, valor);
        if ((linha_atual>=7)&&(linha_atual<=9)&&(coluna_atual>=7)&&(coluna_atual<=9) )
            resp_quadrante = testa_quadrante (mat,7,7, valor);

        // COLOCAR VALOR NO TABULEIRO
        if ((resp_linha==0)&&(resp_coluna==0)&&(resp_quadrante==0)) // nao encontrado impedimento para colocação
        {
            mat[linha_atual][coluna_atual] = valor;   // atribui valor no tabuleiro
            valores[linha_atual][coluna_atual].x[valor]=1;
            mostra_tabul_A(mat);
            // avança para próximo local
            coluna=coluna_atual + 1;
            if (coluna==10)
            {
                linha = linha_atual+1;
                coluna=1;
            }
            if (linha == 10) return 0;  // fim de jogo
            if  (mat_fix[linha][coluna]==0)
                resp = jogar (mat,mat_fix,linha, coluna);    // pode jogar na posição seguinte
            else
            {   // avança mais uma posição
                coluna=coluna + 1;
                if (coluna==10)
                {
                   linha = linha+1;
                   coluna=1;
                }
                if (linha == 10) return 0;  // fim de jogo
                resp = jogar (mat, mat_fix,linha, coluna);    // jogar na posição  seguinte
            }
            if (resp == 20)   // não conseguiu fazer a jogada seguinte
            {
                // desfaz a jogada atual
                mat[linha_atual][coluna_atual] = 0;   // desfaz atribução de valor no tabuleiro
                valores[linha_atual][coluna_atual].x[valor]=0;   // desfaça a indicação de uso do valor
                //printf("Desfazendo ..\n"); system("pause"); mostra_tabul(mat);  // mostra desfazer
            }
            else
                return 0;
        }
        // ESCOLHE novo VALOR
        valor = escolhe_valor (valores,linha_atual,coluna_atual);
        //printf("Escolhido (li=%d co=%d): v=%d\n",linha, coluna, valor); system("pause");
        passos++;
    }
    return 20;   // nao conseguiu colocar nenhum valor na posição
}

// =============================================================================
int inicializa ()
{
    int i,j,z;
    for (i=1;i<=9;i++)
      for (z=1;z<=9;z++)
      {
        valores[i][z].proximo=0;
        for (j=1;j<=9;j++)
           valores[i][z].x[j]=0;
      }
    return 0;
}

// =============================================================================
void main()
{
    // matriz dos indicando locais de valores fixos de inicio do jogo
    // 1 indica que naquela posição o valor nao pode ser alterado pelas jogadas
    // desconsiderar 1a linha e 1a. coluna
    int mat_fix[10][10] =
                { //  1 2 3 4 5 6 7 8 9
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,    // 1
                    0,0,0,0,0,0,0,0,0,0,    // 2
                    0,0,0,0,0,0,0,0,0,0,    // 3
                    0,0,0,0,0,0,0,0,0,0,    // 4
                    0,0,0,0,0,0,0,0,0,0,    // 5
                    0,0,0,0,0,0,0,0,0,0,    // 6
                    0,0,0,0,0,0,0,0,1,0,    // 7
                    0,1,0,0,0,0,0,0,0,0,    // 8
                    0,0,0,0,0,0,0,0,0,0,    // 9
                };
    // matriz do tabuleiro do jogo
    // desconsiderar 1a linha e 1a. coluna
    // 1. CUIDADO PARA DEIXAR AS DUPLAS MATRIZES CONSISTENTE:
    // ONDE TIVER 1 NA "MAT_FIX" TEVE TER UM VALOR NA "MAT"
    // 2. CUIDADO PAA ATRIBUIR VALORES FIXOS QUE TENHAM SOLUÇÃO NO JOGO
    int mat[10][10] =
                { //  1 2 3 4 5 6 7 8 9
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,    // 1
                    0,0,0,0,0,0,0,0,0,0,    // 2
                    0,0,0,0,0,0,0,0,0,0,    // 3
                    0,0,0,0,0,0,0,0,0,0,    // 4
                    0,0,0,0,0,0,0,0,0,0,    // 5
                    0,0,0,0,0,0,0,0,0,0,    // 6
                    0,0,0,0,0,0,0,0,9,0,    // 7
                    0,8,0,0,0,0,0,0,0,0,    // 8
                    0,0,0,0,0,0,0,0,0,0,    // 9
                };
    int linha_ini=1, coluna_ini=1;

    inicializa ();
    printf("Inicial\n");
    mostra_tabul_B(mat);
    system ("pause");

    // Estratégia usada:
    //    - partir da celula[1;1];
    //    - processando  todas colunas desta linha
    //    - mudar de linha e repetir o procedimento de processar todas as colunas
    jogar(mat, mat_fix,linha_ini,coluna_ini);

    printf("Final\n");
    mostra_tabul_B(mat);
    system ("pause");
}
