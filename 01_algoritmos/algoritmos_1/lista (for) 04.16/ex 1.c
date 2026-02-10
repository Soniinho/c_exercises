#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;

    printf("Serão mostrados todos os números multiplos de 3 entre 10 e 51, inclusive.\n");
    printf("Aperte \"enter\" para continuar.\n");
    getchar();

    printf("10\n");

    for (i = 12; i <= 51; i = i + 1)
    {
        if (i % 3 == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}