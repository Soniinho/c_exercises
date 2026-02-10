#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, idade;
    float qtd_v = 0, qtd_c = 0, qtd_a = 0, qtd_f = 0, qtd_m = 0, qtd_f_v = 0, qtd_m_a = 0, qtd_f_c = 0;
    float porcentagem;
    char sexo, cor_olho;

    printf("Serão pedidos o sexo, cor dos olhos e idade de 6 pessoas, faça como se pede.");
    printf("\nAperte \"enter\" para continuar.");
    getchar();

    for (i = 1; i <= 6; i++)
    {
        printf("\n%dª pessoa", i);
        printf("\nf - feminino");
        printf("\nm - masculino");
        printf("\nDigite o sexo da pessoa conforme as opções acima: ");
        scanf("%c%*c", &sexo);

        if (sexo != 'm' && sexo != 'f')
        {
            printf("\nOpção inválida, reinicie o programa.\n");
            return 0;
        }

        printf("v - verdes");
        printf("\nc - castanhos");
        printf("\na - azuis");
        printf("\nDigite a cor de olho da pessoa conforme as opções acima: ");
        scanf("%c%*c", &cor_olho);

        if(cor_olho != 'v' && cor_olho != 'c' && cor_olho != 'a')
        {
            printf("\nOpção inválida, reinicie o programa.\n");
            return 0;
        }

        printf("Digite a idade da pessoa em anos: ");
        scanf("%d%*c", &idade);

        if (sexo == 'f')
        {
            qtd_f += 1;
            if (cor_olho == 'v')
            {
                qtd_v += 1;
                qtd_f_v += 1;
            }
            else if (cor_olho == 'c')
            {
                qtd_c += 1;
                qtd_f_c += 1;
            }
            else if (cor_olho == 'a')
            {
                qtd_a += 1;
            }
        }
        else if (sexo == 'm')
        {
            qtd_m += 1;
            if (cor_olho == 'v')
            {
                qtd_v += 1;
            }
            else if (cor_olho == 'c')
            {
                qtd_c += 1;
            }
            else if (cor_olho == 'a')
            {
                qtd_a += 1;
                qtd_m_a += 1;
            }
        }
    }

    printf("\nHá %.0f pessoas com olhos verdes.", qtd_v);
    printf("\nHá %.0f pessoas com olhos castanhos.", qtd_c);
    printf("\nHá %.0f pessoas com olhos azuis.", qtd_a);
    printf("\nHá %.0f mulheres com olhos verdes.", qtd_f_v);
    printf("\nHá %.0f homens com olhos azuis.", qtd_m_a);

    porcentagem = (qtd_f_c / qtd_f) * 100;

    printf("\n%.2f %% das mulheres apresentadas têm olhos castanhos.", porcentagem);

    return 0;
}