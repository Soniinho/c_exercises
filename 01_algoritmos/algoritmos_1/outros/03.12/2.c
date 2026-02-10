#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2;
    printf("Digite 2 numeros:");
    scanf("%f%f", &n1, &n2);
    if(n1 == n2){
        printf("Estes numeros sao iguais");
    } else {
        printf("Estes numeros nao sao iguais");
    }

    return 0;
}
