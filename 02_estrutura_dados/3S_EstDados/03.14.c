#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//% Tipos Abstratos de Dados
//+ Pode consulta prova, mas só anotação em papel

typedef struct pessoa
{
    int peso;
    float altura;
    T_Pessoa *prox;
} T_Pessoa;

void main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    T_Pessoa *py, *px;

    printf("Tamanho float = %d\n", sizeof(float));
    // printf("Tamanho int = %d\n",sizeof(int));
    // printf("Tamanho T_pessoa = %d\n",sizeof(T_Pessoa));

    px = (T_Pessoa *)malloc(sizeof(T_Pessoa)); //+ sagrado
    py = (T_Pessoa *)malloc(sizeof(T_Pessoa));

    px->peso = 89; //$ onde px aponta, acesse a parte peso (operador "->")
    px->altura = 1.98;
    py->peso = 59;
    py->altura = 1.68;

    px->prox = py; //? lista encadeada -> px vira sagrado, NÃO mexe

    //& marcar que a estrutura terminou
    py->prox = NULL;

    free(px);
    printf("peso = %d\n", px->peso);
}

/*//*------------------------typedef explicação--------------------------------
typedef <existing-type> <new-type-identifier>;

typedef int Integer;
The above statement declare an alias for int with name Integer.
Which means the following two statements are equivalent in meaning.

int     num1 = 0;   // Declare a variable of int type
Integer num2 = 0;   // Declare a variable of int type

struct point {
    int x;
    int y;
};

// Declare typedef for point structure
typedef struct point Point;

or

typedef struct point {
    int x;
    int y;
} Point;
//*--------------------------------------------------------------------------*/

/* struct typedef
struct Pessoa
{
char nome[50], endereco[50];
int idade;
};

struct Pessoa cadpessoa;

ou

typedef struct Pessoa //# "struct Pessoa" -> old type
{
char nome[50], endereco[50];
int idade;
}Pessoas; //& "Pessoas" -> new type

Pessoas cadpessoa;

$ por causa do typedef, n põe struct qnd chama a variável
*/

/* malloc revisão e operador "->"
@   aponta -> conversão int de tantas alocações de tamanho int
    int *vet_din;

    vet_din = (int *)malloc(sizeof(int));

$   alocação dinâmica -> aponta para &
*   malloc aloca memória SEM formato, por isso a conversão antes

px->peso = 89; //+ onde px aponta, acesse a parte peso (operador "->")
*/

/*  Lista Encadeada
%   no fim de mem alocada, no fim tem um pt -> para outra mem alocada
*/
