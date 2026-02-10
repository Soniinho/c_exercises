#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, n;

    printf("Esse programa irá mostrar as tabuadas do números 1 ao 100. Aperte \"enter\" para continuar...");
    getchar();
    system("cls");
    
    for (i = 1; i <= 100; i++)
    {
        printf("   Tabuada do %d\n", i);
        for (n = 0; n <= 10; n++)
        {
            printf("\n      %d x %d \t= %d", i, n, i * n);
        }
        printf("\n\n");
    }

    system("pause");
    return 0;
}