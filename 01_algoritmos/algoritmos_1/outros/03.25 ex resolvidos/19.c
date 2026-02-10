#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float a_degrau, a_usuario, qtd_degraus;
    printf("Digite a altura de cada degrau:");
    scanf("%f%*c",&a_degrau);
    printf("Digite a sua altura:");
    scanf("%f%*c",&a_usuario);

    qtd_degraus = a_usuario / a_degrau;
    printf("A quantidade de degraus é de %.2f.",qtd_degraus);

    return 0;
}
