#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct Aluno
    {
        char nome[30], curso[30];
        int n_matr;
    };

    int i;
    struct Aluno cad[5];

    printf("Realização de cadastro de 5 alunos:\n\n");
    for (i = 0; i < 5; i++)
    {
        printf(" Cadastro [%d]:\n", i + 1);
        printf("N° de matrícula: ");
        scanf("%d%*c", &cad[i].n_matr);

        printf("Nome: ");
        fgets(cad[i].nome, 30, stdin);
        cad[i].nome[strlen(cad[i].nome) - 1] = 0;

        printf("Curso: ");
        fgets(cad[i].curso, 30, stdin);
        cad[i].curso[strlen(cad[i].curso) - 1] = 0;
        printf("\n");
    }
    system("cls");
    printf("-Cadastros feitos:\n\n");
    for (i = 0; i < 5; i++)
    {
        printf(" Cadastro Aluno[%d]\n", i + 1);
        printf("N° de matrícula: %d\n", cad[i].n_matr);
        printf("Nome: %s\n", cad[i].nome);
        printf("Curso: %s\n\n", cad[i].curso);
    }

    return 0;
}

/* gambiarra pra mostrar acento no %s
    for (i = 0; i < 5; i++)
    {
        printf("Cadastro Aluno[%d]\n", i + 1);
        printf("N° de matrícula: %d\n", cad[i].n_matr);

        setlocale(LC_ALL, "C");
        printf("Nome: %s\n", cad[i].nome);

        setlocale(LC_ALL, "portuguese");
        printf("Endereço: ");

        setlocale(LC_ALL, "C");
        printf("%s\n", cad[i].curso);
    }
*/