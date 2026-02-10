#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* -----------------------------------------------------------------------------
^         Estrutura LISTA ENCADEADA SIMPLES com comentários/anotações
------------------------------------------------------------------------------*/

struct no_ls
{
    int dado;
    struct no_ls *prox;
};
typedef struct no_ls Tno_ls; //* typedef feito dps, não junto

/* //+ Tabela de código de erros
%   útil pra saber o que acontece pra dar errado, *fazer sempre*
&   0 é pra êxito

@    0 - sem erro
*    1 - ...
^    2 - ...
*/

/* //@ comentários sobre as funções
?   bom sempre voltar algo, podendo voltar erro
+   pd usar "return();" ou "return;"
*/

/* -----------------------------------------------------------------------------
*                             Protótipos das funções
------------------------------------------------------------------------------*/
int Inicializar_LS(Tno_ls **inicio);
int Inicializar2_LS(Tno_ls **inicio);
int Inserir_inicio_LS(Tno_ls **inicio, int info);
int Inserir_meio_LS(Tno_ls **inicio, int info, int pos);
int Inserir_fim_LS(Tno_ls **inicio, int info);
int Remover_inicio_LS(Tno_ls **inicio);
int Listar_LS(Tno_ls *inicio);
int Obter_Pos_LS(Tno_ls *inicio, int valor, int *pos);
int Obter_Tamanho_LS(Tno_ls *inicio, int *tam);
int Inverte_LS(Tno_ls **inicio);

int Repete_Dado_LS(Tno_ls *inicio, int info, int *resp);
/* verifica se o dado está repetido na estrutura */
/* resp = 1 - sim */
/* resp = 0 - nao */
int Inverter_LS_2(Tno_ls **inicio);
/* inverter a lista encadeada usando as rotinas prontas */

//* exercício da aula
int Deslocar_uma_pos(Tno_ls **inicio, int x);
int Remover_penultimo(Tno_ls **inicio);
int Remove_todos_a(Tno_ls **inicio, int a);
int Copia_Lista(Tno_ls *lista1, Tno_ls **lista2);

//$ --------------------------- FAZER -------------------------------
int Obter_dado_LS(Tno_ls *inicio, int pos, int *dado);
int Remover_meio_LS(Tno_ls **inicio, int pos);
int Remover_fim_LS(Tno_ls **inicio);

int Maiorque_Dado_LS(Tno_ls *inicio, int info, int *quant);
/* obtêm a quantidade de dados maior que info */
//$ ---------------------------------------------------------------//

//! NENHUMA Variável Global

