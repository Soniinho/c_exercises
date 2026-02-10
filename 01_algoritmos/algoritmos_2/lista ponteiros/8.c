#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    float *array;

    array = (float *)malloc(sizeof(float) * 10);

    for (i = 0; i < 10; i++)
    {
        array[i] = i;
    }

    for (i = 0; i < 10; i++)
    {
        printf("[%d]: %p\n", i, &array[i]);
    }

    free(array);
    return 0;
}