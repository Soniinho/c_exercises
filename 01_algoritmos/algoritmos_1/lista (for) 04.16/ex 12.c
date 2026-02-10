#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <math.h>
#define sal_ini (double)2000

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a;
    double salario, aumento;
    salario = sal_ini;

    //1996
    salario = sal_ini * 0.015;

    //2021 - 1997 = 24
    for (a = 1; a <= 24; a++)
    {
        aumento = (0.015 * pow(2,a));
        salario = salario * aumento;        
    }

    printf("Um funcionário recebe aumento anual. Em 1995 foi contratado por %.2lf reais.\n", sal_ini);
    printf("Em 2021 seu salário será de %.2lf reais.\n", salario); 

    return 0;
}