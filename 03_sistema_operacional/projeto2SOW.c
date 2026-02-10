/*******************************************
Matheus Henrique Daltroso RA: 202110059
Thalissa Visentim Lopes   RA: 202110073
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* -----------------------------------------------------------------------------
^                           Estrutura Fila DINÂMICA
------------------------------------------------------------------------------*/

typedef struct no_fila
{
    int PID, prioridade, CPU, IO;
    char nome[20];
    int termino;
    struct no_fila *prox;
} Tno_fila;

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_fila(Tno_fila **inicio);
int IniciApaga_fila(Tno_fila **inicio); // inicializa apagando tudo
int Inserir_fim(Tno_fila **inicio, int PID, char nome[], int prioridade, int CPU, int IO);
int Remover_inicio(Tno_fila **inicio);
int Obter_inicio(Tno_fila *inicio, int *PID, char (*nome)[], int *prioridade, int *CPU, int *IO);
int Estado(Tno_fila *inicio, int *resp);
int Remover_aux_Enc(Tno_fila **inicio, int PID);
int Exibir_Dados_Proc(Tno_fila *ini_aux, int *PID_perg, int PID);
int Exibir_Tab_Proc(Tno_fila *ini_aux, int PID, int modo);
int Exe(Tno_fila *ini_aux);
//$----------------------------------------------------------------------//

int main()
{
    setlocale(LC_ALL, "portuguese");
    int erro;
    char opc, confirm; /* receber a opção do usuário */
    int PID = 100, prioridade, CPU, IO, PID_perg;
    char nome[20], nome_perg[20];
    int i, achou;

    Tno_fila *ini_aux;
    Inicializar_fila(&ini_aux);

    do
    {
        system("cls");
        printf("Menu Principal\n");
        printf("\nOpções:\n");
        printf("1 -> Incluir Processo\n");
        printf("2 -> Exibir Dados do Processo\n");
        printf("3 -> Alterar Dados do Processo\n");
        printf("4 -> Remover Processo\n");
        printf("5 -> Exibir a Tabela de Processos\n");
        printf("6 -> Remover todos os Processos\n");
        printf("7 -> Executar o Algoritmo\n"); //! falta
        printf("8 -> Exibir os Participantes da Equipe\n");
        printf("9 -> Encerrar a Execução do Programa\n");
        printf("Opção (1-9): ");

        scanf("%c%*c", &opc);
        printf("\n");
        switch (opc)
        {
        case '1': //$ Incluir Processo
            printf("----------------------------------------\n");
            printf("PID: %d\n", PID);

            printf("Nome: ");
            fgets(nome, 19, stdin);
            nome[strlen(nome) - 1] = '\0';

            do
            {
                printf("Prioridade: ");
                scanf("%d%*c", &prioridade);
            } while (prioridade < 0 || prioridade > 4);

            printf("CPU: ");
            scanf("%d%*c", &CPU);

            printf("IO: ");
            scanf("%d%*c", &IO);
            printf("----------------------------------------\n");

            do
            {
                printf("Confirmar a Inclusão (S/N): ");
                scanf("%c%*c", &confirm);
            } while (confirm != 'S' && confirm != 'N');

            if (confirm == 'S')
            {
                Inserir_fim(&ini_aux, PID, nome, prioridade, CPU, IO);
                PID++;
            }
            system("pause");
            break;
        case '2': //$ Exibir Dados do Processo
            Exibir_Dados_Proc(ini_aux, &PID_perg, PID);
            system("pause");
            break;
        case '3': //$ Alterar Dados do Processo
            Alt_Dad_Proc(&ini_aux, PID);
            system("pause");
            break;
        case '4': //$ Remover Processo
            erro = Exibir_Dados_Proc(ini_aux, &PID_perg, PID);
            if (erro == 0)
            {
                do
                {
                    printf("Confirmar a Remoção (S/N): ");
                    scanf("%c%*c", &confirm);
                } while (confirm != 'S' && confirm != 'N');

                if (confirm == 'S')
                    Remover_aux_Enc(&ini_aux, PID_perg);
            }
            system("pause");
            break;
        case '5': //$ Exibir a Tabela de Processos
            Exibir_Tab_Proc(ini_aux, PID, 0);
            system("pause");
            break;
        case '6': //$ Remover todos os Processos
            Exibir_Tab_Proc(ini_aux, PID, 0);
            do
            {
                printf("Confirmar a Remoção (S/N): ");
                scanf("%c%*c", &confirm);
            } while (confirm != 'S' && confirm != 'N');

            if (confirm == 'S')
                IniciApaga_fila(&ini_aux);
            system("pause");
            break;
        case '7': //$ Executar o Algoritmo
                  // todo: executar o algoritmo
            Exe(ini_aux);
            Exibir_Tab_Proc(ini_aux, PID, 1);
            system("pause");
            break;
        case '8':
            printf("----------------------------------------\n");
            printf("Matheus Henrique Daltroso\nThalissa Visentim Lopes\n");
            printf("----------------------------------------\n");
            system("pause");
            break;
        case '9':
            printf("Encerrando Programa...\n");
            system("pause");
            break;
        default:
            printf("\n\n Opção inválida.\n");
        }
    } while ((opc != '9'));

    IniciApaga_fila(&ini_aux);
    return 0;
}

