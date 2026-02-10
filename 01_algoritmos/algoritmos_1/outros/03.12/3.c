#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite um numero:");
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("O numero %d e par", n);
    } else {
        printf("O numero %d e impar", n);
    }
    //% pega o resto da divisão em C
    return 0;
}
