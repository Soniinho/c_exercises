#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct Aluno
    {
        char nome[30];
        int mat;
        float med;
    };

    int i, ap, rp;
    struct Aluno reg[10], aprov[10], reprov[10];

    printf("Será feito o registo de 10 alunos:\n");
    for (i = 0, ap = 0, rp = 0; i < 10; i++)
    {
        printf("Nome: ");
        fgets(reg[i].nome, 30, stdin);
        reg[i].nome[strlen(reg[i].nome) - 1] = 0;

        printf("Matrícula: ");
        scanf("%d%*c", &reg[i].mat);

        printf("Média Final: ");
        scanf("%f%*c", &reg[i].med);
        printf("\n");

        if (reg[i].med >= 5)
        {
            aprov[ap] = reg[i];
            ap++;
        }
        else
        {
            reprov[rp] = reg[i];
            rp++;
        }
    }

    system("cls");
    printf("Aprovados:\n\n");
    for (i = 0; i < ap; i++)
    {
        printf("Nome: %s  Matrícula: %d  Média: %.2f\n", aprov[i].nome, aprov[i].mat, aprov[i].med);
    }

    printf("\nReprovados:\n\n");
    for (i = 0; i < rp; i++)
    {
        printf("Nome: %s  Matrícula: %d  Média: %.2f\n", reprov[i].nome, reprov[i].mat, reprov[i].med);
    }

    return 0;
}