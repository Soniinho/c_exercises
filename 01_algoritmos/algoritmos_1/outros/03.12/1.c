#include <stdio.h>

int main(){
    float n;
    printf("Digite um numero:");
    scanf("%f", &n);
    if(n > 10){
        printf("Esse numero e maior que 10");
    } else {
        printf("Esse numero nao e maior que 10");
    }

    return 0;
}
