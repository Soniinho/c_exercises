#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");



    return 0;
}

/* //ex 1 com resposta
    float t,p,e,media;
    printf("Digite a nota do trabalho:");
    scanf("%f%*c",&t);
    printf("Digite a nota da prova semestral:");
    scanf("%f%*c",&p);
    printf("Digite a nota do exame:");
    scanf("%f%*c",&e);

    media = (t*2 + p*3 + e*5)/10;
    printf("Média: %.2f.");

    if(media>=0 && media <5){
        printf("\nE");
    }if(media>=5 && media <6){
        printf("\nD");
    }if(media>=6 && media <7){
        printf("\nC");
    }if(media>=7 && media <8){
        printf("\nB");
    }if(media>=8 && media <=10){
        printf("\nA");
    }
*/

/* //ex 1
    float a,b,c,d,media;
    printf("Digite as suas 4 notas das provas:");
    scanf("%f%*c%f%*c%f%*c%f%*c",&a,&b,&c,&d);

    media = (a+b+c+d)/4;
    printf("A sua média é de %.2f.",media);

    if(media>=7){
        printf("\nVocê foi aprovado.");
    }else{
        printf("\nVocê foi reprovado.");
    }
*/

/* //ex 3
    int x,y,z;
    printf("Digite 3 números inteiros:");
    scanf("%d%*c%d%*c%d%*c",&x,&y,&z);

    if(x>y && x>z){
        printf("x é maior %d",x);
    }
    if(y>x && y>z){
        printf("y é o maior %d",y);
    }
    if(z>y && z>x){
        printf("z é o maior %d",z);
    }

    //código feio
    if(x>y){
        if(x>z){
            printf("x é maior %d",x);
        }
        else if(z>x){
            printf("z é maior %d",z);
        }
    }
    else if(y>x){
        if(y>z){
            printf("y é o maior %d",y);
        }
        else if(z>y){
            printf("z é maior %d",z);
        }
    }
*/

/* //ex 5
    float x,y,opr,fzr;
    printf("Digite 2 números:");
    scanf("%f%*c%f%*c",&x,&y);
    printf("Escolha entre as opções listadas o que fazer com os números digitados:");
    printf("\n\t1 - média entre os números digitados");
    printf("\n\t2 - diferença do maior pelo menor");
    printf("\n\t3 - produto entre os números digitados");
    printf("\n\t4 - Divisão do primeiro número pelo segundo");
    printf("\nDigite o número da opção escolhida:");
    scanf("%f%*c",&opr);

    if(opr == 1){
        fzr = (x+y)/2;
        printf("A média dos números %.2f e %.2f é: %.2f.",x,y,fzr);
    } else if(opr == 2) {
        if(x>y){
            fzr = x-y;
            printf("A diferença do %.2f pelo %.2f é: %.2f.",x,y,fzr);
        } else {
            fzr = y-x;
            printf("A diferença do %.2f pelo %.2f é: %.2f.",y,x,fzr);
        }
    } else if(opr == 3) {
        fzr = x*y;
        printf("O produto do %.2f pelo%.2f é: %.2f.",x,y,fzr);
    } else if(opr == 4) {
        if(y != 0){
            fzr = x/y;
            printf("A divisão de %.2f por %.2f é: %.2f.",x,y,fzr);
        } else {
            printf("Impossível dividir por 0.");
        }
    } else {
        printf("Opção inválida, reinicie o programa.");
    }
*/







