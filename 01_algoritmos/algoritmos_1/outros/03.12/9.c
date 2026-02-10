#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2, n3, m, f;
    char nome[30];
    printf("Digite o nome do Aluno:");
    scanf("%s", &nome);
    printf("Digite as 3 notas do aluno:");
    scanf("%f%f%f", &n1, &n2, &n3);
    printf("Digite o numero de faltas deste aluno:");
    scanf("%f", &f);

    m = (n1 * n2 * n3) / 3;

    if(f >= 0.25 * 80){
        printf("Aluno %s foi reprovado por faltas.", nome);
    }
    else
    {
        if(m < 7){
            printf("Aluno %s foi reprovado por media menor que 7.", nome);
        } else {
             printf("Aluno %s foi aprovado.", nome);
        }
    }

    return 0;
}
