#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct Cad
    {
        char nome[30], place[80];
        int idade;
    };
    struct Cad list;

    printf("Digite seu nome: ");
    fgets(list.nome, 30, stdin);
    printf("Digite sua idade: ");
    scanf("%d%*c", &list.idade);
    printf("Digite seu endereço: ");
    fgets(list.place, 80, stdin);

    list.nome[strlen(list.nome) - 1] = 0;
    list.place[strlen(list.place) - 1] = 0;

    system("cls");
    printf("Cadastro:\n\nNome: %s\nIdade: %d\nEndereço: %s", list.nome, list.idade, list.place);

    return 0;
}