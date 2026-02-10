/*
% Recursão

? fatorial => recursão

$ base:     1! = 1
*           5! = 4! x 5
*           4! = 3! x 4
*           3! = 2! x 3
*           2! = 1! x 2
^   fat(m) = m * fat(m - 1)

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

long double fatorial(long double num)
{
    if (num == 1 || num == 0)
        return 1;
    else
        return (num * fatorial(num - 1));
}

void listar_vet2(int v[], int n)
{
    if (n == 0)
        printf("%d ", v[0]);
    else
    {
        // printf("%d ", v[n]); //imprime invertido
        listar_vet2(v, n - 1);
        printf("%d ", v[n - 1]); // imprime na ordem
    }
}

void listar_vet(int vet[], int l, int i)
{
    printf("%d ", vet[i]);

    if (i < l - 1) // começa em 0 então -1
    {
        i++;
        listar_vet(vet, l, i);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    /*
        long double x;
        printf("Digite um número: ");
        scanf("%Lf%*c", &x);
        printf("%.Lf", fatorial(x));
    */

    int vet[] = {4, 8, 1, 9, 3};

    listar_vet(vet, 5, 0);
    printf("\n\n");
    listar_vet2(vet, 4); //precisa por vet[5] -> 4

    return 0;
}
