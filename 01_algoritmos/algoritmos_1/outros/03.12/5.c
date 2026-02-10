#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Digite 2 numeros:");
    scanf("%d%d", &a, &b);
    if(a > b){
        printf("%d e o maior numero", a);
    } if(a < b) {
        printf("%d e o maior numero", b);
    }
    //teste com 2 if
    return 0;
}
