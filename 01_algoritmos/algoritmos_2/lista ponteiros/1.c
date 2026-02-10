#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int n_int, *p_int;
    float n_float, *p_float;
    char charac, *p_char;

    p_int = &n_int;
    p_float = &n_float;
    p_char = &charac;

    n_int = 1;
    n_float = 1.01;
    charac = 'a';

    printf("Os valores antes da mudança são:\t%d | %.2f | %c\n", n_int, n_float, charac);

    *p_int = 2;
    *p_float = 2.02;
    *p_char = 'b';

    printf("Os valores depois da mudança são:\t%d | %.2f | %c\n", n_int, n_float, charac);

    return 0;
}