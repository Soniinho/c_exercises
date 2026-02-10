#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n;
    printf("Digite um número inteiro:");
    scanf("%d",&n);

    if(n % 5 == 0){
        printf("O número %d é divisível por 5.",n);
    } else{
        printf("O número %d não é divisível por 5.",n);
    }

    return 0;
}
