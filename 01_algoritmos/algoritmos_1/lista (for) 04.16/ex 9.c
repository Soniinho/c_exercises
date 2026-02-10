#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
#define total_bois 7

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    float codigo, peso, gordo, magro, soma_peso, med_peso;
    float codigo_gordo, codigo_magro;

    printf("Será pedido para digitar o código e o peso de 7 bois.\n");
    printf("Aperte \"enter\" para continuar.\n");
    getchar();

    //leitura de referência
    printf("1º boi");
    printf("\nDigite o código do boi:");
    scanf("%f%*c", &codigo);
    printf("Digite o peso do boi em kg:");
    scanf("%f%*c", &peso);
    printf("\n");

    gordo = peso;
    magro = peso;
    codigo_gordo = codigo;
    codigo_magro = codigo;
    soma_peso = peso;

    for (i = 2; i <= total_bois; i++)
    {
        printf("%dº boi", i);
        printf("\nDigite o código do boi:");
        scanf("%f%*c", &codigo);
        printf("Digite o peso do boi em kg:");
        scanf("%f%*c", &peso);
        printf("\n");

        soma_peso = soma_peso + peso;

        if (peso > gordo)
        {
            gordo = peso;
            codigo_gordo = codigo;
        }
        else if (peso < magro)
        {
            magro = peso;
            codigo_magro = codigo;
        }
    }

    med_peso = soma_peso / total_bois;
    printf("\nO boi com o código %.0f é o mais gordo.\n", codigo_gordo);
    printf("O boi com o código %.0f é o mais magro.\n", codigo_magro);
    printf("O peso médio dos bois é de %.2f kg.\n", med_peso);

    return 0;
}