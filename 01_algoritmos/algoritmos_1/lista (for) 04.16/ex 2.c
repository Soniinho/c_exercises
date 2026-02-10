#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;

    printf("Serão mostrados todos os números pares, em ordem decrescente, entre 0 e 100.\n");
    printf("Aperte \"enter\" para continuar.\n");
    getchar();

    for (i = 100; i >= 0; i = i - 2)
    {
        printf("%d\n", i);
    }
    return 0;
}