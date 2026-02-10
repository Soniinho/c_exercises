#include <stdio.h>

typedef int (*FuncaoAnonima)(int);

void aplicarFuncao(int lista[], int tamanho, FuncaoAnonima funcao)
{
    for (int i = 0; i < tamanho; i++)
    {
        lista[i] = funcao(lista[i]);
    }
}

int dobrar(int x)
{
    return 2 * x;
}

int main()
{
    int lista[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    aplicarFuncao(lista, tamanho, dobrar);

    printf("Lista resultante:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
