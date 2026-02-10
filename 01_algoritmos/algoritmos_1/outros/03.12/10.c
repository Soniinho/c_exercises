#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n;
    printf("Digite um numero:");
    scanf("%f", &n);
    if(n > 20 && n < 90){ //&& - e
        printf("O numero %.f esta compreendido entre 20 e 90.", n);
    } else{
        printf("O numero nao %.f esta compreendido entre 20 e 90.", n);
    }

    return 0;
}
