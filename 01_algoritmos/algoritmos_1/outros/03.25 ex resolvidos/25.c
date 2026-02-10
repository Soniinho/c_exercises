#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float custo, convite, qtd;
    printf("Digite o custo do espetáculo:");
    scanf("%f%*c",&custo);
    printf("Digite o custo por convite:");
    scanf("%f%*c",&convite);

    qtd = custo / convite;

    printf("A quantidade a ser vendida é de %.2f.",qtd);

    return 0;
}
