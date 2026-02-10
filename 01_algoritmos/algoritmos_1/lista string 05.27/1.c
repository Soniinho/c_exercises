#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100];
    int i, qtde = 0;
    printf("Digite uma frase");
    fgets(frase, 100, stdin); //stdin = teclado

    for (i = 0; i < (strlen(frase)-1); i++)
    {
        if (frase[i] == 'a' || frase[i] == 'A' || frase[i] == 'e' || frase[i] == 'E' || frase[i] == 'i' || frase[i] == 'I' || frase[i] == 'o' || frase[i] == 'O' || frase[i] == 'u' || frase[i] == 'U')
        {
            qtde++;
        }
    }

    printf("%d", qtde);

    return 0;
}