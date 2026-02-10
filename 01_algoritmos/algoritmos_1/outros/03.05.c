#include <stdio.h> //standard input output header

int main()
{
    int x=3; //int n° inteiro
    float y=3.5; //float ponto flutuante, n° real
    double z=27.6; //double n° real tbm, 8 bytes
    char sexo='f'; //literal, caractere
    char nome[8]="Matheus"; //string - 1 carac a mais pois conta \n no fim

    //printf("Valor de x=%d",x); //%d decimal 2 bytes
    //printf("\nValor de y=%f",y); //%f flutuante 4 bytes
    //printf("\nValor de y=%.1f",y); //%.1f - 1 casa dps do .
    //printf("\nValor de y=%.2f",y);
    //printf("Valor de z=%lf",z); //long float
    //printf("Sexo: %c",sexo);
    printf("Nome: %s",nome);

    //imprimir e formato      //\n nova linha, n pd dar espaço

    //printf("Boa noite, pessoal!");
    //printf("\nSejam bem \nvindos.");
    //printf("\n7.5");

    //printf("Valor: %d",50); //%d decimal
    //printf("\nSalario: %f",50.60); //%f float
    //printf("O Sol dista %d km da Lua que dista %d km da Terra que dista %d km de Marte.",500, 8000, 6000);


    return 0;
}
