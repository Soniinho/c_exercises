#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, j, tam_f;
    char frase[100], frase_corr[100];
    int qtd_palavras = 1;

    printf("Digite uma frase:\n"); //digitar só espaços causa erro
    fgets(frase, 100, stdin);
    frase[strlen(frase) - 1] = 0;
    tam_f = strlen(frase);

    //tirar espaço do fim
    i = tam_f;
    while (frase[i - 1] == ' ')
    {
        i--;
    }
    frase[i] = 0; //msm q definir cm '\0'
    tam_f = strlen(frase);

    //tirar espaço do início
    i = 0;
    while (frase[i] == ' ')
    {
        i++;
    }
    for (j = 0; i < tam_f; i++, j++)
    {
        frase_corr[j] = frase[i];
    }
    strcpy(frase, frase_corr);
    tam_f = strlen(frase);

    //tirar espaços a mais entre palavras
    for (i = 0, j = 0; i < tam_f; i++, j++)
    {
        while (frase[i] == ' ' && frase[i + 1] == ' ')
        {
            i++;
        }
        frase_corr[j] = frase[i];
    }
    frase_corr[j] = 0;
    tam_f = strlen(frase_corr);

    //contar as palavras
    for (i = 0; i < tam_f; i++)
    {
        if (frase_corr[i] == ' ')
        {
            qtd_palavras++;
        }
    }

    //digitar a frase
    printf("\n%s", frase_corr);
    printf("\nHá %d palavras na frase acima.", qtd_palavras);

    return 0;
}