#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, c1, c2;
    float n;
    c1 = 0;
    c2 = 0;

    printf("Será pedido para digitar 8 números. Aperte \"enter\" para continuar.\n");
    getchar();

    for (i = 1; i <= 8; i = i + 1)
    {
        printf("%dº número\n", i);
        printf("Digite um número:");
        scanf("%f%*c", &n);
        printf("\n");

        if (n >= 5 && n <= 9)
        {
            c1 = c1 + 1;
        }
        else
        {
            c2 = c2 + 1;
        }
    }

    printf("A quantidade de números entre o intervalo [5;9] é de %d.\n", c1);
    printf("A quantidade de números fora do intervalo [5;9] é de %d.\n", c2);

    return 0;
}