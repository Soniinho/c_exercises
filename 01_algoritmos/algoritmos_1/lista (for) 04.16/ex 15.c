#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define senha_acesso 123456

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, senha;

    for (i = 1; i <= 3; i++)
    {
        printf("Digite sua senha de 6 dígitos:");
        scanf("%d%*c", &senha);
        printf("\n");

        if (senha == senha_acesso)
        {
            printf("Acesso permitido.");
            return 0;
        }
        else
        {
            printf("Acesso negado.\n\n");
        }
    }

    printf("Você excedeu o limite de tentativas.\n");
    return 0;
}