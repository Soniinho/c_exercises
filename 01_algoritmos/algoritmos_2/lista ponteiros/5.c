#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void maior_valor(int *ptr1, int *ptr2);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int n1, n2;

    printf("Digite um número: ");
    scanf("%d%*c", &n1);
    printf("Digite outro número: ");
    scanf("%d%*c", &n2);
    maior_valor(&n1, &n2);

    printf("\nn1: %d | n2: %d", n1, n2);

    return 0;
}

void maior_valor(int *ptr1, int *ptr2)
{
    if (*ptr2 > *ptr1)
    {
        *ptr1 += *ptr2;
        *ptr2 = *ptr1 - *ptr2;
        *ptr1 -= *ptr2;
    }
}