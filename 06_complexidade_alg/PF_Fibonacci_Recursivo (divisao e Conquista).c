#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* DIVISÃO E CONQUITA */
unsigned long long int fib(unsigned long long int x)
{
    if (x <= 1)
    {
        return x;
    }
    else
    {
        printf("x=%llu\n", x);
        return fib(x - 1) + fib(x - 2);
    }
}

void main()
{
    unsigned long long int num;
    unsigned long long int resp;
    int i;
    time_t inicio_c, fim_c;

    printf("Numero (ate 40): ");
    scanf("%llu", &num);

    inicio_c = time(NULL);
    resp = fib(num);
    fim_c = time(NULL);

    printf("Passaram-se %f segundos\n", difftime(fim_c, inicio_c));
    printf("\n\nResultado: %llu\n", resp);
}
