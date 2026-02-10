#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{setlocale(LC_ALL, "portuguese");

return 0;}

/* //reembrar for e um while
    //variável temporária? //início, fim e incremento
    for(int x = 1; x <= 10; x++)
    {
        printf("%d\n",x);
    }

    int x = 1;
    while(x<=10)
    {
        printf("%d\n",x);
        x++;
    }

///outra coisa
    int x = 0;
    for(;x<=10;){
        printf("%d",x);
        x++;
    }
*/

/* //só while dps
    int x, soma = 0;
    x = 1;
    while(x!=0)
    {
        printf("Digite um número inteiro:");
        scanf("%d%*c",&x);
        soma += x; //acumulador
    }
    printf("\nSoma: %d",soma);
*/

/* //while dentro de um while
    char resp = 's';
    while(resp == 's'){
        printf("Oi\n");
        printf("Se quiser continuar, digite \"s\", caso não, digite \"n\" para sair.\n");
        scanf("%c%*c",&resp);

        while(resp!='n' && resp!='s')
        {
            printf("Opção inválidada, digite \"s\" para continuar ou \"n\" para sair.\n");
            scanf("%c%*c",&resp);
        }
    }
*/

/* //outro ex de só while
    int n;
    char opc = 's';

    while(opc == 's'){
        printf("Digite um número inteiro para ver se ele é par ou ímpar: ");
        scanf("%d%*c",&n);

        if(n % 2 == 0){
            printf("O número %d é par.",n);
        }
        else{
            printf("O número %d é impar.",n);
        }

        printf("\nSe quiser avaliar outro número digite \"s\", se não, digite \"n\": ");
        scanf("%c%*c",&opc);
        while(opc != 's' && opc != 'n'){
            printf("Opção inválida, digite \"s\" para 'sim' ou \"n\" para 'não': ");
            scanf("%c%*c",&opc);
        }
    }
*/

/* //outro ex
    int senha = 1234;
    int senhanova, x = 0;

    while(x < 3){
        printf("Digite a senha para acessar: ");
        scanf("%d%*c",&senhanova);

        if(senhanova == senha){
            printf("Acesso permitido.\n");
            //break;
            return 0;
        }
        else{
            printf("Acesso negado.\n");
        }
        x++; //x += x++; //mlr n
    }
    //system("pause");
*/

/* //seno, cos ou tan de um ang meu
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define pi 3.14159265

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opc;
    double ang, rad;
    char qtd;

    print("Digite \"s\" para iniciar o programa ou digite \"n\" para sair: ");
    scanf("%c%*c",&qtd);

    if(qtd != 's' && qtd != 'n'){
        printf("Opção inválida. Digite \"s\" para iniciar o programa ou \"n\" para sair: ");
        scanf("%c%*c",&qtd);
    }
    system("cls"); //limpar a tela //clear screen

    while(qtd == 's'){
        printf("Digite uma opção de acordo com o menu abaixo:");
        printf("\n1-seno");
        printf("\n2-cosseno");
        printf("\n3-tangente");
        printf("\n4-sair\n");
        scanf("%d%*c",&opc);

        printf("Digite um ângulo: ");
        scanf("%f%*c",&ang);
        rad = (pi* ang)/180;

        switch(opc){
            case 1:{
                printf("O seno do ângulo %.2lf é %.5lf\n",ang,sin(rad));
                break;
            }
            case 2:{
                printf("O cosseno do ângulo %.2lf é %.5lf\n",ang,cos(rad));
                break;
            }
            case 3:{
                printf("A tangente do ângulo %.2lf é %.5lf\n",ang,tan(rad));
                break;
            }
            case 4:{
                printf("Saindo...");
                return 0;
            }
            default:{
                printf("Opção inválida...\n");
                break;
            }
        }
        printf("Digite \"s\" usar novamente ou \"n\" para sair: ");
        scanf("%c%*c",&qtd);
        if(qtd != 's' && qtd != 'n'){
            printf("Opção inválida. Digite \"s\" para usar novamente ou \"n\" para sair: ");
            scanf("%c%*c",&qtd);
        }
        system("cls"); //limpar a tela //clear screen
    }

    return 0;
}
*/

//getche(); ver dps
//system("cls"); //limpar tela
//getch(); //apertar qualquer tecla

/* //do tobias ;-;
#include<stdio.h>

#include<math.h>*(3.14/180)

int main()

{

    int o, oa;

    int ag = 0;

    float a, r;

    char ap;

    while(ap!='S'){

    printf("Informe um angulo:");

    scanf("%f%*c", &a);

    while(oa!=4){

    if(ag == 0){

    printf("Operacoes: \n1 - Seno\n2 - Cosseno\n3 - Tangente\n4 - Cancelar\n");

    }

    printf("Selecione a operacao:");

    scanf("%d%*c", &oa);

    if(oa == 1){

    r = sin(a*(3.14/180));

    printf("sen(%.2f)=%.2f\n", a, r);

    ag = 1;

    }else if(oa == 2){

    r = cos(a*(3.14/180));

    printf("cos(%.2f)=%.2f\n", a, r);

    ag = 1;

    }else if(oa == 3){

    r = tan(a*(3.14/180));

    printf("tan(%.2f)=%.2f\n", a, r);

    ag = 1;

    }else if(oa != 4){

    printf("Valor invalido\n");

    ag = 1;

    }

    }

    printf("Deseja sair da aplicacao?(S ou N)");

    scanf("%c%*c", &ap);

}

return 0;

}
*/

