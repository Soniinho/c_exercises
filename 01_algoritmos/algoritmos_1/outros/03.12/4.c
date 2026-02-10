#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Digite 2 numeros:");
    scanf("%d%d", &a, &b);
    if(a % b == 0){
        printf("O numero %d e divisivel por %d", a, b);
    } else {
        printf("O numero %d nao e divisivel por %d", a, b);
    }

    return 0;
}
