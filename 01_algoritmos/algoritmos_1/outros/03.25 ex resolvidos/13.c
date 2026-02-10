#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    float pes, polegadas, jardas, milhas;
    printf("Digite a medida em pés:");
    scanf("%f%*c",&pes);

    polegadas = pes * 12;
    jardas = pes / 3;
    milhas = jardas / 1760;

    printf("%f pés é igual a:\n",pes);
    printf("%f polegadas.\n%f jardas.\n%f milhas.",polegadas,jardas,milhas);
    return 0;
}
