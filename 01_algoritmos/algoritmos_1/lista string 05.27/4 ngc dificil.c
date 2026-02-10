#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, j, k = 0;
    int tam, tam_d = 256;
    char frase[100], letras[tam_d];
    int qtd_letras[tam_d];

    for (i = 0; i < tam_d; i++)
    {
        qtd_letras[i] = 0;
        letras[i] = 0; //: 0 ou '\0' é a msm coisa
    }

    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin);
    frase[strlen(frase) - 1] = 0;
    //strcpy(frase, "prova ropva");

    tam = strlen(frase);

    for (i = 0; i < tam; i++)
    {
        j = 0;
        while (frase[i] != letras[j] && j < tam)
        {
            j++;
        }
        if (j == tam && frase[i] != letras[j] && frase[i] != ' ')
        {
            letras[k] = frase[i];
            qtd_letras[k]++;
            k++;
        }
        else if (frase[i] == letras[j])
        {
            qtd_letras[j]++;
        }
    }

    for (i = 0; i < k; i++)
    {
        if (qtd_letras[i] > 1)
        {
            printf("A letra %c se repete %d vezes.\n", letras[i], qtd_letras[i]);
        }
    }

    return 0;
}