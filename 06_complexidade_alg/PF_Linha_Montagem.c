/* PROBLEMA DA LINHA DE PRODU√á√ÉO - Backtraking e branch and bound
Prof. Luiz Camolesi Jr. */

#include <stdio.h>
#include <stdlib.h>
#define nlinhas 2
#define nestacoes 6
int /* custos basicos -  linhas  e estacoes */
    custos_est[nlinhas][nestacoes] = {7, 9, 3, 4, 8, 4, 8, 5, 6, 4, 5, 7},
    /* custos das transiÁıes de linhas */
    custo_trans[nlinhas][nestacoes] = {2, 3, 1, 3, 4, 0, 2, 1, 2, 2, 1, 0}, /* lembrar de colocar 0 em transicoes inexistentes */
    /* custos calculados no processo */
    custocalc[nlinhas][nestacoes] = {},
    /* custos de entrada nas linhas */
    custo_entrada[nlinhas] = {2, 4},
    /* custos de saida das linhas */
    custo_saida[nlinhas] = {3, 2};

int cont_passo = 0;

void caminha(int lin, int est, int trans, int *custo, int *min, int *saida)
{
    printf("Custo: %d [linha:%d  estacao:%d]  passo: %d  min atual:%d\n", *custo, lin, est, cont_passo, *min);
    if (est > 5)
        return;

    *custo = *custo + custos_est[lin][est];
    int aux_custo = *custo;
    if (lin == 0)
    {
        if (*custo < *min)
        {
            cont_passo++;
            caminha(lin, est + 1, 0, custo, min, saida);
        }
        if (*custo < *min)
            *min = *custo;
        *custo = aux_custo + custo_trans[lin][est];
        if (*custo < *min)
        {
            cont_passo++;
            caminha(lin + 1, est + 1, 1, custo, min, saida);
        }
        if (*custo < *min)
        {
            *min = *custo;
            *saida = lin + 1; // indicando troca de saida
        }
    }
    else
    {
        *custo = aux_custo;
        if (*custo < *min)
        {
            cont_passo++;
            caminha(lin, est + 1, 0, custo, min, saida);
        }
        if (*custo < *min)
            *min = *custo;
        *custo = aux_custo + custo_trans[lin][est];
        ;
        if (*custo < *min)
        {
            cont_passo++;
            caminha(lin - 1, est + 1, 1, custo, min, saida);
        }
        if (*custo < *min)
        {
            *min = *custo;
            *saida = lin - 1; // indicando troca de saida
        }
    }
}

int main(void)
{
    int custo_1 = 0, custo_2 = 0;
    int min_1 = 1000, min_2 = 1000;
    int saida_1 = 1, saida_2 = 2; // indica por qual linha esta a melhor saida

    custo_1 = custo_1 + custo_entrada[0];
    caminha(0, 0, 0, &custo_1, &min_1, &saida_1);

    custo_2 = custo_2 + custo_entrada[1];
    caminha(1, 0, 0, &custo_2, &min_2, &saida_2);

    printf("custo pela entrada na linha 1: %d\n", min_1);
    printf("custo pela entrada na linha 2: %d\n", min_2);

    printf("Linha de saida iniciando pela linha 1: %d\n", saida_1);
    printf("Linha de saida iniciando pela linha 2: %d\n", saida_2);

    if (min_1 < min_2)
        printf("custo otimo: %d\n", min_1 + custo_saida[saida_1 - 1]);
    else
        printf("custo otimo: %d\n", min_2 + custo_saida[saida_2 - 1]);
}
