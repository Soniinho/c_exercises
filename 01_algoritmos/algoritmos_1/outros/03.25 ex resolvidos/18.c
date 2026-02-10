#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float peso_saco, racao_gato1, racao_gato2, total_final;

    printf("Digite o peso do saco em quilos:");
    scanf("%f%*c",&peso_saco);
    printf("Digite a quantidade de ração para cada gato (2) em gramas:");
    scanf("%f%f%*c",&racao_gato1,&racao_gato2);

    racao_gato1 = racao_gato1 / 1000;
    racao_gato2 = racao_gato2 / 1000;
    total_final = peso_saco - 5 * (racao_gato1 + racao_gato2);

    printf("Restará no saco após 5 dias %.4f quilos.",total_final);
    return 0;
}
