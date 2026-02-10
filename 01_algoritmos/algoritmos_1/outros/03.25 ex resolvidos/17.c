#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float salario, cheque1, cheque2, cpmf1, cpmf2, saldo;
    printf("Digite o salário e os valores dos 2 cheques:");
    scanf("%f%f%f%*c",&salario,&cheque1,&cheque2);

    cpmf1 = cheque1 * 0.0038;
    cpmf2 = cheque2 * 0.0038;
    saldo = salario - cheque1 - cheque2 - cpmf1 - cpmf2;

    printf("O saldo da conta é de %.2f.",saldo);
    return 0;
}
