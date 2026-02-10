#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float s,ns,p,a;
    printf("Digite o salário e o aumento:");
    scanf("%f%f%*c",&s,&p);
    a = s * p/100;
    printf("A porcentagem de aumento é: %.2f", a);
    ns = s + a;
    printf("\nO novo salário é: %.2f", ns);
    return 0;
}
