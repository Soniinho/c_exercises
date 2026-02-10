#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "portuguese");
}

/*
#include <math.h>
void cubo(int *nPtr);

void main()
{
    setlocale(LC_ALL, "portuguese");
    int n = 5;
    printf("Valor era %d,\n", n);
    cubo(&n); //passando por referência
    printf("Agora é %d.", n);
}

void cubo(int *nPtr)
{
    *nPtr = pow(*nPtr, 3);
}
*/

/*
    int *ptr_a;
    ptr_a = malloc(sizeof(int)); //@ função para alocação dinâmica de memória
    //sizeof() trás p tipo de memória usada

    if (ptr_a == NULL)
    {
        printf("Memória insuficiente.\n");
        exit(1);
    }

    printf("Endereço de ptr_a: %p\n", ptr_a);
    *ptr_a = 90;
    printf("Conteúdo de ptr_a: %d\n", *ptr_a);
    free(ptr_a); //@ libera a memória alocada
*/

/*
#include <stdio.h>  //printf
#include <stdlib.h> //malloc
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    int i, *v;
    v = (int *)malloc(sizeof(int) * 10); //@ vetor de 10 inteiros
    //% (int *) faz a conversão da alocação para o ponteiro

    for (i = 0; i < 10; i++)
    {
        v[i] = i + 1;
    }

    for (i = 0; i < 10; i++)
    {
        printf("v[%d]: %d\n", i, v[i]);
    }
    printf("Endereço de 'v': %p", v);
    free(v); //liberar memória
}
*/

/*
void main()
{
    setlocale(LC_ALL, "portuguese");
    int *vet, *ptr;

    vet = (int *)malloc(sizeof(int) * 10);
    vet[4] = 44; //depois do maloc ele funciona como um vetor

    ptr = vet; //aponta para o início da área de 'vet'

    *ptr = 11; //vet[0] = 11;
    ptr++;
    *ptr = 12; //vet[1] = 12;

    printf("%p\n", ptr);
    printf("%d\n", *ptr);

    ptr--;
    free(ptr);
}
*/
