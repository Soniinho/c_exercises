#include <stdio.h>  //biblioteca padrão
#include <stdlib.h> //biblioteca padrão também
#include <locale.h> //biblioteca para trocar linguagem

int main() //função principal
{
    setlocale(LC_ALL, "portuguese"); //comando para por o programa em português(ver acentos e usar vírgula nos números)

    int i, apoio, linha, numero_1; //declaração das variáveis

    numero_1 = 1; //definir o primeiro número da primeira linha como sendo 1

    printf("Digite quantas linhas você quer ver do triângulo de Floyd: "); //escrever na tela para o usuário digitar quantas linhas ele quer ver do triângulo de Floyd
    scanf("%d%*c", &linha);                                                //ler a quantidade de linhas digitadas pelo usuário

    for (i = 1; i <= linha; i++) //loop - fazer o loop rodar a quantidade de vezes de linhas (1 vez = 1 linha, 2 vezes = 2 linhas, etc.)
    {
        for (apoio = 1; apoio <= i; apoio++) //loop 2 - ver qual linha está e digitar quantos números têm em cada linha, que por consequência são iguais ao número da linha (linha 3 têm 3 números, linha 4 têm 4 números, etc)
        {
            printf(" %d\t  ", numero_1); // digitar o número e dar espaço
            numero_1++;                  //adicionar 1 ao número anterior escrito na tela
        }
        printf("\n"); //pular para a próxima linha do triângulo
    }

    system("pause"); //esperar o usuário apertar enter
    return 0;        //retornar 0 - fechar o programa
}