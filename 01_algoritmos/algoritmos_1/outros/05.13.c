#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, a = 20;
    int arr[5] = {10, 20, 30, 40, 50};  //definir array de n° em 1 linha
    char str[30] = "\"fresh2refresh\""; //por ter definido assim n tem o \0 no final

    i = 0;
    while (i < 5)
    {
        printf("\n%d", arr[i]);
        i++;
    }

    printf("\n\n%s aaa", str);

    return 0;
}

/* //do while meu
    int x = 0;
    do
    {
        printf("\n%d",x);
        x++;
    }
    while(x < 10);

    printf("\n");

    x = 0;
    while(x < 10)
    {
        printf("\n%d",x);
        x++;
    }
*/

/* //vetores

    //vetor ou array
    //vetor é uma única linha //matrix tem linha e coluna
    //indice do vetor smp começa em 0 (vetor de 8 vai de 0 a 7)

    //char nome[50]; //string

    int vetor[10];      //0 a 9
    float valores[5];   //0 a 4
    double angulos[90]; //0 a 89

    int vet[10];
    int x;

    //declarar manualmente
    vet[0] = 10; //primeira posiç.
    vet[1] = 5;
    vet[3] = 8;
    vet[4] = 3; //quinta posiç.
    */

/* //atribuir valor a todo o vetor e ler o vetor inteiro
    int vet[10];
    int x;
    x = 0;
    while(x < 10)
    {
        printf("Valor de vet: ");
        scanf("%d%*c", &vet[x]);
        x++;
    }

    //mostrar todos os valores do vetor
    x = 0;
    while(x < 10)
    {
        printf("\nValor de vet: %d",vet[x]);
        x++;
    }

    for (x = 9;x > -1;x--)
    {
        printf("\nValor: %d",vet[x]);
    }
*/

/* //do while

    int i;

    for(i = 0; i < 10; i++)
    {            //quando se sabe quantos passos precisa
        printf("\n%d",i);
    }

    printf("\n");

    i = 0;
    while(i < 10)//checar no começo
    {
        printf("\n%d",i);
        i++;
    }

    printf("\n");

    i = 0;
    do           //checar no fim
    {
        printf("\n%d",i);
        i++;
    }
    while(i < 10);
*/

/* //ex de teste
    float precos[6];
    int j;

    j = 0;
    do{
        printf("Digite o preço do %d° produto: ", j+1);
        scanf("%f%*c", &precos[j]);
        j++;
    }while(j < 6); //ou j <= 5

    for(j = 0; j < 6; j++){
        precos[j] += precos[j] * 0.1;
    }

    j = 0;
    while(j < 6){
        printf("\nO novo %d° preço é: R$%.2f.", j + 1,precos[j]);
        j++;
    }

    printf("\n");
*/

/* //ex do prof de teste
#include <stdio.h>
int main()
{
    ///fazer um programa que leia 6 precos de produtos
    ///aumente 10% nos precos
    ///e mostre os novos precos
    float precos[6]; ///0 1 2 3 4 5
    int j;

    j=0;
    do{
    printf("\nDigite o preco do produto[%d]: ",j+1);
    scanf("%f%*c",&precos[j]);
    j++;
    }while(j<6); ///ou j<=5

    j=0;
    do{
    precos[j] = precos[j] * 1.10;
    printf("\nPreco do produto[%d]: %.2f",j+1,precos[j]);
    j++;
    }while(j<6);

    return 0;
}
*/

/* //outro ex
    setlocale(LC_ALL, "portuguese");
    int vet[6];
    int i = 0;
    int qtd_par = 0, qtd_impar = 0;

    do{
        printf("Digite o %d° número: ", i+1);
        scanf("%d%*c",&vet[i]);
        i++;
    }while(i < 6);

    for(i = 0; i < 6; i++){
        if(vet[i] % 2 == 0){
            qtd_par += 1;
            printf("\nO %d° n° é par: %d.", i+1, vet[i]);
        }
    }
    printf("\nA quantidade de números pares é de %d.\n",qtd_par);

    i = 0;
    while(i < 6){
        if(vet[i] % 2 != 0){
            qtd_impar += 1;
            printf("\nO %d° n° é ímpar: %d.", i+1, vet[i]);
        }
        i++;
    }
    printf("\nA quantidade de números ímpares é de %d.",qtd_impar);

    return 0;
*/

