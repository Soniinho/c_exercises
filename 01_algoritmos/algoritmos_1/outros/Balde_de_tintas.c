#include <stdio.h>
#include<math.h>

int main(){

    float b, h,c; //base e altura
    float p, a; //p= preço a= area
    float t; //tinta
    float f; //final
    printf("Informe o valor da base,da altura e comprimento da parede\n");
    printf("Base = ");
    scanf("%f", &b);
    printf("Altura = ");
    scanf("%f", &h);
    printf("Comprimento = ");
    scanf("%f", &c);
    a = 2*c*h + 2*b*h + c*b;
    printf("Area:%.2f Metros quadrados\n\n", a);
    printf("Valor da lata de tinta\n");
    printf("preco = ");
    scanf("%f", &p);
    printf("Quanto rende uma lata de tinta?\n");
    printf("Rendimento da lata = ");
    scanf("%f", &t);
    printf("Quantidade necessaria de latas de tintas para preencher a area:%.2f\n", a/t);
    printf("Quantidade (ajustada) necessaria de latas de tintas para preencher a area:%.2f\n", ceil(a/t));
    f = a/t;
    f = ceil(f); ///arredondar para cima
    printf("preco a se pagar:%2.f\n\n", f * p);
    system("pause");
    return 0;

}
