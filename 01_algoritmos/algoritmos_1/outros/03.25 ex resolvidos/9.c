#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float b,h,a;
    printf("Digite a base e a altura:");
    scanf("%f%f%*c",&b,&h);
    a = (b*h)/2;
    printf("A área é de: %.2f",a);
    return 0;
}
