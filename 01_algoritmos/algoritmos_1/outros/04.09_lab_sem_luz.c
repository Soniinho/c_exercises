/* // ex 1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float custo, porcentagem, imposto, custo_total;
    printf("Digite o custo de fábrica do carro:\n");
    scanf("%f%*c", &custo);

    if(custo <= 12000){
        custo_total = custo + custo * 0.05;
    }
    else if(custo > 12000 && custo <= 25000) {
        custo_total = custo + custo * 0.1 + custo * 0.15;
    }
    else {
        custo_total = custo + custo * 0.15 + custo * 0.2;
    }

    printf("O preço ao consumudor é de %.2f reais.",custo_total);

    return 0;
}
*/

/* // ex 2
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define imposto sal_total * 0.07

int main()
{
    setlocale(LC_ALL, "portuguese");
    float sal_bruto, sal_total;
    printf("Digite o valor do salário bruto do funcionário:\n");
    scanf("%f%*c", &sal_bruto);

    if(sal_bruto <= 350){
        sal_total = sal_bruto + 100;
    }
    else if(sal_bruto > 350 && sal_bruto < 600){
        sal_total = sal_bruto + 75;
    }
    else if(sal_bruto >= 600 && sal_bruto <= 900){
        sal_total = sal_bruto + 50;
    }
    else {
        sal_total = sal_bruto + 35;
    }

    sal_total = sal_total - imposto;
    printf("O salário do funcionário será de %.2f reais.",sal_total);

    return 0;
    // imposto = sal_bruto * 0.07 ?
    //sal_total = sal_bruto + 100 - imposto;
    //sal_total * 0.07;
}
*/

/* // ex 3
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float preco,novo_preco;
    char classif[20];
    printf("Digite o preço do produto:\n");
    scanf("%f%*c", &preco);

    //achar o novo preço
    if(preco <= 50){
        novo_preco = preco + preco * 0.05;
    }
    else if(preco >50 && preco <= 100) {
        novo_preco = preco + preco * 0.1;
    }
    else{
        novo_preco = preco + preco * 0.15;
    }

    //classificar o produto
    if(novo_preco <= 80){
        strcpy(classif,"barato");
    }
    else if(novo_preco > 80 && novo_preco <= 120){
        strcpy(classif,"normal");
    }
    else if(novo_preco > 120 && novo_preco <= 200){
        strcpy(classif,"caro");
    }
    else{
        strcpy(classif,"muito caro");
    }

    printf("O novo preço do produto é %.2f e é classificado como %s.",novo_preco,classif);

    return 0;
}
*/

/* // ex 4
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int idade;
    char clas[20];
    printf("Digite a idade do nadador:\n");
    scanf("%d%*c", &idade);

    if(idade >= 5 && idade <= 7){
        strcpy(clas,"infantil");
    }
    else if(idade >= 8 && idade <= 10){
        strcpy(clas,"juvenil");
    }
    else if(idade >= 11 && idade <= 15){
        strcpy(clas,"adolescente");
    }
    else if(idade >= 16 && idade <= 30){
        strcpy(clas,"adulto");
    }
    else if(idade > 30){
        strcpy(clas,"sênior");
    }
    else {
        printf("Idade insuficiente para ser nadador.\n");
        return 0;
        //getchar(); //system("pause"); - diz para pressionar enter
        //exit(main); - fecha o programa
    }

    printf("O nadador é classificado como %s.",clas);

    return 0;
}
*/
