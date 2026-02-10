#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int x;

    x = 1;
    for (; x <= 10;)
    {
        printf("%d", x);
        x++;
    }

    return 0;
}