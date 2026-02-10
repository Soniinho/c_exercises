#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>
#define N 10

//total de vendas em reais e perc_comissao em %
int main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    char vendedores[N][30];
    char maior_nome[30], menor_nome[30];
    float tot_vend_ind[N], perc_comissao[N];
    float tot_vendas = 0, maior_val, menor_val;

    printf("Digite os nomes dos vendedores, seu total de vendas em reais e o percentual de comissão\nde cada um:\n\n");
    for (i = 0; i < N; i++)
    {
        printf("%dº: ", i + 1);
        fgets(vendedores[i], 30, stdin);
        vendedores[i][strlen(vendedores[i]) - 1] = 0; //tirar \n

        printf("Total de vendas de %s: R$", vendedores[i]);
        scanf("%f%*c", &tot_vend_ind[i]);
        tot_vendas += tot_vend_ind[i];

        printf("Percentual de comissão de %s: ", vendedores[i]);
        scanf("%f%*c", &perc_comissao[i]);

        if (i == 0)
        {
            maior_val = menor_val = tot_vend_ind[i]; //os 2 são iguais a tot_vend_ind
            strcpy(maior_nome, vendedores[i]);
            strcpy(menor_nome, vendedores[i]);
        }
        else if (tot_vend_ind[i] > maior_val)
        {
            maior_val = tot_vend_ind[i];
            strcpy(maior_nome, vendedores[i]);
        }
        else if (tot_vend_ind[i] < menor_val)
        {
            menor_val = tot_vend_ind[i];
            strcpy(menor_nome, vendedores[i]);
        }
    }
    printf("\nExtrato\n");
    for (i = 0; i < N; i++)
    {
        printf("%dº vendedor = %s\n", i+1, vendedores[i]);
        printf("Comissão = %.2f\n\n", tot_vend_ind[i] * (perc_comissao[i] / 100));
    }

    printf("O total de vendas foi de %.2f.\n", tot_vendas);
    printf("O maior valor a receber é de R$%.2f, e o funcionário %s que o receberá.\n", maior_val, maior_nome);
    printf("O menor valor a receber é de R$%.2f, e o funcionário %s que o receberá.\n", menor_val, menor_nome);
    
    return 0;
}