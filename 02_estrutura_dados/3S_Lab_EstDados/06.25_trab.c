// Matheus Henrique Daltroso RA: 202110059
//todo: não fiz direito
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/* -----------------------------------------------------------------------------
^                           Estrutura Fila DINÂMICA
------------------------------------------------------------------------------*/

typedef struct no_fila
{
    int mom_chegada, direc;
    struct no_fila *prox;
} Tno_fila;

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_fila(Tno_fila **inicio);
int Inicializar2_fila(Tno_fila **inicio);
int Inserir_fim(Tno_fila **inicio, int chegada, int dir);
int Remover_inicio(Tno_fila **inicio);
int Obter_inicio(Tno_fila *inicio, int *dado1, int *dado2);
int Estado(Tno_fila *inicio, int *resp);
//$----------------------------------------------------------------------//
int Calcular(Tno_fila **inicio, int *saida);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int i, pess, tempo, temp_antes, direcao, saida;

    Tno_fila *ini;
    Inicializar_fila(&ini);

    do
    {
        printf("Digite quantas pessoas irão na escada rolante: ");
        scanf("%d%*c", &pess);
    } while (pess < 1 || pess > 10000);

    temp_antes = 0;
    for (i = 0; i < pess; i++)
    {
        do
        {
            printf("\nDigite o momento que a pessoa entra na escada: ");
            scanf("%d%*c", &tempo);
        } while (tempo <= temp_antes || tempo > 100000);

        do
        {
            printf("Digite 0 (->) ou 1 (<-): ");
            scanf("%d%*c", &direcao);
        } while (direcao != 0 && direcao != 1);

        Inserir_fim(&ini, tempo, direcao);
    }

    Calcular(&ini, &saida);

    system("cls");
    printf("O último momento que a escada para é: %d", saida);

    Inicializar2_fila(&ini);
}

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_fila(Tno_fila **inicio)
{
    *inicio = NULL;
    return 0;
}

int Inicializar2_fila(Tno_fila **inicio)
{
    Tno_fila *percorre, *aux;
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
        return 1; // inicializa apagando tudo da fila
    }
}

int Inserir_fim(Tno_fila **inicio, int chegada, int dir)
{
    Tno_fila *no_novo, *percorre;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_fila *)malloc(sizeof(Tno_fila));
    no_novo->mom_chegada = chegada;
    no_novo->direc = dir;

    if (*inicio == NULL)
    { // inserção em fila vazia
        no_novo->prox = NULL;
        *inicio = no_novo;
    }
    else
    { // inserção em fila não vazia
        percorre = *inicio;
        while (percorre->prox != NULL)
        {
            percorre = percorre->prox;
        }
        percorre->prox = no_novo;
    }
    return 0;
}

int Remover_inicio(Tno_fila **inicio)
{
    Tno_fila *aux;
    if (*inicio == NULL)
    {
        return 1; /* fila vazia, impossível remover topo */
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Obter_inicio(Tno_fila *inicio, int *dado1, int *dado2)
{
    if (inicio != NULL)
    {
        *dado1 = inicio->mom_chegada;
        *dado2 = inicio->direc;
        return 0;
    }
    else
        return 1; // Fila Vazia
}

int Estado(Tno_fila *inicio, int *resp)
{
    if (inicio != NULL)
        *resp = 0; // Fila não Vazia
    else
        *resp = 1; // Fila Vazia
    return 0;
}
//$----------------------------------------------------------------------//
/* Leva-se 10 segundos para que a escada rolante dupla leve uma pessoa de uma das pontas até a outra.
Caso contrário, se a escada rolante estiver se movendo na direção oposta, a pessoa terá que esperar
até que a escada rolante pare e só então a pessoa poderá entrar nela.
Você tem que descobrir qual o último momento em que a escada para.    */

int Calcular(Tno_fila **inicio, int *saida)
{
    int d1, d2, antd1, antd2;

    Obter_inicio(*inicio, &d1, &d2);
    Remover_inicio(inicio);
    antd2 = d2;
    antd1 = d1;

    while (*inicio != NULL)
    {
        Obter_inicio(*inicio, &d1, &d2);
        Remover_inicio(inicio);
        if (antd2 == d2)
        {
            antd1 = d1;
        }
        else
        {
            antd2 = d2;
        }
    }

    *saida = d1 + 10;
    return 0;
}
