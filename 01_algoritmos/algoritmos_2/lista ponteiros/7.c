#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int *ptr1, int *ptr2);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a, b;

    printf("Digite um número: ");
    scanf("%d%*c", &a);
    printf("Digite outro número: ");
    scanf("%d%*c", &b);

    soma(&a, &b);

    printf("\nA: [%d],\nB: [%d].", a, b);

    return 0;
}

int soma(int *ptr1, int *ptr2)
{
    *ptr1 += *ptr2;
}