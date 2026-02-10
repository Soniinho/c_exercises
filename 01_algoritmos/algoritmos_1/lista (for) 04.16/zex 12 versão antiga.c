#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define sal_ini 2000

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a;
    double salario_ano, salario, aumento;
    salario = sal_ini;

    //1996
    salario_ano = sal_ini * 0.015;
    salario += salario_ano;

    //2021 - 1997 = 24
    for (a = 1; a <= 24; a++)
    {
        aumento = (0.015 * 2) * a;
        salario_ano = sal_ini * aumento;
        salario += salario_ano; //salario = salario + salario_ano
    }

    printf("Um funcionário recebe aumento anual. Em 1995 foi contratado por 2000,00 reais.\n");
    printf("Em 2021 seu salário será de %.2lf reais.\n", salario); //20030

    return 0;
}