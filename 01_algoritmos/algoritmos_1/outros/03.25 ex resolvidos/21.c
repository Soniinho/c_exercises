#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float x,y,z;

    printf("Digite o tamanho da escada e a altura:");
    scanf("%f%f%*c",&z,&x);

    y = pow(z,2);
    y = sqrt(y);

    printf("A distância que a fumaça deverá ficar é de %.2f.",y);

    return 0;
}
