#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* -----------------------------------------------------------------------------
^                       Estrutura LISTA ENCADEADA DUPLA
------------------------------------------------------------------------------*/
typedef struct no_ld
{
    int dado;
    struct no_ld *prox, *ant;
} Tno_ld;

/* //!--------------------------- Comentários ----------------------------------
% O primeiro "ant" começa em NULL, e o último "prox" termina em NULL
$ ou faz ela ser "circular", ou faz "descritor"
! ----------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
*                             Protótipos das funções
------------------------------------------------------------------------------*/
int Inicializar_LD(Tno_ld **inicio);
int Inicializar2_LD(Tno_ld **inicio);
int Inserir_inicio_LD(Tno_ld **inicio, int info);
int Inserir_fim_LD(Tno_ld **inicio, int info);
int Inserir_meio_LD(Tno_ld **inicio, int info, int pos);
int Remover_inicio_LD(Tno_ld **inicio);
int Remover_meio_LD(Tno_ld **inicio, int pos);
// FAZER int Remover_fim_LD (Tno_ld **inicio);
int Listar_LD(Tno_ld *inicio);
int Listar_Invertido_LD(Tno_ld *inicio);
// FAZER int Obter_dado_LD  (Tno_ld *inicio, int pos, int *dado);
int Obter_pos_LD(Tno_ld *inicio, int dado, int *pos);
int Obter_Tamanho_LD(Tno_ld *inicio, int *tam);
int Inverter_LD(Tno_ld **inicio);

/* ----------------------------------------------------------------------------
*                               Funções de apoio
-----------------------------------------------------------------------------*/
// Gerador aleatório de dados
int gera_dado(int min, int max)
{
    int k;
    double d;
    d = (double)rand() / ((double)RAND_MAX + 1);
    k = d * (max - min + 1);
    return min + k;
}

