#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{   setlocale(LC_ALL, "portuguese");

/* //ex 5
    float preco, novopreco;
    printf("Digite o preço do produto:");
    scanf("%f%*c",&preco); //%*c remove o <<enter>>
    novopreco = preco * 0.9;
    printf("\n Novo preço: %.2f.",novopreco);
*/

/* //ex 6
    float salario, vendas, comissao, novosalario;
    printf("Digite o salário fixo:");
    scanf("%f%*c",&salario);
    printf("\nDigitar o valor das vendas:");
    scanf("%f%*c",&vendas);
    comissao = vendas * 4/100;
    novosalario = salario + comissao;
    printf("\nComissão: %.2f",comissao);
    printf("\nSalário final: %.2f",novosalario);
*/

/* //ex 7  //pra mostrar % precisa de %% no printf
    float peso;
    printf("Digite o peso da pessoa:");
    scanf("%f%*c",&peso);
    printf("\nSeu peso caso engorde 15%%:  %.1f.",peso*1.15);
    printf("\nSeu peso caso emagreça 20%%: %.1f.",peso*0.8);
*/

/* //ex 12
    float salario_min, salario, qtde;
    printf("Digite o valor do salário mínimo:");
    scanf("%f%*c",&salario_min);
    printf("\nDigite o valor do salário atual:");
    scanf("%f%*c",&salario);
    qtde = salario / salario_min;
    printf("\nQtde de salários mínimos: %0.1f",qtde);
*/

/* //ex 13
    int x;
    printf("Digite o valor da tabuada:");
    scanf("%d%*c",&x);
    printf("\n%d x 0  = %d",x,x*0);
    printf("\n%d x 1  = %d",x,x*1);
    printf("\n%d x 2  = %d",x,x*2);
    printf("\n%d x 3  = %d",x,x*3);
    printf("\n%d x 4  = %d",x,x*4);
    printf("\n%d x 5  = %d",x,x*5);
    printf("\n%d x 6  = %d",x,x*6);
    printf("\n%d x 7  = %d",x,x*7);
    printf("\n%d x 8  = %d",x,x*8);
    printf("\n%d x 9  = %d",x,x*9);
    printf("\n%d x 10 = %d",x,x*10);
*/

/* //ex 14
    int ano_nas, ano_atual, idade_anos;
    printf("Digite o ano de nascimento e o ano atual:");
    scanf("%d%d%*c",&ano_nas,&ano_atual);
    idade_anos = ano_atual - ano_nas;
    printf("\nIdade em anos:    %d",idade_anos);
    printf("\nIdade em meses:   %d",idade_anos*12);
    printf("\nIdade em semanas: %d",idade_anos*52);
    printf("\nIdade em dias:    %d",idade_anos*365);
*/

/* //ex 15
    float salario, conta1, conta2, resto;
    printf("Digite o salário e depois o valor das 2 contas:");
    scanf("%f%f%f%*c",&salario,&conta1,&conta2);
    conta1 = conta1 * 1.02;
    conta2 = conta2 * 1.02;
    restante = salario - conta1 - conta2;
    printf("\nSobrou %.2f do salário inicial.");
*/

/* //ex 16
    float cata, catb, hip;
    printf("Digite o valor do cateto a:")
    scanf("%f%*c",&cata);
    printf("Digite o valor do cateto n:")
    scanf("%f%*c",&catb);
    hip = sqrt((pow(cata,2)+pow(catb,2))); //hip = raiz(a^2 + b^2)
    //pow(tudo,0.5) = sqrt(tudo)
    printf("\nO valor da hipotenusa é: %f",hip);
*/

/* //ex 19
    float largura, comprimento, potencia, area;
    printf("Digite a largura do cômodo em metros:");
    scanf("%f%*c",&largura);
    printf("\nDigite a comprimento do cômodo em metros:");
    scanf("%f%*c",&comprimento);
    area = comprimento * largura;
    potencia = 18 * area; //18 para cada metro^2
    printf("\nÁrea do cômodo = %.1f.",area);
    printf("\nPotência total = %.1f.",potencia);
*/

/* //ex 20 //virar rad no ângulo
    double escada, distancia, angulo;
    printf("Digite o ângulo em graus:");
    scanf("%lf%*c",&angulo);
    printf("\nDigite a distância da parede em metros:");
    scanf("%lf%*c",&distancia);
    escada = distancia / cos(angulo*3.14/180);
    printf("\nO comprimento da escada é de %.2lf.",escada);
*/

return 0;}
