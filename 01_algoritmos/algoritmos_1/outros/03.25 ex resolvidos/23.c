#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    double num, i, f, a, d;
    printf("Digite um número:");
    scanf("%lf%*c", &num);  //float n aguenta
    d = modf(num,&i); //"i" parte inteira e "d" parte decimal
    a = floor(num); //precisa de double pq 32 bits/2 = 32 e 32

    printf("Parte inteira = %.2lf.\nParte decimal = %.2lf.",i,d);
    printf("\nNúmero arredondado = %.lf.",a);
    return 0;
}

/*
int main()
{
    setlocale(LC_ALL, "portuguese");
    double num, i, f, a, z;
    printf("Digite um número:");
    scanf("%lf%*c", &num);
    z = modf(num,&i);
    f = num - i;
    a = floor(num);

    printf("Parte inteira = %.2lf.\nParte decimal = %.2lf.\nNúmero arredondado = %lf.",i,f,a);

    return 0;
}
*/
