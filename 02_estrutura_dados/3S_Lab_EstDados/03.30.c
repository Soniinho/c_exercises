#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct coordenada
{
    int x, y;
} Coordenada;

void soma_es_coord(int sx, int sy, Coordenada **cord);

int main()
{
    setlocale(LC_ALL, "portuguese");

    Coordenada c1, c2, *c3, *c4;

    c3 = &c1;
    c4 = &c2;

    c1.x = 10;
    c1.y = 7;

    c2.x = 11;
    c2.y = 5;

    printf("C1 = (%d, %d)\n", c1.x, c1.y);
    printf("C2 = (%d, %d)\n", c2.x, c2.y);
    /*
        printf("*C1 = (%d, %d)\n", c3->x, c3->y);
        printf("*C1 = (%d, %d)\n", (*c3).x, (*c3).y); //! tipo ruim
        printf("*C2 = (%d, %d)\n", c4->x, c4->y);
    */

    soma_es_coord(5, 6, &c3);

    printf("*C1 = (%d, %d)\n", c3->x, c3->y);
    printf("*C2 = (%d, %d)\n", c4->x, c4->y);
    return 0;
}

void soma_es_coord(int sx, int sy, Coordenada **cord)
{
    (*cord)->x += sx;
    (*cord)->y += sy;
}

/* //* calloc, alocação dinâmica de matriz
    int i, **p;

    @ calloc faz o mesmo que malloc, só que colocando 0 em cada posição
    p = calloc(5, sizeof(int *)); //& criando um ponteiro que aponta para 5 ponteiros do tipo int

    for (i < 0; i < 5; i++) //% isso cria uma matriz 5 por 3
    {
        p[i] = calloc(3, sizeof(int));
    }

    for (i < 0; i < 5; i++) //! desalocar
    {
        free(p[i]);
    }
    free(p);
*/