/* //do prof
#include <stdio.h>
#include <math.h>

int main()
{
    int opcao;
    char resposta;
    double seno,cosseno, tangente,angulo;

    printf("\nDeseja realizar calculos trigonometricos?");
    scanf("%c%*c",&resposta);

    while(resposta=='s'){
        system("cls") ;//limpar a tela
        printf("\n1-Seno\n2-Cosseno\n3-Tangente\n4-Sair\nOpcao:");
        scanf("%d%*c",&opcao);
        if (opcao==1){
        printf("Digite o angulo:");
        scanf("%lf%*c",&angulo);
        seno = sin(angulo*3.14/180);//para transformar de radianos
        printf("\nSeno do angulo %.1lf = %lf",angulo,seno);
        printf("\nPressione qualquer tecla para continuar");
        getch();//aguardo pressionar uma tecla
        system("cls");
        printf("\nDeseja realizar calculos trigonometricos?");
        scanf("%c%*c",&resposta);
        }
        if (opcao==2){
        printf("Digite o angulo:");
        scanf("%lf%*c",&angulo);
        cosseno = cos(angulo*3.14/180);//para transformar de radianos
        printf("\nCosseno do angulo %.1lf = %lf",angulo,cosseno);
        printf("\nPressione qualquer tecla para continuar");
        getch();//aguardo pressionar uma tecla
        system("cls");
        printf("\nDeseja realizar calculos trigonometricos?");
        scanf("%c%*c",&resposta);
        }
        if (opcao==3){
        printf("Digite o angulo:");
        scanf("%lf%*c",&angulo);
        tangente = tan(angulo*3.14/180);//para transformar de radianos
        printf("\Tangente do angulo %.1lf = %lf",angulo,tangente);
        printf("\nPressione qualquer tecla para continuar");
        getch();//aguardo pressionar uma tecla
        system("cls");
        printf("\nDeseja realizar calculos trigonometricos?");
        scanf("%c%*c",&resposta);
        }
        if(opcao==4){
        printf("\nObrigado por usar nosso sistema. Encerrando...");
        resposta='n';
        }
        if (opcao<1 || opcao>4){
        printf("\nOpcao invalida. Pressione qualquer tecla para continuar");
        getch();//aguardo pressionar uma tecla
        system("cls") ;//limpar a tela
        }
    }
    return 0;
}
*/

/* //outro ex
        char sexo, gostar, opc;
    int gost_s = 0, gost_n = 0, gost_f_s = 0, sex_m = 0, gost_m_n = 0, qtd_m = 0;
    float porc;
    //ignora a parte de ser maiusculo ou minusculo
    printf("Quer iniciar o programa (S ou N)?\n");
    scanf("%c%*c",&opc);

    if(opc == 'n' || opc == 'N'){
        return 0;
    }
    else if(opc != 'n' && opc != 'N' && opc != 's' && opc != 'S'){
        printf("Reinicie o programa.");
        return 0;
    }
    system("cls");

    while(opc == 'S' || opc == 's'){
        printf("Digite o sexo de uma pessoa:");
        scanf("%c%*c",&sexo);
        if(sexo != 'f' && sexo != 'F' && sexo != 'm' && sexo != 'M'){
            printf("Tipo inválido...reinicie o programa.");
            return 0;
        }

        printf("Digite se essa pessoa gostou ou não:");
        scanf("%c%*c",&gostar);
        if(gostar != 's' && gostar != 'S' && gostar != 'n' && gostar != 'N'){
            printf("Tipo inválido...reinicie o programa.");
            return 0;
        }

        printf("Deseja inserir os dados da próxima pessoa entrevistada(S ou N)?  ");
        scanf("%c%*c",&opc);
        if(opc != 'n' && opc != 'N' && opc != 's' && opc != 'S'){
            printf("Tipo inválido...reinicie o programa.");
            return 0;
        }

        if(sexo == 'm' || sexo == 'M'){
            qtd_m += 1;
        }

        if(gostar == 's' || gostar == 'S'){
            gost_s += 1;
        }
        else if(gostar == 'n' || gostar == 'N'){
            gost_n += 1;
        }

        if(gostar == 's' || gostar == 'S' && sexo == 'f' || sexo == 'F'){
            gost_f_s += 1;
        }
        else if(gostar == 'n' || gostar == 'n' && sexo == 'm' || sexo == 'M'){
            gost_m_n += 1;
        }
    }
    system("cls");
    printf("O número de pessoas que responderam sim é %d.",gost_s);
    printf("\nO número de pessoas que responderam não é %d.",gost_n);
    printf("\nO número de mulheres que responderam sim é %d.",gost_f_s);

    porc = (gost_m_n / qtd_m)*100;
    printf("\nA percentagem de homens que responderam não, entre todos os homens analisados é %.2f.",porc);

*/

