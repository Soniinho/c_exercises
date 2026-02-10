#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

void soma();
int subtracao();
void multiplicacao(int z, int y);
float divisao(int c, int v);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int sub, n;
    float div;

    soma();
    sub = subtracao();
    printf("\nA subtração deles é: %d\n", sub);
    printf("Digite 1 número para ser usado com o resultado de cima: ");
    scanf("%d%*c", &n);
    multiplicacao(sub, n);
    div = divisao(sub, n);
    printf("\nA divisão deles é: %.2f\n", div);
    return 0;
}

void soma()
{
    int n1, n2;
    printf("Digite um número: ");
    scanf("%d%*c", &n1);
    printf("Digite outro número: ");
    scanf("%d%*c", &n2);

    printf("\nA soma deles é: %d\n", n1 + n2);
}

int subtracao()
{
    int n1, n2;
    printf("Digite um número: ");
    scanf("%d%*c", &n1);
    printf("Digite outro número: ");
    scanf("%d%*c", &n2);

    return (n1 - n2);
}

void multiplicacao(int z, int y)
{
    printf("\nA multiplicação da subtração com o último número é: %d\n", z * y);
}

float divisao(int c, int v)
{
    return (c / v);
}

/*
& double eu_sei_la_3(int z, int x);
* getchar(); //mostra na tela, n gostei
* getch();   //não mostra na tela 
+ precisa da <conio.h>
% declaração de função  //retorno e parâmetro(s)
@ variáveis globais
# int a1, a2, a3;       //ficam fora das funções
*/

/* prog q demonstra os 4 tipos
#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

void soma();
int subtracao();
void multiplicacao(int z, int y);
float divisao(int c, int v);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int sub, n;
    float div;

    soma();
    sub = subtracao();
    printf("\nA subtração deles é: %d\n", sub);
    printf("Digite 1 número para ser usado com o resultado de cima: ");
    scanf("%d%*c", &n);
    multiplicacao(sub, n);
    div = divisao(sub, n);
    printf("\nA divisão deles é: %.2f\n", div);
    return 0;
}

void soma()
{
    int n1, n2;
    printf("Digite um número: ");
    scanf("%d%*c", &n1);
    printf("Digite outro número: ");
    scanf("%d%*c", &n2);

    printf("\nA soma deles é: %d\n", n1 + n2);
}
int subtracao()
{
    int n1, n2;
    printf("Digite um número: ");
    scanf("%d%*c", &n1);
    printf("Digite outro número: ");
    scanf("%d%*c", &n2);

    return (n1 - n2);
}
void multiplicacao(int z, int y)
{
    printf("\nA multiplicação da subtração com o último número é: %d\n", z * y);
}
float divisao(int c, int v)
{
    return (c / v);
}
*/
