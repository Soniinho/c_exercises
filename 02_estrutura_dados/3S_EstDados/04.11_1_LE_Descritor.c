#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/* -----------------------------------------------------------------------------
^               Estrutura LISTA ENCADEADA SIMPLES - COM DESCRITOR
------------------------------------------------------------------------------*/

typedef struct no_ls
{
    int dado;
    struct no_ls *prox;
} Tno_ls;

//% dados úteis sobre a extrutura de acesso rápido
//% todas as estruturas PODEM tem descritor (normalmente tem)
typedef struct descritor_ls
{
    int tam;
    int quant_acessos;
    struct no_ls *prim; //ou "Tno_ls no_ls *prim;"
    struct no_ls *ult;
} Tdescritorno_ls;

/* --------------------------------------------------------------------------------------
*                                  Protótipos das funções

$ pdesc --> ponteiro para descritor  (passagem por referência)
$ cdesc --> copia do descritor       (passagem por valor)
---------------------------------------------------------------------------------------*/
int Inicializar_LS(Tdescritorno_ls *pdesc);
int Inicializar2_LS(Tdescritorno_ls *pdesc);
int Inserir_inicio_LS(Tdescritorno_ls *pdesc, int info);
int Inserir_fim_LS(Tdescritorno_ls *pdesc, int info);
int Inserir_meio_LS(Tdescritorno_ls *pdesc, int info, int pos);
int Remover_inicio_LS(Tdescritorno_ls *pdesc);
int Remover_meio_LS(Tdescritorno_ls *pdesc, int pos);
int Remover_fim_LS(Tdescritorno_ls *pdesc);
int Listar_LS(Tdescritorno_ls cdesc);
int Obter_dado_LS(Tdescritorno_ls cdesc, int pos, int *dado);
int Obter_pos_LS(Tdescritorno_ls cdesc, int dado, int *pos);
int Obter_Tamanho_LS(Tdescritorno_ls cdesc, int *tam);
int Inverte_LS(Tdescritorno_ls *pdesc);
int Copia_lista(Tdescritorno_ls cdesc_orig, Tdescritorno_ls *pdec_cop);

/* --------------------------------------------------------------------------------------
+                                         PRINCIPAL
---------------------------------------------------------------------------------------*/
int main(void)
{
    setlocale(LC_ALL, "portuguese");

    int info, pos;
    int erro; /* valor de erro retornado pelas funções */
    int q; /* receber a opção do usuário */

    Tdescritorno_ls desc; //! lista fica "dentro" do descritor -> *prim 
    
    erro = Inicializar_LS(&desc); //inicializar a lista

    do
    {
        system("cls");
        printf("LISTA ENCADEADA COM DESCRITOR - LESD");
        printf("\n\nOpções: \n\n");
        printf("1 -> Inserir no início \n");
        printf("2 -> Inserir no meio\n");
        printf("3 -> Inserir no final\n");
        printf("4 -> Remover no início\n");
        printf("5 -> Mostrar toda a lista \n");
        printf("6 -> Inicializar a lista (v2)\n");

        printf("7 -> Sair \n");
        printf(":");
        scanf("%d", &q); /* Ler a opcao do usuario */
        switch (q)
        {
        case 1:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            erro = Inserir_inicio_LS(&desc, info);
            if (erro == 0)
                printf("Inserção realizada com sucesso.\n");
            system("pause");
            break;
        case 2:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            printf("Posicao da inserção na lista: ");
            scanf("%d", &pos);
            Inserir_meio_LS(&desc, info, pos);
            break;
        case 3:
            printf("Dado para inserção na lista: ");
            scanf("%d", &info);
            Inserir_fim_LS(&desc, info);
            break;
        case 4:
            erro = Remover_inicio_LS(&desc);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível remover.");
            }
            system("pause");
            break;
        case 5:
            erro = Listar_LS(desc);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossível listar.");
            }
            system("pause");
            break;
        case 6:
            erro = Inicializar2_LS(&desc);
            printf("\nInicialização realizada com sucesso !\n");
            printf("\nLISTA VAZIA !\n");
            system("pause");
            break;
        case 7:
            break;
        default:
            printf("\n\n Opção não válida.");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 7));
}

