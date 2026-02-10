#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float s,sr,g,i;
    printf("Digite o salário:");
    scanf("%f%*c",&s);

    g = s * 0.05;
    i = s * 0.07;
    sr = s + g - i;

    printf("Salário a receber é: %.2f",sr);
    return 0;
}
