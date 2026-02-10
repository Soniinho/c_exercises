#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float s,ns;
    printf("Digite o salário:");
    scanf("%f%*c",&s);
    ns = s + s*0.25;
    printf("O novo salário é: %.2f", ns);
    return 0;
}