/* --------------------------------------------------------------------------------------
*               LISTAR todos os elementos presentes na lista encadeada
---------------------------------------------------------------------------------------*/
int Listar_LS(Tdescritorno_ls cdesc) //+ cópia descritor
{
    int i;
    Tno_ls *percorre;

    if (cdesc.prim == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");
    percorre = cdesc.prim;
    while (percorre != NULL)
    {
        printf("%d  ", percorre->dado);
        percorre = percorre->prox;
    }
    printf("\n");
    return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* --------------------------------------------------------------------------------------
*                                       INICIALIZAR
---------------------------------------------------------------------------------------*/
int Inicializar_LS(Tdescritorno_ls *pdesc) //+ posição descritor
{
    pdesc->prim = NULL;
    pdesc->ult = NULL;
    pdesc->tam = 0;
    pdesc->quant_acessos = 0;
    return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

//=======================================================================================
int Inicializar2_LS(Tdescritorno_ls *pdesc)
{
    Tno_ls *percorre, *aux;
    if ((pdesc->prim) != NULL)
    {
        percorre = pdesc->prim;
        while (percorre != NULL) //! isso apaga a lista toda
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }
        pdesc->prim = NULL;
        pdesc->ult = NULL;
        pdesc->tam = 0;
        pdesc->quant_acessos = 0;
        return 1; // inicializa apagando tudo da lista
    }
    else
    {
        return 0;
    }
}

//=======================================================================================
int Obter_Tamanho_LS(Tdescritorno_ls cdesc, int *tam)
{
    if (cdesc.prim != NULL)
    {
        *tam = cdesc.tam;
    }
    else
    {
        *tam = 0;
    }
}

/* --------------------------------------------------------------------------------------
*                                        INSERÇÃO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS(Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *no_novo;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo->dado = info;

    if (pdesc->prim == NULL)
    { // inserção em lista vazia
        no_novo->prox = NULL;
        pdesc->prim = no_novo;
        pdesc->ult = no_novo;
    }
    else
    { // inserção em lista não vazia
        no_novo->prox = pdesc->prim;
        pdesc->prim = no_novo;
    }
    pdesc->tam = pdesc->tam + 1;
    return 0;
}

//=======================================================================================
int Inserir_meio_LS(Tdescritorno_ls *pdesc, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    // Tratamento de erros =======================================
    if (pos <= 0)
        return 1; // posição inválida para inserção

    Obter_Tamanho_LS(*pdesc, &tam);
    if (pos > tam + 1)
        return 2; // posição inválida. Acima do tamanho da lista
    // ===========================================================

    // Alocação do novo nó
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo->dado = info;

    // procura pela posição de inserção
    if (pos == 1)
    { // inserção no inicio
        Inserir_inicio_LS(pdesc, info);
    }
    else
    {
        if (pos == tam + 1)
        {
            Inserir_fim_LS(pdesc, info);
        }
        else
        {
            int pos_aux = 1;
            percorre = pdesc->prim;
            while (pos_aux != pos - 1) // parar uma posição antes
            {
                percorre = percorre->prox;
                pos_aux++;
            }
            no_novo->prox = percorre->prox;
            percorre->prox = no_novo;
        }
    }
    (pdesc->tam)++;
    return 0;
}

/* ------------------------------------------------------------------------------------*/
int Inserir_fim_LS(Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo->dado = info;
    no_novo->prox = NULL;

    if (pdesc->prim == NULL)
    { // lista vazia.
        pdesc->prim = no_novo;
    }
    else
    { // lista não vazia
        (pdesc->ult)->prox = no_novo;
    }
    pdesc->ult = no_novo;
    (pdesc->tam)++;
    return 0;
}

/* ------------------------------------------------------------------------------------*/
int Obter_Pos_LS(Tdescritorno_ls cdesc, int valor, int *pos)
/* obtem o valor armazenado em uma posição da lista */
{
    Tno_ls *percorre;
    percorre = cdesc.prim;
    *pos = 0;
    while (percorre != NULL)
    {
        (*pos)++;
        if (valor == percorre->dado)
            return 0; // dado encontrado
        percorre = percorre->prox;
    }
    return 1; // dado não encontrado
}

/* --------------------------------------------------------------------------------------
*                                         REMOÇÃO
---------------------------------------------------------------------------------------*/
int Remover_inicio_LS(Tdescritorno_ls *pdesc)
{
    Tno_ls *aux;
    if (pdesc->prim == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1; /* lista vazia, impossível remover o primeiro */
    }
    else
    {
        aux = pdesc->prim;
        pdesc->prim = (pdesc->prim)->prox;
        free(aux);
        (pdesc->tam)--;
        return 0;
    }
}
