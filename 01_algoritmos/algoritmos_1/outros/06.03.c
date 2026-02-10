#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
//todo: funções

//*void soma(); assinatura da função (declaradas antes da main)
//colocar as funções embaixo da main, e colocar as assinaturas em cima

//!----------variáveis globais----------//
//?se declarar a mesma dentro da função, ela é substituída na função

int abecedario = 300, asv = 10;
float abc = 10, yz = 50;
//!-------------------------------------//

//!----------tipos de função------------//
//? retorno(volta valor da função) e parâmetro(manda valor pra função)
//~ variáveis nascem e morrem na função(são locais)

void soma1();             //*sem retorno[void] e sem parâmetro(s)[dentro do () e coloca o tipo na frente]
void soma2(int x, int y); //*sem retorno e com parâmetro(s)
int soma3();              //*com retorno[int, char, etc] e sem parâmetro(s)
int soma4(int x, int y);  //*com retorno e com parâmetro(s)
//!--------------------------------------//

int main()
//void main(){} sem return
{
    setlocale(LC_ALL, "portuguese");

    //!--------variável local--------//
    //morre dps da função acabar, liberando memória
    //funciona tbm pra outros escopos(for, if, while, etc)
    //*for([é um escopo]){[é outro escopo]}

    int x, y;
    //!------------------------------//

    soma1();
    x = soma3();
    printf("\nSoma: %d.", x);

    soma2(10, 20);
    y = soma4(20, 10);
    printf("\nSoma: %d.", y);

    return 0;
}

void soma1()
{
    int a, b, s;
    printf("Digite 2 valores inteiros: ");
    scanf("%d%d%*c", &a, &b);
    s = a + b;
    printf("\nA soma é %d.", s);
}

int soma3()
{
    int a, b, s;
    printf("Digite 2 valores inteiros: ");
    scanf("%d%d%*c", &a, &b);
    s = a + b;
    return s;
}

void soma2(int x, int y)
{
    int s;
    s = x + y;
    printf("\nSoma: %d.", s);
}

int soma4(int x, int y)
{
    int s;
    s = x + y;
    return s;
}
