#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int n1, n2;

    printf("Digite um número: ");
    scanf("%d%*c", &n1);
    printf("Digite outro número: ");
    scanf("%d%*c", &n2);

    if (&n1 > &n2)
    {
        printf("O endereço de n1 é maior, seu conteúdo é: [%d]", n1);
    }
    else
    {
        printf("O endereço de n2 é maior, seu conteúdo é: [%d]", n2);
    }
    
    return 0;
}