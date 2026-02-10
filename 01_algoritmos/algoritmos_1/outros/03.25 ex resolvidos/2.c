#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float n1,n2,n3,m;
    printf("Digite 3 notas:");
    scanf("%f%f%f%*c",&n1,&n2,&n3);
    m = (n1+n2+n3)/3;
    printf("A média é %.2f",m);
    return 0;
}
