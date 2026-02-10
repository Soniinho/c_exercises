#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* -----------------------------------------------------------------------------
^                           FILA DINÂMICA/FIFO COM DESC
------------------------------------------------------------------------------*/
//* elementos
typedef struct no
{
    float dado;
    struct no *prox;
} No;

//@ controle da fila
typedef struct fila
{
    No *ini;
    No *fim;
} Fila;

//$--------------------------- Funções Básicas --------------------------//
Fila *Inicializar();
void Inserir(Fila *fifo, float dado);
float Remover(Fila *fifo);
void Listar(Fila *fifo);
int Vazio(Fila *fifo);
int LIBERAR_TD(); //todo
//$----------------------------------------------------------------------//

int main()
{
    setlocale(LC_ALL, "portuguese");
    Fila *f = Inicializar();

    Inserir(f, 10.3);
    Inserir(f, 12.9);
    Inserir(f, 45.1);
    Inserir(f, 18.7);
    Inserir(f, 31.3);
    Listar(f);

    printf("\nElemento retirado: %.1f\n", Remover(f));
    Listar(f);

    return 0;
}

//$--------------------------- Funções Básicas --------------------------//
Fila *Inicializar()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));

    fila->ini = NULL;
    fila->fim = NULL;

    return fila;
}

void Inserir(Fila *fifo, float dado)
{
    No *noNovo = (No *)malloc(sizeof(No));
    noNovo->dado = dado;
    noNovo->prox = NULL;

    if (Vazio(fifo))
    {
        fifo->ini = noNovo;
        fifo->fim = noNovo;
    }
    else
    {
        fifo->fim->prox = noNovo;
        fifo->fim = noNovo;
    }
}

float Remover(Fila *fifo)
{
    No *aux;
    float valor;

    if (fila_vazia(fifo))
        exit(1);

    aux = fifo->ini;
    fifo->ini = aux->prox;
    valor = aux->dado;

    free(aux);

    if (fila_vazia(fifo)) // se remover o último
        fifo->fim = NULL;

    return valor;
}

void Listar(Fila *fifo)
{
    No *percorre;
    if (!Vazio(fifo))
    {
        printf("Fila:\t");
        for (percorre = fifo->ini; percorre != NULL; percorre = percorre->prox)
            printf("%.1f\t", percorre->dado);
    }
    else
        printf("Fila Vazia.\n");
}

int Vazio(Fila *fifo)
{
    if (fifo->ini == NULL)
        return 1; // fila vazia
    else
        return 0; // fila não vazia
}
//$----------------------------------------------------------------------//
