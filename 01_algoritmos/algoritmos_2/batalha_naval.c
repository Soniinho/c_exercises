/*------------------------------------------------------------//
    Por Aline e Matheus:

    Aline da Silva Zuquer de Carvalho RA: 202010393
    Matheus Henrique Daltroso         RA: 202110059
--------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //acento
#include <string.h> //string
#include <unistd.h> //getpid
#include <time.h>   //pegar o horário do pc

void opc();
char opc_dig();
void tabuleiro(int tam_matriz, char (*jogo_player)[tam_matriz], char (*jogo_pc)[tam_matriz]);
void esc_pl_tela(int tam_matriz, char (*jogo_player_hide)[tam_matriz]);
void esc_pl(int tam_matriz, char (*jogo_player_hide)[tam_matriz]);
void esc_pc(int tam_matriz, char (*jogo_pc_hide)[tam_matriz]);
int vez_player(int tam_matriz, char (*jogo_player)[tam_matriz], char (*jogo_pc)[tam_matriz], char (*jogo_pc_hide)[tam_matriz]);
int vez_pc(int tam_matriz, char (*jogo_player)[tam_matriz], char (*jogo_pc)[tam_matriz], char (*jogo_player_hide)[tam_matriz]);
int derrubar_bichinho(int tam_matriz, char (*jogo_hide)[tam_matriz], int player_pc, int *navio, int *porta, int *hidro);
void rank(int vit1, int vit2);

struct Jogadores
{
    char nick[20];
};

int main()
{
    int i, j, tam_matriz, newgame, vitoria_player = 0, vitoria_pc = 0;
    char esc_tabule, esc_start, ganhar;

    setlocale(LC_ALL, "portuguese");

    do
    {
        int navio_0 = 2, porta_0 = 1, hidro_0 = 2, navio_1 = 2, porta_1 = 1, hidro_1 = 2;
        srand(getpid()); //seed pra iniciar //srand((unsigned)time(NULL));
        system("cls");
        opc();
        esc_tabule = opc_dig();
        if (esc_tabule == '1')
        {
            tam_matriz = 10;
        }
        else if (esc_tabule == '2')
        {
            tam_matriz = 15;
        }
        else
        {
            printf("Tenha um bom dia!");
            printf("Feito por Aline Zuquer e Matheus Daltroso.");
            return 0;
        }
        char jogo_player[tam_matriz][tam_matriz], jogo_pc[tam_matriz][tam_matriz];
        char jogo_pc_hide[tam_matriz][tam_matriz], jogo_player_hide[tam_matriz][tam_matriz];

        for (i = 0; i < tam_matriz; i++) //preencher as matrizes com nd
        {
            for (j = 0; j < tam_matriz; j++)
            {
                jogo_player[i][j] = 'O';
                jogo_pc[i][j] = 'O';

                jogo_pc_hide[i][j] = 'O';
                jogo_player_hide[i][j] = ' ';
            }
        }

        //pc escolher
        esc_pc(tam_matriz, jogo_pc_hide);
        //player escolher
        esc_pl(tam_matriz, jogo_player_hide);
        system("pause");
        system("cls");

        ganhar = 0;
        esc_start = rand() % 2; //escolher quem começa

        while (ganhar == 0) //até terminar o jogo
        {
            if (esc_start == 0) //player
            {
                esc_start = vez_player(tam_matriz, jogo_player, jogo_pc, jogo_pc_hide);
                ganhar = derrubar_bichinho(tam_matriz, jogo_pc_hide, esc_start, &navio_0, &porta_0, &hidro_0);
            }
            else //pc
            {
                esc_start = vez_pc(tam_matriz, jogo_player, jogo_pc, jogo_player_hide);
                ganhar = derrubar_bichinho(tam_matriz, jogo_player_hide, esc_start, &navio_1, &porta_1, &hidro_1);
            }
        }

        if (ganhar == 1)
        {
            vitoria_player++;
        }
        else if (ganhar == 2)
        {
            vitoria_pc++;
        }

        printf("\n Deseja jogar Novamente?\n");
        printf("1) Continuar\n");
        printf("2) Sair\n\n");
        scanf("%d%*c", &newgame);
        if (newgame != 1 && newgame != 2)
        {
            printf("Opção inválida. Digite novamente: ");
            scanf("%d%*c", &newgame);
        }
    } while (newgame == 1);
    rank(vitoria_player, vitoria_pc);

    system("pause");
    return 0;
}

void opc()
{
    printf("\t\tBatalha Naval\n");

    printf("Escolha uma das opções abaixo para o tabuleiro:\n");
    printf("1) 10x10\n");
    printf("2) 15x15\n");
    printf("3) sair\n\n");
}

char opc_dig()
{
    char opcao;
    scanf("%c%*c", &opcao);
    while (opcao != '1' && opcao != '2' && opcao != '3')
    {
        printf("Opção inválida. Escolhe entre as 2 opções acima:\n");
        scanf("%c%*c", &opcao);
    }
    return opcao;
}

void tabuleiro(int tam_matriz, char (*jogo_player)[tam_matriz], char (*jogo_pc)[tam_matriz])
{
    int i, j;

    system("cls");

    if (tam_matriz == 10)
    {
        printf("\t\t\t\t\t    Batalha Naval\n\n");
        printf("\t\t          Player                        \t\t Pc\n\n");
        printf("\t        1  2  3  4  5  6  7  8  9 10\t\t    1  2  3  4  5  6  7  8  9 10\n");
    }
    else
    {
        printf("\t\t\t\t\t\t\t    Batalha Naval\n\n");
        printf("\t\t                  Player                                   \t\t\t Pc\n\n"); //todo: arrumar tabulação
        printf("\t       1  2  3  4  5  6  7  8  9  10 11 12 13 14 15");
        printf("\t\t   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
    }
    for (i = 0; i < tam_matriz; i++)
    {
        printf("\t    %2.d  ", i + 1);
        for (j = 0; j < tam_matriz; j++)
        {
            printf("%c  ", jogo_player[i][j]);
        }

        printf("\t\t");
        printf("%2.d  ", i + 1);
        for (j = 0; j < tam_matriz; j++)
        {
            printf("%c  ", jogo_pc[i][j]);
        }

        printf("\n");
    }
}

void esc_pc(int tam_matriz, char (*jogo_pc_hide)[tam_matriz])
{
    int i, j;
    int linha, coluna, cima_baixo, navio = 0, porta = 0, hidro = 0;

    //$ navio
    do
    {
        linha = 2 + (rand() % (tam_matriz - 3)); //escolher entre 2 e 7
        coluna = 2 + (rand() % (tam_matriz - 3));

        if (jogo_pc_hide[linha][coluna] == 'O') //checar se a posição ta vazia
        {
            cima_baixo = rand() % 2; //0 vertical, 1 horizontal

            if (cima_baixo == 0) //vertical
            {
                if (jogo_pc_hide[linha - 1][coluna] == 'O' && jogo_pc_hide[linha + 1][coluna] == 'O') //checar se a posição para o navio está vazia
                {
                    jogo_pc_hide[linha - 1][coluna] = 'N';
                    jogo_pc_hide[linha][coluna] = 'N';
                    jogo_pc_hide[linha + 1][coluna] = 'N';
                    navio++;
                }
            }
            else //horizontal
            {
                if (jogo_pc_hide[linha][coluna - 1] == 'O' && jogo_pc_hide[linha][coluna + 1] == 'O') //checar se a posição para o navio está vazia
                {
                    jogo_pc_hide[linha][coluna - 1] = 'N';
                    jogo_pc_hide[linha][coluna] = 'N';
                    jogo_pc_hide[linha][coluna + 1] = 'N';
                    navio++;
                }
            }
        }
    } while (navio < 2);

    //$ porta avião
    do
    {
        linha = 2 + (rand() % (tam_matriz - 3));
        coluna = 2 + (rand() % (tam_matriz - 3));

        if (jogo_pc_hide[linha][coluna] == 'O') //checar se a posição ta vazia
        {
            cima_baixo = rand() % 2; //0 vertical, 1 horizontal

            if (cima_baixo == 0) //vertical
            {
                if (jogo_pc_hide[linha - 1][coluna] == 'O' && jogo_pc_hide[linha + 1][coluna] == 'O' && jogo_pc_hide[linha + 2][coluna] == 'O')
                {
                    jogo_pc_hide[linha - 1][coluna] = 'P';
                    jogo_pc_hide[linha][coluna] = 'P';
                    jogo_pc_hide[linha + 1][coluna] = 'P';
                    jogo_pc_hide[linha + 2][coluna] = 'P';
                    porta++;
                }
            }
            else //horizontal
            {
                if (jogo_pc_hide[linha][coluna - 1] == 'O' && jogo_pc_hide[linha][coluna + 1] == 'O' && jogo_pc_hide[linha][coluna + 2] == 'O')
                {
                    jogo_pc_hide[linha][coluna - 1] = 'P';
                    jogo_pc_hide[linha][coluna] = 'P';
                    jogo_pc_hide[linha][coluna + 1] = 'P';
                    jogo_pc_hide[linha][coluna + 2] = 'P';
                    porta++;
                }
            }
        }
    } while (porta < 1);

    //$ hidroavião
    do
    {
        linha = 2 + (rand() % (tam_matriz - 3));
        coluna = 2 + (rand() % (tam_matriz - 3));

        if (jogo_pc_hide[linha][coluna] == 'O') //checar se a posição ta vazia
        {
            cima_baixo = rand() % 2; //0 vertical, 1 horizontal

            if (cima_baixo == 0) //vertical
            {
                if (jogo_pc_hide[linha - 1][coluna] == 'O' && jogo_pc_hide[linha + 1][coluna] == 'O' && jogo_pc_hide[linha - 1][coluna - 1] == 'O' && jogo_pc_hide[linha][coluna - 1] == 'O' && jogo_pc_hide[linha + 1][coluna - 1] == 'O')
                {
                    jogo_pc_hide[linha - 1][coluna] = 'H';
                    jogo_pc_hide[linha][coluna] = '-';
                    jogo_pc_hide[linha + 1][coluna] = 'H';

                    jogo_pc_hide[linha - 1][coluna - 1] = '-';
                    jogo_pc_hide[linha][coluna - 1] = 'H';
                    jogo_pc_hide[linha + 1][coluna - 1] = '-';
                    hidro++;
                }
            }
            else //horizontal
            {
                if (jogo_pc_hide[linha][coluna - 1] == 'O' && jogo_pc_hide[linha][coluna + 1] == 'O' && jogo_pc_hide[linha - 1][coluna - 1] == 'O' && jogo_pc_hide[linha - 1][coluna] == 'O' && jogo_pc_hide[linha - 1][coluna + 1] == 'O')
                {
                    jogo_pc_hide[linha][coluna - 1] = 'H';
                    jogo_pc_hide[linha][coluna] = '-';
                    jogo_pc_hide[linha][coluna + 1] = 'H';

                    jogo_pc_hide[linha - 1][coluna - 1] = '-';
                    jogo_pc_hide[linha - 1][coluna] = 'H';
                    jogo_pc_hide[linha - 1][coluna + 1] = '-';
                    hidro++;
                }
            }
        }
    } while (hidro < 2);
}

void esc_pl_tela(int tam_matriz, char (*jogo_player_hide)[tam_matriz]) //tela para por os navios
{
    int i, j;
    system("cls");
    printf("\t\t\t\t\t    Batalha Naval\n\n");
    if (tam_matriz == 10)
    {
        printf("\t\t\t            1  2  3  4  5  6  7  8  9 10\n");

        for (i = 0; i < tam_matriz; i++)
        {
            printf("\t\t\t        %2.d  ", i + 1);
            for (j = 0; j < tam_matriz; j++)
            {
                printf("%c  ", jogo_player_hide[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("\t\t            1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
        for (i = 0; i < tam_matriz; i++)
        {
            printf("\t\t        %2.d  ", i + 1);
            for (j = 0; j < tam_matriz; j++)
            {
                printf("%c  ", jogo_player_hide[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void esc_pl(int tam_matriz, char (*jogo_player_hide)[tam_matriz])
{
    int i, j, k;
    int por_l, por_c;
    char h_ou_v;

    for (k = 0; k < 2; k++) //@ navio
    {
        esc_pl_tela(tam_matriz, jogo_player_hide);

        printf("Escolha a posição para colocar um Navio (3 casas -> [1 2 3]):\n");

        do
        {
            printf("H para horizontal ou V para vertical: ");
            scanf("%c%*c", &h_ou_v);
        } while (h_ou_v != 'H' && h_ou_v != 'V');
        if (h_ou_v == 'H') //horizontal
        {
            do
            {
                do
                {
                    printf("Casa do centro do navio (linha): ");
                    scanf("%d%*c", &por_l);
                    printf("Casa do centro do navio (coluna): ");
                    scanf("%d%*c", &por_c);
                    por_l--;
                    por_c--;
                    if (por_c < 1 || por_c > tam_matriz - 2 || por_l < 0 || por_l > tam_matriz - 1) //checar se está dentro da matriz e se pode
                    {
                        printf("Posição inválida.\n");
                    }
                } while (por_c < 1 || por_c > tam_matriz - 2 || por_l < 0 || por_l > tam_matriz - 1);
                if (jogo_player_hide[por_l][por_c] == 'N' || jogo_player_hide[por_l][por_c - 1] == 'N' || jogo_player_hide[por_l][por_c + 1] == 'N') //checar se ja tem algo no lugar
                {
                    printf("Posição Ocupada.\n");
                }
            } while (jogo_player_hide[por_l][por_c] == 'N' || jogo_player_hide[por_l][por_c - 1] == 'N' || jogo_player_hide[por_l][por_c + 1] == 'N');

            jogo_player_hide[por_l][por_c] = 'N';
            jogo_player_hide[por_l][por_c - 1] = 'N';
            jogo_player_hide[por_l][por_c + 1] = 'N';
        }
        else //vertical
        {
            do
            {
                do
                {
                    printf("Casa do centro do navio (linha): ");
                    scanf("%d%*c", &por_l);
                    printf("Casa do centro do navio (coluna): ");
                    scanf("%d%*c", &por_c);
                    por_l--;
                    por_c--;
                    if (por_c < 0 || por_c > tam_matriz - 1 || por_l < 1 || por_l > tam_matriz - 2) //checar se está dentro da matriz e se pode
                    {
                        printf("Posição inválida.\n");
                    }
                } while (por_c < 0 || por_c > tam_matriz - 1 || por_l < 1 || por_l > tam_matriz - 2);
                if (jogo_player_hide[por_l][por_c] == 'N' || jogo_player_hide[por_l - 1][por_c] == 'N' || jogo_player_hide[por_l + 1][por_c] == 'N') //checar se ja tem algo no lugar
                {
                    printf("Posição Ocupada.\n");
                }
            } while (jogo_player_hide[por_l][por_c] == 'N' || jogo_player_hide[por_l - 1][por_c] == 'N' || jogo_player_hide[por_l + 1][por_c] == 'N');
            jogo_player_hide[por_l][por_c] = 'N';
            jogo_player_hide[por_l - 1][por_c] = 'N';
            jogo_player_hide[por_l + 1][por_c] = 'N';
        }
    }

    esc_pl_tela(tam_matriz, jogo_player_hide);
    printf("Escolha a posição para colocar um Porta Aviões (4 casas -> [1 2 3 4]):\n"); //@ porta aviões

    do
    {
        printf("H para horizontal ou V para vertical: ");
        scanf("%c%*c", &h_ou_v);
    } while (h_ou_v != 'H' && h_ou_v != 'V');
    if (h_ou_v == 'H') //horizontal
    {
        do
        {
            do
            {
                printf("2ª casa do PA (linha): ");
                scanf("%d%*c", &por_l);
                printf("2ª casa do PA (coluna): ");
                scanf("%d%*c", &por_c);
                por_l--;
                por_c--;
                if (por_c < 1 || por_c > tam_matriz - 3 || por_l < 0 || por_l > tam_matriz - 1) //checar se está dentro da matriz e se pode
                {
                    printf("Posição inválida.\n");
                }
            } while (por_c < 1 || por_c > tam_matriz - 3 || por_l < 0 || por_l > tam_matriz - 1);
            if (jogo_player_hide[por_l][por_c] != ' ' || jogo_player_hide[por_l][por_c - 1] != ' ' || jogo_player_hide[por_l][por_c + 1] != ' ' || jogo_player_hide[por_l][por_c + 2] != ' ') //checar se ja tem algo no lugar
            {
                printf("Posição Ocupada.\n");
            }
        } while (jogo_player_hide[por_l][por_c] != ' ' || jogo_player_hide[por_l][por_c - 1] != ' ' || jogo_player_hide[por_l][por_c + 1] != ' ' || jogo_player_hide[por_l][por_c + 2] != ' ');

        jogo_player_hide[por_l][por_c] = 'P';
        jogo_player_hide[por_l][por_c - 1] = 'P';
        jogo_player_hide[por_l][por_c + 1] = 'P';
        jogo_player_hide[por_l][por_c + 2] = 'P';
    }
    else //vertical
    {
        do
        {
            do
            {
                printf("2ª casa do PA (linha): ");
                scanf("%d%*c", &por_l);
                printf("2ª casa do PA (coluna): ");
                scanf("%d%*c", &por_c);
                por_l--;
                por_c--;
                if (por_c < 0 || por_c > tam_matriz - 1 || por_l < 1 || por_l > tam_matriz - 3) //checar se está dentro da matriz e se pode
                {
                    printf("Posição inválida.\n");
                }

            } while (por_c < 0 || por_c > tam_matriz - 1 || por_l < 1 || por_l > tam_matriz - 3);
            if (jogo_player_hide[por_l][por_c] == 'N' || jogo_player_hide[por_l - 1][por_c] == 'N' || jogo_player_hide[por_l + 1][por_c] == 'N' || jogo_player_hide[por_l + 2][por_c] == 'N') //checar se ja tem algo no lugar
            {
                printf("Posição Ocupada.\n");
            }
        } while (jogo_player_hide[por_l][por_c] == 'N' || jogo_player_hide[por_l - 1][por_c] == 'N' || jogo_player_hide[por_l + 1][por_c] == 'N' || jogo_player_hide[por_l + 2][por_c] == 'N');

        jogo_player_hide[por_l - 1][por_c] = 'P';
        jogo_player_hide[por_l][por_c] = 'P';
        jogo_player_hide[por_l + 1][por_c] = 'P';
        jogo_player_hide[por_l + 2][por_c] = 'P';
    }

    for (k = 0; k < 2; k++) //@ hidroavião
    {
        esc_pl_tela(tam_matriz, jogo_player_hide);
        printf("Escolha a posição para colocar um Hidroaviões (3 casas->  [- 2 -]):\n"); //hidro aviões n terminado
        printf("\t\t\t\t\t\t\t  [1 - 3]\n");

        do
        {
            printf("H para horizontal ou V para vertical: ");
            scanf("%c%*c", &h_ou_v);
        } while (h_ou_v != 'H' && h_ou_v != 'V');
        if (h_ou_v == 'H') //hprizontal
        {
            do
            {
                do
                {
                    printf("2ª casa do Hidroavião (linha): ");
                    scanf("%d%*c", &por_l);
                    printf("2ª casa do Hidroavião (coluna): ");
                    scanf("%d%*c", &por_c);
                    por_l--;
                    por_c--;
                    if (por_c < 1 || por_c > tam_matriz - 2 || por_l < 0 || por_l > tam_matriz - 1) //checar se está dentro da matriz e se pode
                    {
                        printf("Posição inválida.\n");
                    }
                } while (por_c < 1 || por_c > tam_matriz - 2 || por_l < 0 || por_l > tam_matriz - 1);
                if (jogo_player_hide[por_l][por_c] != ' ' || jogo_player_hide[por_l][por_c - 1] != ' ' || jogo_player_hide[por_l][por_c + 1] != ' ' || jogo_player_hide[por_l + 1][por_c] != ' ' || jogo_player_hide[por_l + 1][por_c - 1] != ' ' || jogo_player_hide[por_l + 1][por_c + 1] != ' ') //checar se ja tem algo no lugar
                {
                    printf("Posição Ocupada.\n");
                }
            } while (jogo_player_hide[por_l][por_c] != ' ' || jogo_player_hide[por_l][por_c - 1] != ' ' || jogo_player_hide[por_l][por_c + 1] != ' ' || jogo_player_hide[por_l + 1][por_c] != ' ' || jogo_player_hide[por_l + 1][por_c - 1] != ' ' || jogo_player_hide[por_l + 1][por_c + 1] != ' ');

            jogo_player_hide[por_l][por_c - 1] = '-';
            jogo_player_hide[por_l][por_c] = 'H';
            jogo_player_hide[por_l][por_c + 1] = '-';
            jogo_player_hide[por_l + 1][por_c - 1] = 'H';
            jogo_player_hide[por_l + 1][por_c] = '-';
            jogo_player_hide[por_l + 1][por_c + 1] = 'H';
        }
        else //vertical
        {
            do
            {
                do
                {
                    printf("2ª casa do Hidroavião (linha): ");
                    scanf("%d%*c", &por_l);
                    printf("2ª casa do Hidroavião (coluna): ");
                    scanf("%d%*c", &por_c);
                    por_l--;
                    por_c--;
                    if (por_c < 0 || por_c > tam_matriz - 2 || por_l < 1 || por_l > tam_matriz - 2) //checar se está dentro da matriz e se pode
                    {
                        printf("Posição inválida.\n");
                    }
                } while (por_c < 0 || por_c > tam_matriz - 2 || por_l < 1 || por_l > tam_matriz - 2);
                if (jogo_player_hide[por_l][por_c] != ' ' || jogo_player_hide[por_l - 1][por_c] != ' ' || jogo_player_hide[por_l + 1][por_c] != ' ' || jogo_player_hide[por_l - 1][por_c + 1] != ' ' || jogo_player_hide[por_l][por_c + 1] != ' ' || jogo_player_hide[por_l + 1][por_c + 1] != ' ') //checar se ja tem algo no lugar
                {
                    printf("Posição Ocupada.\n");
                }
            } while (jogo_player_hide[por_l][por_c] != ' ' || jogo_player_hide[por_l - 1][por_c] != ' ' || jogo_player_hide[por_l + 1][por_c] != ' ' || jogo_player_hide[por_l - 1][por_c + 1] != ' ' || jogo_player_hide[por_l][por_c + 1] != ' ' || jogo_player_hide[por_l + 1][por_c + 1] != ' ');

            jogo_player_hide[por_l - 1][por_c] = '-';
            jogo_player_hide[por_l][por_c] = 'H';
            jogo_player_hide[por_l + 1][por_c] = '-';
            jogo_player_hide[por_l - 1][por_c + 1] = 'H';
            jogo_player_hide[por_l][por_c + 1] = '-';
            jogo_player_hide[por_l + 1][por_c + 1] = 'H';
        }
    }

    esc_pl_tela(tam_matriz, jogo_player_hide);
}

int vez_player(int tam_matriz, char (*jogo_player)[tam_matriz], char (*jogo_pc)[tam_matriz], char (*jogo_pc_hide)[tam_matriz])
{
    int linha, coluna;

    tabuleiro(tam_matriz, jogo_player, jogo_pc);
    printf("\nVez do: Jogador\n\n");
    do
    {
        do
        {
            printf("Escolha a posição que deseja atirar:\nLinha: ");
            scanf("%d%*c", &linha);
            printf("Coluna: ");
            scanf("%d%*c", &coluna);
            linha--;
            coluna--;
            if (coluna < 0 || coluna > tam_matriz - 1 || linha < 0 || linha > tam_matriz - 1)
            {
                printf("Posição inválida.\n");
            }
        } while (coluna < 0 || coluna > tam_matriz - 1 || linha < 0 || linha > tam_matriz - 1);
        if (jogo_player[linha][coluna] != 'O')
        {
            printf("Já atirou nessa posição.\n");
        }
    } while (jogo_player[linha][coluna] != 'O');

    if (jogo_pc_hide[linha][coluna] == 'O' || jogo_pc_hide[linha][coluna] == '-') //checar se onde atirou não tem nada
    {
        jogo_player[linha][coluna] = '-';
        printf("Você errou.\n");
        return 1; //ir para pc
    }
    else if (jogo_pc_hide[linha][coluna] == 'N' || jogo_pc_hide[linha][coluna] == 'P' || jogo_pc_hide[linha][coluna] == 'H') //checar se onde atirou tem algo e o que
    {
        jogo_player[linha][coluna] = 'X';

        if (jogo_pc_hide[linha][coluna] == 'N')
        {
            printf("Você acertou um Navio.\n");
        }
        else if (jogo_pc_hide[linha][coluna] == 'P')
        {
            printf("Você acertou um Porta Aviões.\n");
        }
        else
        {
            printf("Você acertou um Hidroavião.\n");
        }

        jogo_pc_hide[linha][coluna] = 'X';
        return 0; //ir para player
    }
    return 2; //erro
}

int vez_pc(int tam_matriz, char (*jogo_player)[tam_matriz], char (*jogo_pc)[tam_matriz], char (*jogo_player_hide)[tam_matriz])
{
    int linha, coluna;

    linha = rand() % tam_matriz - 1; //escolher entre 0 e 9
    coluna = rand() % tam_matriz - 1;

    if (jogo_player_hide[linha][coluna] == ' ') //se n tem nd, ele errou
    {
        jogo_pc[linha][coluna] = '-';
    }
    else //se tem algo, ele acertou
    {
        jogo_pc[linha][coluna] = 'X';
        jogo_player_hide[linha][coluna] = 'X';
    }

    tabuleiro(tam_matriz, jogo_player, jogo_pc);
    printf("\nVez do: PC\n");
    if (jogo_pc[linha][coluna] == '-')
    {
        printf("O pc errou.\n");
        return 0;
    }
    else
    {
        printf("O pc acertou.\n");
        return 1;
    }
    return 2;
}

int derrubar_bichinho(int tam_matriz, char (*jogo_hide)[tam_matriz], int player_pc, int *navio, int *porta, int *hidro)
{
    int i, j, erro_arq, total;

    for (i = 0; i < tam_matriz; i++) //percorre de cima a baixo e da esquerda para direita
    {
        for (j = 0; j < tam_matriz; j++)
        {
            if (jogo_hide[i][j] == 'X') //ver se acertou
            {
                if (jogo_hide[i][j + 1] == 'X') //direita
                {
                    if (jogo_hide[i][j + 2] == 'X' && jogo_hide[i][j + 3] == 'X') //porta horizontal
                    {
                        *porta -= 1;
                        jogo_hide[i][j] = 'O';
                        jogo_hide[i][j + 1] = 'O';
                        jogo_hide[i][j + 2] = 'O';
                        jogo_hide[i][j + 3] = 'O';
                    }
                    else if (jogo_hide[i][j + 2] == 'X' && jogo_hide[i][j + 3] != 'X' && jogo_hide[i][j + 3] != 'P' && jogo_hide[i][j - 1] != 'P' && jogo_hide[i - 1][j] != 'P' && jogo_hide[i - 1][j + 1] != 'P' && jogo_hide[i - 1][j + 2] != 'P' && jogo_hide[i + 1][j] != 'P' && jogo_hide[i + 1][j + 1] != 'P' && jogo_hide[i + 1][j + 2] != 'P') //navio horiz
                    {
                        *navio -= 1;
                        jogo_hide[i][j] = 'O';
                        jogo_hide[i][j + 1] = 'O';
                        jogo_hide[i][j + 2] = 'O';
                    }
                }
                else if (jogo_hide[i + 1][j] == 'X') //baixo
                {
                    if (jogo_hide[i + 2][j] == 'X' && jogo_hide[i + 3][j] == 'X') //porta vertical
                    {
                        *porta -= 1;
                        jogo_hide[i][j] = 'O';
                        jogo_hide[i + 1][j] = 'O';
                        jogo_hide[i + 2][j] = 'O';
                        jogo_hide[i + 3][j] = 'O';
                    }
                    else if (jogo_hide[i + 2][j] == 'X' && jogo_hide[i + 3][j] != 'X' && jogo_hide[i + 3][j] != 'P' && jogo_hide[i - 1][j] != 'P' && jogo_hide[i][j - 1] != 'P' && jogo_hide[i + 1][j - 1] != 'P' && jogo_hide[i + 2][j - 1] != 'P' && jogo_hide[i][j + 1] != 'P' && jogo_hide[i + 1][j + 1] != 'P' && jogo_hide[i + 2][j + 1] != 'P') //navio vert
                    {
                        *navio -= 1;
                        jogo_hide[i][j] = 'O';
                        jogo_hide[i + 1][j] = 'O';
                        jogo_hide[i + 2][j] = 'O';
                    }
                }
                else if (jogo_hide[i + 1][j - 1] == 'X' && jogo_hide[i + 2][j] == 'X') //hidro vertical
                {
                    if (jogo_hide[i][j - 1] == '-' && jogo_hide[i + 1][j] == '-' && jogo_hide[i + 2][j - 1] == '-') //terminar de verificar
                    {
                        *hidro -= 1;
                        jogo_hide[i][j] = 'O';
                        jogo_hide[i + 1][j - 1] = 'O';
                        jogo_hide[i + 2][j] = 'O';
                    }
                }
                else if (jogo_hide[i + 1][j - 1] == 'X' && jogo_hide[i + 1][j + 1] == 'X') //hidro horizontal
                {
                    if (jogo_hide[i][j - 1] == '-' && jogo_hide[i][j + 1] == '-' && jogo_hide[i + 1][j] == '-') //terminar de verificar
                    {
                        *hidro -= 1;
                        jogo_hide[i][j] = 'O';
                        jogo_hide[i + 1][j - 1] = 'O';
                        jogo_hide[i + 1][j + 1] = 'O';
                    }
                }
            }
        }
    }
    total = *navio + *porta + *hidro; //total de coisas
    printf("Há %d navios em campo, %d porta aviões em campo e %d hidroaviões em campo.\n", *navio, *porta, *hidro);
    system("pause");

    if (total <= 2) //ver se alguém ganhou
    {
        if (player_pc == 0)
        {
            printf("O Jogador ganhou a partida.");
            return 1;
        }
        else
        {
            printf("O Pc ganhou a partida.");
            return 2;
        }
    }

    return 0; //ninguém ganhou ainda
}

void rank(int vit1, int vit2)
{
    setlocale(LC_ALL, "portuguese");
    FILE *arq;
    int erro_arq;
    char string[100], string_vit1[3], string_vit2[3], data[5][5];
    struct Jogadores player;
    struct tm *data_hora_atual; //ponteiro para struct que armazena data e hora

    time_t segundos;                        //variável do tipo time_t para armazenar o tempo em segundos
    time(&segundos);                        //obtendo o tempo em segundos
    data_hora_atual = localtime(&segundos); //para converter de segundos para o tempo local

    system("cls");
    printf("\t\tBatalha Naval\n\n");
    printf("\tDigite seu Usuário: ");
    fgets(player.nick, 20, stdin);
    player.nick[strlen(player.nick) - 1] = 0; //tirar o \n do fim do fgets

    //converter o inteiro em char
    sprintf(string_vit1, "%d", vit1);
    sprintf(string_vit2, "%d", vit2);
    sprintf(data[0], "%d", data_hora_atual->tm_hour);
    sprintf(data[1], "%d", data_hora_atual->tm_min);
    sprintf(data[2], "%d", data_hora_atual->tm_mday);
    sprintf(data[3], "%d", data_hora_atual->tm_mon + 1);
    sprintf(data[4], "%d", data_hora_atual->tm_year + 1900);

    arq = fopen("ranking.txt", "r"); //abre o arquivo como leitura
    if (arq == NULL)                 //se não tiver arquivo
    {
        fclose(arq);                     //fecha o arquivo
        arq = fopen("ranking.txt", "w"); //reabre como escrita

        strcpy(string, "\tRank dos Jogadores\n"); //colocar td em 1 string
        strcat(string, data[0]);
        strcat(string, ":");
        strcat(string, data[1]);
        strcat(string, "    ");
        strcat(string, data[2]);
        strcat(string, "\\");
        strcat(string, data[3]);
        strcat(string, "\\");
        strcat(string, data[4]);
        strcat(string, "\nVitórias do ");
        strcat(string, player.nick);
        strcat(string, ": ");
        strcat(string, string_vit1);
        strcat(string, "\nVitórias do Pc: ");
        strcat(string, string_vit2);
        strcat(string, "\n");

        erro_arq = fputs(string, arq); //colocar a string no arquivo
        if (erro_arq == EOF)           //checar se ocorreu erro na gravação
        {
            printf("Erro na gravação");
        }

        fclose(arq);
    }
    else //se tiver arquivo
    {
        fclose(arq);                     //fechar ele
        arq = fopen("ranking.txt", "a"); //abrir o arquivo como "append" (adicionar ao fim do arquivo)

        strcpy(string, "\n\tRank dos Jogadores\n"); //colocar td em 1 string só
        strcat(string, data[0]);
        strcat(string, ":");
        strcat(string, data[1]);
        strcat(string, "    ");
        strcat(string, data[2]);
        strcat(string, "\\");
        strcat(string, data[3]);
        strcat(string, "\\");
        strcat(string, data[4]);
        strcat(string, "\nVitórias do ");
        strcat(string, player.nick);
        strcat(string, ": ");
        strcat(string, string_vit1);
        strcat(string, "\nVitórias do Pc: ");
        strcat(string, string_vit2);
        strcat(string, "\n");

        erro_arq = fputs(string, arq); //colocar a string no arquivo
        if (erro_arq == EOF)           //ver se ocorreu erro
        {
            printf("Erro na gravação");
        }

        fclose(arq); //fecha o arquivo
    }
}