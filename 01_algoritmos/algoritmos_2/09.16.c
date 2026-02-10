#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //português
#include <string.h>

void main()
{
    setlocale(LC_ALL, "portuguese");
}

/* definição 1
int main()
{
    setlocale(LC_ALL, "portuguese");
    //% struct - registro/ficha, dados heterogêneos/homogêneos

    struct //definição de estrutura (sem nome)
    {
        int dia; //campos
        int mes;
        int ano;
    } dataAtual; //variáveis da struct

    dataAtual.dia = 16;
    dataAtual.mes = 9;
    dataAtual.ano = 2021;

    printf("%d/%d/%d", dataAtual.dia, dataAtual.mes, dataAtual.ano);
    return 0;
}
*/

/* definição 2
#include <string.h> //string
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    struct Aluno
    {
        int ra;
        char nome[50];
        int idade;
    } a1, a2;

    a1.ra = 10;
    strcpy(a1.nome, "Maria");
    a1.idade = 21;

    a2.ra = 11;
    strcpy(a2.nome, "João");
    a2.idade = 11;

    printf("O(a) aluno(a) %s de ra: %d tem idade: %d.\n", a1.nome, a1.ra, a1.idade);
    printf("O(a) aluno(a) %s de ra: %d tem idade: %d.", a2.nome, a2.ra, a2.idade);
}
*/

/* struct (definição definitiva)
void main()
{
    setlocale(LC_ALL, "portuguese");

    struct Aluno //nome
    {
        int ra; //campos
        char nome;
        int idade;
    };

    struct Aluno a1, a2; //variáveis
}
*/

/* exemplo 1
#include <string.h>
void main()
{
    setlocale(LC_ALL, "portuguese");

    struct Horario
    {
        int horas, minutos, segundos;
    };
    struct Horario horaAtual;

    horaAtual.horas = 19;
    horaAtual.minutos = 53;
    horaAtual.segundos = 15;
    printf("%dh%dm%ds\n", horaAtual.horas, horaAtual.minutos, horaAtual.segundos);

    system("pause");
    system("cls");

    struct Compromisso
    {
        char data[11], hora[6], texto[50]; //compromisso[50]
    };

    struct Compromisso c1;

    strcpy(c1.data, "16/09/2021");
    strcpy(c1.hora, "20:30");
    strcpy(c1.texto, "Fazer exercícios extras.");

    printf("%s\n%s\n%s", c1.data, c1.hora, c1.texto);
}
*/

/* ex 2 struct aninhada (struct01 vid)
struct Data
    {
        int dia, mes, ano;
    };
    struct Horario
    {
        char horas[3], minutos[3], segundos[3];
    };
    struct Compromisso
    {
        struct Data dataCompromisso;
        struct Horario horaCompromisso;
        char texto[50];
    };

    struct Compromisso agenda;

    agenda.dataCompromisso.dia = 20;
    agenda.dataCompromisso.mes = 10;
    agenda.dataCompromisso.ano = 2021;
    strcpy(agenda.horaCompromisso.horas, "18");
    strcpy(agenda.horaCompromisso.minutos, "00");
    strcpy(agenda.horaCompromisso.segundos, "00");
    strcpy(agenda.texto, "Reunião com alunos.");

    printf("%d/%d/%d\n%s:%s:%s\n%s", agenda.dataCompromisso.dia, agenda.dataCompromisso.mes, agenda.dataCompromisso.ano, agenda.horaCompromisso.horas, agenda.horaCompromisso.minutos, agenda.horaCompromisso.segundos, agenda.texto);
*/

/* ex 3
    struct Ficha
    {
        int idade;
        char nome[50], endereco[50];
    };

    struct Ficha p1;

    printf("Digite seu nome: ");
    fgets(p1.nome, 50, stdin);
    p1.nome[strlen(p1.nome) - 1] = 0;
    printf("Digite sua idade: ");
    scanf("%d%*c", &p1.idade);
    printf("Digite seu endereço: ");
    fgets(p1.endereco, 50, stdin);
    p1.endereco[strlen(p1.endereco) - 1] = 0;
    printf("Nome: %s;\nIdade: %d;\nEndereço: %s.", p1.nome, p1.idade, p1.endereco);
}
*/

/* ex 4 vetor
int i;
    struct Aluno
    {
        int ra;
        char nome[50], curso[20];
    };
    struct Aluno aluno[5];

    for (i = 0; i < 5; i++)
    {
        printf("Digite os dados do Aluno [%d]: ", i + 1);
        scanf("%d%*c", &aluno[i].ra);
        fgets(aluno[i].nome, 50, stdin);
        aluno[i].nome[strlen(aluno[i].nome) - 1] = 0;
        fgets(aluno[i].curso, 20, stdin);
        aluno[i].curso[strlen(aluno[i].curso) - 1] = 0;
    }
    system("cls");

    for (i = 0; i < 5; i++)
    {
        printf("RA: %d\nNome: %s\nCurso: %s\n", aluno[i].ra, aluno[i].nome, aluno[i].curso);
        printf("\n");
    }
*/

/* struct fora da main (struct02 vid)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //português
#include <string.h>

struct Pessoa
{
    char nome[50], endereco[50];
    int idade;
};

void main()
{
    setlocale(LC_ALL, "portuguese");
    struct Pessoa cadpessoa;

    printf("Nome: ");
    fgets(cadpessoa.nome, 50, stdin);
    cadpessoa.nome[strlen(cadpessoa.nome) - 1] = 0;

    printf("Endereço: ");
    fgets(cadpessoa.endereco, 50, stdin);
    cadpessoa.endereco[strlen(cadpessoa.endereco) - 1] = 0;

    printf("Idade: ");
    scanf("%d%*c",&cadpessoa.idade);

    printf("Nome: %s\nIdade: %d\nEndereço: %s", cadpessoa.nome, cadpessoa.idade, cadpessoa.endereco);
}
*/
