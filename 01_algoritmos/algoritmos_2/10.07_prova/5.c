#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define N 10

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct Alunos
    {
        int matr, cod_dis;
        char nome[30];
        float n1, n2, med;
    };

    int i;
    struct Alunos cad[10];

    printf("Será feito o cadastro de 10 alunos:\n\n");
    for (i = 0; i < N; i++)
    {
        printf("Cadastro [%d]:\n", i + 1);
        printf("Matrícula: ");
        scanf("%d%*c", &cad[i].matr);

        printf("Nome: ");
        fgets(cad[i].nome, 30, stdin);
        cad[i].nome[strlen(cad[i].nome) - 1] = 0;

        printf("Código da Disciplina: ");
        scanf("%d%*c", &cad[i].cod_dis);

        printf("Notas da P1 e P2, respectivamente:\n");
        scanf("%f%*c%f%*c", &cad[i].n1, &cad[i].n2);

        cad[i].med = (cad[i].n1 + (cad[i].n2 * 2)) / 3;
    }

    system("cls");
    for (i = 0; i < N; i++)
    {
        printf("Cadastro [%d]:\n", i + 1);
        printf("Nome: %s  --> Média: %2.f.", cad[i].nome, cad[i].med);
        printf("\n\n");
    }

    return 0;
}