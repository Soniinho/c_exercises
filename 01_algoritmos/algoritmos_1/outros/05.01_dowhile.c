#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "portuguese");

    int contador;
    /* //for (mais restrito)
        //início, final, de quanto em quanto
        for(contador = 1; contador <= 10; contador++)
        {
            printf("\nValor: %d", contador);
        }
        printf("\n");
        for(contador = 10; contador >= 0; contador--)
        {
            printf("\nValor: %d", contador);
        }
        printf("\n");
    */ /*
    //condição
    contador = 1;
    while(contador <= 10)
    {
        printf("\nValor: %d", contador);
        contador++;
    }
    printf("\n");

    contador = 0;
    while(contador != -1)
    {
        printf("\nValor: %d", contador);
        printf("\nDigite um valor diferente de -1 para continuar: ");
        scanf("%d",&contador);
    }
*/

/* //executado dps de ser checado //while (controle de usuário)
    int x = 0; //ou if(x % 2 == 0); x++
    while(x <= 100){
        printf("\nValor: %d", x);
        x += 2;
    }
*/

    //executar pelo menos uma vez sem ser checado //do while
    int x = 0; //início
    do //passo
    {
        printf("\nValor: %d", x);
        x += 2;
    }
    while(x <= 100);//fim

    //exit(main);
}
