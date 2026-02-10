#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define pi 3.14

int main()
{
    setlocale(LC_ALL, "portuguese");
    float ang, alt, escada, radiano;
    printf("Digite o ângulo e a altura do triângulo:");
    scanf("%f%f",&ang,&alt);

    radiano = ang * pi /180;
    escada = alt / sin(radiano);
    printf("A medida da escada é de %.2f",escada);
    return 0;
}
