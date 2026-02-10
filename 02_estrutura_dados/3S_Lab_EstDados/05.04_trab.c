// Matheus Henrique Daltroso RA: 202110059
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 11 //"boa noite\0" = 10 + '\n'
struct pilha
{
    int n;
    char vet[MAX];
};
typedef struct pilha Pilha;

//$--------------------------- Funções Básicas --------------------------//
Pilha *cria(void);
void push(Pilha *p, char v);
char pop(Pilha *p);
int vazia(Pilha *p);
void libera(Pilha *p);
//$----------------------------------------------------------------------//
int Listar(Pilha p);
Pilha *inv_pilha(Pilha *p);
Pilha *inverte_letras(Pilha *p);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int i, j, q;
    char frase[MAX], carac;
    Pilha *l1, *l2;

    l1 = cria();
    l2 = cria();
    do
    {
        system("cls");
        printf("\tPilha Estática:\n");
        printf("1 -> Insere frase\n");
        printf("2 -> Remove topo\n");
        printf("3 -> Ver estado\n");
        printf("4 -> Sair\n");
        printf("5 -> Inverte letras\n");
        printf(":");

        scanf("%d%*c", &q);
        printf("\n");
        switch (q)
        {
        case 1:
            printf("Digite uma frase: ");
            fgets(frase, MAX, stdin);
            frase[strlen(frase) - 1] = 0;

            for (i = 0; i < strlen(frase); i++)
                push(l1, frase[i]);
            system("pause");
            break;
        case 2:
            carac = pop(l1);
            printf("O topo era: %c.\n", carac);
            break;
        case 3:
            j = vazia(l1);
            if (j == 1)
                printf("A pilha está vazia.\n");
            else
                printf("A pilha não está vazia.\n");
            system("pause");
            break;
        case 4:
            printf("Saindo...\n");
            libera(l1);
            libera(l2);
            system("pause");
            break;
        case 5:
            l2 = inverte_letras(l1);

            printf("Pilha 1\n");
            Listar(*l1);
            printf("Pilha 2\n");
            Listar(*l2);
            system("pause");
            break;
        default:
            printf("Opção inválida.\n");
            system("pause");
            break;
        }
    } while (q != 4);
}

//$--------------------------- Funções Básicas --------------------------//
Pilha *cria(void)
{
    Pilha *p = (Pilha *)calloc(0, sizeof(Pilha));
    p->n = 0; /* inicializa com zero elementos */
    return p;
}

void push(Pilha *p, char v)
{
    if (p->n == MAX)
    { /* capacidade esgotada */
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;
    p->n++;
}

char pop(Pilha *p)
{
    char v;
    if (vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    /* retira elemento do topo */
    v = p->vet[p->n - 1];
    p->n--;
    return v;
}

int vazia(Pilha *p)
{
    return (p->n == 0);
}

void libera(Pilha *p)
{
    free(p);
}
//$----------------------------------------------------------------------//
int Listar(Pilha p)
{
    int i, erro;
    erro = vazia(&p);
    if (erro == 0)
    {
        for (i = 0; i <= p.n; i++)
            printf("%c", p.vet[i]);
        printf("\n");
        return 0;
    }
    else
        return 1; /* impossível listar, pois a pilha vazia */
}

Pilha *inv_pilha(Pilha *p)
{
    Pilha *inv;
    inv = cria();

    int vazio;
    char carac;

    vazio = vazia(p);
    while (vazio != 1)
    {
        carac = pop(p);
        push(inv, carac);
        vazio = vazia(p);
    }

    libera(p);
    return inv;
}

//@ inverter a ordem das letras em uma frase sem inverter a ordem das palavras
Pilha *inverte_letras(Pilha *p) // n funciona se começar com espaço ou terminar com espaços pq preguiça
{
    Pilha *p1, *p2;
    p1 = cria();
    *p1 = *p;
    p2 = cria();

    char carac;
    int vazio, spaces = 0, i;

    // contar qnts palavras tem
    vazio = vazia(p1);
    while (vazio != 1)
    {
        carac = pop(p1);
        if (carac == ' ')
            spaces++;
        push(p2, carac);
        vazio = vazia(p1);
    }
    libera(p1);

    if (spaces == 0)
    {
        libera(p);
        return p2; //% se só tiver 1 palavra, termina a função
    }

    // criar pilhas pra qnt de palavras
    spaces++; // 1 espaço = 2 palavras
    Pilha *pilhas_aux[spaces];
    for (i = 0; i < spaces; i++)
        pilhas_aux[i] = cria();

    // passar palavras para pilhas diferentes
    for (i = 0; i < spaces; i++)
    {
        vazio = vazia(p2);
        carac = 0;
        while (carac != ' ' && vazio != 1)
        {
            carac = pop(p2);
            if (carac == ' ')
                break;
            push(pilhas_aux[i], carac);
            vazio = vazia(p2);
        }
    }

    pilhas_aux[spaces - 1] = inv_pilha(pilhas_aux[spaces - 1]);

    // juntar as pilhas na última
    for (i = 0; i < (spaces - 1); i++)
    {
        vazio = vazia(pilhas_aux[i]);
        push(pilhas_aux[spaces - 1], ' ');
        while (vazio != 1)
        {
            carac = pop(pilhas_aux[i]);
            push(pilhas_aux[spaces - 1], carac);
            vazio = vazia(pilhas_aux[i]);
        }
        libera(pilhas_aux[i]);
    }

    return pilhas_aux[spaces - 1];
}
