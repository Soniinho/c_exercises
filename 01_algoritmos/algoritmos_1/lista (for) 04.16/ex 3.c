#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, idade;
    float media, soma;

    printf("Será pedido a idade de 6 pessoas. Aperte \"enter\" para continuar.\n");
    getchar();

    printf("1ª pessoa\n");
    printf("Digite a idade de uma pessoa:");
    scanf("%d%*c", &idade);
    printf("\n");
    soma = idade;

    for (i = 2; i <= 6; i = i + 1)
    {
        printf("%dª pessoa\n", i);
        printf("Digite a idade de outra pessoa:");
        scanf("%d%*c", &idade);
        printf("\n");
        soma = soma + idade;
    }
    media = soma / 6;

    printf("A média das idades lidas é %.2f.", media);
    printf("\nA soma das idades lidas é %.2f.", soma);

    return 0;
}