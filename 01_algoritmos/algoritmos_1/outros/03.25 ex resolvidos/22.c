#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float vlr_sal, qtd_kw, vlr_kw, vlr_reais, desc, vlr_desc;
    printf("Digite o valor do salário mínimo:");
    scanf("%f%*c",&vlr_sal);
    printf("Digite a quantidade de Kw consumida por uma residência:");
    scanf("%f%*c",&qtd_kw);

    vlr_kw = vlr_sal / 5;
    vlr_reais = vlr_kw * qtd_kw;
    desc = vlr_reais * 0.15;
    vlr_desc = vlr_reais - desc;

    printf("%.2f kw.",vlr_kw);
    printf("\n%.2f reais.",vlr_reais);
    printf("\n%.2f desconto.",vlr_desc);

    return 0;
}
