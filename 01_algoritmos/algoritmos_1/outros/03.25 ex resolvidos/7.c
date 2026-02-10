#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float s,sr,i;
    printf("Digite o salário:");
    scanf("%f%*c",&s);

    i = s * 0.1;
    sr = s + 50 - i;

    printf("Salário a receber é: %.2f",sr);
    return 0;
}
