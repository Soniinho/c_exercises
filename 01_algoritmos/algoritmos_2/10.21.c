#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    return 0;
}

/* fprintf
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    char nome[20];

    ptr_arq = fopen("arq1.txt", "w");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    printf("Digite seu primeiro nome:\n");
    scanf("%s%*c", nome);

    fprintf(ptr_arq, "%s", nome);

    fclose(ptr_arq);
    printf("\nDados gravados.");
    
    return 0;
}
*/

/* fputc
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    int i;
    char frase[50];

    ptr_arq = fopen("arq2.txt", "w");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    printf("Digite uma frase:\n");
    fgets(frase, 50, stdin);
    frase[strlen(frase) - 1] = 0;

    for (i = 0; i < strlen(frase); i++)
    {
        fputc(frase[i], ptr_arq);
    }

    fclose(ptr_arq);
    printf("\nDados gravados.");

    return 0;
}
*/

/* fputs
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    int i, teste;
    char frase[50];

    ptr_arq = fopen("arq3.txt", "w");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    printf("Digite uma frase:\n");
    fgets(frase, 50, stdin);
    frase[strlen(frase) - 1] = 0;

    teste = fputs(frase, ptr_arq);
    if (teste == EOF)
    {
        printf("Erro na gravação.");
    }

    fclose(ptr_arq);
    printf("\nDados gravados.");

    return 0;
}
*/

/* ler arquivo 1
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    char c;

    ptr_arq = fopen("arq2.txt", "r");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    do
    {
        c = fgetc(ptr_arq);
        printf("%c", c);
    } while (ptr_arq != EOF);

    fclose(ptr_arq);

    return 0;
}
*/

/* ler arquivo 2
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    char texto[50];

    ptr_arq = fopen("arq1.txt", "r");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    while (fgets(texto, 50, ptr_arq) != NULL)
    {
        printf("%s",texto);
    }

    fclose(ptr_arq);

    return 0;
}
*/

/* escrever 10 frases
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    int i, linha = 0;
    char texto[50];

    ptr_arq = fopen("arq1.txt", "w");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    while (linha < 10)
    {
        printf("Digite uma frase:");
        fgets(texto, 50, stdin);
        fputs(texto, ptr_arq);
        linha++;
    }

    fclose(ptr_arq);

    return 0;
}
*/

/* ler n° de caracteres
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    int carac = 0;
    char c;

    ptr_arq = fopen("arq1.txt", "r");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    while ((c = fgetc(ptr_arq)) != EOF)
    {
        if (c != '\n') //\n no ngc conta cm 2 caracteres, (cr / lf) = (\n)
        {
            carac++;
        }
    }

    printf("O arquivo tem %d caracteres.", carac);
    fclose(ptr_arq);

    return 0;
}
*/

/* ler qnts palavras tem de modo porco
int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;
    int palavras = 1;
    char c, t;

    ptr_arq = fopen("arq1.txt", "r");
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    while ((c = fgetc(ptr_arq)) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            palavras++;
        }
    }

    printf("O arquivo tem %d palavras.", palavras);
    fclose(ptr_arq);

    return 0;
}
*/
