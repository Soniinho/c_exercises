/* --------------------------------------------/
    Matheus Henrique Daltroso - RA: 202110059
    Thalissa Visentim Lopes   - RA: 202110073    
/-------------------------------------------- */
#include <stdio.h>  //biblioteca padrão
#include <stdlib.h> //biblioteca padrão
#include <locale.h> //para o comando setlocale

//declaração de funções
void jogo_matriz();

//variáveis globais
char jogo[3][3];

//função principal
int main()
{
    //permitir acento
    setlocale(LC_ALL, "portuguese");

    //variáveis
    int i, j, turno;
    int linha, coluna;
    char ser_X_O;

    //preencher matriz com vazio
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            jogo[i][j] = ' ';
        }
    }

    //decidir qual jogador terá o 1° turno ("X" ou "O")
    do
    {
        printf("Qual jogador irá começar jogando, (\"X\" ou \"O\"): ");
        scanf("%c%*c", &ser_X_O);
        if (ser_X_O != 'X' && ser_X_O != 'O')
        {
            printf("Jogador inválido, digite novamente.\n");
        }
    } while (ser_X_O != 'X' && ser_X_O != 'O');

    turno = 1;         //começar no turno 1
    while (turno <= 9) //rodar 9 turnos (jogo da velha só tem 9 turnos)
    {
        //mostrar jogo
        jogo_matriz();

        //escolher posição para colocar o jogador no jogo
        printf("Digite a posição que se quer colocar o \"%c\":\n", ser_X_O);
        do
        {
            printf("Linha: ");
            scanf("%d%*c", &linha); //digitar linha
            printf("Coluna: ");
            scanf("%d%*c", &coluna); //digitar coluna
            if (linha < 1 || linha > 3) //avisar se a linha está fora do intervalo determinado
            {
                printf("Linha inválida, digite novamente.\n");
            }
            else if (coluna < 1 || coluna > 3) //avisar se a coluna está fora do intervalo determinado
            {
                printf("Coluna inválida, digite novamente.\n");
            }
            else if (jogo[linha - 1][coluna - 1] != ' ') //avisar se a casa ja está ocupada
            {
                printf("Posição já ocupada.\n");
            }
        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || jogo[linha - 1][coluna - 1] != ' '); //testar se a coluna é entre 1 e 3

        //matriz em C começa em 0
        //o intervalo de linha/coluna usado começa em 1, portanto precisa retirar 1 unidade
        linha -= 1;
        coluna -= 1;

        //escrever o X ou O na matriz
        jogo[linha][coluna] = ser_X_O;

        //checar vitórias
        //diagonal principal
        if (jogo[0][0] != ' ' && jogo[0][0] == jogo[1][1] && jogo[0][0] == jogo[2][2])
        {
            //mostrar jogo
            jogo_matriz();
            printf("Jogador \"%c\" ganhou.", ser_X_O);
            return 0;
        }
        //diagonal secundária
        else if (jogo[0][2] != ' ' && jogo[0][2] == jogo[1][1] && jogo[0][2] == jogo[2][0])
        {
            jogo_matriz();
            printf("Jogador \"%c\" ganhou.", ser_X_O);
            return 0;
        }

        //linhas e colunas
        for (i = 0; i < 3; i++)
        {
            if (jogo[i][0] != ' ' && jogo[i][0] == jogo[i][1] && jogo[i][0] == jogo[i][2]) //linhas
            {
                //mostrar jogo
                jogo_matriz();
                printf("Jogador \"%c\" ganhou.", ser_X_O);
                return 0;
            }
            else if (jogo[0][i] != ' ' && jogo[0][i] == jogo[1][i] && jogo[0][i] == jogo[2][i]) //colunas
            {
                jogo_matriz();
                printf("Jogador \"%c\" ganhou.", ser_X_O);
                return 0;
            }
        }

        //alterar o jogador para o próximo turno
        if (ser_X_O == 'X')
        {
            ser_X_O = 'O';
        }
        else
        {
            ser_X_O = 'X';
        }

        turno++; //somar 1 turno
    }

    //se passar de 10 turno, é empate (só tem 9 casas para completar o jogo)
    if (turno == 10)
    {
        jogo_matriz();
        printf("Deu velha.");
    }

    return 0;
}

void jogo_matriz()
{
    //variáveis
    int i, j;

    //mostrar matriz do jogo
    system("cls"); //limpar tela
    printf("\tJogo da Velha:\n\n");
    printf("\t   1   2   3\n");
    for (i = 0; i < 3; i++)
    {
        printf("\t%d  ", i + 1);
        for (j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                printf("%c | ", jogo[i][j]);
            }
            else
            {
                printf("%c", jogo[i][j]);
            }
        }
        if (i != 2)
        {
            printf("\n\t  ---+---+---\n");
        }
    }
    printf("\n\n");
}