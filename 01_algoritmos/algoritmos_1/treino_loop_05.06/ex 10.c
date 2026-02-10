#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, p, n, soma_n_pares = 0, soma_n_primos = 0, primo;

    for (i = 1; i <= 10; i++)
    {

        printf("Digite um número inteiro:");
        scanf("%d%*c", &n);

        if (n % 2 == 0)
        {
            soma_n_pares += n;
        }

        for (p = 2, primo = 1; p < n && primo == 1; p++)
        {
            if (n % p == 0)
            {
                primo = 0;
            }
        }

        if (primo == 1)
        {
            soma_n_primos += n;
        }
    }

    printf("\nA soma dos números pares é de %d", soma_n_pares);
    printf("\nA soma dos números primos é de %d", soma_n_primos);

    system("pause");
    return 0;
}