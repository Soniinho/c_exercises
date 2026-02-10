#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int ct100 = 0, ct50 = 0, ct20 = 0, ct10 = 0, ct5 = 0, ct2 = 0, ct1 = 0;
    int saque, saque_menos, saque_ini;
    
    printf("Digite o quanto quer sacar de sua conta em reais:");
    scanf("%d%*c", &saque_ini);

    for (saque = saque_ini; saque > 0; saque -= saque_menos)
    {
        if (saque >= 100)
        {
            saque_menos = 100;
            ct100 += 1;
        }
        else if (saque >= 50)
        {
            saque_menos = 50;
            ct50 += 1;
        }
        else if (saque >= 20)
        {
            saque_menos = 20;
            ct20 += 1;
        }
        else if (saque >= 10)
        {
            saque_menos = 10;
            ct10 += 1;
        }
        else if (saque >= 5)
        {
            saque_menos = 5;
            ct5 += 1;
        }
        else if (saque >= 2)
        {
            saque_menos = 2;
            ct2 += 1;
        }
        else if (saque >= 1)
        {
            saque_menos = 1;
            ct1 += 1;
        }
    }

    printf("\nPara o valor %d:", saque_ini);
    printf("\nvocê receberá %d notas de 100, %d notas de 50, %d notas de 20,", ct100, ct50, ct20);
    printf("\n%d notas de 10, %d notas de 5, %d notas de 2 e %d moedas de 1 real.\n", ct10, ct5, ct2, ct1);
    printf("\nObs: Neste programa, centavos são desconsiderados.\n");
    return 0;
}