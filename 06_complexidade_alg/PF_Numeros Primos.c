#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void main()
{
    long int i, x;
    for (i = 2;; i++)
    {
        x = 2;
        while (((i % x) != 0) && (x <= i))
        {
            x++;
        }
        if (i <= x)
        {
            printf("%ld  ", i);
            Sleep(100);
            /* getchar(); */
        }
    }
}
