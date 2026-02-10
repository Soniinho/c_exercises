#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define tamanho 8 // tamanho máximo da pilha

/* -----------------------------------------------------------------------------
^                            Estrutura PILHA ESTÁTICA
------------------------------------------------------------------------------*/

typedef struct pilha
{
    int topo;
    int item[tamanho];
} T_PILHA;

T_PILHA mat[4][4]; //^ Variável global

//$--------------------------- Funções Básicas --------------------------//
int Inicializa(T_PILHA *p);
int Estado(T_PILHA p);
int Empilha(T_PILHA *p, int x); //& PUSH
int Desempilha(T_PILHA *p);     //& POP
int Listar(T_PILHA p);
int Obter_topo(T_PILHA p, int *dado);
int Copia_Pilha(T_PILHA p, T_PILHA *p2);
//$----------------------------------------------------------------------//
int Transfere(int lin_PO, int col_PO, int lin_PD, int col_PD);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int info, erro, q, esc_lista;

    do
    {
        system("cls");
        printf("PILHA ESTÁTICA - LIFO\n");
        printf("\n\nOpções: \n\n");
        printf("1 -> Teste\n");
        printf("2 -> Sair\n");
        printf(":");

        scanf("%d", &q);
        printf("\n");
        switch (q)
        {
        case 1:
            Inicializa(&mat[0][1]);
            Inicializa(&mat[4][8]);
            Empilha(&mat[0][1], 10);
            Empilha(&mat[0][1], 20);
            Empilha(&mat[0][1], 30);
            Empilha(&mat[0][1], 40);
            Empilha(&mat[4][8], 100);
            Empilha(&mat[4][8], 200);
            Empilha(&mat[4][8], 300);
            printf("mat[0][1]: ");
            Listar(mat[0][1]);
            printf("\nmat[4][8]: ");
            Listar(mat[4][8]);
            Transfere(0, 1, 4, 8);
            printf("-----------------------------------------\n");
            printf("mat[0][1]: ");
            Listar(mat[0][1]);
            printf("\nmat[4][8]: ");
            Listar(mat[4][8]);
            system("pause");
            break;
        case 2:
            break;
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 2));
}

//$--------------------------- Funções Básicas --------------------------//
int Inicializa(T_PILHA *p)
{
    (*p).topo = -1;
    return 0;
}

int Estado(T_PILHA p)
{
    if (p.topo == -1)
        return 0; /* pilha vazia */
    else
    {
        if (p.topo == tamanho - 1)
            return 1; /* pilha cheia */
        else
            return 2; /* pilha não vazia com capacidade de armazenamento */
    }
}

int Empilha(T_PILHA *p, int x)
{
    int erro = Estado(*p);
    if ((erro == 0) || (erro == 2))
    {
        (*p).topo++;
        (*p).item[(*p).topo] = x; /* empilhamento efetuado */
        return 0;
    }
    else
        return 1; /* impossível empilhar. overflow */
}

int Desempilha(T_PILHA *p)
{
    int erro = Estado(*p);
    if (erro != 0)
    {
        (*p).topo--; /* desempilhamento efetuado */
        return 0;
    }
    else
        return 1; /* impossível desempilhar. Underflow */
}

int Listar(T_PILHA p)
{
    int i, erro;
    erro = Estado(p);
    if ((erro == 1) || (erro == 2))
    {
        for (i = 0; i <= p.topo; i++)
            printf("%d\\ ", p.item[i]);
        printf(" (Topo)\n");
        return 0;
    }
    else
        return 1; /* impossível listar, pois a pilha vazia */
}

int Obter_topo(T_PILHA p, int *dado)
{
    int i;
    if (p.topo == -1)
        return 1; /* pilha vazia */
    else
    {
        *dado = p.item[p.topo];
        return 0;
    }
}

int Copia_Pilha(T_PILHA p, T_PILHA *p2)
{
    int dado;
    T_PILHA paux;
    Inicializa(&paux);

    /* transferir para pilha auxiliar */
    while (Estado(p) != 0)
    {
        Obter_topo(p, &dado);
        Desempilha(&p);
        Empilha(&paux, dado);
    }

    printf("\nLista da pilha auxiliar\n");
    Listar(paux);
    printf("\n");

    /* transferir para pilha destino */
    while (Estado(paux) != 0)
    {
        Obter_topo(paux, &dado);
        Desempilha(&paux);
        Empilha(p2, dado);
    }
    return 0;
}
//$----------------------------------------------------------------------//

//@ crie uma extrutura de matriz (4x4) de pilhas estáticas de tam max 8
//@ então faça uma função que transfira uma pilha A da posição (LA, CA) para uma posição (LB, CB) formando uma pilha B
int Transfere(int lin_PO, int col_PO, int lin_PD, int col_PD)
{
    //* PO - pilha origem / PD - pilha destino
    int dado, resp;
    T_PILHA p_aux;

    Inicializa(&p_aux);
    Inicializa(&mat[lin_PD][col_PD]); // zerar pilha de chegada

    resp = Estado(mat[lin_PO][col_PO]);
    while (resp != 0)
    {
        Obter_topo(mat[lin_PO][col_PO], &dado);
        Desempilha(&mat[lin_PO][col_PO]);
        Empilha(&p_aux, dado);
        resp = Estado(mat[lin_PO][col_PO]);
    }

    resp = Estado(p_aux);
    while (resp != 0)
    {
        Obter_topo(p_aux, &dado);
        Desempilha(&p_aux);
        Empilha(&mat[lin_PD][col_PD], dado);
        resp = Estado(p_aux);
    }
    return 0;
}
