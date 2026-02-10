#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int n1, n2;
    
    if (&n1 > &n2)
    {
        printf("O endereço de n1 é maior: [%p]", &n1);
    }
    else
    {
        printf("O endereço de n2 é maior: [%p]", &n2);
    }

    return 0;
}