#include <stdio.h>

void main()
{
    int i = 0;

    while (1) //1 = true, 0 = false
    {
        printf("%d ", i);
        i++;
        if (i == 10)
        {
            break; //break the loop
        }
    }
    printf("\ncame out of while loop");
}