/* -------------------------------------------------------------------------------------
?                                   PRINCIPAL
@                       Serve para testar as estruturas
--------------------------------------------------------------------------------------*/
int main(void)
{
    setlocale(LC_ALL, "portuguese");

    int info, i;
    int resp, pos;
    int quant;
    int erro; /* valor de erro retornado pelas funcoes */
    int q;    /* receber a opção do usuário */

    // para marcação do tempo de execução
    clock_t tempo_inicio, tempo_agora, tempo_fim;
    double tempo;

    Tno_ls *ini; //! a lista está aqui
    Tno_ls *ini2;

    erro = Inicializar_LS(&ini);

    do
    {
        system("cls");
        printf("LISTA ENCADEADA SIMPLES - LES");
        printf("\n\nOpções: \n\n");
        printf("1 -> Inserir no início \n");
        printf("2 -> Inserir no meio\n");
        printf("3 -> Inserir no final\n");
        printf("4 -> Remover no início\n");
        printf("5 -> Mostrar toda a lista \n");
        printf("6 -> Inicializar a lista (v2)\n");
        printf("7 -> Inverter a lista\n");
        printf("8 -> Verificar a repetição de um dado\n");
        printf("9 -> Sair \n");
        printf("10-> [EX] Trocar a posição dele pelo da frente\n");
        printf("11-> [EX] Remover Penúltimo\n");
        printf("12-> Inserir massivamente dados\n");
        printf("13-> Remover todas as ocorrências de um valor da lista\n");
        printf("14-> Copiar a lista para outra lista\n");
        printf(":");
        scanf("%d", &q); /* Ler a opção do usuário */
        switch (q)
        {
        case 1:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            erro = Inserir_inicio_LS(&ini, info);
            if (erro == 0)
                printf("Inserção realizada com sucesso\n");
            system("pause");
            break;
        case 2:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            printf("Posição de inserção: ");
            scanf("%d", &pos);
            erro = Inserir_meio_LS(&ini, info, pos);
            if (erro == 0)
                printf("Inserção realizada com sucesso\n");
            system("pause");
            break;
        case 3:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            Inserir_fim_LS(&ini, info);
            break;
        case 4:
            erro = Remover_inicio_LS(&ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível remover\n");
            }
            system("pause");
            break;
        case 5:
            erro = Listar_LS(ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível listar\n");
            }
            system("pause");
            break;
        case 6:
            erro = Inicializar2_LS(&ini);
            printf("\nInicialização realizada com sucesso !\n");
            printf("\nLISTA VAZIA !\n");
            system("pause");
            break;
        case 7:
            erro = Inverte_LS(&ini);
            if (erro == 1)
                printf("\nLista vazia. Inversão não realizada !\n");
            else
                printf("\nInversão realizada !\n");
            system("pause");
            break;
        case 8:
            printf("Dado para pesquisa na lista: ");
            scanf("%d", &info);
            erro = Repete_Dado_LS(ini, info, &resp);
            if (erro != 0)
                printf("\nErro na operação");
            else
                printf("\nResposta (1:Sim, 0:Não) : %d \n", resp);
            system("pause");
            break;
        case 9:
            break;
        case 10:
            printf("Posição para ser alterada: ");
            scanf("%d", &pos);
            erro = Deslocar_uma_pos(&ini, pos);
            if (erro == 0)
            {
                printf("Posição modificada com sucesso.\n\n");
            }
            system("pause");
            break;
        case 11:
            erro = Remover_penultimo(&ini);
            if (erro == 0)
            {
                printf("Posição modificada com sucesso.\n\n");
            }
            system("pause");
            break;
        case 12:
            printf("Quantidade de dados para inserção na lista: ");
            scanf("%d%*c", &quant);
            tempo_inicio = clock();
            for (i = 1; i <= quant; i++)
            {
                erro = Inserir_fim_LS(&ini, i);
                tempo_agora = clock();
                tempo = (tempo_agora - tempo_inicio) / (double)CLOCKS_PER_SEC;
                if (i % 100 == 0)
                    printf("Dado: %d    - Tempo usado: %f seg \n", i, tempo);
            }
            tempo_fim = clock();
            // tempo usado na operação
            tempo = (tempo_fim - tempo_inicio) / (double)CLOCKS_PER_SEC;
            printf("\n\nTempo total na operação: %f seg \n", tempo);

            system("pause");
            break;
        case 13:
            printf("Dado que deseja remover da lista: ");
            scanf("%d", &info);
            erro = Remove_todos_a(&ini, info);
            if (erro == 0)
            {
                printf("Valores removidos com sucesso.\n\n");
            }
            system("pause");
            break;
        case 14:
            erro = Copia_Lista(ini, &ini2);
            printf("Lista copiada com sucesso.\n\n");
            system("pause");
            break;
        default:
            printf("\n\n Opção não válida.");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 9));
}

/* -------------------------------------------------------------------------------------
                LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS(Tno_ls *inicio)
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
    } while (inicio != NULL); //+ antes tava diferente de auxiliar

    printf("\n");
    return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* ------------------------------------------------------------------------------------------------
                                        INICIALIZAR
-------------------------------------------------------------------------------------------------*/
int Inicializar_LS(Tno_ls **inicio) //% ponteiro de ponteiro (endereço de endereço de um nó)
{
    *inicio = NULL; //^ NULL em desenho é uma barrinha no endereço, q é um quadrado

    return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

/*============================================================================================== */
int Inicializar2_LS(Tno_ls **inicio)
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
        } while (percorre != NULL); //+ antes tava "*inicio"
        *inicio = NULL;
        return 1; /* inicializa apagando tudo da lista */
    }
    else
    {
        return 0;
    }
}

/*============================================================================================== */
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

/*============================================================================================== */
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
    return 1; /* dado não encontrado */
}

