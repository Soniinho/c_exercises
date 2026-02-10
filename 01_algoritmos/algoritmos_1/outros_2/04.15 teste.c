#include <stdio.h>  //f6 complia
#include <stdlib.h> //western 1252
#include <locale.h> //fold all comments

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i;
    float numero, tab;

    printf("Digite um número para ver sua tabuada:");
    scanf("%f%*c", &numero);

    for (i = 0; i <= 10; i = i + 1)
    {
        tab = i * numero;
        printf("   %.2f x %d\t= %.2f \n", numero, i, tab); // \t arruma o 9=(2) 10=(3)
    }                                                      // \t são 8 espaços

    /*
    for(i = 0;i <= 9;i = i + 1){
        tab = i * numero;
        printf("%.2f x %d  = %.2f \n", numero, i, tab); // \t arruma o 9=(2) 10=(3)
    }
    for(i = 10;i <= 20;i = i + 1){
        tab = i * numero;
        printf("%.2f x %d = %.2f \n", numero, i, tab); // \t arruma o 9=(2) 10=(3)
    }
*/

    return 0;
}

/* //switch case (exemplo do livro)
    int i;
    printf(“Digite um número ”);
    scanf(“%d%*c”,&i);
    switch (i)                  // olhar o i
    {
    case 1:                     // i = 1
    printf(“Número 1”);
    break;
    case 2:
    printf(“Número 2”);         // i = 2
    break;
    default:                    // msm coisa q else
    printf(“Número diferente de 1 e de 2”);
    }
    getchar();
*/

/* //case prof
    int opcao;
    printf("1 - Feijoada"
           "\n2 - Cachorro Quente"
           "\n3 - Lasanha"
           "\n4 - Sopa"
           "\n5 - Macarronada"
           "\n6 - Arroz"
           "\n7 - Pizza"
           "\n8 - Lanche"
           "\n9 - Pudim"
           );
    printf("\nDigite a opção desejada:");
    scanf("%d%*c",&opcao);
    switch(opcao){
        case 1:{
            printf("Prato escolhido foi feijoada.");
            break;
        }
        case 2:{
            printf("Prato escolhido foi cachorro quente.");
            break;
        }
        case 3:{
            printf("Prato escolhido foi lasanha.");
            break;
        }
        case 4:{
            printf("Prato escolhido foi sopa.");
            break;
        }
        case 5:{
            printf("Prato escolhido foi macarronada.");
            break;
        }
        case 6:{
            printf("Prato escolhido foi arroz.");
            break;
        }
        case 7:{
            printf("Prato escolhido foi pizza.");
            break;
        }
        case 8:{
            printf("Prato escolhido foi lanche.");
            break;
        }
        case 9:{
            printf("Prato escolhido foi pudim.");
            break;
        }
        default:{
            printf("Opção inválida.");
        }
    }
*/

/* //msm de cima só q com char (pega só o 1° valor)
    char opcao;
    printf("\n1- Feijoada");
    printf("\n2- Cachorro Quente");
    printf("\n3- Lasanha");
    printf("\n4- Sopa");
    printf("\n5- Macarronada");
    printf("\n6- Arroz");
    printf("\n7- Pizza");
    printf("\n8- Lanche");
    printf("\n9- Pudim");
    printf("\nSelecione um item do menu:");
    scanf("%c%*c",&opcao);



    switch (opcao)
    {
    case '1':{
    printf("Prato escolhido foi feijoada");
    break;
    }
    case '2':{
    printf("Prato escolhido foi Cachorro Quente");
    break;
    }
    case '3':{
    printf("Prato escolhido foi Lasanha");
    break;
    }
    case '4':{
    printf("Prato escolhido foi Sopa");
    break;
    }
    case '5':{
    printf("Prato escolhido foi Macarronada");
    break;
    }
    case '6':{
    printf("Prato escolhido foi Arroz");
    break;
    }
    case '7':{
    printf("Prato escolhido foi Pizza");
    break;
    }
    case '8':{
    printf("Prato escolhido foi Lanche");
    break;
    }
    case '9':{
    printf("Prato escolhido foi Pudim");
    break;
    }
    default:{
    printf("Opçao inválida!");
    }
    }
*/

