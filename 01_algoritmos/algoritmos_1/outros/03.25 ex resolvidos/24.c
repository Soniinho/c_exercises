#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    double hora, h, m, conversao,z;
    printf("Digite a hora:");
    scanf("%lf%*c",&hora);
    z = modf(hora,&h);
    m = hora - h;
    conversao = (h*60) + (m*100);
    printf("%lf minutos.",conversao);

    return 0;
}