/* //outro modo de imprimir em ordem
#include <stdio.h>

int main(){
    int num[6], num_impar[6], num_par[6];
    int i, qt_par, qt_impar, i_par, i_impar;
    i = qt_par = qt_impar = 0;
    do{
        printf("Informe um valor: ");
        scanf("%d", &num[i]);
        if(num[i]%2 == 0){
            num_par[qt_par] = num[i];
            qt_par++;
        }else{
            num_impar[qt_impar] = num[i];
            qt_impar++;
        }
        i++;
    }while(i < 6);
    i = 0;
    printf("Quantidade de numeros pares: %d;", qt_par);
    printf("\nSendo deles:");
    do{
        printf("%d", num_par[i]);
        if(i == qt_par-1){
            printf(";");
        }else{
            printf(", ");
        }
        i++;
    }while(i < qt_par);
    i = 0;
    printf("\nQuantidade de numeros impares: %d", qt_impar);
    printf("\nSendo deles:");
    do{
        printf("%d", num_impar[i]);
            if(i == qt_impar-1){
            printf(";");
        }else{
            printf(", ");
        }
        i++;
    }while(i < qt_impar);

    return 0;
}
*/

/* //do prof
#include <stdio.h>
int main()
{
    int num[6]; ///0 1 2 3 4 5
    int x, qtdepar=0, qtdeimpar=0;

    for(x=0;x<6;x++){
        printf("\nDigite um numero inteiro:");
        scanf("%d%*c",&num[x]);
    }
    for(x=0;x<6;x++){
        if (num[x]%2==0){
            printf("Par = %d",num[x]);
            qtdepar++;
        }
        if (num[x]%2!=0){
            printf("Impar = %d",num[x]);
            qtdeimpar++;
        }
    }
    printf("Qtde de pares: %d",qtdepar);
    printf("Qtde de Impares: %d",qtdeimpar);
    return 0;
}
*/

/* //mais um ex
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int num[7], m2[7], m3[7], m2_3[7];
    int qtd_2 = 0, qtd_3 = 0, qtd_2_3 = 0;
    int i;

    i = 0;

    do{
        printf("Digite o %dº número: ", i+1);
        scanf("%d%*c", &num[i]);
        i++;
    }while(i < 7);

    i = 0;
    while(i < 7){
        if(num[i] % 2 == 0){
            m2[qtd_2] = num[i];
            qtd_2++;
        }
        if(num[i] % 3 == 0){
            m3[qtd_3] = num[i];
            qtd_3++;
        }
        if(num[i] % 2 == 0 && num[i] % 3 == 0){
            m2_3[qtd_2_3] = num[i];
            qtd_2_3++;
        }
        i++;
    }

    i = 0;
    printf("\nMúltiplos de 2:");
    while(i < qtd_2){
        printf("\n%d", m2[i]);
        i++;
    }
    printf("\nMúltiplos de 3:");
    i = 0;
    while(i < qtd_3){
        printf("\n%d", m3[i]);
        i++;
    }
    printf("\nMúltiplos de 2 e de 3:");
    i = 0;
    while(i < qtd_2_3){
        printf("\n%d", m2_3[i]);
        i++;
    }

    return 0;
}
*/

/* //do prof
    int vet[7];
    int i, j;

    for(i=0;i<7;i++){
        printf("\nDigite um numero %d: ",i+1);
        scanf("%d%*c",&vet[i]);
        for(j = 0; j < i; j++){
            if(vet[i] == vet[j]){
                i--;
                printf("O Valor já foi digitado\n");
            }
        }

        if (vet[i]%2==0){
            printf("Multiplo de 2: %d",vet[i]);
        }
        if (vet[i]%3==0){
            printf("Multiplo de 3: %d",vet[i]);
        }
        if (vet[i]%2==0 && vet[i]%3==0){
            printf("Multiplo de 2 e 3: %d",vet[i]);
        }
    }
*/
