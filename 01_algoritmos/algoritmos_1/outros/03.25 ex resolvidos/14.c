#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int ano,ano_nas,idade,idade_2050;
    printf("Digite o ano que estamos e o seu ano de nascimento:");
    scanf("%d%d%*c",&ano,&ano_nas);

    idade = ano - ano_nas;
    idade_2050 = 2050 - ano_nas;

    printf("Sua idade atual é de %d anos.",idade);
    printf("\nSua idade em 2050 será de %d anos.",idade_2050);

    return 0;
}
