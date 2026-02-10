#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, *array;

    array = (int *)malloc(sizeof(int) * 5);
    printf("Será pedido para digitar 10 números:\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d%*c", &array[i]);
        array[i] *= 2;
    }

    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("[%d]: %d\n", i, array[i]);
    }

    free(array);
    return 0;
}