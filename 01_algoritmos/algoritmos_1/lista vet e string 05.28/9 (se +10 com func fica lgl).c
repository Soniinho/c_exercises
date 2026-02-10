#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    char frase[100], frase_nova[100];

    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin);

    frase[strlen(frase) - 1] = 0;
    strcpy(frase_nova, frase);

    for (i = 0; i < strlen(frase); i++)
    {
        if (frase[i] == ' ' && frase[i - 1] != ' ')
        {
            frase_nova[i] = '\n';
        }
    }
    frase[i] = '\0';

    printf("\n%s", frase_nova);

    return 0;
}