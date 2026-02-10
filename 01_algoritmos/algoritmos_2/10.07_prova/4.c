#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct Aluno
    {
        int matr;
        char nome[30];
        float nota_1, nota_2, nota_3, media;
    };

    int i, m_p1, mai_m, men_m;
    float nota_mp1, nota_maimed, nota_menmed;
    struct Aluno cad[5];

    printf("Será feito o cadastro de 5 Alunos (média de aprovação é 6):\n");
    for (i = 0; i < 5; i++)
    {
        printf("Cadastro [%d]:\n", i + 1);
        printf("N° da matrícula: ");
        scanf("%d%*c", &cad[i].matr);

        printf("Nome: ");
        fgets(cad[i].nome, 30, stdin);
        cad[i].nome[strlen(cad[i].nome) - 1] = 0;

        printf("Digite a nota da 1ª, 2ª e 3ª prova, em sequência:\n");
        scanf("%f%*c%f%*c%f%*c", &cad[i].nota_1, &cad[i].nota_2, &cad[i].nota_3);
        printf("\n");
    }

    for (i = 0; i < 5; i++)
    {
        cad[i].media = (cad[i].nota_1 + cad[i].nota_2 + cad[i].nota_3) / 3;

        if (i == 0)
        {
            nota_mp1 = cad[i].nota_1;
            m_p1 = i;
            nota_maimed = cad[i].media;
            nota_menmed = cad[i].media;
            mai_m = i;
            men_m = i;
        }
        else
        {
            if (cad[i].nota_1 > nota_mp1)
            {
                nota_mp1 = cad[i].nota_1;
                m_p1 = i;
            }

            if (cad[i].media > nota_maimed)
            {
                nota_maimed = cad[i].media;
                mai_m = i;
            }
            else if (cad[i].media < nota_menmed)
            {
                nota_menmed = cad[i].media;
                men_m = i;
            }
        }
    }

    system("cls");
    printf("Aluno com maior nota da 1ª prova é: %s --> Nota: %.2f", cad[m_p1].nome, nota_mp1);
    printf("\nAluno com maior média é: %s --> Média: %.2f", cad[mai_m].nome, nota_maimed);
    printf("\nAluno com menor média é: %s --> Média: %.2f", cad[men_m].nome, nota_menmed);

    printf("\n\n");
    for (i = 0; i < 5; i++)
    {
        if (cad[i].media >= 6)
        {
            printf("O aluno %s foi aprovado com média %.2f.\n", cad[i].nome, cad[i].media);
        }
        else
        {
            printf("O aluno %s foi reprovado com média %.2f.\n", cad[i].nome, cad[i].media);
        }
    }

    return 0;
}