#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{setlocale(LC_ALL, "portuguese");

/* //if if //&& //if ou else só com um comando n precisa de {}
    int idade;
    char sexo;
    printf("Digite a idade:");
    scanf("%d%*c",&idade);
    printf("Digite o sexo:");
    scanf("%c%*c",&sexo);



    if (idade>=18 && sexo=='m'){
    printf("\nMaior idade");
    printf("\nJa pode se alistar");
    }
    if (idade>=18 && sexo=='f'){
    printf("\nMaior idade");
    printf("\nJa pode se viajar");
}
*/

/* //if else //um else para cada if
    int idade;
    printf("Digite a idade:");
    scanf("%d%*c",&idade);

    if (idade>=18){
        printf("\nMaior de idade.");
    }
    else {
        printf("\nMenor de idade.");
    }
*/

/* //else if (para encadear os if) //poder usar um else para vários if
    int idade;
    printf("Digite a idade:");
    scanf("%d%*c",&idade);

    if(idade>=18){
        printf("\nProfissional.");
    }
    else if(idade>=15 && idade<18){
        printf("\nJuvenil.");
    }
    else{
        printf("\nAmador.");
    }
*/

/* //else if exemplo
    int opcao;
    printf("\n\t\tCADASTRO DE PESSOAS");
    printf("\n\t\t1- Incluir");
    printf("\n\t\t2- Exluir");
    printf("\n\t\t3- Alterar");
    printf("\n\t\t4- Consultar");
    printf("\n\t\t5- Sair");
    printf("\n\t\tOpcao: ");
    scanf("%d%*c",&opcao);
    if (opcao==1){
    printf("incluindo....");
    }
    else if (opcao==2){
    printf("excluindo....");
    }
    else if (opcao==3){
    printf("alterando....");
    }
    else if (opcao==4){
    printf("consultando....");
    }
    else if (opcao==5){
    printf("sair....");
    }
    else{
    printf("Opcao invalida");
    }
*/

/* //if dentro de if
    int x, y, z;
    printf("Digite tres valores:");
    scanf("%d%*c",&x);
    scanf("%d%*c",&y);
    scanf("%d%*c",&z);

    if(x>y){
    if (x>z){
    printf("x e maior %d",x);
    }
    else if(x==z) {
    printf("x igual a z");
    }
    else{
    printf("z maior x");
    }
    }
*/






return 0;}
