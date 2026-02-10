#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float p_fab, perc_d, perc_i, vlr_d, vlr_i, p_final;
    printf("Digite o preço de fábrica, o percentual de lucro do distribuidor e os impostos:");
    scanf("%f%f%f%*c",&p_fab, &perc_d, &perc_i);

    vlr_d = p_fab * perc_d/100;
    vlr_i = p_fab * perc_i/100;
    p_final = p_fab + vlr_d + vlr_i;

    printf("O lucro do distribuidor é de %.2f.",vlr_d);
    printf("\nO valor dos impostos é de %.2f.",vlr_i);
    printf("\nO preço final do veículo é de %.2f.",p_final);
    return 0;
}
