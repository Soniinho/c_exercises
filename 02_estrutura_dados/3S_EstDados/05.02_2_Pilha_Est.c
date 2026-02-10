#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define tamanho 10 // tamanho máximo da pilha

/* -----------------------------------------------------------------------------
^                            Estrutura PILHA ESTÁTICA
------------------------------------------------------------------------------*/

typedef struct pilha
{
    int topo;
    int item[tamanho];
} T_PILHA;

//$--------------------------- Funções Básicas --------------------------//
int Inicializa(T_PILHA *p);
int Estado(T_PILHA p);
int Empilha(T_PILHA *p, int x); //& PUSH
int Desempilha(T_PILHA *p);     //& POP
int Listar(T_PILHA p);
int Obter_topo(T_PILHA p, int *dado);
int Copia_Pilha(T_PILHA p, T_PILHA *p2);
//$----------------------------------------------------------------------//
int Juntar_Pilhas(T_PILHA *P1, T_PILHA *P2, T_PILHA *P3);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int info, erro, q, esc_lista;
    T_PILHA s, s1, s2;

    Inicializa(&s);
    Inicializa(&s1);
    Inicializa(&s2);
    do
    {
        system("cls");
        printf("PILHA ESTÁTICA - LIFO\n");
        printf("\n\nOpções: \n\n");
        printf("1 -> Inicializa\n");
        printf("2 -> Insere\n");
        printf("3 -> Remove\n");
        printf("4 -> Verifica Estado de Vazio\n");
        printf("5 -> Lista\n");
        printf("6 -> Obtêm Topo\n");
        printf("7 -> Copia pilha 1 para pilha 2\n");
        printf("8 -> Sair\n");
        printf("9 -> Juntar 2 Pilhas em 1\n");
        printf(":");

        scanf("%d", &q);
        printf("\n");
        switch (q)
        {
        case 1:
            erro = Inicializa(&s);
            printf("\nInicialização da 1ª pilha realizada com sucesso!\n");
            printf("\nPilha Vazia.\n");
            system("pause");
            break;
        case 2:
            do
            {
                printf("Escolha a lista para inserção (s[1] ou s1[2]): ");
                scanf("%d%*c", &esc_lista);
            } while (esc_lista != 1 && esc_lista != 2);
            //----------------------------------------------------//
            printf("Dado para inserção: ");
            scanf("%d", &info);
            if (esc_lista == 1)
                erro = Empilha(&s, info);
            else if (esc_lista == 2)
                erro = Empilha(&s1, info);
            //----------------------------------------------------//
            if (erro == 1)
                printf("\nPilha Cheia. Overflow.\n");
            system("pause");
            break;
        case 3:
            erro = Desempilha(&s);
            if (erro == 1)
                printf("\nPilha Vazia. Underflow.\n");
            system("pause");
            break;
        case 4:
            erro = Estado(s);
            if (erro == 0)
                printf("\nA pilha está vazia.\n");
            if (erro == 2)
                printf("\nA pilha está em condições de uso.\n");
            if (erro == 1)
                printf("\nA pilha está cheia.\n");
            system("pause");
            break;
        case 5:
            erro = Listar(s);
            if (erro == 1)
                printf("A pilha está vazia.\n");

            erro = Listar(s1);
            if (erro == 1)
                printf("A pilha está vazia.\n");

            erro = Listar(s2);
            if (erro == 1)
                printf("A pilha está vazia.\n");
            system("pause");
            break;
        case 6:
            erro = Obter_topo(s, &info);
            if (erro == 0)
            {
                printf("Dado no topo: %d\n", info);
            }
            else
                printf("Pilha vazia. Sem topo\n");
            system("pause");
            break;
        case 7:
            erro = Copia_Pilha(s, &s1);
            if (erro == 0)
            {
                printf("Cópia realizada.\n");
                Listar(s1);
            }
            else
                printf("Erro de copiação.\n");
            system("pause");
            break;
        case 8:
            break;
        case 9:
            erro = Juntar_Pilhas(&s, &s1, &s2);
            if (erro != 0)
                printf("Alguma pilha está vazia.\n");
            else
                printf("Operação realizada com sucesso!.\n");
            system("pause");
            break;
        default:
            printf("\n\n Opção inválida.\n");
            system("pause");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 8));
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

//@ faça uma função que junte 2 pilhas em outra
//@ Colocando a P1 no topo de P2 (virando P3)
int Juntar_Pilhas(T_PILHA *P1, T_PILHA *P2, T_PILHA *P3)
{
    int vazio, prim;
    T_PILHA pilha_aux, pilha_aux2;
    Inicializa(P3);
    Inicializa(&pilha_aux2);

    //------------------- Erros -------------------//
    vazio = Estado(*P1);
    if (vazio == 0)
        return 1; // 1ª pilha vazia

    vazio = Estado(*P2);
    if (vazio == 0)
        return 2; // 2ª pilha vazia

    //---------- colocar p2 em p3 -----------------//
    pilha_aux = *P2; //$ só da pra fzr pq é um vetor

    vazio = Estado(pilha_aux);
    if (vazio == 0)
        return 3; // Pilha aux vazia

    while (vazio != 0) // inverter p2
    {
        Obter_topo(pilha_aux, &prim);
        Desempilha(&pilha_aux);
        Empilha(&pilha_aux2, prim);
        vazio = Estado(pilha_aux);
    }

    vazio = Estado(pilha_aux2);
    while (vazio != 0)
    {
        Obter_topo(pilha_aux2, &prim);
        Desempilha(&pilha_aux2);
        Empilha(P3, prim);
        vazio = Estado(pilha_aux2);
    }

    //---------- colocar p1 em p3 -----------------//
    Inicializa(&pilha_aux2); // zerar pilha_aux2
    pilha_aux = *P1;

    vazio = Estado(pilha_aux);
    if (vazio == 0)
        return 3; // Pilha aux vazia

    while (vazio != 0) // inverter p1
    {
        Obter_topo(pilha_aux, &prim);
        Desempilha(&pilha_aux);
        Empilha(&pilha_aux2, prim);
        vazio = Estado(pilha_aux);
    }

    vazio = Estado(pilha_aux2);
    while (vazio != 0)
    {
        Obter_topo(pilha_aux2, &prim);
        Desempilha(&pilha_aux2);
        Empilha(P3, prim);
        vazio = Estado(pilha_aux2);
    }

    return 0;
}
