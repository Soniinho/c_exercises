#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

float x1, x2;
int max_parcial=0;
// ==============================================
int f_objetivo ()   // maximizar esta função
{
    int result;
    result = 6*x1 + 5*x2;
    return result;
}
// ==============================================
int f_restricao1()  // função de restrição 1
{
    int r1;
    r1 = 15*x1 + 7*x2;
    if (r1 > 49)    return 1;
    else            return 0;
}
// ==============================================
int f_restricao2()   // função de restrição 2
{
    int r2;
    r2 = 2*x1 + 4*x2;
    if (r2 > 17)    return 1;
    else            return 0;
}
// ==============================================
int restricao_inteira()   // Programação Inteira
{
    if ((x1 == abs(x1))&&(x2 == abs(x2)))
        return 0;  // são inteiros
    else
        return 1;
} // ============================================

main ()
{
    int resp, x1_parcial, x2_parcial;
    for (x1=1;x1<=6;x1=x1+0.5)
        for (x2=1;x2<=6;x2=x2+0.5)
        {
            printf("x1= %f    x2= %f\n\n",x1,x2);
            resp = restricao_inteira();
            if (resp ==1)  printf("Restricao de inteiros nao atendida\n");
            else
                {
                   resp = f_restricao1();
                    if (resp ==1)   printf("Restricao 1 nao atendida\n");
                    else
                    {
                        resp = f_restricao2();
                        if (resp ==1)  printf("Restricao 2 nao atendida\n");
                        else
                        {
                            resp = f_objetivo ();
                            if (resp > max_parcial)
                            {
                                x1_parcial = x1;
                                x2_parcial = x2;
                                max_parcial = resp;
                                printf("PARCIAL= %d\n\n",max_parcial);
                            }
                        }
                    }
                }
            Sleep(500);  system("cls");
            }
            printf("x1= %d    x2= %d\n\n",x1_parcial,x2_parcial);
            printf("SOLUCAO= %d\n\n",max_parcial);
            system("pause");
}
