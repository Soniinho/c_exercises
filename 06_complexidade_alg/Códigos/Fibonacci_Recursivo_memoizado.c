#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned long long int F[40];
/* DIVISÃO E CONQUITA */
int fib (unsigned long long int x)
{
    if (x<=1)
    {
        return x;
    }
    else
    {
        if (F[x] != -1)
            return F[x];
        else
        {
            printf("x=%llu\n",x);
            F[x] = fib(x-1)+fib(x-2);
            return F[x];
        }
    }
}

main ()
{
    long int num;
    unsigned long long int resp;
    int i;
    time_t inicio_c, fim_c;


    for (i=0; i<=40; i++)
        F[i] = -1;
    printf("Numero (ate 40): ");
    scanf("%ld",&num);

    inicio_c = time(NULL);
    resp = fib(num);
    fim_c = time(NULL);

    printf("Passaram-se %f segundos\n", difftime(fim_c,inicio_c));
    printf("\n\nResultado: %llu\n",resp);
}
