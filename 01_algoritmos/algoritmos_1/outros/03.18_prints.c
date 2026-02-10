#include <stdio.h>
#include <stdlib.h>

/*
#define maxvalor 65 //constante - define Nome ValorDaConst

int main()
{
    int a= 10;
    printf("%d%",a);
    printf("%d",maxvalor);

    return 0;
}
     */

/*
int main()
{
    char sexo = 'f' // f
    char sexo = "f" // f\0   -  n funciona
    printf("%c",sexo);
    return 0;
}
*/

/*
int main()
{
    char opcao;
    opcao = 's';

    //char nome[40];      -V
    //nome = "Maria";      assim n funciona

    char nome = "Maria";
    char frase[] ={'p','e','d','r','o'};     //exemplos do que funciona
    char senhadigitada[]="senhadigitada";
    printf("%s",nome);

    char nome1[40];
    strcpy(nome1,"Maria"); //string copy
    printf("%s",nome1);

    char nome2[40];
    strcpy(nome2,"Maria"); //string copy
    char senha[12]="cerva";
    char senhanova[12];
    strcpy(senhanova,senha);
    printf("%s",senhanova);

    return 0;
}
*/

/*
int main()
{
    char sexo;
    char nome[40];
    int idade;
    float peso;
    printf("Digite seu nome:");
    scanf("%s%*c",&nome); //%*c -limpa o buffer do teclado em td
    printf("Digite sua idade:");
    scanf("%d%*c",&idade);
    printf("Digite seu peso:");
    scanf("%f%*c",&peso);
    //fflush(stdin); //limpa o buff do teclado no windows
    printf("Digite seu sexo:");
    scanf("%c%*c",&sexo);

    return 0;
}
*/

/*
int main()
{
    int x,z;
    float y;
    x=5;
    y=3;
    z = x%(int)y; //casting - transformar variavel
    printf("%d",z);

    return 0;
}
*/

/*
int main()
{
    int x,z;
    float y;
    x = 5;
    y = 3.5;

    printf("\n%f",ceil(y)); //4 - aprox pra cima
    printf("\n%f",floor(y)); //3 - aprox pra baixo

    return 0;
}
*/

/*
#include <math.h>
int main()
{
    double x,y;
    double z;
    x = 14.523;
    z = modf(x,&y);
    //y pega a parte inteira
    //z pega a parte decimal

    printf("\n%f\t%f",y,z); //\t - da espaço

    return 0;
}
*/

/*
#include <math.h>
int main()
{
    int x=3, y=5;
    x = x + 2;
    printf("%d",x);
    x = 3; y = 5;
    x++;
    x+=2;
    printf("\n%d",x);

    return 0;
}
*/

/*
int main()
{
    char nome[40];
    fgets(nome,40,stdin); //digitar string com espaço dentro

    return 0;
}
*/
