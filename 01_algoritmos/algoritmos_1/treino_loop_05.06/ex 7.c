#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define qtd_pessoas 5

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, idade;
    float altura, peso;
    float cont_idade = 0, soma_alturas = 0, qtd_pessoas_menor_40 = 0, med_alturas, porcentagem;

    printf("Será pedido para digitar 3 informações de %d pessoas. Aperter qualquer tecla para continuar...", qtd_pessoas);
    getchar();
    system("cls");

    for (i = 1; i <= 5; i++)
    {
        printf("%dª pessoa:\n", i);
        printf("Digite a idade em anos:");
        scanf("%d%*c", &idade);
        printf("Digite a altura em metros:");
        scanf("%f%*c", &altura);
        printf("Digite o peso em kg:");
        scanf("%f%*c", &peso);

        if (idade > 50)
        {
            cont_idade = +1;
        }
        else if (idade >= 10 && idade <= 20)
        {
            soma_alturas = +altura;
        }
        else if (peso < 40)
        {
            qtd_pessoas_menor_40 = +1;
        }
        printf("\n");
    }

    printf("A quantidade de pessoas com idade superior a 50 anos é de %.2f pessoas.", cont_idade);

    med_alturas = soma_alturas / qtd_pessoas;
    printf("\nA média das alturas de pessoas com idade entre 10 e 20 anos é de %.2f metros.", med_alturas);

    porcentagem = (qtd_pessoas_menor_40 / qtd_pessoas) * 100;
    printf("\nA porcentagem de pessoas com peso inferior a 40 kg entre todos os analisados é de %.2f %%.", porcentagem);

    system("pause");
    return 0;
}