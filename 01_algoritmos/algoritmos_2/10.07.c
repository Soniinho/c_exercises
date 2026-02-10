#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    setlocale(LC_ALL, "portuguese");
}

//% existem arquivos .txt e binários (.exe da vida)

//+ FILE *prt;
//^ ponteiro para manipulação do arquivo

/*
$ FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura); -> retorna ou NULL ou o ptr para o arquivo
@ mesmo diretorio do programa -> ".\\arquivo.txt" ou "arquivo.txt"
* caso não, é absoluto -> "C:\\Projeto\\Algoritmos\\arquivo.txt"

& Modos de abertura de arquivo (r, w, a, rb, wb, ab, r+, w+, a+, r+b, w+b, a+b)
*/

/* exemplo 1
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    FILE *ptr_arq;

    ptr_arq = fopen("exemplo.bin", "wb"); // binário para escrita
    if (ptr_arq == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        system("pause");
        exit(1);
    }
    else
    {
        printf("Arquivo aberto com sucesso.\n");
    }

    fclose(ptr_arq); //fecha o arquivo do ptr_arq
    system("pause");
}
*/

/* fputc (escrever no .txt) e fflush(forçar gravar)
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    FILE *arq;
    char string[100];
    int i;

    arq = fopen("arquivo.txt", "w");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    printf("Digite a string a ser gravada no arquivo:\n");
    fgets(string, 100, stdin);

    for (i = 0; i < strlen(string); i++)
    {
        fputc(string[i], arq);
    }

    fflush(arq); //gravar o arquivo, forçar gravação de dados
    fclose(arq);

    // fputc('*',stdout); -> escreve na tela do monitor invés de em um arquivo
    //fflush(stdin); //limpar buffer do teclado
}
*/

/* fgetc (pegar do .txt)
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    FILE *arq;
    char c;
    int i;

    arq = fopen("arquivo.txt", "r");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    for (i = 0; i < 50; i++)
    {
        c = fgetc(arq); //# pega o caractere do arquivo,
        //$ converte do inteiro da fgetc para char
        printf("%c", c);
    }

    fclose(arq);
    //% & char c fgetc(stdin) -> pd ser usado para ler do teclado
}
*/

/* feof e EOF (fgetc)
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    FILE *arq;
    char c;

    arq = fopen("arquivo.txt", "r");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    while ((c = fgetc(arq)) != EOF) //+ end of file (constante)
    {
        printf("%c", c);
    }

    fclose(arq);
}

    * ou
    \*
    while (1)
    {
        c = fgetc(arq);
        if (feof(arq)) //+ file end of file
        {
            break;
        }
        printf("%c", c);
    }
    *\

    & OBS: while (!feof(arq)) só funciona sem setlocale
    \*
    while (!feof(arq)) //+ file end of file
    {
        c = fgetc(arq);
        printf("%c", c);
    }
    *\
*/

/* ftell (identificar posição dentro do arquivo)
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    // long int ftell(FILE *fp) -> saber onde está no arquivo
    FILE *arq;
    arq = fopen("arquivo.bin", "rb");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    int tamanho;
    fseek(arq, 0, SEEK_END); //mudar a posição do ponteiro (do início mudou para o final)
    tamanho = ftell(arq);

    fclose(arq);
    printf("O tamanho do arquivo em bytes é: %d", tamanho);
}
*/

//$ Strings

/* fputs (por string em arquivo)
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    // fputs -> gravar string em arquivo, n coloca \n
    int result;
    char str[20] = "Biscoito yey";
    FILE *arq;
    arq = fopen("arquivo.txt", "w");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    result = fputs(str, arq); // EOF = -1;
    if (result == EOF)
    {
        printf("Erro na gravação");
    }
    fclose(arq);

    //fputs e fputc podem ser usados para mostar na tela (stdout)
}
*/

/* fgets (adiciona \n)
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    char str[20];
    char *result;
    FILE *arq;
    arq = fopen("arquivo.txt", "r");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    result = fgets(str, 20, arq); // EOF = -1;
    if (result == NULL)
    {
        printf("Erro na leitura");
    }
    else
    {
        printf("%s", str);
    }
    fclose(arq);
}
*/
