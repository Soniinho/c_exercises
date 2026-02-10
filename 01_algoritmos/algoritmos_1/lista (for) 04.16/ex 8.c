#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define n_pessoas 5

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, idade, c_idade;
    float altura, peso, soma_alturas, med_alturas, porc_pessoas, soma_pess_menor_40;
    c_idade = 0;
    soma_alturas = 0;
    soma_pess_menor_40 = 0;

    printf("Será pedido para digitar a idade, altura e peso de 5 pessoas.\n");
    printf("Aperte \"enter\" para continuar.\n");
    getchar();

    for (i = 1; i <= n_pessoas; i++)
    {
        printf("%dª pessoa\n", i);
        printf("Digite a idade da pessoa em anos:");
        scanf("%d%*c", &idade);
        printf("Digite a altura da pessoa em metros:");
        scanf("%f%*c", &altura);
        printf("Digite o peso da pessoa em kg:");
        scanf("%f%*c", &peso);
        printf("\n");

        if (peso < 40) //ver se é inclusive 40
        {
            soma_pess_menor_40 = soma_pess_menor_40 + 1;
        }

        if (idade > 50)
        {
            c_idade = c_idade + 1;
        }
        else if (idade > 10 && idade < 20) //ver se é inclusive 10 e 20
        {
            soma_alturas = soma_alturas + altura;
        }
    }

    med_alturas = soma_alturas / n_pessoas;                //5 pessoas
    porc_pessoas = (soma_pess_menor_40 / n_pessoas) * 100; // (soma / total) * 100

    printf("Há %d pessoas com idade superior a 50 anos.\n", c_idade);
    printf("A média das alturas das pessoas com idade entre 10 e 20 anos é de %.2f metros.\n", med_alturas);
    printf("A porcentagem de pessoas com peso inferior a 40 kg entre todas as analisadas é de %.2f %%.", porc_pessoas);

    return 0;
}