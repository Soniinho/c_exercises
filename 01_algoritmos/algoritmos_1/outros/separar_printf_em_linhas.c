#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float a=10,b=11,c=12;
    printf("aaaaaaaaaa %.0f"
           "bbbbbbbbbb %.0f"
           "cccccccccc %.0f",
           a,
           b,
           c);//assim vai mas aparentemente as pessoa n gosta

    printf("\nnão sei %.0f\
b %.0f\
c %.0f",
a,
b,
c); //usar \ é uma bela duma merda, pq
    //tem q deixar no canto pra n contar espaço

    return 0;
}
