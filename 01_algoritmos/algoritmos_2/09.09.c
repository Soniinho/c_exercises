#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    
    return 0;
}

/* ponteiro revisão 1
    int i = 10, j = 5;
    int *p, *q;
    p = &i;
    q = &j;
    printf("%d", p);                      //endereço de i
    printf("\n%d", *p);                   //valor de i
    printf("\n%d", &p);                   //endereço de p
    printf("\n%d", *&p);                  //endereço de i
    printf("\n%d", **&p);                 //valor de i
    printf("\n%d", 3 * (-*p) / (*q) + 7); //-30/5 -6 +7 = 1
*/

/* ponteiro revisão 2
    int i = 5, *p;
    p = &i;
    printf("%x", p); //endereço de i em hexadecimal
    printf("\n%p", p);
    printf("\n%d", *p + 2);   //7
    printf("\n%d", **&p + 4); //9
    printf("\n%d", 3 * (*p)); //15
*/

/* exemplo
void calcula(float r, float *p, float *a);

int main()
{
    setlocale(LC_ALL, "portuguese");
    float raio, perimetro, area;
    printf("Digite o valor para o raio: ");
    scanf("%f%*c", &raio);

    calcula(raio, &perimetro, &area);

    printf("\nPerímetro: %.1f", perimetro);
    printf("\nÁrea: %.1f", area);

    return 0;
}

void calcula(float r, float *p, float *a)
{
    *p = 2 * 3.14 * r;
    *a = 3.14 * r * r;
}
*/

/* xor para trocar valores
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    & ou
    a = a + b;
    b = a - b;
    a = a - b;
*/

/* ex 1
void trocaValor(int *a, int *b);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i = 5, j = 10;
    trocaValor(&i, &j);
    printf("Valores trocados i=%d e j=%d.", i, j);

    return 0;
}

void trocaValor(int *a, int *b)
{
    int troca;

    troca = *a;
    *a = *b;
    *b = troca;
}
*/

/* passagem de vetores
void maiusculo(char *s);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    char palavra[10];
    printf("Digite uma palavra de até 9 letras em minúsculo: ");
    scanf("%s%*c", palavra); //não passar endereço para vetor

    maiusculo(palavra); //endereço da primeira posição do vetor

    printf("\n%s é a palavra.", palavra);
}

void maiusculo(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = toupper(s[i]); //colocar em maiúsculo
        s[i++];
    }
}
*/
