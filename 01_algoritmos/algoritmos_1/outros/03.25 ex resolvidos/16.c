#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float horas_t, vlr_sal_min, vlr_hora_t,
          vlr_sal_bru, imp, vlr_sal_liq;

    printf("Digite o número de horas trabalhadas:");
    scanf("%f%*c",&horas_t);
    printf("Digite o valor do salário mínimo:");
    scanf("%f%*c",&vlr_sal_min);

    vlr_hora_t = vlr_sal_min / 2;
    vlr_sal_bru = vlr_hora_t * horas_t;
    imp = vlr_sal_bru * 0.03;
    vlr_sal_liq = vlr_sal_bru - imp;

    printf("O valor do salário liquido é de %.2f",vlr_sal_liq);

    return 0;
}
