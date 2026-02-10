#include <stdio.h>
#include <stdlib.h>

int main()
{
    float v, vf;
    printf("Digite o valor do produto:");
    scanf("%f", &v);

    if(v < 20){
        vf = v + v * 0.45;
    } else {
        vf = v + v * 0.3;
    }

    printf("Valor ajustado do produto: %.2f", vf);

    return 0;
}
