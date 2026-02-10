#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
%    lista encadeada simples
?    lista encadeada circular (não tem inicio nem fim)
^    lista duplamente encadeada (vai e volta) (2 pont -> antes e depois)
!    lista duplamente encadeada e circular
$   lista encadeada com descritor
*/

struct turma
{
    char *nome;
    float nota;
    struct turma *prox;
};
typedef struct turma Turma;

Turma *inicializa(void);
Turma *insere(Turma *t, float f, char *n);
Turma *insere_fim(Turma *t, float f, char *n);
Turma *insere_ordem(Turma *t, float f, char *n);
void imprime(Turma *t);
void libera(Turma *t);
Turma *remove_no(Turma *t, char *n);

int main()
{
    setlocale(LC_ALL, "portuguese");

    Turma *t;

    t = inicializa();
    // t --> NULL
    t = insere_ordem(t, 7.5, "Maria");
    // t --> Maria --> NULL
    t = insere_ordem(t, 6.4, "João");
    // t --> Joao --> Maria --> NULL
    t = insere_ordem(t, 8.2, "José");
    // t --> Joao --> Maria --> Jose --> NULL
    t = insere_ordem(t, 7.0, "Ana");
    // t --> Joao (6.4) --> Ana (7.0) --> Maria (7.5) --> Jose (8.2) --> NULL

    t = remove_no(t, "Maria");
    t = remove_no(t, "Ana");

    imprime(t);
    libera(t);

    return 0;
}

Turma *inicializa(void)
{
    return NULL;
}

void imprime(Turma *t)
{
    Turma *p;
    for (p = t; p != NULL; p = p->prox)
    {
        printf("%s - %3.2f\n", p->nome, p->nota);
    }
}

Turma *insere(Turma *t, float f, char *n)
{
    // t = Joao
    // f = 8.2
    // n = Jose

    Turma *novo_no = (Turma *)malloc(sizeof(Turma));

    novo_no->nota = f;
    novo_no->nome = n;
    novo_no->prox = t;

    return novo_no;
}

Turma *insere_fim(Turma *t, float f, char *n)
{

    Turma *novo_no = (Turma *)malloc(sizeof(Turma));
    novo_no->nota = f;
    novo_no->nome = n;
    novo_no->prox = NULL;

    if (t == NULL)
    { // 1o elemento da lista
        return novo_no;
    }
    else
    {
        Turma *p = t;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novo_no;
    }

    return t;
}

Turma *insere_ordem(Turma *t, float f, char *n)
{
    // t = Joao
    // f = 7.0
    // n = Ana

    Turma *novo_no = (Turma *)malloc(sizeof(Turma));
    novo_no->nota = f;
    novo_no->nome = n;
    novo_no->prox = NULL;

    if (t == NULL)
    {
        return novo_no;
    }
    else
    {
        Turma *ant = t;
        Turma *atual = t;
        while (atual != NULL && atual->nota < novo_no->nota)
        { // 7.5 < 7.0
            ant = atual;
            atual = atual->prox;
        }

        // ant = Joao
        // atual = Maria
        // Joao --> Ana --> Maria --> Jose --> NULL

        if (atual == t)
        { // insere no início
            novo_no->prox = t;
            return novo_no;
        }
        else
        {
            novo_no->prox = ant->prox;
            // Ana --> Maria
            ant->prox = novo_no;
            // Joao --> Ana
        }
    }

    return t;
}

void libera(Turma *t)
{
    Turma *p = t;
    while (p != NULL)
    {
        Turma *t = p->prox;
        free(p);
        p = t;
    }
}

Turma *remove_no(Turma *t, char *n)
{
    if (t == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        Turma *ant = t;
        Turma *atual = t;

        while (atual != NULL && atual->nome != n)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == NULL) // percorreu td e não achou
        {
            printf("Nó não encontrado!\n");
        }
        else
        {
            if (atual == t) // remover do início
            {
                t = atual->prox;
            }
            else // remover do meio ou fim (passa o NULL)
            {
                ant->prox = atual->prox;
            }

            free(atual); // libera o nó
        }
    }

    return t;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct turma
{
    char *nome;
    float nota;
    struct turma *prox;
};
typedef struct turma Turma;