/* --------------------------------------------------------------------------------------
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

/* -------------------------------------------------------------------------
                                    REMOÇÃO
--------------------------------------------------------------------------*/
int Remover_inicio_LS(Tno_ls **inicio)
{
    Tno_ls *aux;
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

/* -------------------------------------------------------------------------
                                INVERTER LISTA
--------------------------------------------------------------------------*/
int Inverte_LS(Tno_ls **inicio) //& fazer td na msm lista
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

int Inverter_LS_2(Tno_ls **inicio) //$ uso de lista auxiliar (gasta mto)
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
    int cont = 0; /* contagem de repetições */
    if (inicio == NULL)
    {
        *resp = 0; /* Dado não repete */
        return 1;  /* lista vazia */
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

//@ exercício dia 28/03 --------------------------------------------------------//
//  Fazer uma função que desloque um nó de uma posição X para a posição X+1
int Deslocar_uma_pos(Tno_ls **inicio, int x)
{
    int tam, cont_pos = 1;
    Tno_ls *percorre, *aux_1, *aux_2, *aux_3, *aux_4;

    /* Tratamento de erros ======================================= */
    if (*inicio == NULL)
        return 1; // lista vazia
    if ((*inicio)->prox == NULL)
        return 2; // lista com apenas 1 nó

    Obter_Tamanho_LS(*inicio, &tam);
    if (x <= 0 || x >= tam)
        return 3; // posição inexistente
    /* =========================================================== */

    percorre = *inicio;
    while (cont_pos < x - 1)
    {
        percorre = percorre->prox;
        cont_pos++;
    }

    if (x != 1)
    {
        aux_1 = percorre;
        aux_2 = aux_1->prox;
        aux_3 = aux_2->prox;
        aux_4 = aux_3->prox;

        aux_1->prox = aux_3;
        aux_2->prox = aux_4;
        aux_3->prox = aux_2;

        return 0;
        //@  daria para usar só um auxiliar
        //~  aux_1 ficaria na posição antes do X, e o percorre na posição depois do X
    }
    else //# caso diferente (Primeira posição)
    {
        //$ queremos deslocar o primeiro , não temos aux1
        aux_2 = *inicio;
        aux_3 = aux_2->prox;
        aux_4 = aux_3->prox;

        //& --------------- fazer operação
        *inicio = aux_3;
        aux_3->prox = aux_2;
        aux_2->prox = aux_4;

        return 0;
    }
}
//@-----------------------------------------------------------------------------//

//# lição dia 04/04-------------------------------------------------------------//
//  Fazer um Remove que apague o *penúltimo* nó
int Remover_penultimo(Tno_ls **inicio)
{
    int tam, cont_pos = 1;
    // Tno_ls *aux_1;
    Tno_ls *percorre, *aux_2;

    /* Tratamento de erros ======================================= */
    if (*inicio == NULL)
        return 1; // lista vazia
    if ((*inicio)->prox == NULL)
        return 2; // lista com apenas 1 nó
    /* =========================================================== */

    Obter_Tamanho_LS(*inicio, &tam);
    if (tam == 2)
    {
        percorre = *inicio;
        percorre = percorre->prox;
        free(*inicio);
        *inicio = percorre;
    }
    else
    {
        percorre = *inicio; // vai ser o antepenúltimo
        while (cont_pos < tam - 2)
        {
            percorre = percorre->prox;
            cont_pos++;
        }
        // aux_1 = percorre->prox;         // penúltimo
        aux_2 = (percorre->prox)->prox; // último

        free(percorre->prox);   //* tlz por "percorre->prox" invés de "aux_1"
        percorre->prox = aux_2; // antepenúltimo recebe a posição do último
    }

    return 0;
}
//#-----------------------------------------------------------------------------//

//$ exercício dia 11/04 --------------------------------------------------------//
//  Fazer uma função que remove todos os nós que contém o valor "a"
int Remove_todos_a(Tno_ls **inicio, int a)
{
    int tam;
    Tno_ls *percorre, *ant;

    /* Tratamento de erros ======================================= */
    if (*inicio == NULL)
        return 1; // lista vazia
    /* =========================================================== */

    while ((*inicio)->dado == a) // remover do início
    {
        Remover_inicio_L1(inicio);
        /*
        if (tam == 1 && (*inicio)->dado == a) // se primeiro for e se só tiver 1
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
        if (percorre->dado == a)
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
    if (percorre->dado == a)
    {
        ant->prox = NULL;
        free(percorre);
    }

    return 0;
}
//$ ----------------------------------------------------------------------------//

// todo: exercício 2 dia 11/04 ---------------------------------------------------
//   Fazer uma funçã que copie uma lista encadeada simples
//   não circular "x" para outra lista "y"
int Copia_Lista(Tno_ls *lista1, Tno_ls **lista2) //! nem testei
{
    Tno_ls *percorre;

    Inicializar_LS(lista2);

    percorre = lista1;
    Inserir_inicio_LS(lista2, percorre->dado); // inserir primeiro valor

    while (percorre->prox != NULL)
    {
        percorre = percorre->prox;
        Inserir_fim_LS(lista2, percorre->dado);
    }

    return 0;
}
// todo---------------------------------------------------------------------------//
