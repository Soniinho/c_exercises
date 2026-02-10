//assinatura
void soma();              //sem retorno(voltar algum valor) e sem parametros(mandar valores)
void soma1(int x, int y); //sem retorno e com parametros
int soma3();              //com retorno e sem parametros
int soma2(int x, int y);  //com retorno e com parametros

void subtrai();
int diferenca();

#include <stdio.h>

int main()
{
    int x, y;
    //soma();
    //x = soma3();
    //printf("\nSoma: %d", x);

    /*
    int x;
    int a, b, s;
    printf("\nDigite dois valores inteiros:");
    scanf("%d%*c", &a);
    scanf("%d%*c", &b);
    soma(a, b);
    x = soma3(a, b);
    printf("\nSoma: %d", x);
    */

    subtrai();
    printf("\n\n");
    y = diferenca();
    printf("A diferenca e %d.", y);

    return 0;
}

void soma()
{
    int a, b, s;
    printf("\nDigite dois valores inteiros:");
    scanf("%d%*c", &a);
    scanf("%d%*c", &b);
    s = a + b;
    printf("\nSoma: %d", s);
}

int soma3()
{
    int a, b, s;
    printf("\nDigite dois valores inteiros:");
    scanf("%d%*c", &a);
    scanf("%d%*c", &b);
    s = a + b;
    return s;
}

void soma1(int x, int y)
{
    int s;
    s = x + y;
    printf("\nSoma: %d", s);
}

int soma2(int x, int y)
{
    int s;
    s = x + y;
    return s;
}

void subtrai()
{
    int a, b, sub;
    printf("Sera subtraido o 2 do 1 valor.\n");
    printf("Digite 2 valores: ");
    scanf("%d%d*%c", &a, &b);
    sub = a - b;
    printf("Subtracao: %d.", sub);
}

int diferenca()
{
    int a, b, sub;
    printf("Sera subtraido o 1 do 2 valor.\n");
    printf("Digite 2 valores: ");
    scanf("%d%d*%c", &a, &b);
    sub = b - a;
    return sub;
}

/* //1
#include <stdio.h>
///funcao sem retorno e sem parametro
///determine se o numero e par ou impar

void parImpar();

int main()
{
    parImpar();
    return 0;
}

void parImpar()
{
    int a;
    printf("\nDigite um numero inteiro:");
    scanf("%d%*c", &a);
    if (a % 2 == 0)
    {
        printf("Numero e par");
    }
    else
    {
        printf("Numero impar");
    }
}
*/

/* //2
#include <stdio.h>
///funcao sem retorno e sem parametro
///determine se o numero e par ou impar

char parImpar(int x);

int main()
{
    char retorno;
    int a;
    printf("\nDigite um numero inteiro:");
    scanf("%d%*c", &a);
    retorno = parImpar(a);
    printf("%c", retorno);
    return 0;
}

char parImpar(int x)
{

    if (x % 2 == 0)
    {
        return 'p';
    }
    else
    {
        return 'i';
    }
}
*/

/* //3
#include <stdio.h>
///funcao sem retorno e sem parametro
///determine se o numero e par ou impar

char parImpar(int x);

int main()
{
    char retorno;
    int a;
    printf("\nDigite um numero inteiro:");
    scanf("%d%*c", &a);
    retorno = parImpar(a);
    printf("%c", retorno);
    return 0;
}

char parImpar(int x)
{

    if (x % 2 == 0)
    {
        return 'p';
    }
    else
    {
        return 'i';
    }
}
*/

/* //4
#include <stdio.h>
#include <locale.h>

float quociente(float x, float y);

void main()
{
    setlocale(LC_ALL, "portuguese");
    float r;
    int x = 4, y = 6;

    r = quociente(x, y);
    printf("\nQuociente: %f.", r);
}

float quociente(float x, float y)
{
    float resultado;
    resultado = x / y;
    return resultado;
}
*/

/* //5

///ela só n morre na função
#include <stdio.h>

float x = 10;

void mudaX1();
void mudaX2();

void main(){
    mudaX1();
    mudaX2();
    printf("\n%f", x);    
}

void mudaX1()
{
    x++;
    printf("\n%f", x);
}

void mudaX2()
{
    x += 3;
    printf("\n%f", x);
}
*/
