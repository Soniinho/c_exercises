#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    return 0;
}

/* //% função recursiva (se chama sozinha no fim dela)
int fatorial(int x);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n, r;

    do
    {
        printf("Digite um número inteiro positivo: ");
        scanf("%d%*c", &n);
    } while (n < 0);

    r = fatorial(n);
    printf("\nFatorial de %d = %d", n, r);

    return 0;
}

int fatorial(int x)
{
    int resultado;

    if (x == 0 || x == 1)
    {
        resultado = 1;
    }
    else
    {
        resultado = x * fatorial(x - 1);
    }

    return resultado;
}
*/

/*
int soma_intervalo(int p_de, int p_ate)
{
    int resultado;
    if (p_ate == p_de)
    {
        resultado = p_de;
    }
    else if (p_ate > p_de)
    {
        resultado = p_ate + soma_intervalo(p_de, p_ate - 1);
    }
    else
    {
        resultado = p_ate + soma_intervalo(p_de, p_ate + 1);
    }
    return resultado;
}

int main()
{
    int de, ate, resultado;
    printf("Informe um intervalo numerico:");
    printf("\nDe:");
    scanf("%d%*c", &de);
    printf("Ate:");
    scanf("%d%*c", &ate);
    resultado = soma_intervalo(de, ate);
    printf("A soma dos numeros no intervale de %d ate %d = %d", de, ate, resultado);
    return 0;
}
*/
