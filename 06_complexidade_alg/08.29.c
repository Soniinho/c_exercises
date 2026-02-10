#include <stdio.h>
#include <stdlib.h>

int a1[] = {0, 7, 9, 3, 4, 8, 4};
int a2[] = {0, 8, 5, 6, 4, 5, 7};

int t1[] = {0, 2, 3, 1, 3, 4, 3};
int t2[] = {0, 2, 1, 2, 2, 1, 2};

int e[] = {0, 2, 4};
int x[] = {0, 3, 2};

int f1[7], f2[7];
int l1[7], l2[7];

int f, l;

void linhaprod()
{
    int j, n = 7;

    f1[1] = e[1] + a1[1];
    f2[1] = e[2] + a2[1];

    for (j = 2; j <= 7; j++)
    {
        if ((f1[j - 1] + a1[j]) <= (f2[j - 1] + t2[j - 1] + a1[j]))
        {
            f1[j] = f1[j - 1] + a1[j];
            l1[j] = 1;
        }
        else
        {
            f1[j] = f2[j - 1] + t2[j - 1] + a1[j];
            l1[j] = 2;
        }

        if ((f2[j - 1] + a2[j]) <= (f1[j - 1] + t1[j - 1] + a2[j]))
        {
            f2[j] = f2[j - 1] + a2[j];
            l2[j] = 2;
        }
        else
        {
            f2[j] = f1[j - 1] + t1[j - 1] + a2[j];
            l2[j] = 1;
        }
    }

    if (f1[n] + x[1] <= f2[n] + x[2])
    {
        f = f1[n] + x[1];
        l = 1;
    }
    else
    {
        f = f2[n] + x[1];
        l = 2;
    }
}

int main()
{
    int i, n = 7;

    linhaprod();

    printf("f1:");
    for (i = 1; i < n; i++)
    {
        printf(" %d", f1[i]);
    }

    printf("\nf2:");
    for (i = 1; i < n; i++)
    {
        printf(" %d", f2[i]);
    }

    printf("\nl1:");
    for (i = 2; i < n; i++)
    {
        printf(" %d", l1[i]);
    }

    printf("\nl2:");
    for (i = 2; i < n; i++)
    {
        printf(" %d", l2[i]);
    }

    printf("\n f* = %d \n l* = %d", f, l);

    return 0;
}