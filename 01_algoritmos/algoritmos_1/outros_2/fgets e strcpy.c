#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");

    char nome[10], nome1[20];

    printf("Digite o seu nome: ");
    fgets(nome, 10, stdin); //string smp termina com \n

    printf("%s é o seu nome", nome);

    strcpy(nome1, "Maria");
    printf("\n%s strcpy.", nome1);

    system("pause");
    return 0;
}