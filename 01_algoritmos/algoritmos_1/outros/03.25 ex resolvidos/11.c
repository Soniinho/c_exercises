#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float n,q,c,r2,r3;
    printf("Digite um número:");
    scanf("%f",&n);

    q = pow(n,2);
    c = pow(n,3);
    r2 = sqrt(n);
    r3 = cbrt(n); //pow(n,0.3333);

    printf("O seu quadrado é %.2f.\nO seu cubo é %.2f.", q, c);
    printf("\nA sua raiz quadrada é %.2f.\nA sua raiz cúbica é %.2f.", r2, r3);
    return 0;
}
