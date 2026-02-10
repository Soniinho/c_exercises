#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float salario, gasto_total;
    printf("Informe o total gasto:");
    scanf("%f%*c",&gasto_total);
    printf("Informe o salário:");
    scanf("%f%*c",&salario);

    if(salario<=gasto_total){
        printf("Gastos dentro do orçamento.");
    } else {
        printf("Orçamento estrourado.");
    }

    return 0;
}
