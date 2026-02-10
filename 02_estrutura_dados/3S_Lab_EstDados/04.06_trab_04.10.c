// Matheus Henrique Daltroso RA: 202110059

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *initVet(int *size, int *maxSize);
void printVet(int *v, int size, int maxSize);
int *addVet(int *v, int *size, int *maxSize, int e);
int find(int *v, int size, int e);
int *removeVet(int *v, int *size, int *maxSize, int e);

void main()
{
    setlocale(LC_ALL, "portuguese");

    int opc;
    int *vetor = NULL, tam, tam_max, valor, pos_find;
    //vetor = NULL;

    vetor = initVet(&tam, &tam_max); //tinha que ter colocado isso no trab
    do
    {
        system("cls");
        printf("  Criação de Vetor (Não use sem inicializar) \n");
        printf("Selecione uma das opções abaixo para continuar:\n\n");
        printf("1- Inicializar o vetor\n");
        printf("2- Imprimir conteúdo e tamanho associados ao vetor\n");
        printf("3- Adicionar um elemento ao final do vetor\n");
        printf("4- Procurar valor no vetor\n");
        printf("5- Remover a primeira ocorrência de um elemento do vetor\n");
        printf("6- Sair\n");

        printf("Opção: ");
        scanf("%d%*c", &opc);

        switch (opc)
        {
        case 1:
            vetor = initVet(&tam, &tam_max);
            if (initVet != NULL)
            {
                printf("Vetor inicializado com sucesso.\n");
            }
            system("pause");
            break;
        case 2:
            printVet(vetor, tam, tam_max);
            printf("\n");
            system("pause");
            break;
        case 3:
            printf("Digite o valor que deseja adicionar: ");
            scanf("%d%*c", &valor);
            addVet(vetor, &tam, &tam_max, valor);
            system("pause");
            break;
        case 4:
            printf("Digite o valor que deseja procurar: ");
            scanf("%d%*c", &valor);
            pos_find = find(vetor, tam, valor);
            if (pos_find == -1)
            {
                printf("O elemento %d não está no vetor.\n", valor);
            }
            else
            {
                printf("O elemento %d está na posição %d.\n", valor, pos_find);
            }
            system("pause");
            break;
        case 5:
            printf("Digite o valor que deseja remover: ");
            scanf("%d%*c", &valor);
            removeVet(vetor, &tam, &tam_max, valor);
            system("pause");
            break;
        case 6:
            printf("Terminando programa.\n");
            printf("Programa Finalizado com sucesso.\n");
            system("pause");
            break;
        default:
            printf("Opção Inválida. Seleciona uma das opções acima\n");
            system("pause");
            break;
        }
    } while (opc != 6);

    free(vetor);
}

int *initVet(int *size, int *maxSize)
{
    int *vet_aux;

    *size = 0;
    *maxSize = 4;

    vet_aux = (int *)malloc((*maxSize) * sizeof(int));

    return vet_aux;
}

void printVet(int *v, int size, int maxSize)
{
    int i;

    printf("\n Tamanho: %d e Tamanho Máximo: %d \n", size, maxSize);
    printf("Vetor[%d]: ", size);
    if (size != 0)
    {
        for (i = 0; i < size; i++)
        {
            printf("%d ", v[i]);
        }
    }
}

int *addVet(int *v, int *size, int *maxSize, int e)
{
    int i, *v_aux;

    if (*size < *maxSize)
    {
        v[*size] = e;
        (*size)++;
    }
    else if (*size == *maxSize)
    {
        *maxSize *= 2;
        v_aux = (int *)malloc((*maxSize) * sizeof(int));

        for (i = 0; i < *size; i++)
        {
            v_aux[i] = v[i];
        }
        free(v);
    }

    return v_aux;
}

int find(int *v, int size, int e)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (v[i] == e)
        {
            break;
        }
    }

    if (i == size && v[i] != e)
    {
        i = -1;
    }

    return i;
}

int *removeVet(int *v, int *size, int *maxSize, int e)
{
    int i, j, pos_proc, *v_aux;

    pos_proc = find(v, *size, e);
    if (pos_proc == -1)
    {
        exit;
    }
    else
    {
        if (*size < ((*maxSize) / 4) && (*size - 1) != 0)
        {
            *maxSize = (*maxSize) / 2;
        }

        v_aux = (int *)malloc((*maxSize) * sizeof(int));

        if ((*size - 1) != 0)
        {
            for (i = 0; i < (*size); i++)
            {
                if (i != pos_proc)
                {
                    v_aux[j] = v[i];
                    j++;
                }
            }
        }
        (*size)--;
    }

    free(v);
    return v_aux;
}
