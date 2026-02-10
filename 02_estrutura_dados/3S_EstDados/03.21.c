#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* ---------------------------------------------------------------------------------------
^         Estrutura LISTA ENCADEADA SIMPLES com comentários/anotações incompletas
----------------------------------------------------------------------------------------*/

struct no_ls
{
    int dado;
    struct no_ls *prox;
};
typedef struct no_ls Tno_ls; //*typedef feito dps, não junto

/* Tabela de codigo de erros
%   útil pra saber o que acontece pra dar errado, *fazer sempre*
&   0 é pra êxito

@    0 - sem erro
*    1 - ...
^    2 - ...
*/

/* -----------------------------------------------------------------------------
                            Protótipos das funções
------------------------------------------------------------------------------*/
int Inicializar_LS(Tno_ls **P_inicio);
int Inicializar2_LS(Tno_ls **P_inicio);
int Inserir_inicio_LS(Tno_ls **P_inicio, int info);
int Inserir_fim_LS(Tno_ls **P_inicio, int info);
int Inserir_meio_LS(Tno_ls **P_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **P_inicio);
int Listar_LS(Tno_ls *CP_inicio);
int Obter_pos_LS(Tno_ls *CP_inicio, int dado, int *pos);
int Obter_Tamanho_LS(Tno_ls *CP_inicio, int *tam);
int Inverte_LS(Tno_ls **P_inicio);

/*
?   bom sempre voltar algo, podendo voltar erro
+   pd usar "return();" ou "return;"
*/

// ------------ FAZER
int Obter_dado_LS(Tno_ls *inicio, int pos, int *dado);
int Remover_meio_LS(Tno_ls **P_inicio, int pos);
int Remover_fim_LS(Tno_ls **P_inicio);

int Repete_Dado_LS(Tno_ls *inicio, int info, int *resp);
/* verifica se o dado está repetido na estrutura */
/* resp = 1 - sim */
/* resp = 0 - nao */

int Maiorque_Dado_LS(Tno_ls *inicio, int info, int *quant);
/* obtêm a quantidade de dados maior que info */

int Inverte_LS_2(Tno_ls **P_inicio);
/* inverter a lista encadeada usando as rotinas prontas */

/* Variáveis global */
//! NENHUMA

/* -----------------------------------------------------------------------------
?                                   PRINCIPAL
@                       Serve para testar as estruturas
------------------------------------------------------------------------------*/
int main(void)
{
    setlocale(LC_ALL, "portuguese");

    int info;
    int resp, pos;
    int erro; /* valor de erro retornado pelas funcoes */

    Tno_ls *ini; //! a lista está aqui

    int q; /* receber a opcao do usuario */
    erro = Inicializar_LS(&ini);

    do
    {
        system("cls");
        printf("LISTA ENCADEADA SIMPLES - LES");
        printf("\n\nOpcoes: \n\n");
        printf("1 -> Inserir no inicio \n");
        printf("2 -> Inserir no meio\n");
        printf("3 -> Inserir no final\n");
        printf("4 -> Remover no inicio\n");
        printf("5 -> Mostrar toda a lista \n");
        printf("6 -> Inicializar a lista (versao 2)\n");
        printf("7 -> Inverter a lista\n");
        printf("8 -> Verifica a repeticao de um dado\n");
        printf("9 -> Sair \n:");
        scanf("%d", &q); /* Ler a opcao do usuario */
        switch (q)
        {
        case 1:
            printf("Dado para insercao na lista: ");
            scanf("%d", &info);
            erro = Inserir_inicio_LS(&ini, info);
            if (erro == 0)
                printf("Insercao realizada com sucesso\n");
            system("pause");
            break;
        case 2:
            printf("Dado para insercao na lista: ");
            scanf("%d", &info);
            printf("Posicao de insercao: ");
            scanf("%d", &pos);
            erro = Inserir_meio_LS(&ini, info, pos);
            if (erro == 0)
                printf("Insercao realizada com sucesso\n");
            system("pause");
            break;
        case 3:
            printf("Dado para insercao na lista: ");
            scanf("%d", &info);
            Inserir_fim_LS(&ini, info);
            break;
        case 4:
            erro = Remover_inicio_LS(&ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossivel remover");
            }
            system("pause");
            break;
        case 5:
            erro = Listar_LS(ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossivel listar");
            }
            system("pause");
            break;
        case 6:
            erro = Inicializar2_LS(&ini);
            printf("\nInicializacao realizada com sucesso !\n");
            printf("\nLISTA VAZIA !\n");
            system("pause");
            break;
        case 7:
            erro = Inverte_LS(&ini);
            if (erro == 1)
                printf("\nLista vazia. Inversao nao realizada !\n");
            else
                printf("\nInversao realizada !\n");
            system("pause");
            break;
        case 8:
            printf("Dado para pesquisa na lista: ");
            scanf("%d", &info);
            erro = Repete_Dado_LS(ini, info, &resp);
            if (erro != 0)
                printf("\nErro na operação");
            else
                printf("\nResposta (1:sim, 0:Nao) : %d \n", resp);
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 9));
}

