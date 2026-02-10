#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

//declarações
void jogo_da_velha();
char else_if(int i, int j);
char resultado();

//variáveis globais
char jogo[3][3];

void main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j, linha, coluna, validar, velha = 1;
    char jogador, vencedor;

    //preencher o jogo da velha com vazio
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            jogo[i][j] = ' ';
        }
    }

    //verificar qual jogador começa jogando
    do
    {
        printf("Digite o jogador que irá jogar primeiro (\"X\" ou \"O\"): ");
        scanf("%c%*c", &jogador);
        if (jogador != 'X' && jogador != 'O')
        {
            printf("Jogador inválido, digite novamente.\n");
        }
    } while (jogador != 'X' && jogador != 'O');

    //jogo em si
    while (velha <= 9)
    {
        //mostrar o jogo da velha
        jogo_da_velha();

        //ver a posição para por o jogador
        do
        {
            validar = 0;
            printf("Digite a posição que se quer o %c:\n", jogador);
            printf("Linha: ");
            scanf("%d%*c", &linha);
            linha -= 1; //matriz começa em 0
            printf("Coluna: ");
            scanf("%d%*c", &coluna);
            coluna -= 1; //matriz começa em 0, eu já falei isso

            if (jogo[linha][coluna] == ' ' && linha < 3 && coluna < 3)
            {
                jogo[linha][coluna] = jogador;
                if (jogador == 'X')
                {
                    jogador = 'O';
                }
                else
                {
                    jogador = 'X';
                }
            }
            else
            {
                printf("Posição inválida.\n");
                validar = 1;
            }
        } while (validar == 1);
        vencedor = resultado();
        if (vencedor == 'X' || vencedor == 'O')
        {
            jogo_da_velha();
            printf("O jogador \"%c\" ganhou o jogo.", vencedor);
            break;
        }

        velha++; //próxima rodada
    }

    //empate
    if (velha >= 10)
    {
        jogo_da_velha();
        printf("O jogo terminou em Empate.");
    }
}

void jogo_da_velha()
{
    int i, j;

    system("cls");
    printf("\t  Jogo da Velha:\n\n");

    printf("\t    1   2   3\n");
    for (i = 0; i < 3; i++)
    {
        printf("\t%d | ", i + 1);
        for (j = 0; j < 3; j++)
        {
            printf("%c | ", jogo[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

char else_if(int i, int j)
{
    if (jogo[i][j] == 'X')
    {
        return 'X';
    }
    else if (jogo[i][j] == 'O')
    {
        return 'O';
    }
    else
    {
        return 0;
    }
}

char resultado()
{
    int i, j;

    //testar diagonais
    if (jogo[0][0] != ' ' && jogo[0][0] == jogo[1][1] && jogo[0][0] == jogo[2][2])
    {
        return else_if(0, 0);
    }
    else if (jogo[0][2] != ' ' && jogo[0][2] == jogo[1][1] && jogo[0][2] == jogo[2][0])
    {
        return else_if(0, 2);
    }

    //testar resto
    for (i = 0, j = 0; i < 3; i++)
    {
        if (jogo[i][j] != ' ' && jogo[i][j] == jogo[i][j + 1] && jogo[i][j] == jogo[i][j + 2])
        {
            return else_if(i, j);
        }
        else if (jogo[j][i] != ' ' && jogo[j][i] == jogo[j + 1][i] && jogo[j][i] == jogo[j + 2][i])
        {
            return else_if(j, i);
        }
    }

    return 0;
}

/* versão sem a função else_if
//*para X ganhar
    //testar diagonais
    if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X')
    {
        return 'X';
    }
    else if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')
    {
        return 'X';
    }

    //testar resto
    for (i = 0, j = 0; i < 3; i++)
    {
        if (jogo[i][j] == 'X' && jogo[i][j + 1] == 'X' && jogo[i][j + 2] == 'X')
        {
            return 'X';
        }
        else if (jogo[i][j] == 'X' && jogo[i + 1][j] == 'X' && jogo[i + 2][j] == 'X')
        {
            return 'X';
        }
    }

    //*para O ganhar
    //testar diagonais
    if (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O')
    {
        return 'O';
    }
    else if (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O')
    {
        return 'O';
    }

    //testar resto
    for (i = 0, j = 0; i < 3; i++)
    {
        if (jogo[i][j] == 'O' && jogo[i][j + 1] == 'O' && jogo[i][j + 2] == 'O')
        {
            return 'O';
        }
        else if (jogo[i][j] == 'O' && jogo[i + 1][j] == 'O' && jogo[i + 2][j] == 'O')
        {
            return 'O';
        }
    }
*/
