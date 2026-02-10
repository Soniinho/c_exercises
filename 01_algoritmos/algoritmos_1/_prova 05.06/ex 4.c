#include <stdio.h>  //biblioteca padrão
#include <stdlib.h> //biblioteca padrão também
#include <locale.h> //biblioteca para trocar linguagem

int main() //função principal
{
    setlocale(LC_ALL, "portuguese"); //comando para por o programa em português(ver acentos e usar vírgula nos números)
    int i, numero, soma_divisores; //declaração de variáveis

    soma_divisores = 0; //por ser uma soma deve ser definida como 0 no início do código

    printf("Digite um número inteiro:"); //escreve na tela para o usuário digitar um número inteiro
    scanf("%d%*c", &numero); //lê o número digitado pelo usuário

    for (i = 1; i < numero; i++) //loop - repetição que conta de 1 até o valor do número digitado
    {
        if (numero % i == 0) //condição - vê se o número digitado é divisível por cada i (desde 1 até um número antes do número digitado pelo usuário)
        {
            soma_divisores += i; //soma o divisor ao valor já calculádo de soma dos 
        }
    }

    printf("A soma dos divisores do número digitado é %d.", soma_divisores); //escreve a soma dos divisores na tela

    system("pause"); //esperar o usuário apertar enter
    return 0;        //retornar 0 - fechar o programa
}