/* ------------------------------------------------------------------------------------
                LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS(Tno_ls *inicio) // todo: ta com erro
{
    int i;
    Tno_ls *aux;

    if (inicio == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");
    aux = inicio;
    do
    {
        printf(" %d", inicio->dado);
        inicio = inicio->prox;
    } while (inicio != aux);

    printf("\n");
    return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* ------------------------------------------------------------------------------------
                                        INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS(Tno_ls **inicio) //% ponteiro de ponteiro (endereço de endereço de um nó)
{
    *inicio = NULL; //^ NULL em desenho é uma barrinha no endereço, q é um quadrado

    return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

/*===================================================== */
int Inicializar2_LS(Tno_ls **inicio) // todo: ta com erro
{
    Tno_ls *percorre, *aux;
    if (*inicio != NULL)
    {
        percorre = *inicio;
        do
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        } while (percorre != *inicio);
        *inicio = NULL;
        return 1; /* inicializa apagando tudo da lista */
    }
    else
    {
        return 0;
    }
}

/*===================================================== */
int Obter_Tamanho_LS(Tno_ls *inicio, int *tam)
{
    Tno_ls *percorre;
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

/* -------------------------------------------------------------------------------------
                                        INSERÇÃO
---------------------------------------------------------------------------------------*/
//? enfia no início e joga o q tiver para baixo
int Inserir_inicio_LS(Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo->dado = info;

    if (*inicio == NULL)
    { /* inserção em lista vazia */
        no_novo->prox = NULL;
        *inicio = no_novo;
    }
    else
    { /* inserção em lista não vazia */
        // todo: desenhar esses ngc como as memórias para entender
        no_novo->prox = *inicio;
        *inicio = no_novo;
    }
    return 0;
}

/*===================================================== */
int Inserir_meio_LS(Tno_ls **inicio, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos <= 0)
        return 1; /* posição inválida para inserção */

    Obter_Tamanho_LS(*inicio, &tam);
    if (pos > tam + 1)
        return 2; /* posição inválida. Acima do tamanho da lista */
    /* =========================================================== */

    /* procura pela posição de inserção */
    if (pos == 1)
    { /* inserção no início */
        Inserir_inicio_LS(inicio, info);
    }
    else
    {
        if (pos == tam + 1)
        {
            Inserir_fim_LS(inicio, info);
        }
        else
        {
            int pos_aux = 1;

            //? Alocação do novo nó (numa posição melhor)
            no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
            no_novo->dado = info;

            percorre = *inicio;
            while (pos_aux != pos - 1) /* parar uma posição antes */
            {
                percorre = percorre->prox;
                pos_aux++;
            }
            no_novo->prox = percorre->prox; //*desenha pra n ficar confuso
            percorre->prox = no_novo;
        }
    }
    return 0;
}

