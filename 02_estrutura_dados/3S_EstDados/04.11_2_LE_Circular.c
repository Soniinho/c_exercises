#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/* -----------------------------------------------------------------------------
^                    Estrutura LISTA ENCADEADA SIMPLES Circular
------------------------------------------------------------------------------*/

/*  //! ------------------------------------------------------------ //
%   A estrutura n tem marcador de fim
$   O "último" nó agora aponta para o "primeiro" nó
&   *Escalonar* as coisas -> não acaba, volta pro "inicio"
! ------------------------------------------------------------------ */

struct no_ls_c
{
    int dado;
    struct no_ls_c *prox;
};
typedef struct no_ls_c Tno_ls_c;

/* -----------------------------------------------------------------------------
+                             Protótipos das funções
------------------------------------------------------------------------------*/
int Inicializar_LS_C(Tno_ls_c **inicio);
int Inicializar2_LS_C(Tno_ls_c **inicio);
int Inserir_inicio_LS_C(Tno_ls_c **inicio, int info);
int Inserir_fim_LS_C(Tno_ls_c **inicio, int info);
int Inserir_meio_LS_C(Tno_ls_c **inicio, int info, int pos);
int Remover_inicio_LS_C(Tno_ls_c **inicio);
int Listar_LS_C(Tno_ls_c *inicio);
int Obter_Tamanho_LS_C(Tno_ls_c *inicio, int *tam);

/* -----------------------------------------------------------------------------
@                                   PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{
    setlocale(LC_ALL, "portuguese");

    int info, pos;
    int resp;
    int erro; /* valor de erro retornado pelas funções */
    Tno_ls_c *ini;
    int q; /* receber a opção do usuário */
    erro = Inicializar_LS_C(&ini);

    do
    {
        system("cls");
        printf("LISTA ENCADEADA SIMPLES Circular - LESC");
        printf("\n\nOpções: \n\n");
        printf("1 -> Inserir no início \n");
        printf("2 -> Inserir no meio \n");
        printf("3 -> Inserir no final\n");
        printf("4 -> Remover no início\n");
        printf("5 -> Mostrar toda a lista \n");
        printf("6 -> Inicializar a lista (v2)\n");
        printf("9 -> Sair \n");
        printf(":");
        scanf("%d", &q); /* Ler a opção do usuário */
        switch (q)
        {
        case 1:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            erro = Inserir_inicio_LS_C(&ini, info);
            if (erro == 0)
                printf("Inserção realizada com sucesso.\n");
            system("pause");
            break;
        case 2:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            printf("Posição para inserção na lista: ");
            scanf("%d", &pos);
            Inserir_meio_LS_C(&ini, info, pos);
            break;
        case 3:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            Inserir_fim_LS_C(&ini, info);
            break;
        case 4:
            erro = Remover_inicio_LS_C(&ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível remover.");
            }
            system("pause");
            break;
        case 5:
            erro = Listar_LS_C(ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível listar.");
            }
            system("pause");
            break;
        case 6:
            erro = Inicializar2_LS_C(&ini);
            printf("\nInicialização realizada com sucesso !\n");
            printf("\nLISTA VAZIA !\n");
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("\n\n Opção não válida.");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 9));
}

/* ------------------------------------------------------------------------------------
*                  LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS_C(Tno_ls_c *inicio)
{
    Tno_ls_c *aux;
    aux = inicio;
    if (inicio == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");
    // mostra o primeiro
    printf("%d  ", aux->dado);
    aux = aux->prox;

    while (inicio != aux)
    {
        printf("%d  ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
    return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* ------------------------------------------------------------------------------------
*                                     INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS_C(Tno_ls_c **inicio)
{
    *inicio = NULL;
    return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

/* //================================================================================ */
int Inicializar2_LS_C(Tno_ls_c **inicio)
{
    Tno_ls_c *percorre, *aux;
    if (*inicio != NULL)
    {
        percorre = *inicio;
        // apaga o primeiro
        aux = percorre;
        percorre = percorre->prox;
        free(aux);

        while (percorre != *inicio)
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }
        *inicio = NULL;
        return 1; /* inicializa apagando tudo da lista */
    }
    else
    {
        return 0;
    }
}

/* //================================================================================ */
int Obter_Tamanho_LS_C(Tno_ls_c *inicio, int *tam)
{
    Tno_ls_c *percorre;

    *tam = 0;
    if (inicio != NULL)
    {
        percorre = inicio;
        (*tam)++;
        percorre = percorre->prox;
        while (percorre != inicio)
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

/* -------------------------------------------------------------------------------------
#                                       INSERÇÃO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS_C(Tno_ls_c **inicio, int info)
{
    Tno_ls_c *no_novo, *aux;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_ls_c *)malloc(sizeof(Tno_ls_c));
    no_novo->dado = info;

    if (*inicio == NULL)
    { /* inserção em lista vazia */
        no_novo->prox = no_novo;
        *inicio = no_novo;
    }
    else
    { /* inserção em lista não vazia */
        no_novo->prox = *inicio;

        // procurar o último
        aux = *inicio;
        while (aux->prox != *inicio)
            aux = aux->prox;
        aux->prox = no_novo;
        *inicio = no_novo;
    }
    return 0;
}

/* //================================================================================ */
int Inserir_meio_LS_C(Tno_ls_c **inicio, int info, int pos)
{
    int tam;
    Tno_ls_c *no_novo, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos <= 0)
        return 1; /* posição inválida para inserção */

    Obter_Tamanho_LS_C(*inicio, &tam);
    if (pos > tam + 1)
        return 2; /* posição inválida. Acima do tamanho da lista */
    /* ================================================= */

    /* Alocação do novo nó */
    no_novo = (Tno_ls_c *)malloc(sizeof(Tno_ls_c));
    no_novo->dado = info;

    /* procura pela posição de inserção */
    if (pos == 1)
    { /* inserção no inicio */
        Inserir_inicio_LS_C(inicio, info);
    }
    else
    {
        if (pos == tam + 1)
        {
            Inserir_fim_LS_C(inicio, info);
        }
        else
        {
            int pos_aux = 1;
            percorre = *inicio;
            while (pos_aux != pos - 1) /* parar uma posição antes */
            {
                percorre = percorre->prox;
                pos_aux++;
            }
            no_novo->prox = percorre->prox;
            percorre->prox = no_novo;
        }
    }
    return 0;
}

/* //================================================================================ */
int Inserir_fim_LS_C(Tno_ls_c **inicio, int info)
{
    Tno_ls_c *no_novo, *percorre;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_ls_c *)malloc(sizeof(Tno_ls_c));
    no_novo->dado = info;
    no_novo->prox = *inicio;

    if (*inicio == NULL)
    { /* lista vazia. */
        *inicio = no_novo;
    }
    else
    { /* lista não vazia */
        percorre = *inicio;
        while (percorre->prox != *inicio)
        {
            percorre = percorre->prox;
        }
        percorre->prox = no_novo;
    }
    return 0;
}

/* -------------------------------------------------------------------------
*                                   REMOÇÃO
-------------------------------------------------------------------------*/
int Remover_inicio_LS_C(Tno_ls_c **inicio)
{
    Tno_ls_c *aux, *aux_r;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemoção Impossivel\n");
        return 1; /* lista vazia, impossível remover primeiro */
    }
    else
    {
        aux_r = *inicio;

        // procurar o último
        aux = *inicio;
        while (aux->prox != *inicio)
            aux = aux->prox;
        aux->prox = (*inicio)->prox;

        *inicio = (*inicio)->prox;
        free(aux_r);

        return 0;
    }
}
