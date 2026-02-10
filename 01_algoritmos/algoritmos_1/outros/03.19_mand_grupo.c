#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int num1, num2;
    float num_decimal;
    double inteiro, fracionado;

    printf("CALCULADORA\n");
    printf("\n\nDigite um número: ");
    scanf("%d%*c", &num1);

    printf("Digite outro número: ");
    scanf("%d%*c", &num2);

    printf("\nResultaods dos cálculos:");

    printf("\nSoma: %d", (num1 + num2));
    printf("\nSubtração: %d", (num1 - num2));
    printf("\nDivisão: %d", (num1 / num2));
    printf("\nMultiplicação: %d", (num1 * num2));
    printf("\nResto: %d", (num1 % num2));

    //Funções matemáticas avançadas, uso com <math.h>
    printf("\nSena do número 1: %f", (sin(num1)));
    printf("\nCosseno do número 1: %f", (cos(num1)));
    printf("\nTangente do número 1: %f", (tan(num1)));

    printf("\n\nDigite um número decimal: ");
    scanf("%f%*c", &num_decimal);

    printf("\nO número decimal é: %.2f", (num_decimal));
    printf("\nCeil do número decimal: %.2f", (ceil(num_decimal)));
    printf("\nFloor do número decimal: %.2f", (floor(num_decimal)));
    printf("\nLog natural do número decimal: %.2f", (exp(num_decimal)));
    printf("\nValor absoluto do número decimal: %d", (abs(num_decimal)));
    printf("\nLog Natural do número decimal: %.2f", (log(num_decimal)));
    printf("\nLog base 10 do número decimal: %.2f", (log10(num_decimal)));

    fracionado = modf(num_decimal, &inteiro);
    printf("\nMODF do número decimal: %f %f", inteiro, fracionado);

    printf("\nNúmero 1 elevado ao 2: %.2f", (pow(num1, num2)));
    printf("\nRaiz quadrada do número 1: %.2f", (sqrt(num1)));

    getch();
    system("cls");
    main();

    return 0;
}
