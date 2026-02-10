#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    printf("digite");
    getch();
    printf("teste");
    getch();
    return 0;
}
