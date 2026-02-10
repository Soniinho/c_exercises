#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h> //para strcpy etc

int main()
{
    setlocale(LC_ALL, "portuguese");



    return 0;
}

/*  //explicações
    ///manipulação de cadeias de caracteres
    //* outra variável n pega o espaço n usado do vetor
    ///? após o último caractere digitado, é colocado \0 (windows) ou \n (linux)
    
    
    char nome1[] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', 'a', '\0'};
    char nome[] = "Programa"; //ambos tem 9, o de baixo tem /0 tbm
    char sobrenome[] = "Daltroso";

    ///? nome = "Matheus"; //vai tentar colocar td no 0, n funciona

    strcpy(nome, "Matheus "); //* funciona
    ///strcat(nome, " "); //se n tiver um espaço no de cima
    strcat(nome, sobrenome);

    
    printf("%s", nome);
    char name[10] = "Mat";
    printf("\n%s oioioi.", name); //n ta pulando linha n sei pq

    char dia[3], mes[3], ano[5];
    char data[10]; //11,12,13 ta zoado se usar td de strcat, ou deve zerar a string    

    strcpy(dia, "27");
    strcpy(mes, "05");
    strcpy(ano, "2021");
    printf("%s/%s/%s", dia, mes, ano);

    strcpy(data, dia);
    strcat(data, "/");
    strcat(data, mes);
    strcat(data, "/");
    strcat(data, ano);
    printf("%s", data);

    ///char pd até 127 ou unsigned char até 255 (isso conta o \0)

    char frase[100];
    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin); //stdin de entrada padrão
    printf("%s aaaa", frase);
    printf("%d", strlen(frase));
    ///strlen retorna o tamanho da string sem o \0, se n usar fgets
    
*/

/* //programinha
    
#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#include <string.h> //para strcpy etc

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, tamanho;
    char frase[100];
    
    printf("Digite uma frase:\n");
    fgets(frase, 100, stdin);
    tamanho = strlen(frase) - 1;
    
    for (i = 0; i < tamanho; i++)
    {
        printf("\n%c", frase[i]);
    }

    return 0;
}

*/