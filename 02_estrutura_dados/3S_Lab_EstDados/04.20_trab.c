// Matheus Henrique Daltroso RA: 202110059

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista
{
    float nota;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *inicializa(void);
Lista *insere_fim(Lista *t, float f);
void libera(Lista *t);
Lista *media(Lista *t, float *med);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, med, v_est[] = {1, 2, 3, 4, 5};

    int med2, *v_din;

    float med3;
    Lista *t;

    // vetor estático
    med = 0;
    for (i = 0; i < 5; i++)
    {
        med += v_est[i];
    }
    med = med / 5;

    // vetor dinâmico
    med2 = 0;
    v_din = (int *)malloc(5 * sizeof(int)); // vai ser {1, 2, 3, 4, 5}

    for (i = 0; i < 5; i++)
    {
        v_din[i] = i + 1;

        med2 += v_din[i];
    }
    med2 = med2 / 5;

    // lista encadeada
    t = inicializa();

    t = insere_fim(t, 1);
    t = insere_fim(t, 2);
    t = insere_fim(t, 3);
    t = insere_fim(t, 4);
    t = insere_fim(t, 5);
    t = media(t, &med3);

    // mostrar médias
    printf("Média do vetor estático: %d\n", med);
    printf("Média do vetor dinâmico: %d\n", med2);
    printf("Média da lista encadeada simples: %.2f\n", med3);

    libera(t);
    free(v_din);
    return 0;
}

Lista *inicializa(void)
{
    return NULL;
}

Lista *insere_fim(Lista *t, float f)
{

    Lista *novo_no = (Lista *)malloc(sizeof(Lista));
    novo_no->nota = f;
    novo_no->prox = NULL;

    if (t == NULL)
    { // 1o elemento da lista
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

Lista *media(Lista *t, float *med)
{
    Lista *p;
    int cont = 0;

    *med = 0;
    for (p = t; p != NULL; p = p->prox)
    {
        *med += p->nota;
        cont++;
    }
    *med = (*med) / cont;

    return t;
}