Turma *inicializa(void);
Turma *insere(Turma *t, float f, char *n);
Turma *insere_fim(Turma *t, float f, char *n);
Turma *insere_ordem(Turma *t, float f, char *n);
void imprime(Turma *t);
void libera(Turma *t);
Turma *remove_no(Turma *t, char *n);

int main()
{
    setlocale(LC_ALL, "portuguese");

    Turma *t;

    t = inicializa();
    // t --> NULL
    t = insere_ordem(t, 7.5, "Maria");
    // t --> Maria --> NULL
    t = insere_ordem(t, 6.4, "João");
    // t --> Joao --> Maria --> NULL
    t = insere_ordem(t, 8.2, "José");
    // t --> Joao --> Maria --> Jose --> NULL
    t = insere_ordem(t, 7.0, "Ana");
    // t --> Joao (6.4) --> Ana (7.0) --> Maria (7.5) --> Jose (8.2) --> NULL

    t = remove_no(t, "Maria");
    t = remove_no(t, "Ana");

    imprime(t);
    libera(t);

    return 0;
}

Turma *inicializa(void)
{
    return NULL;
}

void imprime(Turma *t)
{
    Turma *p;
    for (p = t; p != NULL; p = p->prox)
    {
        printf("%s - %3.2f\n", p->nome, p->nota);
    }
}

Turma *insere(Turma *t, float f, char *n)
{
    // t = Joao
    // f = 8.2
    // n = Jose

    Turma *novo_no = (Turma *)malloc(sizeof(Turma));

    novo_no->nota = f;
    novo_no->nome = n;
    novo_no->prox = t;

    return novo_no;
}

Turma *insere_fim(Turma *t, float f, char *n)
{

    Turma *novo_no = (Turma *)malloc(sizeof(Turma));
    novo_no->nota = f;
    novo_no->nome = n;
    novo_no->prox = NULL;

    if (t == NULL)
    { // 1o elemento da lista
        return novo_no;
    }
    else
    {
        Turma *p = t;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novo_no;
    }

    return t;
}

Turma *insere_ordem(Turma *t, float f, char *n)
{
    // t = Joao
    // f = 7.0
    // n = Ana

    Turma *novo_no = (Turma *)malloc(sizeof(Turma));
    novo_no->nota = f;
    novo_no->nome = n;
    novo_no->prox = NULL;

    if (t == NULL)
    {
        return novo_no;
    }
    else
    {
        Turma *ant = t;
        Turma *atual = t;
        while (atual != NULL && atual->nota < novo_no->nota)
        { // 7.5 < 7.0
            ant = atual;
            atual = atual->prox;
        }

        // ant = Joao
        // atual = Maria
        // Joao --> Ana --> Maria --> Jose --> NULL

        if (atual == t)
        { // insere no início
            novo_no->prox = t;
            return novo_no;
        }
        else
        {
            novo_no->prox = ant->prox;
            // Ana --> Maria
            ant->prox = novo_no;
            // Joao --> Ana
        }
    }

    return t;
}

void libera(Turma *t)
{
    Turma *p = t;
    while (p != NULL)
    {
        Turma *t = p->prox;
        free(p);
        p = t;
    }
}

Turma *remove_no(Turma *t, char *n)
{
    if (t == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        Turma *ant = t;
        Turma *atual = t;

        while (atual != NULL && atual->nome != n)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == NULL) // percorreu td e não achou
        {
            printf("Nó não encontrado!\n");
        }
        else
        {
            if (atual == t) // remover do início
            {
                t = atual->prox;
            }
            else // remover do meio ou fim (passa o NULL)
            {
                ant->prox = atual->prox;
            }

            free(atual); // libera o nó
        }
    }

    return t;
}
*/
