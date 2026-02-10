#include <stdio.h>  //biblioteca padrão
#include <stdlib.h> //biblioteca padrão também
#include <locale.h> //biblioteca para trocar linguagem

int main() //função principal
{
    setlocale(LC_ALL, "portuguese"); //comando para por o programa em português(ver acentos e usar vírgula nos números)

    int numero;                                                         //declaração de variável
    int soma_num, qtd_numeros, maior_num, menor_num, soma_par, qtd_par; //declaração de variável
    float media, media_pares;                                           //declaração de variável
    char opc;                                                           //declaração de variável

    soma_num = 0;    //definir soma dos números como sendo 0
    qtd_numeros = 0; //definir quantidade dos números como sendo 0
    soma_par = 0;    //definir soma dos números pares como sendo 0
    qtd_par = 0;     //definir quantidade dos números pares como sendo 0

    //primeira leitura
    printf("Digite um número inteiro: "); //escrever na tela para digitar um número inteiro
    scanf("%d%*c", &numero);              //ler o número inteiro digitado

    soma_num += numero; //adicionar o valor do número à soma dos números
    qtd_numeros += 1;   //adicionar 1 ao valor da quantidade de números

    maior_num = numero; //fazer o valor digitado ser uma referência para maior número
    menor_num = numero; //fazer o valor digitado ser uma referência para menor número

    if (numero % 2 == 0) //condição - ver se o número digitado é par
    {
        qtd_par += 1;       //adicionar 1 à quantidade de números pares
        soma_par += numero; //adicionar o valor do número à soma dos números pares
    }

    printf("Deseja digitar mais números? \"s\" para sim ou \"n\" para não\n"); //escrever na tela se o usuário deseja digitar mais números
    scanf("%c%*c", &opc);                                                      //ler a letra digitada pelo usuário (s para sim ou n para n)

    if (opc != 'n' && opc != 's') //condição - ver se o usuário digitou uma opção válida
    {
        for (; opc != 'n' && opc != 's';) //loop - checar se o usuário digitou uma opção válida
        {
            printf("Opção inválida, digite \"s\" para sim ou \"n\" para não\n"); //escrever na tela que o usuário digitou uma opção inválida e pedir para ele digitar novamente uma opção
            scanf("%c%*c", &opc);                                                //ler a letra digitada pelo usuário (s para sim ou n para n)
        }
    }

    for (; opc == 's';) //loop - digitação da quantidade de números que o usuário quiser
    {
        printf("Digite um número inteiro: "); //escrever na tela para digitar um número inteiro
        scanf("%d%*c", &numero);              //ler o número inteiro digitado

        soma_num += numero; //adicionar o valor do número à soma dos números
        qtd_numeros += 1;   //adicionar 1 ao valor da quantidade de números

        if (numero > maior_num) //condição - se o número digitado é maior que o maior número
        {
            maior_num = numero; //substituir o maior número pelo valor do número digitado pelo usuário
        }
        else if (numero < menor_num) //condição - se o número digitado é menor que o menor número
        {
            menor_num = numero; //substituir o menor número pelo valor do número digitado pelo usuário
        }

        if (numero % 2 == 0) //condição - ver se o número digitado é par
        {
            qtd_par += 1;       //adicionar 1 à quantidade de números pares
            soma_par += numero; //adicionar o valor do número à soma dos números pares
        }

        printf("Deseja digitar mais números? \"s\" para sim ou \"n\" para não\n"); //escrever na tela se o usuário deseja digitar mais números
        scanf("%c%*c", &opc);                                                      //ler a letra digitada pelo usuário (s para sim ou n para n)

        if (opc != 'n' && opc != 's') //condição - ver se o usuário digitou uma opção válida
        {
            for (; opc != 'n' && opc != 's';) //loop - checar se o usuário digitou uma opção válida
            {
                printf("Opção inválida, digite \"s\" para sim ou \"n\" para não\n"); //escrever na tela que o usuário digitou uma opção inválida e pedir para ele digitar novamente uma opção
                scanf("%c%*c", &opc);                                                //ler a letra digitada pelo usuário (s para sim ou n para n)
            }
        }
    }

    system("cls"); //limpar a tela

    media = soma_num / qtd_numeros;   //calcular a média dos números
    media_pares = soma_par / qtd_par; //calcular a média dos números pares

    printf("\nA soma dos números digitados é %d.", soma_num);    //escrever na tela a soma dos números digitados
    printf("\nForam digitados %d números.", qtd_numeros);        //escrever na tela quantos números foram digitados
    printf("\nA média dos números digitados é de %.2f.", media); //escrever na tela a média dos números digitados
    printf("\nO maior número digitado é %d.", maior_num);        //escrever na tela o maior número digitado
    printf("\nO menor número digitado é %d.", menor_num);        //escrever na tela o menor número digitado
    printf("\nA média dos números pares é %.2f.", media_pares);  //escrever na tela a média dos números pares

    system("pause"); //esperar o usuário apertar enter
    return 0;        //retornar 0 - fechar o programa
}