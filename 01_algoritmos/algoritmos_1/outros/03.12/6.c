#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Digite 2 numeros:");
    scanf("%d%d", &a, &b);
    if(a > b){
        printf("A ordem crescente e %d, %d.", b, a);
    } else {
        printf("A ordem crescente e %d, %d.", a, b);
    }
    return 0;
}
