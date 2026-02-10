#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>
#define N 7

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    char nomes[N][30], nome_maior_media[30];
    float media[N], maior_media;

    printf("Digite o nome de %d alunos e suas médias a seguir:\n", N);
    for (i = 0; i < N; i++)
    {
        printf("%dº aluno: ", i + 1);
        fgets(nomes[i], 30, stdin);
        nomes[i][strlen(nomes[i]) - 1] = 0;

        printf("Média de %s: ", nomes[i]);
        scanf("%f%*c", &media[i]);

        if (i == 0)
        {
            maior_media = media[i];
            strcpy(nome_maior_media, nomes[i]);
        }
        else if (media[i] > maior_media)
        {
            maior_media = media[i];
            strcpy(nome_maior_media, nomes[i]);
        }
    }
    printf("\nO aluno com maior média (%.2f) é %s.\n\n", maior_media, nome_maior_media);
    printf("Alunos com médias abaixo de 7:\n\n");

    for (i = 0; i < N; i++)
    {
        if (media[i] < 7)
        {
            printf("O aluno %s obteve %.2f de média final.\n", nomes[i], media[i]);
            printf("%s precisa tirar %.2f no exame final para ser aprovado.\n", nomes[i], 10 - media[i]);
        }
    }

    return 0;
}