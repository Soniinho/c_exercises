#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/* -----------------------------------------------------------------------------
^                           Estrutura PILHA DINÂMICA
------------------------------------------------------------------------------*/

typedef struct no_pilha
{
    int dado;
    struct no_pilha *prox;
} Tno_pilha;

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_pilha(Tno_pilha **inicio);
int Inicializar2_pilha(Tno_pilha **inicio);
int Inserir_topo(Tno_pilha **inicio, int info);
int Remover_topo(Tno_pilha **inicio);
int Obter_topo(Tno_pilha *inicio, int *dado);
int Verifica_vazio(Tno_pilha *inicio, int *resp);
//$----------------------------------------------------------------------//

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int info, erro, resposta;
    int q; /* receber a opção do usuário */

    Tno_pilha *ini;
    Inicializar_pilha(&ini);

    do
    {
        system("cls");
        printf("PILHA DINÂMICA\n");
        printf("\n\nOpções:\n");
        printf("1 -> Inserir \n");
        printf("2 -> Remover\n");
        printf("3 -> Inicializar\n");
        printf("4 -> Consultar Topo\n");
        printf("5 -> Verificar Vazio\n");
        printf("6 -> Sair\n\n");
        printf(":");

        scanf("%d", &q);
        printf("\n");
        switch (q)
        {
        case 1:
            printf("Dado para inserção na Pilha: ");
            scanf("%d", &info);
            erro = Inserir_topo(&ini, info);
            if (erro == 0)
                printf("Inserção realizada com sucesso.\n");
            system("pause");
            break;
        case 2:
            erro = Remover_topo(&ini);
            if (erro == 1)
            {
                printf("\nPilha vazia. Impossível remover.\n");
            }
            system("pause");
            break;
        case 3:
            erro = Inicializar2_pilha(&ini);
            printf("\nInicializacao realizada com sucesso!\n");
            printf("\nPilha Vazia!\n");
            system("pause");
            break;
        case 4:
            erro = Obter_topo(ini, &info);
            if (erro == 1)
            {
                printf("\nPilha vazia. Impossível consultar topo.\n");
            }
            else
            {
                printf("\nTopo: %d\n", info);
            }
            system("pause");
            break;
        case 5:
            erro = Verifica_vazio(ini, &resposta);
            if (resposta == 1)
            {
                printf("\nPilha vazia.\n");
            }
            else
            {
                printf("\nPilha não vazia.\n");
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

int Inserir_topo(Tno_pilha **inicio, int info)
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

int Obter_topo(Tno_pilha *inicio, int *dado)
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