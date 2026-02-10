#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float hrs_trabal, salario_min, hrs_extras_trabal, sal_bruto, vlr_hrs_trabal, vlr_hrs_extras_trabl;
    printf("Digite o número de horas trabalhadas, o valor do salário mínimo e o número de horas extras trabalhadas:\n");
    scanf("%f%f%f%*c", &hrs_trabal, &salario_min, &hrs_extras_trabal);

    vlr_hrs_trabal = (salario_min * 1/8); // 1/8 0.125 ou 0.125 * salario_min
    vlr_hrs_extras_trabl = (salario_min * 1/4); // 1/4 0.25 ou 0.25 * salario_min
    sal_bruto = hrs_trabal * vlr_hrs_trabal + hrs_extras_trabal * vlr_hrs_extras_trabl;

    printf("O valor a ser recebido é de %.2f.", sal_bruto);
    return 0;

    /*
    float a,b;
    printf("escreva a e b:");
    scanf("%f%f",&a,&b);
    printf("%f",1/8);
    */
}
