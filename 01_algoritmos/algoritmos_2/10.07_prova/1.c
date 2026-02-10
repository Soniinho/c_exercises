#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Horario
    {
        int hora, min, seg;
    };

    struct Data
    {
        int dia, mes, ano;
    };

    struct Compromisso
    {
        struct Horario horComp;
        struct Data datComp;
        char comp[100];
    };

    struct Compromisso agenda;

    printf("Será pedido para digitar informações do seu compromisso(mín 2 digitos):\n");
    printf("Hora: ");
    scanf("%d%*c", &agenda.horComp.hora);
    printf("Minuto: ");
    scanf("%d%*c", &agenda.horComp.min);
    printf("Segundo: ");
    scanf("%d%*c", &agenda.horComp.seg);

    printf("\n");
    printf("Dia: ");
    scanf("%d%*c", &agenda.datComp.dia);
    printf("Mês: ");
    scanf("%d%*c", &agenda.datComp.mes);
    printf("Ano: ");
    scanf("%d%*c", &agenda.datComp.ano);

    system("cls");
    printf("Por último, digite um texto que descreve o compromisso: ");
    fgets(agenda.comp, 100, stdin);
    agenda.comp[strlen(agenda.comp) - 1] = 0;

    system("cls");
    printf("%2.d/%2.d/%4.d   ", agenda.datComp.dia, agenda.datComp.mes, agenda.datComp.ano);
    printf("%2.d:%2.d:%2.d\n", agenda.horComp.hora, agenda.horComp.min, agenda.horComp.seg);
    printf("\n%s", agenda.comp);

    return 0;
}