/* //ex do prof resolvido
    int opcao;
    float n1,n2,media;
    printf("\n1- Calcular a média");
    printf("\n2- Calcular o maior");
    printf("\n3- Calcular o menor");
    printf("\n4- Encerrar");
    printf("\nSelecione um item do menu:");
    scanf("%d%*c",&opcao);



    switch (opcao)
    {
    case 1:{
    printf("Digite dois numeros reais:");
    scanf("%f%f%*c",&n1,&n2);
    media = (n1 + n2)/2;
    printf("Media = %f",media);
    break;
    }
    case 2:{
    printf("Digite dois numeros reais:");
    scanf("%f%f%*c",&n1,&n2);
    if (n1>n2){
    printf("%f e maior que %f",n1,n2);
    }
    if (n2>n1){
    printf("%f e maior que %f",n2,n1);
    }



    break;
    }
    case 3:{
    printf("Digite dois numeros reais:");
    scanf("%f%f%*c",&n1,&n2);
    if (n1<n2){
    printf("%f e menor que %f",n1,n2);
    }
    if (n2<n1){
    printf("%f e menor que %f",n2,n1);
    }
    break;
    }
    case 4:{
    printf("Encerrando o programa....");
    break;
    }
    default:{
    printf("Opçao inválida!");
    }
    }
*/

//for (i = valor_inicial; condição; incremento ou decremento de i)
//for (no início n pode ==, no meio até vai mas n faz sentido)
//getchar(); //recebe uma tecla
//x + 1 ou x++

/* //for (explicando)
    int x;

    for(x = 0;x <= 10;x = x+2){
        printf("\nValor de x = %d",x);
    }

    for(x = 1;x <= 100;x = x+2){
        printf("\nValor de x = %d",x);
    }

    for(x = 0;x <= 100;x = x+1){ //pares
        if(x % 2 == 0){
        printf("\nValor de x = %d",x);
        }
    }

    for(x = 0;x <= 100;x = x+1){ //ímpares
        if(x % 2 != 0){
        printf("\nValor de x = %d",x);
        }
    }
*/

/* //for (tipo acumulador)
    int x;
    float soma, preco;

    soma = 0;
    for(x = 1;x <= 5;x = x + 1){
        printf("Digite o preço do produto:");
        scanf("%f%*c", &preco);
        soma = soma + preco; //acumulador
    }
    printf("O valor a pagar é de %.2f reais.", soma);
*/

/* //for sem incremento/decremento
    int x;
    float soma, preco;
    char resposta='s';

    soma=0;
    for(resposta='s';resposta!='n';){
        printf("Digite o preço do produto:");
        scanf("%f%*c",&preco);
        soma = soma + preco;
        printf("Deseja continuar?");
        scanf("%c%*c",&resposta);
        //if (resposta=='n'){ break; }
    }
    printf("Total a pagar: %f",soma);
*/

/* // for ex 1(editado) modo gambiarra
    int i;
    float numero, soma, media;
    float maior = -999999999;  //modo n convencional, supor q n vai digitar acima de tal número;
    float menor =  999999999;  //msm coisa de cima
    soma = 0;

    for(i = 1;i <= 5; i++){
        printf("Digite um número:");
        scanf("%f%*c", &numero);
        soma = soma + numero; //acumulador

        if(numero > maior){
            maior = numero;
        }
        if(numero < menor){
            menor = numero;
        }
    }
    media = soma / 5;


    printf("A soma dos números digitados é  %.2f.\n", soma);
    printf("A média dos números digitados é %.2f.\n", media);
    printf("O maior número é %.2f.\n", maior);
    printf("O menor número é %.2f.\n", menor);
*/

/* // for ex 1(editado) mlr jeito

    int i;
    float numero, soma, media, maior, menor;

    //1° valor
    printf("Digite um número:");
    scanf("%f%*c", &numero);
    maior = numero;
    menor = numero;
    soma = numero;

    //outros 4 valores
    for(i = 2;i <= 5; i++){  //leu um antes de começar
        printf("Digite um número:");
        scanf("%f%*c", &numero);
        soma = soma + numero; //acumulador

        if(numero > maior){
            maior = numero;
        }
        if(numero < menor){
            menor = numero;
        }
    }
    media = soma / 5;


    printf("A soma dos números digitados é  %.2f.\n", soma);
    printf("A média dos números digitados é %.2f.\n", media);
    printf("O maior número é %.2f.\n", maior);
    printf("O menor número é %.2f.", menor);
*/

/* //do tobias
int main()
{

    for(int c = 1; c <= 10;c++){

        printf("Tabuada do %d \n", c);

        for(int i = 1;i<=10;i++){

            printf("%dx%d=%d \n", c, i, c*i);

        }

    }

   return 0;

}
*/