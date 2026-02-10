//vetor 05.17 ex 3

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define Q 10

//pelo menos 1 pedido é necessário, mesmo se o cod_cliente = 0
int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, existe = 0;
    int cod_produtos[Q], total_estoque[Q];
    int cod_cliente, cod_compra, qtd_produto;

    printf("Digite 10 códigos de produtos e sua quantidade no estoque:\n\n");

    for (i = 0; i < Q; i++)
    {
        printf("%dº produto: ", i + 1);
        scanf("%d%*c", &cod_produtos[i]);

        printf("Total deste produto no estoque: ");
        scanf("%d%*c", &total_estoque[i]);
    }

    printf("\nParte do cliente:\n\n");

    do
    {
        printf("Digite o código do produto que deseja comprar: ");
        scanf("%d%*c", &cod_compra);

        for (i = 0; i < Q; i++)
        {
            if (cod_compra == cod_produtos[i])
            {
                existe = 1;
                break;
            }
        }

        if (existe == 1)
        {
            printf("Digite quanto deseja comprar: ");
            scanf("%d%*c", &qtd_produto);

            printf("\n");
            if (total_estoque[i] == 0)
            {
                printf("Não temos estoque suficiente dessa mercadoria.");
            }
            else if (qtd_produto <= total_estoque[i])
            {
                total_estoque[i] -= qtd_produto;
                printf("Pedido atendido.");
            }
            else if (qtd_produto > total_estoque[i])
            {
                printf("Só foi possível comprar %d produtos.", total_estoque[i]);
                total_estoque[i] = 0;
            }
            existe = 0;
        }
        else
        {
            printf("\nEsse código de produto não existe em nosso estoque.");
        }

        printf("\n\nDigite o seu código de cliente (0 finaliza as compras): ");
        scanf("%d%*c", &cod_cliente);
        printf("\n");
    } while (cod_cliente != 0);

    system("cls");

    for (i = 0; i < Q; i++)
    {
        printf("Código[%d]: %d\n", i + 1, cod_produtos[i]);
        printf("Quantidade desse produto no estoque: %d\n\n", total_estoque[i]);
    }
    printf("Obrigado, volte sempre!");

    exit(main);
}