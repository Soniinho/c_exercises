#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/* -----------------------------------------------------------------------------
^                           Estrutura Fila DINÂMICA
------------------------------------------------------------------------------*/

typedef struct no_fila
{
    int dado;
    struct no_fila *prox;
} Tno_fila;

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_fila(Tno_fila **inicio);
int Inicializar2_fila(Tno_fila **inicio);
int Inserir_fim(Tno_fila **inicio, int info);
int Remover_inicio(Tno_fila **inicio);
int Obter_inicio(Tno_fila *inicio, int *dado);
int Estado(Tno_fila *inicio, int *resp);
//$----------------------------------------------------------------------//

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int info, erro, resposta;
    int q; /* receber a opção do usuário */

    Tno_fila *ini;
    Inicializar_fila(&ini);

    do
    {
        system("cls");
        printf("FILA DINÂMICA\n");
        printf("\n\nOpções:\n");
        printf("1 -> Inserir \n");
        printf("2 -> Remover\n");
        printf("3 -> Inicializar\n");
        printf("4 -> Consultar Início\n");
        printf("5 -> Verificar Estado\n");
        printf("6 -> Sair\n\n");
        printf(":");

        scanf("%d", &q);
        printf("\n");
        switch (q)
        {
        case 1:
            printf("Dado para inserção na Fila: ");
            scanf("%d", &info);
            erro = Inserir_fim(&ini, info);
            if (erro == 0)
                printf("Inserção realizada com sucesso.\n");
            system("pause");
            break;
        case 2:
            erro = Remover_inicio(&ini);
            if (erro == 1)
            {
                printf("\nFila vazia. Impossível remover.\n");
            }
            system("pause");
            break;
        case 3:
            erro = Inicializar2_fila(&ini);
            printf("\nInicializacao realizada com sucesso!\n");
            printf("\nFila Vazia!\n");
            system("pause");
            break;
        case 4:
            erro = Obter_inicio(ini, &info);
            if (erro == 1)
            {
                printf("\nFila vazia. Impossível consultar início.\n");
            }
            else
            {
                printf("\nInpicio: %d\n", info);
            }
            system("pause");
            break;
        case 5:
            erro = Estado(ini, &resposta);
            if (resposta == 1)
            {
                printf("\nFila vazia.\n");
            }
            else
            {
                printf("\nFila não vazia.\n");
            }
            system("pause");
            break;
        case 6:
            break;
        default:
            printf("\n\n Opção inválida.\n");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 6));
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

int Inserir_fim(Tno_fila **inicio, int info)
{
    Tno_fila *no_novo, *percorre;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_fila *)malloc(sizeof(Tno_fila));
    no_novo->dado = info;

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

int Obter_inicio(Tno_fila *inicio, int *dado)
{
    if (inicio != NULL)
    {
        *dado = inicio->dado;
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