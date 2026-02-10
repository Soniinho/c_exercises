#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no_arv
{
    int info;
    struct no_arv *esq, *dir;
};
typedef struct no_arv Arv;

Arv *cria_no(int n) // adiciona a raiz e os nós
{
    Arv *p;

    p = (Arv *)malloc(sizeof(Arv));
    p->info = n;
    p->esq = NULL;
    p->dir = NULL;

    return p;
}

void ins_esq(Arv *p, int n)
{
    Arv *aux;

    aux = cria_no(n);
    p->esq = aux;
}

void ins_dir(Arv *p, int n)
{
    Arv *aux;

    aux = cria_no(n);
    p->dir = aux;
}

//---------------- listar ----------------//
void pre_ordem(Arv *p)
{
    if (p)
    {
        printf("%d - ", p->info);
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}

void ordem(Arv *p)
{
    if (p)
    {
        ordem(p->esq);
        printf("%d - ", p->info);
        ordem(p->dir);
    }
}

void pos_ordem(Arv *p)
{
    if (p)
    {
        pos_ordem(p->esq);
        pos_ordem(p->dir);
        printf("%d - ", p->info);
    }
}
//----------------------------------------//

int main()
{
    setlocale(LC_ALL, "portuguese");
    int num;
    Arv *raiz, *p, *q;

    printf("Digite a raiz: ");
    scanf("%d%*c", &num);

    raiz = cria_no(num);

    // 10 - 8 - 5 - 9 - 23 - 40 - (-1)

    while (num != -1)
    {
        printf("Digite um número: ");
        scanf("%d%*c", &num);

        p = raiz;
        q = raiz;

        if (num != -1)
        {
            while (num != p->info && q != NULL) // NULL retorna 0
            {
                p = q;
                if (num < p->info)
                    q = p->esq;
                else
                    q = p->dir;
            }

            if (num == p->info)
                printf("Número %d já existe.\n", num);
            else
            {
                if (num < p->info)
                    ins_esq(p, num);
                else
                    ins_dir(p, num);
            }
        }
    }

    printf("\nImprime pré-ordem: ");
    pre_ordem(raiz);
    printf("\nImprime ordem: ");
    ordem(raiz);
    printf("\nImprime pós-ordem: ");
    pos_ordem(raiz);

    return 0;
}