/* -----------------------------------------------------------------------------
&                                    PRINCIPAL
------------------------------------------------------------------------------*/
int main()
{
    setlocale(LC_ALL, "portuguese");

    int min, max, i;
    clock_t t;
    int info, erro, q;
    Tno_ld *ini;

    erro = Inicializar_LD(&ini);
    do
    {
        system("cls");
        printf("LISTA ENCADEADA DUPLA - LED");
        printf("\n\nOpções: \n\n");
        printf("1 -> Inserir no início \n");
        printf("2 -> Inserir no final\n");
        printf("3 -> Remover no início\n");
        printf("4 -> Mostrar toda a lista \n");
        printf("5 -> Inicializar a lista (v2)\n");
        printf("6 -> Inverter a lista\n");
        printf("11-> Inserir muitos dados\n");
        printf("9 -> Sair \n:");
        scanf("%d", &q); /* Ler a opção do usuário */
        switch (q)
        {
        case 1:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            erro = Inserir_inicio_LD(&ini, info);
            if (erro == 0)
                printf("Inserção realizada com sucesso\n");
            system("pause");
            break;
        case 2:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            Inserir_fim_LD(&ini, info);
            break;
        case 3:
            erro = Remover_inicio_LD(&ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível remover!");
            }
            system("pause");
            break;
        case 4:
            erro = Listar_LD(ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível listar!");
            }
            system("pause");
            break;
        case 5:
            erro = Inicializar2_LD(&ini);
            printf("\nInicialização realizada com sucesso!\n");
            printf("\nLISTA VAZIA!\n");
            system("pause");
            break;
        case 6:
            erro = Inverter_LD(&ini);
            printf("\nInversão realizada!\n");
            system("pause");
            break;
        case 11:
            min = 1;
            max = 100;
            t = clock();
            for (i = 1; i <= 100000; i++)
            {
                // info = gera_dado(min, max);
                Inserir_fim_LD(&ini, 1);
                if ((i % 1000) == 0)
                {
                    t = clock() - t;
                    printf("Tempo de execução: %lf\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
                }
            }
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("\n\n Opção inválida.");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 9));
}

/* ------------------------------------------------------------------------------------
*               LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LD(Tno_ld *inicio)
{
    int i;
    if (inicio == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");
    while (inicio != NULL)
    {
        printf("%d  ", inicio->dado);
        inicio = inicio->prox;
    }
    printf("\n");
    return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* ------------------------------------------------------------------------------------
$       LISTAR todos os elementos presentes na lista encadeada na ordem inversa
--------------------------------------------------------------------------------------*/
int Listar_Invertido_LD(Tno_ld *inicio)
{
    int i;
    if (inicio == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");

    while (inicio->prox != NULL) // ir ate a última posição
    {
        inicio = inicio->prox;
    }

    while (inicio != NULL) // ir além da primeira posição imprimindo
    {
        printf("%d  ", inicio->dado);
        inicio = inicio->ant;
    }
    printf("\n");
    return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* ------------------------------------------------------------------------------------
!                                     INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LD(Tno_ld **inicio)
{
    *inicio = NULL;
    return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

int Inicializar2_LD(Tno_ld **inicio)
{
    Tno_ld *percorre, *aux;
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
        return 1; // inicializa apagando tudo da lista
    }
    else
    {
        Inicializar_LD(inicio); // inicializa
        return 0;
    }
}

int Obter_Tamanho_LD(Tno_ld *inicio, int *tam)
{
    Tno_ld *percorre;
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
    return 0;
}

/* -------------------------------------------------------------------------------------
?                                        INSERÇÃO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LD(Tno_ld **inicio, int info)
{
    Tno_ld *no_novo;

    /* Criacao do novo nó - Alocação de memória */
    no_novo = (Tno_ld *)malloc(sizeof(Tno_ld));
    no_novo->dado = info;

    if (*inicio == NULL)
    { // inserção em lista vazia
        no_novo->prox = NULL;
        *inicio = no_novo;
        no_novo->ant = NULL;
    }
    else
    { // inserção em lista não vazia
        no_novo->prox = *inicio;
        no_novo->ant = NULL;
        (*inicio)->ant = no_novo; // anterior do 1º. aponta para o novo
        *inicio = no_novo;        // atualizo o 1º., que passa a ser o novo
    }
    return 0;
}

int Inserir_meio_LD(Tno_ld **inicio, int info, int pos)
{
    int tam;
    Tno_ld *no_novo, *percorre;

    // Tratamento de erros =======================================
    if (pos <= 0)
        return 1; // posição inválida para inserção

    Obter_Tamanho_LD(*inicio, &tam);
    if (pos > tam + 1)
        return 2; // posição inválida. Acima do tamanho da lista
    // ===========================================================

    // Alocacao do novo nó
    no_novo = (Tno_ld *)malloc(sizeof(Tno_ld));
    no_novo->dado = info;

    // procura pela posição de inserção
    if (pos == 1)
    { // inserção no início
        Inserir_inicio_LD(inicio, info);
    }
    else
    {
        if (pos == tam + 1)
        {
            Inserir_fim_LD(inicio, info);
        }
        else
        {
            int pos_aux = 1;
            percorre = *inicio;
            while (pos_aux != pos - 1) // parar uma posição antes
            {
                percorre = percorre->prox;
                pos_aux++;
            }
            no_novo->prox = percorre->prox; // D
            percorre->prox = no_novo;       // B
            no_novo->ant = percorre;        // A
            (no_novo->prox)->ant = no_novo; // C
        }
    }
    return 0;
}

int Inserir_fim_LD(Tno_ld **inicio, int info)
{
    Tno_ld *no_novo, *percorre;

    /* Criacao do novo nó - Alocação de memória */
    no_novo = (Tno_ld *)malloc(sizeof(Tno_ld));
    no_novo->dado = info;
    no_novo->prox = NULL;
    if (*inicio == NULL)
    { // lista vazia.
        *inicio = no_novo;
        no_novo->ant = NULL;
    }
    else
    { // lista não vazia
        percorre = *inicio;
        while (percorre->prox != NULL) // até o último
        {
            percorre = percorre->prox;
        }
        percorre->prox = no_novo; // ligação do último com o novo
        no_novo->ant = percorre;  // liga o novo último ao anterior
    }
    return 0;
}

int Obter_Pos_LD(Tno_ld *inicio, int valor, int *pos)
{
    *pos = 0;
    while (inicio != NULL)
    {
        (*pos)++;
        if (valor == inicio->dado)
            return 0; // dado encontrado
        inicio = inicio->prox;
    }
    return 1; // dado não encontrado
}

/* -------------------------------------------------------------------------
$                                 REMOÇÃO
-------------------------------------------------------------------------*/
int Remover_inicio_LD(Tno_ld **inicio)
{
    Tno_ld *aux;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA! \nRemoção Impossível.\n");
        return 1;
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        (*inicio)->ant = NULL;
        free(aux);
        return 0;
    }
}

int Remover_meio_LD(Tno_ld **inicio, int pos)
{
    Tno_ld *percorre;
    int pos_aux;
    int tam;
    // Tratamento de erros =======================================
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA! \nRemoção Impossível.\n");
        return 1;
    }
    if (pos <= 0)
        return 2; // posicao inválida para remoção
    Obter_Tamanho_LD(*inicio, &tam);
    if (pos > tam)
        return 3; // posicao inválida. Acima do tamanho da lista
    // ===========================================================
    percorre = *inicio;
    pos_aux = 1;
    while (pos_aux != pos) // encontrar o nó para remoção
    {
        percorre = percorre->prox;
        pos_aux++;
    }
    // ligar o vizinho anterior com o vizinho próximo
    (percorre->ant)->prox = percorre->prox;
    // ligar o vizinho próximo com o vizinho anterior
    (percorre->prox)->ant = percorre->ant;

    free(percorre);
    return 0;
}

int Remover_fim_LD(Tno_ld **inicio)
{
    Tno_ld *percorre, *penultimo;

    if (*inicio == NULL)
        return 1; // lista vazia

    percorre = *inicio;
    if (percorre->prox == NULL) // Lista com 1 elemento
    {
        free(percorre);
        *inicio = NULL;
    }

    while (percorre->prox != NULL) // navegar até o último
    {
        percorre = percorre->prox;
    }
    penultimo = percorre->ant;
    free(percorre);         // liberando o último
    penultimo->prox = NULL; // no penúltimo indicando fim de lista
    return 0;
}

/* -------------------------------------------------------------------------
?                               INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverter_LD(Tno_ld **inicio)
{
    Tno_ld *percorre, *aux1, *aux2;
    percorre = *inicio;
    if (percorre == NULL)
    {
        return 1; // Caso a lista esteja vazia.
    }
    else if (percorre->prox == NULL)
    {
        return 0; // Caso a lista tenha apenas um nó.
    }
    else
    {
        while (percorre != NULL) // até o último
        {
            // Troca do ant pelo prox e vice-versa em cada nó
            aux1 = percorre->prox;
            percorre->prox = percorre->ant;
            percorre->ant = aux1;

            if (aux1 == NULL)       // o percorre esta no último nó
                *inicio = percorre; // define novo inicio
            // Avançar para o próximo nó de inversao
            percorre = percorre->ant;
        }
    }
    return 0;
}
