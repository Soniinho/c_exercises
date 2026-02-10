#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include  <limits.h>

main()
{
    int a;
    short int b;
    unsigned int c;
    unsigned short int d;
    long int e;
    unsigned long int f;
    long long int g;
    unsigned long long int h;

    printf("Tamanho do unsigned short int     : %d bytes\n", sizeof(unsigned short int));
    printf("Tamanho do short int              : %d bytes\n", sizeof(short int));
    printf("Tamanho do int                    : %d bytes\n", sizeof(int));
    printf("Tamanho do unsigned int           : %d bytes\n", sizeof(unsigned int));
    printf("Tamanho do long int               : %d bytes\n", sizeof(long int));
    printf("Tamanho do unsigned long int      : %d bytes\n", sizeof(unsigned long int));
    printf("Tamanho do long long int          : %d bytes\n", sizeof(long long int));
    printf("Tamanho do unsigned long long int : %d bytes\n", sizeof(unsigned long long int));

    /* limits.h */
    printf("\n\n");
    printf("Maximo SHORT INT              = %d\n", SHRT_MAX);
    printf("Maximo INT                    = %d\n", INT_MAX);
    printf("Maximo UNSIGNED INT           = %u\n", UINT_MAX);
    printf("Maximo LONG INT               = %ld\n", LONG_MAX);
    printf("Maximo UNSIGNET LONG INT      = %lu\n", ULONG_MAX);
    printf("Maximo LONG LONG INT          = %lld\n", LLONG_MAX);
    printf("Maximo UNSIGNED LONG LONG INT = %llu\n", ULLONG_MAX);

}
