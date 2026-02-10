#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s, sf;
    printf("Digite o salario para atualiza-lo:");
    scanf("%f", &s);

    if(s <= 600){
        sf = s + s * 0.3;
    } if(s > 600 && s <= 1100){
        sf = s + s * 0.25;
    } if(s > 1100 && s <= 2400){
        sf = s + s * 0.2;
    } if(s > 2400 && s <= 3550){
        sf = s + s * 0.15;
    } if(s > 3500){
        sf = s + s * 0.1;
    }

    printf("O salario atualizado e: %.2f", sf);

    return 0;
}
