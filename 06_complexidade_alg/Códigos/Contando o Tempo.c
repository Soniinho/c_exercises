#include <stdio.h>
#include <time.h>
// apenas testando a contagem de tempo

int main(void)
{
clock_t inicio_c, fim_c;

int contador = 0;
inicio_c = clock();                       // obtem tempo inicial

do{ //// o que quero medir
        contador++;
}while(contador > -1);

fim_c = clock();                            // obtem tempo final

printf("Passaram-se %ld segundos\n", (long)((fim_c - inicio_c)/CLOCKS_PER_SEC));


return 0;
system("pause");
}
