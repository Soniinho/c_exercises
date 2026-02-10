#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define tamanho 10 // tamanho máximo da FILA

/* -----------------------------------------------------------------------------
^                            Estrutura FILA ESTÁTICA
------------------------------------------------------------------------------*/

typedef struct fila
{
    int item[tamanho];
    int inicio, fim;
} T_FILA;

//$--------------------------- Funções Básicas --------------------------//
int Inicializa(T_FILA *f);
int Estado(T_FILA f);
int Insere(T_FILA *f, int x);
int Remove(T_FILA *f);
int Listar(T_FILA f);
int Obter_primeiro(T_FILA f, int *dado);
//$----------------------------------------------------------------------//
int Divide_Fila(T_FILA *F, T_FILA *F1, T_FILA *F2);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int info, erro;
    int q; /* receber a opção do usuário */
    T_FILA s, s1, s2;

    Inicializa(&s); //% pra não dar erro
    do
    {
        system("cls");
        printf("FILA Estática \n");
        printf("\n\nOpções: \n\n");
        printf("1 -> Inicializa \n");
        printf("2 -> Insere\n");
        printf("3 -> Remove\n");
        printf("4 -> Verifica Estado de Vazio\n");
        printf("5 -> Lista \n");
        printf("6 -> Obter Primeiro \n");
        printf("7 -> Divide fila em outras 2\n");
        printf("8 -> Sair\n");
        printf(":");

        scanf("%d", &q);
        printf("\n");
        switch (q)
        {
        case 1:
            erro = Inicializa(&s);
            printf("\nInicialização realizada com sucesso!\n");
            printf("\nFila VAZIA.\n");
            system("pause");
            break;
        case 2:
            printf("Dado para inserção: ");
            scanf("%d", &info);
            erro = Insere(&s, info);
            if (erro == 1)
            {
                printf("\nFila cheia. Overflow.\n");
            }
            system("pause");
            break;
        case 3:
            erro = Remove(&s);
            if (erro == 1)
            {
                printf("\nFila Vazia. Underflow.\n");
            }
            system("pause");
            break;
        case 4:
            erro = Estado(s);
            if (erro == 0)
                printf("\nA fila está vazia.\n");
            if (erro == 2)
                printf("\nA fila está em condições de uso.\n");
            if (erro == 1)
                printf("\nA fila está cheia.\n");
            system("pause");
            break;
        case 5:
            erro = Listar(s);
            if (erro == 1)
                printf("\nA fila está vazia.\n");

            erro = Listar(s1);
            if (erro == 1)
                printf("\nA fila está vazia.\n");

            erro = Listar(s2);
            if (erro == 1)
                printf("\nA fila está vazia.\n");
            system("pause");
            break;
        case 6:
            erro = Obter_primeiro(s, &info);
            if (erro == 0)
            {
                printf("Dado no início: %d\n", info);
            }
            else
            {
                printf("Fila vazia. Sem primeiro.\n");
            }
            system("pause");
            break;
        case 7:
            erro = Divide_Fila(&s, &s1, &s2);
            if (erro == 1)
                printf("Fila vazia, impossível didivir.\n");
            system("pause");
            break;
        case 8:
            break;
        default:
            printf("\n\n Opção inválida.\n");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 8));
}

//$--------------------------- Funções Básicas --------------------------//
int Inicializa(T_FILA *f)
{
    (*f).inicio = -1;
    (*f).fim = -1;
    return 0;
}

int Estado(T_FILA f)
{
    if ((f.inicio == -1) || (f.inicio == tamanho) || (f.inicio == f.fim + 1))
        return 0; // fila vazia
    else
    {
        if (f.fim == tamanho - 1)
            return 1; // fila cheia
        else
            return 2; // fila não vazia com capacidade de armazenamento
    }
}

int Insere(T_FILA *f, int x)
{
    int erro = Estado(*f);
    if ((erro == 0) || (erro == 2))
    {
        (*f).fim++;
        (*f).item[(*f).fim] = x; // inserção efetuada
        if ((*f).inicio == -1)
            (*f).inicio = 0;
        return 0;
    }
    else
        return 1; // impossível inserção. overflow
}

int Remove(T_FILA *f)
{
    int erro = Estado(*f);
    if (erro != 0)
    {
        (*f).inicio++; // remoção efetuada
        return 0;
    }
    else
        return 1; // impossível remover. Underflow
}

int Listar(T_FILA f)
{
    int i, erro;
    erro = Estado(f);
    if ((erro == 1) || (erro == 2))
    {
        for (i = f.inicio; i <= f.fim; i++)
            printf("%d - ", f.item[i]);
        printf("\n");
        return 0;
    }
    else
        return 1; // não possível listar pois a fila está vazia
}

int Obter_primeiro(T_FILA f, int *dado)
{
    int i;
    if ((f.inicio == -1) || (f.inicio == tamanho) || (f.inicio == f.fim + 1))
        return 1; // fila vazia
    else
    {
        *dado = f.item[f.inicio];
        return 0;
    }
}
//$----------------------------------------------------------------------//

//@ faça uma função que divida uma fila f na metade, criando duas novas filas F1 e F2
/* //& outro jeito de fazer
int Divide_Fila(T_FILA *F, T_FILA *F1, T_FILA *F2)
{
    int i, count = 0;
    int vazio, prim;
    T_FILA fila_aux;

    fila_aux = *F; //# pra n perder a fila completa
    vazio = Estado(fila_aux);
    if (vazio == 0)
        return 1; // fila vazia

    Inicializa(F1);
    Inicializa(F2);

    while (vazio != 0)
    {
        Obter_primeiro(fila_aux, &prim);
        Remove(&fila_aux);
        Insere(F2, prim);
        count++;

        vazio = Estado(fila_aux);
    }

    for (i = 0; i < (count / 2); i++)
    {
        Obter_primeiro(*F2, &prim);
        Remove(F2);
        Insere(F1, prim);
    }

    return 0;
}
*/
int Divide_Fila(T_FILA *F, T_FILA *F1, T_FILA *F2)
{
    int i, count = 0;
    int vazio, prim;
    T_FILA fila_aux;

    fila_aux = *F; //# pra n perder a fila completa
    vazio = Estado(fila_aux);
    if (vazio == 0)
        return 1; // fila vazia

    Inicializa(F1);
    Inicializa(F2);

    for (i = 0; i < ((fila_aux.fim + 1) / 2); i++)
    {
        Obter_primeiro(fila_aux, &prim);
        Remove(&fila_aux);
        Insere(F1, prim);
    }

    *F2 = fila_aux;

    return 0;
}
