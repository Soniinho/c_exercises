#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");

    double i, x, y, soma;
    soma = 0;
    i = -1;

    printf("Será mostrada a soma: 1/1 + 3/2 + 5/3 + 7/4 + ... + 99/50.\n");
    printf("Aperte \"enter\" para continuar.\n");
    getchar();

    for (x = 1; x <= 50; x = x + 1)
    {
        i = i + 2;
        y = i / x;
        soma = soma + y;
    }

    printf("A soma é igual a %lf.", soma); //95,500795

    return 0;
}