//ex 4

#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, aux;
    float vet[20], x;

    for (i = 0; i < 20; i++)
    {
        printf("Digite um número[%d]: ", i);
        scanf("%f%*c", &vet[i]);
    }

    printf("Digite o número que deseja achar a posição no vetor: ");
    scanf("%f%*c", &x);

    aux = 0;
    for (i = 0; i < 20; i++)
    {
        if (vet[i] == x)
        {
            printf("\nO número %.2f está na posição [%d] do vetor.", x, i);
            aux = 1;
            break; //se tirar o break aparece msm se for tiver repetido no vetor
        }
    }
    
    if (aux == 0)
    {
        printf("\nO número %.2f não pertence ao vetor.", x);
    }

    return 0;
}