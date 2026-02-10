#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float n1,n2,n3,p1,p2,p3,m;
    printf("Digite 3 notas:");
    scanf("%f%f%f%*c",&n1,&n2,&n3);
    printf("Digite os 3 pesos:");
    scanf("%f%f%f%*c",&p1,&p2,&p3);
    m = (n1*p1+n2*p2+n3*p3)/(p1+p2+p3);
    printf("A média ponderada é: %.2f",m);
    return 0;
}
