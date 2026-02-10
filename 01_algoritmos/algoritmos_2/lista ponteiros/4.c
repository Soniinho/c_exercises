#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void troca(int *ptr1, int *ptr2);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int n1, n2;

    printf("Digite um número: ");
    scanf("%d%*c", &n1);
    printf("Digite outro número: ");
    scanf("%d%*c", &n2);
    troca(&n1, &n2);
    printf("\nn1: %d | n2: %d", n1, n2);

    return 0;
}

void troca(int *ptr1, int *ptr2)
{
    *ptr1 += *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 -= *ptr2;
}