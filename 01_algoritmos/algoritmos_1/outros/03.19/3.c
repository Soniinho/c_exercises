#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    float a,b,c,ma,mp;
    printf("Digite um número inteiro e positivo:");
    scanf("%d%*c",&i);
    printf("Digite 3 valores:");
    scanf("%f%f%f%*c", &a, &b, &c);
    i = abs(i); //caso a pessoa digite n° negativo

    if(i % 2 == 0){
        ma = (a + b + c)/3;
        printf("A média aritimética dos valores é %.2f",ma);
    } else {
        if(i>10){
            mp = ((a*2)+(b*3)+(c*4))/9; //2+3+4
            printf("A média ponderada dos valores é %.2f",mp);
        } else {
            printf("Não existe consulta para primeiro valor digitado (%d).",i);
        }
    }

    return 0;
}