/*===================================================== */
int Inserir_fim_LS(Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo nó - Alocação de memória */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo->dado = info;
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

/*===================================================== */
int Obter_Pos_LS(Tno_ls *inicio, int valor, int *pos)
{
    *pos = 0;
    while (inicio != NULL)
    {
        (*pos)++;
        if (valor == inicio->dado)
            return 0; /* dado encontrado */
        inicio = inicio->prox;
    }
    if (inicio == NULL)
        *pos = 0;
    return 1; /* dado nao encontrado */
}

/* -------------------------------------------------------------------------
                                    REMOÇÃO
--------------------------------------------------------------------------*/
int Remover_inicio_LS(Tno_ls **inicio)
{
    Tno_ls *aux;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1; /* lista vazia, impossivel remover primeiro */
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

/* -------------------------------------------------------------------------
                                INVERTER LISTA
--------------------------------------------------------------------------*/
int Inverte_LS(Tno_ls **inicio)
{
    Tno_ls *percorre, *aux_1, *aux_2, *aux_3;
    percorre = *inicio;
    if (percorre == NULL)
    {
        return 1; /*Caso a lista esteja vazia. */
    }
    else if (percorre->prox == NULL)
    {
        return 0; /*Caso a lista tenha apenas um nó. */
    }
    else
    {
        aux_1 = *inicio;     /*O ponteiro aux_a aponta para o primeiro nó, uma vez que o ponteiro "ini" passará a apontar para o último. */
        aux_2 = aux_1->prox; /*O ponteiro aux_p passa a apontar para o segundo nó da lista.*/
        aux_3 = aux_2->prox; /*O ponteiro aux_v passa a apontar para o terceiro nó da lista.*/
        aux_1->prox = NULL;  /*O primeiro nó da lista passa a ser o último, apontando para NULL.*/
        aux_2->prox = aux_1; /*O segundo nó da lista passa a apontar para o primeiro, começando a inversão da lista.*/
                             /*Início - Processo de inversão.*/
        while (aux_3 != NULL)
        {
            aux_1 = aux_2;       /*O ponteiro aux_a pega o valor do nó a sua frente na lista.*/
            aux_2 = aux_3;       /*O ponteiro aux_p pega o valor do nó a sua frente na lista.*/
            aux_3 = aux_3->prox; /*O ponteiro aux_v pega o valor do nó a sua frente na lista.*/
            aux_2->prox = aux_1; /*O nó para o qual aux_p está apontado passa a apontar para o nó anterior a ele na lista.*/
        }
        /*Fim - Processo de inversão. */
        *inicio = aux_2; /* atualização do ponteiro de inicio */
    }

    return 0;
}

/* -------------------------------------------------------------------------
                               INVERTER LISTA 2
--------------------------------------------------------------------------*/
int Inverter_LS_2(Tno_ls **inicio)
{
    int i, erro, tam, info;
    Tno_ls *inicio_lista_aux; /* lista auxiliar */

    erro = Obter_Tamanho_LS(*inicio, &tam);
    if (tam == 0)
    {
        return 1; /*Caso a lista esteja vazia.*/
    }
    else if (tam == 1)
    {
        return 0; /*Caso a lista tenha apenas um nó.*/
    }
    else
    {
        Inicializar_LS(&inicio_lista_aux);
        for (i = 1; i <= tam; i++)
        {
            info = (*inicio)->dado; /* obtendo o dado do 1o. nó */
            Remover_inicio_LS(inicio);
            Inserir_inicio_LS(&inicio_lista_aux, info);
        }
        *inicio = inicio_lista_aux;
    }
    return 0;
}
/* ---------------------------------------------------------------------- */

int Repete_Dado_LS(Tno_ls *inicio, int info, int *resp)
{
    int cont = 0; /* contagem de repeticoes*/
    if (inicio == NULL)
    {
        *resp = 0; /* Dados nao repete */
        return 1;  /* lista vazia*/
    }
    while (inicio != NULL)
    {
        if (inicio->dado == info)
            cont++;
        inicio = inicio->prox;
    }
    if (cont > 1)
        *resp = 1;
    else
        *resp = 0;
    return 0; /* sem erro */
}
