#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    char nome[10];
    fgets(nome, 10, stdin);
    printf("%d", strlen(nome));
    printf("\n%s", nome);

    return 0;
}