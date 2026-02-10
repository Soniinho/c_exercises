#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, qt_balao_total, qt_balao_aux;
    int *vetor;
    int maior_altura, flechas = 0;

    printf("Digite a quantidade de balões: ");
    scanf("%d%*c", &qt_balao_total);

    vetor = (int *)malloc(sizeof(int) * qt_balao_total);

    for (i = 0; i < qt_balao_total; i++)
    {
        printf("Digite a altura do balão [%d]: ", i + 1);
        scanf("%d%*c", &vetor[i]);
    }

    qt_balao_aux = qt_balao_total;
    while (qt_balao_aux > 0)
    {
        // ver a altura maior q possui balão
        maior_altura = vetor[0];
        for (i = 1; i < qt_balao_total; i++)
            if (maior_altura < vetor[i])
                maior_altura = vetor[i];

        // percorrer o eixo X, tirando balão e diminuindo altura se necessário
        for (i = 0; i < qt_balao_total; i++)
        {
            if (vetor[i] == maior_altura)
            {
                vetor[i] = -1;
                maior_altura--;
                qt_balao_aux--;
            }
        }

        flechas++;
    }

    printf("O número de flechas é: %d", flechas);

    return 0;
}
