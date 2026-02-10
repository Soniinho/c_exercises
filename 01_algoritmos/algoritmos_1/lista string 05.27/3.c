#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, qtd = 0, j;
    char frase[100];
    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin);

    //frase[strcspn(frase, "\n")] = 0;
    //mudar primeira ocorrência, definir cm 0 mata td dps dessa posição
    
    if (strlen(frase) > 1) //retirar ultimo "\n" sem riscos
    {
        if (frase[strlen(frase) - 1] != NULL && frase[strlen(frase) - 1] == '\n')
        {
            frase[strlen(frase) - 1] = 0; //retirar ultimo "\n"
        }
    }

    if (frase[0] != ' ' && frase[0] != '\n')
    {
        qtd++;
    }

    for (i = 1; i < (strlen(frase) - 1); i++) //conta o enter
    {
        if (frase[i] != ' ' && frase[i - 1] == ' ')
        {
            qtd++;
        }
    }

    printf("Foram digitadas %d palavras.", qtd);

    return 0;
}