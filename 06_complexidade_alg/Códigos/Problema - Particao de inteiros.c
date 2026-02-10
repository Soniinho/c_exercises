#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int particoes_x;

mostra_m(int Tab[][particoes_x], int linha, int coluna)
{
    int x, y;
    for (x=0; x<=linha; x++)
    {   printf("\n");
        for (y=0; y<=coluna; y++)
        {
            printf("%d\t", Tab[x][y]);
        }
        printf("\n");
    }
    printf("-----------------------------------\n");
}

main ()
{
    int x;
    int linha,coluna;

    printf("Inteiro a particionar: ");
    scanf("%d",&x);

    particoes_x = x;
    particoes_x++;
    int Tab[x+1][x+1];

    // inicialização ------------------------------------
    // geral
    for (linha=0;linha<=x;linha++)
       for (coluna=0;coluna<=x;coluna++)
         Tab[linha][coluna]=0;
    //mostra_m (Tab,x,x); system("pause"); system("cls");

    // específica
    for (coluna=0;coluna<=x;coluna++)
        Tab[0][coluna]=1;
    for (linha=0;linha<=x;linha++)
        Tab[linha][0]=0;
    //mostra_m (Tab,x,x); system("pause"); system("cls");

    for (linha=1;linha<=x;linha++)
       for (coluna=1;coluna<=x;coluna++)
            if (linha >= coluna)
            {
                Tab[linha][coluna]= Tab[linha][coluna-1] + Tab[linha-coluna][coluna];
                //mostra_m (Tab,x,x); system("pause"); system("cls");
            }
            else
            {
                Tab[linha][coluna]= Tab[linha][coluna-1];
                //mostra_m (Tab,x,x); system("pause"); system("cls");
            }
   mostra_m (Tab,x,x);
   printf("\n--- Resultado: %d",Tab[x][x]);

}
