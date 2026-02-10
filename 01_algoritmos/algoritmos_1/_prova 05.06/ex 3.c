#include <stdio.h>  //biblioteca padrão
#include <stdlib.h> //biblioteca padrão também
#include <locale.h> //biblioteca para trocar linguagem

int main() //função principal
{
    setlocale(LC_ALL, "portuguese"); //comando para por o programa em português(ver acentos e usar vírgula nos números)

    int numero, i, i_fatorial; //declaração de variável
    float fatorial, E;         //declaração de variável

    E = 0; // número E é uma soma, deve ser declarado com 0 no início do código

    printf("Digite um número inteiro e positivo: "); //escreve na tela para o usuário digitar um número inteiro e positivo
    scanf("%d%*c", &numero);                         //lê o número digitado pelo usuário

    for (i = 1; i <= numero; i++) //loop - roda a repetição de 1 até o valor do número digitado
    {
        i_fatorial = i; //define i_fatorial = i para não alterar o i, assim não quebrando a 1ª repetição

        //fatorial tem formula [n . (n – 1).(n – 2)...] então...
        for (fatorial = 1; i_fatorial > 1; i_fatorial -= 1) //repetição que acha o fatorial, sendo i_fatorial o n da fórmula mostrada acima
        {
            fatorial *= i_fatorial; //multiplica o n ou termo com o n da fórmula do fatorial com o valor já calculado do fatorial e o substitui
        }

        E += 1 / fatorial; //adiciona o fatorial no denominador da conta e adiciona ao valor do E já calculado
    }

    printf("O valor de E é %f.", E); //escreve o valor de E na tela

    system("pause"); //esperar o usuário apertar enter
    return 0;        //retornar 0 - fechar o programa
}