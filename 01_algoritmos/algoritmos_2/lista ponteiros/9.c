#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j;
    float matriz[3][3];

    printf("  L | C |     Endereço\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" [%d] [%d]: %p\n", i, j, &matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}