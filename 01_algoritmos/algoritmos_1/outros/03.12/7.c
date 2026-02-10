#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;
    printf("Digite os valores a,b e c, respectivamente, de uma equação de segundo grau:");
    scanf("%f%f%f", &a, &b, &c);
    delta = pow(b, 2) -4*a*c;
    if(delta != 0){
        if(delta > 0){
            x1 = ( -b + sqrt(delta) ) / 2 * a;
            x2 = ( -b - sqrt(delta) ) / 2 * a;
            printf("As raizes sao %f e %f.", x1, x2);
        } else {
            printf("Nao possui raizes reais.");
        }
    } else {
        x1 = -b / 2 * a;
        printf("A raiz e %f", x1);
    }
    // != diferente
    return 0;
}
