#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int n1,n2,n3,n4,soma;
    printf("Digite 4 números:");
    scanf("%d%d%d%d%*c",&n1,&n2,&n3,&n4);
    soma = n1+n2+n3+n4;
    printf("A soma é: %d",soma);
    return 0;
}
