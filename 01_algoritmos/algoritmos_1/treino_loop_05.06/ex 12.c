#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, p, n, primo, qtd_primo = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Digite um número inteiro:");
        scanf("%d%*c", &n);

        for (p = 2, primo = 1; p < n && primo == 1; p++)
        {
            if (n % p == 0)
            {
                primo = 0;
            }
        }

        if (primo == 1)
        {
            qtd_primo += 1;
        }
    }
    printf("\nA quantidade de números primos digitada é de %d.", qtd_primo);

    system("pause");
    return 0;
}