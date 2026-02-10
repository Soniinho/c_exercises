#include <stdio.h>  //f6 para compilar
#include <stdlib.h> //encoding windows 1252(Western)
#include <locale.h> //fold all comments
//% Ponteiros -> acessar outras variáveis indiretamente

int main()
{
    setlocale(LC_ALL, "portuguese");

    //!---------------declaração-de-ponteiros---------------//
    int *ponteiro_int;
    char *ponteiro_1, *ponteiro_2;
    //? Usar o & para saber o endereço de alguma var (&x)
    //!-----------------------------------------------------//

    int count = 10, count_ind;
    int *pt;

    pt = &count; //recebendo endereço
    //$ Para alterar o valor, usa o inverso do &, que é o *

    *pt = 12;        //@ O valor de count agora é 12
    count_ind = *pt; //igualado indiretamente a count

    /* -------------Todos-mostram-a-mesma-coisa-------------/
    ^    printf("%d", count);
    ^    printf("\n%d", *pt);
    ^    printf("\n%d", count_ind);
    /----------------------------------------------------- */
    //$ printf("%d", pt);        //mostra o endereço de count
    //% printf("%p", count);     //%p mostra o endereço da variável no printf (como hexadecimal)
    //? printf("%p", count_ind); //lendo 12 em hexadecimal
    //? printf("\n%d", &count);  //mostrando endereço em decimal

    int x = 3, y = 4, z;
    int *p1 = &x, *p2 = &y, *p3;

    *p1 = *p2; //x agora vale 4
    p1 = p2;   //p1 está apontando para y

    /* -------------------------------------/
    *    printf("%d  %d\n", x, y);
    *    printf("%d  %d\n", p1, p2);
    *    printf("%d  %d\n", *p1, *p2);
    /------------------------------------- */

    //$ ponteiro sem o * vale o endereço de memória que ele está apontando (endereço)
    //@ ponteiro com o * vale o valor da variável que ele está apontando   (conteúdo)
    //% *p3 = &p1 //ponteiro vai apontar para o *endereço* do p1

    //p3++;    //? mudar para a próxima célula de memória (tantos bytes para frente)
    //p3++;    //# não muda o conteúdo
    //(*p3)++; //+ incrementar o *conteúdo* de p1

    p1 = p1 + 15;   //? passar 15 células para frente
    z = *(p1 - 15); //+ utilizar o conteúdo de 15 células para frente
    //% Não se multiplica nem divide ponteiro, mas se pode comparar

    return 0;
}