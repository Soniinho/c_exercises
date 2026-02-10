#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, n_lesma, lesma_maior_dist = 1;
    float temp_compet, maior_dist, *veloc_lesma, *dist_total;

    printf("\tCorrida de Lesmas!\n\n");
    do
    {
        printf(" Digite o número de lesmas que estarão na corrida: ");
        scanf("%d%*c", &n_lesma);
    } while (n_lesma < 1);

    do
    {
        printf(" Digite a duração da competição em horas: ");
        scanf("%f%*c", &temp_compet);
    } while (temp_compet <= 0);

    veloc_lesma = (float *)malloc(sizeof(float) * n_lesma);
    dist_total = (float *)malloc(sizeof(float) * n_lesma);

    for (i = 0; i < n_lesma; i++)
    {
        do
        {
            printf("Digite a velocidade da lesma [%d] em cm/h: ", i + 1);
            scanf("%f%*c", &veloc_lesma[i]);
            if (veloc_lesma[i] > 100)
            {
                printf("Essa lesma é rápida demais para uma lesma, digite uma velocidade real.\n");
            }
        } while (veloc_lesma[i] < 0 && veloc_lesma > 100);
    }

    maior_dist = 0;
    for (i = 0; i < n_lesma; i++)
    {
        if (veloc_lesma[i] <= 10)
        {
            if (temp_compet <= 3)
            {
                dist_total[i] = veloc_lesma[i] * temp_compet;
            }
            else
            {
                dist_total[i] = veloc_lesma[i] * 3;
            }
        }
        else if (veloc_lesma[i] > 10 && veloc_lesma[i] >= 20)
        {
            if (temp_compet <= 2)
            {
                dist_total[i] = veloc_lesma[i] * temp_compet;
            }
            else
            {
                dist_total[i] = veloc_lesma[i] * 2;
            }
        }
        else
        {
            if (temp_compet <= 1)
            {
                dist_total[i] = veloc_lesma[i] * temp_compet;
            }
            else
            {
                dist_total[i] = veloc_lesma[i] * 1;
            }
        }

        if (dist_total[i] > maior_dist)
        {
            maior_dist = dist_total[i];
            lesma_maior_dist = i + 1;
        }
    }

    printf("A lesma que vai mais longe nas condições apresentadas é a lesma %d, com velocidade de %.2f cm/h.", lesma_maior_dist, veloc_lesma[lesma_maior_dist - 1]);

    free(veloc_lesma);
    free(dist_total);
    return 0;
}