#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char *concatena(char *s1, char *s2);

int main()
{
    setlocale(LC_ALL, "portuguese");
    char frase1[20], frase2[20], *concatenado;
    printf("\tConcatenação de 2 frases\n\n");
    printf("Digite uma frase: ");
    fgets(frase1, 20, stdin);
    frase1[strlen(frase1) - 1] = 0;
    printf("Digite uma segunda frase: ");
    fgets(frase2, 20, stdin);
    frase2[strlen(frase2) - 1] = 0;

    concatenado = concatena(frase1, frase2);

    printf("\n%s", concatenado);

    /* //* testado se ta pondo certo msm
    printf("\n");
    for (int i = 0; i < strlen(concatenado); i++)
    {
        printf("%c", concatenado[i]);
    }
    */

    free(concatenado);
    return 0;
}

char *concatena(char *s1, char *s2)
{
    char *retorno = NULL; // o NULL serve pra verificar se ta funcionado

    // retorno = (char *)malloc((t1 + t2 + 1) * sizeof(char));
    retorno = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char)); //@ +1 pro \0

    strcat(retorno, s1);
    strcat(retorno, s2);

    return retorno;
}

/* Explicações
% operador "sobrecarregado" -> serve para mais de 1 coisa (ex: "*")
$ vetor NÃO usa & para passar para ponteiro -> se passar sem nd vai só o nome da var
------------------- ex ----------------------------
int a[3], *p;
p = a; ou p = &a[0]; //+ a ja tem um & de mem
---------------------------------------------------
? n da pra alocar 4 bilhões de int fixamente
! casting pro malloc não precisa, mas é bom fazer
~ alocação dinâmica aloca em lugar diferente da mem, e maior
^ alocação dinâmica n é desalocado quando acaba a função, mas NÃO é global (só libera com free)
todo: calloc zera os ngc, estudar dps
*/

/*
% função n pd devolver vetor, mas pd devolver ponteiro
* usar:
"   char *concatena(char *s1, char*s2);   "
*/