//$--------------------------- Funções Básicas --------------------------//
int Inicializar_fila(Tno_fila **inicio)
{
    *inicio = NULL;
    return 0;
}

int IniciApaga_fila(Tno_fila **inicio)
{
    Tno_fila *percorre, *aux;
    if (*inicio != NULL)
    {
        percorre = *inicio;
        while (percorre != NULL)
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }
        *inicio = NULL;
        return 1; // inicializa apagando tudo da fila
    }
}

int Inserir_fim(Tno_fila **inicio, int PID, char nome[], int prioridade, int CPU, int IO)
{
    Tno_fila *no_novo, *percorre;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_fila *)malloc(sizeof(Tno_fila));
    no_novo->PID = PID;
    strcpy(no_novo->nome, nome);
    no_novo->prioridade = prioridade;
    no_novo->CPU = CPU;
    no_novo->IO = IO;
    no_novo->termino = NULL;

    no_novo->prox = NULL;

    if (*inicio == NULL)
    {
        // inserção em fila vazia
        *inicio = no_novo;
    }
    else
    {
        // inserção em fila não vazia
        percorre = *inicio;
        while (percorre->prox != NULL)
        {
            percorre = percorre->prox;
        }
        percorre->prox = no_novo;
    }
    return 0;
}

int Remover_inicio(Tno_fila **inicio)
{
    Tno_fila *aux;
    if (*inicio == NULL)
    {
        return 1; /* fila vazia, impossível remover topo */
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Obter_inicio(Tno_fila *inicio, int *PID, char (*nome)[], int *prioridade, int *CPU, int *IO)
{
    int i = 0;
    if (inicio != NULL)
    {
        *PID = inicio->PID;
        do
        {
            (*nome)[i] = inicio->nome[i];
            i++;
        } while (inicio->nome[i - 1] != '\0');
        *prioridade = inicio->prioridade;
        *CPU = inicio->CPU;
        *IO = inicio->IO;
        return 0;
    }
    else
        return 1; // Fila Vazia
}

int Estado(Tno_fila *inicio, int *resp)
{
    if (inicio != NULL)
        *resp = 0; // Fila não Vazia
    else
        *resp = 1; // Fila Vazia
    return 0;
}

int Remover_aux_Enc(Tno_fila **inicio, int PID)
{
    Tno_fila *percorre, *ant;
    // Tratamento de erros =======================================
    if (*inicio == NULL)
        return 1;
    // ===========================================================

    percorre = *inicio;
    if (percorre->PID == PID) // se for na primeira pos
    {
        ant = *inicio;
        *inicio = (*inicio)->prox;
        free(ant);

        return 0;
    }

    while (percorre->prox != NULL && percorre->PID != PID) // encontrar o nó para remoção
    {
        ant = percorre;
        percorre = percorre->prox;
    }

    if (percorre->prox != NULL)
        ant->prox = percorre->prox;
    else
        ant->prox = NULL;

    free(percorre);

    return 0;
}

int Exibir_Dados_Proc(Tno_fila *ini_aux, int *PID_perg, int PID)
{
    int achou;
    int prio_perg, cpu_perg, io_perg;
    char nome_perg[20];
    Tno_fila *percorre;

    if (ini_aux == NULL)
        return 1;

    printf("----------------------------------------\n");
    do
    {
        printf("PID: ");
        scanf("%d%*c", PID_perg);
        if ((*PID_perg) > PID - 1 || (*PID_perg) < 100)
            printf("PID inexistente, digite novamente.\n");
    } while ((*PID_perg) > PID - 1 || (*PID_perg) < 100);
    achou = 0;

    percorre = ini_aux;
    while (percorre != NULL && percorre->PID != (*PID_perg))
        percorre = percorre->prox;

    if (percorre != NULL)
    {
        strcpy(nome_perg, percorre->nome);
        prio_perg = percorre->prioridade;
        cpu_perg = percorre->CPU;
        io_perg = percorre->IO;
        printf("Nome: %s\nPrioridade: %d\nCPU: %d\nIO: %d\n", nome_perg, prio_perg, cpu_perg, io_perg);
        achou = 1;
    }

    if (achou == 0)
        printf("Não existe processo com este PID. (erro)\n");
    printf("----------------------------------------\n");

    return 0;
}

int Exibir_Tab_Proc(Tno_fila *ini_aux, int PID, int modo)
{
    int PID_perg, prio_perg, cpu_perg, io_perg, term_perg;
    char nome_perg[20];
    Tno_fila *percorre;

    if (ini_aux == NULL)
        return 1;

    printf("--------------------------------------------------\n");
    if (modo == 0)
        printf("NOME\tPID\tPRI\tCPU\tI/O\n");
    if (modo == 1)
        printf("NOME\tPID\tPRI\tCPU\tI/O\tTERM\n");
    PID_perg = 100;

    while (PID_perg < PID)
    {
        percorre = ini_aux;
        while (percorre != NULL && percorre->PID != PID_perg)
            percorre = percorre->prox;

        if (percorre != NULL)
        {
            strcpy(nome_perg, percorre->nome);
            prio_perg = percorre->prioridade;
            cpu_perg = percorre->CPU;
            io_perg = percorre->IO;
            term_perg = percorre->termino;
            if (modo == 0) // sem termino
                printf("%s\t%d\t%d\t%d\t%d\n", nome_perg, PID_perg, prio_perg, cpu_perg, io_perg);
            if (modo == 1) // com termino
                printf("%s\t%d\t%d\t%d\t%d\t%d\n", nome_perg, PID_perg, prio_perg, cpu_perg, io_perg, term_perg);
        }
        PID_perg++;
    }
    printf("--------------------------------------------------\n");

    return 0;
}

int Alt_Dad_Proc(Tno_fila **ini_aux, int PID)
{
    int achou;
    int PID_perg, prio_perg, cpu_perg, io_perg;
    char nome_perg[20], confirm;
    Tno_fila *percorre;

    if (*ini_aux == NULL)
        return 1;

    printf("----------------------------------------\n");
    do
    {
        printf("PID: ");
        scanf("%d%*c", &PID_perg);
        if (PID_perg > PID - 1 || PID_perg < 100)
            printf("PID inexistente, digite novamente.\n");
    } while (PID_perg > PID - 1 || PID_perg < 100);
    achou = 0;

    percorre = *ini_aux;
    while (percorre != NULL && percorre->PID != PID_perg)
        percorre = percorre->prox;

    if (percorre != NULL)
    {
        printf("Nome: ");
        fgets(nome_perg, 19, stdin);
        nome_perg[strlen(nome_perg) - 1] = '\0';

        do
        {
            printf("Prioridade: ");
            scanf("%d%*c", &prio_perg);
        } while (prio_perg < 0 || prio_perg > 4);

        printf("CPU: ");
        scanf("%d%*c", &cpu_perg);

        printf("IO: ");
        scanf("%d%*c", &io_perg);
        printf("----------------------------------------\n");

        do
        {
            printf("Confirmar a Alteração (S/N): ");
            scanf("%c%*c", &confirm);
        } while (confirm != 'S' && confirm != 'N');

        if (confirm == 'S')
        {
            strcpy(percorre->nome, nome_perg);
            percorre->prioridade = prio_perg;
            percorre->CPU = cpu_perg;
            percorre->IO = io_perg;
        }

        achou = 1;
    }

    if (achou == 0)
        printf("Não existe processo com este PID. (erro)\n");

    return 0;
}

int Exe(Tno_fila *ini_aux)
{
    int i, estado, estado2, termino = 1;
    int pid_perg, prio_perg, cpu_perg, io_perg;
    char nome_perg[20];
    int pid_perg1, prio_perg1, cpu_perg1, io_perg1, bloqueado;
    char nome_perg1[20];
    Tno_fila *percorre, *filas[6]; // 0 a 4 + block

    if (ini_aux == NULL)
        return 1;

    for (i = 0; i < 6; i++)
        Inicializar_fila(&filas[i]);

    // adicionar nas prioridades 0 a 4
    percorre = ini_aux;
    while (percorre != NULL)
    {
        pid_perg = percorre->PID;
        strcpy(nome_perg, percorre->nome);
        prio_perg = percorre->prioridade;
        cpu_perg = percorre->CPU;
        io_perg = percorre->IO;

        Inserir_fim(&filas[prio_perg], pid_perg, nome_perg, prio_perg, cpu_perg, io_perg);
        percorre = percorre->prox;
    }

    // execução em si
    do
    {
        for (i = 0; i < 5; i++)
        {
            bloqueado = 0;
            percorre = filas[i];
            Estado(filas[i], &estado2);
            if (estado2 == 0)
            {
                Obter_inicio(filas[i], &pid_perg, nome_perg, &prio_perg, &cpu_perg, &io_perg);
                Remover_inicio(&filas[i]);

                // se tiver cpu ainda
                if (cpu_perg > 0)
                    cpu_perg--;

                // caso tenha i/o, faz td o processo de bloqueado
                if (io_perg > 0)
                {
                    io_perg--;
                    Estado(filas[5], &estado);
                    if (estado == 1)
                        Inserir_fim(&filas[5], pid_perg, nome_perg, prio_perg, cpu_perg, io_perg);
                    else
                    {
                        Inserir_fim(&filas[5], pid_perg, nome_perg, prio_perg, cpu_perg, io_perg);
                        Obter_inicio(filas[5], &pid_perg1, nome_perg1, &prio_perg1, &cpu_perg1, &io_perg1);
                        Remover_inicio(&filas[5]);

                        if (prio_perg1 > 0)
                            prio_perg1--;
                        Inserir_fim(&filas[prio_perg1], pid_perg1, nome_perg1, prio_perg1, cpu_perg1, io_perg1);
                        bloqueado = 1;
                    }
                    break;
                }

                // se só tirou cpu e ainda tem mais
                if (cpu_perg > 0 && bloqueado == 0)
                {
                    if (prio_perg < 4)
                        prio_perg++;
                    Inserir_fim(&filas[prio_perg], pid_perg, nome_perg, prio_perg, cpu_perg, io_perg);
                    break;
                }

                // se tirou cpu e já encerrou
                if (cpu_perg == 0 && bloqueado == 0)
                {
                    percorre = ini_aux;
                    while (percorre != NULL && percorre->PID != pid_perg)
                        percorre = percorre->prox;

                    if (percorre != NULL)
                    {
                        percorre->termino = termino;
                        termino++;
                    }
                    break;
                }
                i = 0;
            }
        }
        if (estado2 == 1)
        {
            Estado(filas[5], &estado);
            if (estado == 0)
            {
                Obter_inicio(filas[5], &pid_perg1, nome_perg1, &prio_perg1, &cpu_perg1, &io_perg1);
                Remover_inicio(&filas[5]);

                if (prio_perg1 > 0)
                    prio_perg1--;
                Inserir_fim(&filas[prio_perg1], pid_perg1, nome_perg1, prio_perg1, cpu_perg1, io_perg1);
            }
        }

        for (i = 0; i < 6; i++)
        {
            Estado(filas[i], &estado);
            if (estado == 0)
                break;
        }
    } while (estado != 1);

    for (i = 0; i < 6; i++)
        IniciApaga_fila(&filas[i]);

    return 0;
}
//$----------------------------------------------------------------------//
