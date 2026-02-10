#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float a,r;
    printf("Digite o raio:");
    scanf("%f%*c",&r);

    a = 3.1415 * pow(r,2);
    printf("A área é de: %.4f",a);
    return 0;
}
