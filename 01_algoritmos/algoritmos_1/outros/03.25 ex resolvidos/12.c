#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float n1,n2,r1,r2;
    printf("Digite 2 números maiores que 0:");
    scanf("%f%f%*c",&n1,&n2);

    r1 = pow(n1,n2);
    r2 = pow(n2,n1);

    printf("As duas opções uma elevada a outra são: %.2f e %.2f",r1,r2);

    return 0;
}
