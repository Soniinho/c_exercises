#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float a, l, c, ct, alt;
    printf("Digite as dimensões do seu reservatório em centímetros conforme o que se pede:");
    printf("\nAltura:");
    scanf("%f%*c",&a);
    printf("Largura:");
    scanf("%f%*c",&l);
    printf("Comprimento:");
    scanf("%f%*c",&c);

    ct = (a*l*c)/1000; //1 litro = 1000 cm^3
    printf("A capacidade total do reservatório é %.2f L.",ct);

    alt = ct / 150; //150 L para resid. por dia
    printf("\nA autonomia desse reservatório para uma residência é de %.0f dias.",floor(alt));
    //arrendondar para baixo o número de dias

    if(alt<2){
        printf("\nConsumo elevado.");
    } else{
        if(alt>=2 && alt<7){
            printf("Consumo moderado.");
        } else {
            printf("Consumo reduzido."); // >= 7
        }
    }

    return 0;
}
