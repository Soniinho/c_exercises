#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int *ptr1, int *ptr2);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a, b, soma_dobro;

    printf("Digite um número: ");
    scanf("%d%*c", &a);
    printf("Digite outro número: ");
    scanf("%d%*c", &b);

    soma_dobro = soma(&a, &b);

    printf("\nA*2: [%d],\nB*2: [%d],\nSoma de A e B: [%d].", a, b, soma_dobro);
    //printf("\nA*2: [%d],\nB*2: [%d],\nSoma de A e B: [%d].", a, b, soma(&a, &b));

    return 0;
}

int soma(int *ptr1, int *ptr2)
{
    *ptr1 *= 2;
    *ptr2 *= 2;

    return *ptr1 + *ptr2;
}