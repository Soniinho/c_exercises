#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    char vogal[] = "aáàââãeéêiíoôuúAÁÀEÉIÍOUèêìîóòõùûÂÃÈÊÌÎÓÒÔÚÙÛ"; //y e Y
    char consoante[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZİ"; //ç e Ç n vai
    char frase[100];
    int i, j, qtd_c = 0, qtd_v = 0;

    //ou  {'a', 'á', 'à', 'â', 'ã', 'e', 'é', 'ê', 'i', 'í', 'o', 'ó', 'ô', 'u', 'ú'};
    //ou {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    //tem q por as maiusculas neles
    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin); 

    for (i = 0; i < strlen(frase); i++)
    {
        for (j = 0; j < strlen(consoante); j++)
        {
            if (frase[i] == consoante[j])
            {
                qtd_c++;
                break;
            }
        }

        for (j = 0; j < strlen(vogal); j++)
        {
            if (frase[i] == vogal[j])
            {
                qtd_v++;
                break;
            }
        }
    }

    printf("Há %d consoantes na frase.", qtd_c);
    printf("\nHá %d vogais na frase.", qtd_v);

    return 0;
}