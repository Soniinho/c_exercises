#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    float saldo_ini, saque, deposito, saldo;
    char opcao;
    
    printf("Digite o saldo inicial de sua conta do banco XYZ:\n");
    scanf("%f%*c", &saldo_ini);
    saldo = saldo_ini;

    for (i = 1; i <= 5; i = i + 1)
    {
        printf("\n%dª movimentação", i);
        printf("\n   D- Depósito");
        printf("\n   S- Saque");
        printf("\nDigite \"S\" para sacar ou \"D\" para depositar: ");
        scanf("%c%*c", &opcao);
        //printf("\n");

        if (opcao == 'D')
        {
            printf("Digite o quanto quer depositar:");
            scanf("%f%*c", &deposito);
            saldo = saldo + deposito;
        }
        else if (opcao == 'S')
        {
            printf("Digite o quanto quer sacar:");
            scanf("%f%*c", &saque);
            saldo = saldo - saque;
        }
        else
        {
            printf("Opção inválida, reinicie o programa.");
            return 0;
        }
    }

    printf("\nO saldo inicial era de %.2f reais.\n", saldo_ini);
    printf("Agora o seu novo saldo é de %.2f reais.", saldo);
    return 0;
}