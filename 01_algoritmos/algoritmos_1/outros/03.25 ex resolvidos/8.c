#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float d,t,r,tot;
    printf("Digite o depósito e a taxa:");
    scanf("%f%f%*c",&d,&t);

    r = d * t/100;
    tot = d + r;

    printf("O rendimento é de: %.2f", r);
    printf("\nO valor total é de: %.2f", tot);

    return 0;
}
