#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int x;
    float v[10];

    for (x = 0; x < 10; x++)
    {
        printf("Digite um número[%d]: ", x);
        scanf("%f%*c", &v[x]);
    }

    for (x = 0; x < 9; x++)
    {
        v[x + 1] = v[x] + v[x + 1];
    }

    system("cls");

    printf("\nO vetor será:\n");
    for (x = 0; x < 10; x++)
    {
        printf("%.2f\n", v[x]);
    }
    
    return 0;
}