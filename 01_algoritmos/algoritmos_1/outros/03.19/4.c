#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int g1, g2;
    printf("Digite o n° de gols do primeiro time:");
    scanf("%d%*c",&g1);
    printf("Digite o n° de gols do segundo time:");
    scanf("%d%*c",&g2);

    if(g1==g2){
        printf("Empate: %d a %d",g1,g2);
    } else {
        if(g1>g2){
            printf("Vítoria do primeiro time: %d x %d",g1,g2);
        } else {
            printf("Vítoria do segundo time: %d x %d",g1,g2);
        }
    }

    return 0;
}
