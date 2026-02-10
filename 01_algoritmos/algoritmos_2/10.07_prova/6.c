#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct Data
    {
        int dia, mes, ano;
    };
    struct Func
    {
        int idade, cpf, cod_set;
        float sal;
        char nome[30], gen, cargo[30];
        struct Data nasc;
    };

    struct Func reg;

    printf("Cadastro único:\n");
    printf("Nome: ");
    fgets(reg.nome, 30, stdin);
    reg.nome[strlen(reg.nome) - 1] = 0;

    printf("Idade: ");
    scanf("%d%*c", &reg.idade);

    do
    {
        printf("Gênero: ");
        scanf("%c%*c", &reg.gen);
    } while (reg.gen != 'm' && reg.gen != 'f');

    printf("CPF: ");
    scanf("%d%*c", &reg.cpf);

    printf("Data de Nascimento(dia mês e ano, respectivamente):\n");
    scanf("%d%*c%d%*c%d%*c", &reg.nasc.dia, &reg.nasc.mes, &reg.nasc.ano);

    do
    {
        printf("Código do Setor: ");
        scanf("%d%*c", &reg.cod_set);
    } while (reg.cod_set < 0 || reg.cod_set > 99);

    printf("Cargo: ");
    fgets(reg.cargo, 30, stdin);
    reg.cargo[strlen(reg.cargo) - 1] = 0;

    printf("Salário: ");
    scanf("%f%*c", &reg.sal);

    system("cls");
    printf("Seu cadastro:\n");
    printf("Nome: %s\nIdade: %d\nGênero: %c\n", reg.nome, reg.idade, reg.gen);
    printf("CPF: %d\nData de Nascimento: %d/%d/%d", reg.cpf, reg.nasc.dia, reg.nasc.mes, reg.nasc.ano);
    printf("\nCódigo de Setor: %d\nCargo: %s\nSalário: %.2f", reg.cod_set, reg.cargo, reg.sal);

    return 0;
}