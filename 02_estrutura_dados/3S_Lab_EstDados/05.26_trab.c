// Matheus Henrique Daltroso RA: 202110059
// Thalissa Visentim Lopes   RA: 202110073

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct l1
{
    char letra;
    struct l1 *prox;
};
typedef struct l1 L1;

struct l2
{
    int num;
    struct l2 *prox;
};
typedef struct l2 L2;

/* ---------------------------------------------------------------------- */
int Inicializar_LS(L1 **inicio, L2 **inicio2);
int Apagar_LS(L1 **inicio, L2 **inicio2);

int Inserir_fim_L1(L1 **inicio, char info);
int Remover_inicio_L1(L1 **inicio);
int Listar_L1(L1 *inicio);
int Obter_Tamanho_L1(L1 *inicio, int *tam);

int Inserir_fim_L2(L2 **inicio2, int info);
int Listar_L2(L2 *inicio2);

int Remove_todos_a(L1 **inicio, char a);
int Muda_Null(L1 **inicio, L2 **inicio2);
/* ---------------------------------------------------------------------- */

int main(void)
{
    setlocale(LC_ALL, "portuguese");

    int i, numero, opc;
    char letra;

    L1 *lista1;
    L2 *lista2;

    Inicializar_LS(&lista1, &lista2);

    printf("Digite a quantidade de letras que deseja na L1: ");
    scanf("%d%*c", &opc);
    for (i = 0; i < opc; i++)
    {
        printf("Digite 1 letra[%d]: ", i + 1);
        scanf("%c%*c", &letra);
        Inserir_fim_L1(&lista1, letra);
    }

    printf("\nDigite a quantidade de posições(nº) que deseja na L2: ");
    scanf("%d%*c", &opc);
    for (i = 0; i < opc; i++)
    {
        do
        {
            printf("Digite 1 nº[%d]: ", i + 1);
            scanf("%d%*c", &numero);
        } while (numero < 0); // n pd negativo

        numero--; // pra digitar começando em 1
        Inserir_fim_L2(&lista2, numero);
    }

    Listar_L1(lista1);
    Listar_L2(lista2);

    Muda_Null(&lista1, &lista2);
    printf("\n");

    Listar_L1(lista1);
    Listar_L2(lista2);

    Apagar_LS(&lista1, &lista2);
}

/* ---------------------------------------------------------------------- */
int Inicializar_LS(L1 **inicio, L2 **inicio2)
{
    *inicio = NULL;
    *inicio2 = NULL;
    return 0;
}

int Apagar_LS(L1 **inicio, L2 **inicio2)
{
    L1 *percorre, *aux;
    L2 *percorre2, *aux2;

    if (*inicio2 != NULL)
    {
        percorre2 = *inicio2;
        do
        {
            aux2 = percorre2;
            percorre2 = percorre2->prox;
            free(aux);
        } while (percorre2 != NULL);
        *inicio2 = NULL;
    }

    if (*inicio != NULL)
    {
        percorre = *inicio;
        do
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        } while (percorre != NULL);
        *inicio = NULL;
        return 1; /* inicializa apagando tudo da lista */
    }
    else
    {
        return 0;
    }
}
/* ---------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */
int Inserir_fim_L1(L1 **inicio, char info)
{
    L1 *no_novo, *percorre;

    /* Criacao do novo nó - Alocação de memória */
    no_novo = (L1 *)malloc(sizeof(L1));
    no_novo->letra = info;
    no_novo->prox = NULL;

    if (*inicio == NULL)
    { /* lista vazia. */
        *inicio = no_novo;
    }
    else
    { /* lista não vazia */
        percorre = *inicio;
        while (percorre->prox != NULL)
        {
            percorre = percorre->prox;
        }
        percorre->prox = no_novo;
    }
    return 0;
}

int Remover_inicio_L1(L1 **inicio)
{
    L1 *aux;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemoção Impossível\n");
        return 1; /* lista vazia, impossível remover primeiro */
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Listar_L1(L1 *inicio)
{
    int i;
    L1 *aux;

    if (inicio == NULL)
    {
        return 1;
    }
    printf("LISTA: (%c", inicio->letra);
    aux = inicio->prox;
    while (aux != NULL)
    {
        printf(",%c", aux->letra);
        aux = aux->prox;
    }

    printf(")\n");
    return 0;
}

int Obter_Tamanho_L1(L1 *inicio, int *tam)
{
    L1 *percorre;
    *tam = 0;
    if (inicio != NULL)
    {
        percorre = inicio;
        while (percorre != NULL)
        {
            (*tam)++;
            percorre = percorre->prox;
        }
    }
    else
    {
        *tam = 0;
    }
}
/* ---------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */
int Inserir_fim_L2(L2 **inicio2, int info)
{
    L2 *no_novo, *percorre;

    /* Criacao do novo nó - Alocação de memória */
    no_novo = (L2 *)malloc(sizeof(L1));
    no_novo->num = info;
    no_novo->prox = NULL;

    if (*inicio2 == NULL)
    { /* lista vazia. */
        *inicio2 = no_novo;
    }
    else
    { /* lista não vazia */
        percorre = *inicio2;
        while (percorre->prox != NULL)
        {
            percorre = percorre->prox;
        }
        percorre->prox = no_novo;
    }
    return 0;
}

int Listar_L2(L2 *inicio2)
{
    int i;
    L2 *aux;

    if (inicio2 == NULL)
    {
        return 1;
    }
    printf("LISTA: (%d", (inicio2->num + 1));
    aux = inicio2->prox;
    while (aux != NULL)
    {
        printf(",%d", (aux->num + 1));
        aux = aux->prox;
    }

    printf(")\n");
    return 0;
}

/* ---------------------------------------------------------------------- */

int Remove_todos_a(L1 **inicio, char a)
{
    int tam;
    L1 *percorre, *ant;

    /* Tratamento de erros ======================================= */
    if (*inicio == NULL)
        return 1; // lista vazia
    /* =========================================================== */

    while ((*inicio)->letra == a) // remover do início
    {
        Remover_inicio_L1(inicio);
        /*
        if (tam == 1 && (*inicio)->letra == a) // se primeiro for e se só tiver 1
        {
            free(*inicio);
            *inicio = NULL;
        }
        else
        {
            ant = *inicio;
            *inicio = ant->prox;
            free(ant);
        }
        Obter_Tamanho_L1(*inicio, &tam);
        */
    }

    // remover do meio (errado)
    percorre = *inicio;
    while (percorre->prox != NULL)
    {
        if (percorre->letra == a)
        {
            ant->prox = percorre->prox;
            free(percorre);
            percorre = ant->prox;
        }
        else
        {
            ant = percorre;
            percorre = percorre->prox;
        }
    }

    // remove último
    if (percorre->letra == a)
    {
        ant->prox = NULL;
        free(percorre);
    }

    return 0;
}

int Muda_Null(L1 **inicio, L2 **inicio2)
{
    int i, pos_l2;
    L2 *percorre, *aux_1;
    L1 *anda;

    // andar a lista 2 toda
    percorre = *inicio2;
    while (percorre != NULL)
    {
        pos_l2 = percorre->num;

        // mudar na posição que l2 escolhe a 'letra' para '\0'
        anda = *inicio;
        for (i = 0; i <= pos_l2; i++)
        {
            if (i != pos_l2)
                anda = anda->prox;
            else
                anda->letra = '\0';
        }

        percorre = percorre->prox;
    }

    Remove_todos_a(inicio, '\0');

    return 0;
}
