// Matheus Henrique Datroso RA: 202110059

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista
{
    int num;
    struct lista *prox;
};
typedef struct lista Lista;

//-----------------------------------------//
Lista *inicializa(void);
Lista *insere_fim(Lista *t, int num);
Lista *insere_ordem(Lista *t, int N);
void imprime(Lista *t);
void libera(Lista *t);
Lista *nao_soma(Lista *t, Lista *t2);
//-----------------------------------------//
Lista *insere(Lista *t, int f);

int main()
{
    int i, escolha, numero;
    setlocale(LC_ALL, "portuguese");

    Lista *l1, *l2;

    l1 = inicializa();
    l2 = inicializa();

    printf("Digite a quantidade de números que quer por numa lista: ");
    scanf("%d%*c", &escolha);
    for (i = 0; i < escolha; i++)
    {
        printf("Digite um número: ");
        scanf("%d%*c", &numero);
        l1 = insere_ordem(l1, numero);
    }

    l2 = nao_soma(l1, l2);

    imprime(l2);
    libera(l1);
    libera(l2);
    return 0;
}

//&--------------------------------------------------------//
Lista *inicializa(void)
{
    return NULL;
}

void imprime(Lista *t)
{
    Lista *p;
    for (p = t; p != NULL; p = p->prox)
    {
        printf("%d\n", p->num);
    }
}

Lista *insere_fim(Lista *t, int num)
{
    Lista *novo_no = (Lista *)malloc(sizeof(Lista));
    novo_no->num = num;
    novo_no->prox = NULL;

    if (t == NULL)
    {
        return novo_no;
    }
    else
    {
        Lista *p = t;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novo_no;
    }

    return t;
}

Lista *insere_ordem(Lista *t, int N)
{
    Lista *novo_no = (Lista *)malloc(sizeof(Lista));
    novo_no->num = N;
    novo_no->prox = NULL;

    if (t == NULL)
    {
        return novo_no;
    }
    else
    {
        Lista *ant = t;
        Lista *atual = t;
        while (atual != NULL && atual->num < novo_no->num)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == t)
        {
            novo_no->prox = t;
            return novo_no;
        }
        else
        {
            novo_no->prox = ant->prox;
            ant->prox = novo_no;
        }
    }

    return t;
}

void libera(Lista *t)
{
    Lista *p = t;
    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}
//&--------------------------------------------------------//

/* //% prova
Crie uma lista encadeada simples L1 com N números inteiros
garantindo que a lista se mantenha ordenada (ordem crescente).
 A inserção deve ser realizada através de uma função. Depois, escreva uma função para
 encontrar todos os números da lista que não podem ser formados pela soma de dois outros
 números que estão em L1. Os números encontrados devem ser inseridos em outra lista encadeada
 simples denominada L2. Ao final do programa, imprima os elementos de L2.

Lista *nao_soma(Lista *t, Lista *t2) //% ta ao contrário ???? (+/-)
{
    Lista *atual, *ant, *aux;
    int x;

    aux = t;
    while (aux != NULL)
    {
        atual = t;
        ant = t;

        while (ant != NULL && x != (aux->num))
        {
            while (atual != NULL && x != (aux->num))
            {
                x = (atual->num) + (ant->num);
                atual = atual->prox;
            }
            ant = ant->prox;
        }

        if (x == (aux->num))
        {
            t2 = insere_fim(t2, x);
        }

        aux = aux->prox;
    }

    return t2;
}
*/

//% Comentários dps da prova
//$ fazer uma l3 com todas as somas possíveis e comparar l1 com l3
Lista *insere(Lista *t, int f)
{
    Lista *novo_no = (Lista *)malloc(sizeof(Lista));

    novo_no->num = f;
    novo_no->prox = t;

    return novo_no;
}

Lista *nao_soma(Lista *l1, Lista *l2) //* 2, 5, 7, 14, 19, 22 -> 2, 5, 14, 22 (ou 7 e 19)
{
    Lista *p1, *p2, *l3;
    int achou;

    l3 = inicializa();

    //...

    libera(l3);
    return l2;
}
