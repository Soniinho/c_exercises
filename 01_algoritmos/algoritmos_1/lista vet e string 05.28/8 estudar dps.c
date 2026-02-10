#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>

//esse programa n funciona se por acento
int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, j;
    char frase[100], frase_cript[100];
    char consoantes[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"; //ç n vai sla pq

    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin);

    frase[strlen(frase) - 1] = 0; //tira o \n, -1 pq é vetor
    j = strlen(frase) - 1;        //vetor começa em 0

    //inverter a frase
    for (i = 0; frase[i] != '\0'; i++)
    {
        frase_cript[j] = frase[i];
        j--;
    }
    frase_cript[i] = '\0'; //evitar mostrar lixo de memória

    strcpy(frase, frase_cript); //põe a invertida na frase digitada

    //trocar consoantes por #
    for (i = 0; i < strlen(frase); i++)
    {
        for (j = 0; j < strlen(consoantes); j++)
        {
            if (frase[i] == consoantes[j])
            {
                frase_cript[i] = '#';
            }
        }
    }

    printf("\nA nova frase é:\n%s", frase_cript);
    return 0;
}