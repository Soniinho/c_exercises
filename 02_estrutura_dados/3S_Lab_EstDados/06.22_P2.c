// Matheus Henrique Daltroso RA: 202110059
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/* Considere uma entrada S formada exclusivamente por uma sequência dos caracteres ‘1’ e ‘0’,
 os quais representam as operações de empilhar e desempilhar, respectivamente.
 Escreva um programa recursivo para encontrar o tamanho exato de elementos que a pilha deve
 conter para que as operações em S sejam possíveis de serem executadas. Utilize uma estrutura
 de lista encadeada para implementação da pilha. Apenas o arquivo .c deve ser entregue. */

typedef struct no_pilha
{
    char dado;
    struct no_pilha *prox;
} Tno_pilha;

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_pilha(Tno_pilha **inicio);
int Inicializar2_pilha(Tno_pilha **inicio);
int Inserir_topo(Tno_pilha **inicio, char info);
int Remover_topo(Tno_pilha **inicio);
int Obter_topo(Tno_pilha *inicio, char *dado);
int Verifica_vazio(Tno_pilha *inicio, int *resp);
//$----------------------------------------------------------------------//
int Operacoes_S(Tno_pilha **inicio, int *vezes); //Exercício

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int i, parar, vez;
    char info;

    Tno_pilha *S;
    Inicializar_pilha(&S);

    printf("Digite quantas vezes deseja operar a pilha (empilhar/desempilhar): ");
    scanf("%d%*c", &parar);

    for (i = 0; i < parar; i++)
    {
        printf("Digite 1 (empilhar) ou 0 (desempilhar): ");
        scanf("%c%*c", &info);

        Inserir_topo(&S, info);
    }

    vez = 0;
    Operacoes_S(&S, &vez);

    if (vez < 0)
        vez = vez * (-1);

    printf("\nA pilha deverá ter no mínimo %d elementos antes das operações S.", vez);

    Inicializar2_pilha(&S);
    free(S);
}

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_pilha(Tno_pilha **inicio)
{
    *inicio = NULL;
    return 0;
}

int Inicializar2_pilha(Tno_pilha **inicio)
{
    Tno_pilha *percorre, *aux;
    if (*inicio != NULL)
    {
        percorre = *inicio;
        while (percorre != NULL)
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }
        *inicio = NULL;
        return 1; // inicializa apagando tudo da pilha
    }
}

int Inserir_topo(Tno_pilha **inicio, char info)
{
    Tno_pilha *no_novo;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_pilha *)malloc(sizeof(Tno_pilha));
    no_novo->dado = info;

    if (*inicio == NULL)
    { // inserção em pilha vazia
        no_novo->prox = NULL;
        *inicio = no_novo;
    }
    else
    { // inserção em pilha não vazia
        no_novo->prox = *inicio;
        *inicio = no_novo;
    }
    return 0;
}

int Remover_topo(Tno_pilha **inicio)
{
    Tno_pilha *aux;
    if (*inicio == NULL)
    {
        return 1; /* pilha vazia, impossível remover topo */
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Obter_topo(Tno_pilha *inicio, char *dado)
{
    if (inicio != NULL)
    {
        *dado = inicio->dado;
        return 0;
    }
    else
        return 1; // Pilha Vazia
}

int Verifica_vazio(Tno_pilha *inicio, int *resp)
{
    if (inicio != NULL)
        *resp = 0; // Pilha não Vazia
    else
        *resp = 1; // Pilha Vazia
    return 0;
}
//$----------------------------------------------------------------------//
/* //sem recursivo
int Operacoes_S(Tno_pilha **inicio, int *vezes)
{
    int vazio;
    char dado;

    *vezes = 0;
    Verifica_vazio(*inicio, &vazio);
    while (vazio == 0)
    {
        Obter_topo(*inicio, &dado);
        Remover_topo(inicio);

        if (dado == '0')
            (*vezes)--;
        if (dado == '1')
            (*vezes)++;
        Verifica_vazio(*inicio, &vazio);
    }

    return 0;
}
*/

int Operacoes_S(Tno_pilha **inicio, int *vezes)
{
    int vazio;
    char dado;

    Verifica_vazio(*inicio, &vazio);
    if (vazio == 0)
    {
        Obter_topo(*inicio, &dado);
        Remover_topo(inicio);

        if (dado == '0')
            (*vezes)--;
        if (dado == '1')
            (*vezes)++;
        Operacoes_S(inicio, vezes);
    }

    return 0;
}
