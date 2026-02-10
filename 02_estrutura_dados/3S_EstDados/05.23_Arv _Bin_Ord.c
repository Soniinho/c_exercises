#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* -----------------------------------------------------------------------------
^                    Árvore Binária de Busca/Ordenada Clássica
------------------------------------------------------------------------------*/

typedef int Tipo_Dado;

typedef struct bloco_ab
{
    Tipo_Dado Dado;
    struct bloco_ab *FilhoEsq, *FilhoDir;
    struct bloco_ab *Pai; /* adicionalmente foi incluído o ponteiro para pai */
} Nodo_AB;

FILE *saida;

//$------------------------------------------- Funções -------------------------------------------//
int gera_dado(int min, int max); //? Gerador aleatório de dados
void imprimeNo(int d, int p, int b);
void mostraArvore(Nodo_AB *Pai, Nodo_AB *AB, int b);
void calc_largura(Nodo_AB *AB, int *larg);
int inicializa_arvbin(Nodo_AB **AB);
int insere_ord_arvbin(Nodo_AB **AB, Tipo_Dado Dado);
// todo: int remove_dado_arvbin(Nodo_AB **AB, Tipo_Dado Dado); -- é bem extenso
int exibe_ab_infixado(Nodo_AB *AB);  //# ordem
int exibe_ab_prefixado(Nodo_AB *AB); //# pró-ordem
int exibe_ab_posfixado(Nodo_AB *AB); //# pré-ordem
void exibe_maiores(Nodo_AB *AB, int x, int *total);
void ver_balanc(Nodo_AB *AB, int *resp, int *alt);

//! -------------------------- Exercícios -------------------------- !//
int apaga_arvbin(Nodo_AB **AB);                 // apaga toda a arvore
int conta_nodos_arvbin(Nodo_AB *AB, int *cont); //-- conta quant. de nós na árvore
// int pesquisa_arvbin     (Nodo_AB   *AB, Tipo_Dado Dado, int *resp); //-- procura por dado na árvore
int menor_arvbin(Nodo_AB *AB, Tipo_Dado *Dado_out);                // menor da árvore
int maior_arvbin(Nodo_AB *AB, Tipo_Dado *Dado_out);                // maior da árvore
int menor_q_arvbin(Nodo_AB *AB, Tipo_Dado Dado, Tipo_Dado *menor); //-- obtém o primeiro menor que
// todo: EXERCICIO int maior_q_arvbin        (Nodo_AB   *AB, Tipo_Dado Dado, Tipo_Dado *maior); -- obtem o primeira maior que
// todo: EXERCICIO int sucessor_arvbin     (Nodo_AB   *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out); -- obtem filho direito de
// todo: EXERCICIO int predecessor_arvbin  (Nodo_AB   *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out); -- obtem pai de
//! ---------------------------------------------------------------- !//

//$-----------------------------------------------------------------------------------------------//

int main()
{
    setlocale(LC_ALL, "portuguese");

    int i, q, aux, quant, min, max, dado, erro, larg, ct, min_q, max_q;
    Nodo_AB *Arvore;
    int resp, alt;
    int x, total = 0;

    inicializa_arvbin(&Arvore);
    do
    {
        system("cls");
        printf("Árvore Binária de Busca/Ordenada\n\n");
        printf("\n\nOpções: \n\n");
        printf("0  -> Inicializa\n");
        printf("1  -> Insere quant. de dados aleatórios\n");
        printf("2  -> Insere um único dado\n");
        printf("3  -> Mostra Árvore em forma hierárquica\n");
        printf("4  -> Mostra Dados da Árvore em Ordem\n");
        printf("5  -> Mostra Dados da Árvore em Pré-Ordem\n");
        printf("6  -> Mostra Dados da Árvore em Pós-Ordem\n");
        printf("7  -> Verifica balanceamento, altura e largura\n");
        printf("8  -> Exibe total de maiores que um dado\n");
        printf("9  -> Sair\n");
        printf("10 -> Apaga toda a árvore\n");
        printf("11 -> Conta quantos nós tem na árvore\n");
        printf("13 -> Mostra o menor dado da árvore\n");
        printf("14 -> Mostra o maior dado da árvore\n");
        printf("15 -> Mostra o 1º dado menor que o digitado\n");
        printf(":");

        scanf("%d", &q);
        printf("\n");
        switch (q)
        {
        case 0:
            inicializa_arvbin(&Arvore);
            break;

        case 1: /* inserção de dados aleatórios para teste */
            printf("Quantidade de Dados desejados: ");
            scanf("%d", &quant);
            printf("Valor MÍNIMO no intervalo de geração do inteiro aleatório: ");
            scanf("%d", &min);
            printf("Valor MÁXIMO no intervalo de geração do inteiro aleatório: ");
            scanf("%d", &max);
            // sugestões: quant = 20 min = 6 max = 500

            dado = gera_dado(min, max); // desprezando o primeiro gerado

            for (i = 1; i <= quant; i++)
            {
                dado = gera_dado(min, max);
                printf("dado = %d\n", dado);
                insere_ord_arvbin(&Arvore, dado);
            }
            system("pause");
            break;

        case 2: /* insere um dado */
            printf("Dado = ");
            scanf("%d", &dado);
            erro = insere_ord_arvbin(&Arvore, dado);
            if (erro == 1)
                printf("Inserção não realizada - Dado já existente.\n\n");
            else
                printf("Inserção realizada com sucesso.\n\n");
            system("pause");
            break;

        case 3: /* mostra árvore em forma de árvore*/
            // preparando arquivo
            saida = fopen("D:\\Soniinho\\Documents\\Vs_Code_aula\\C_aula\\3S_EstDados\\saida.txt", "wt");
            if (saida == NULL)
            {
                printf("\nImpossível abrir arquivo de saída.\n");
                system("pause");
            }
            fprintf(saida, "\nMostra Árvore Ordenada\n\n\n");
            printf("\nMostra Árvore Binária Ordenada\n\n\n");
            mostraArvore(NULL, Arvore, 1);
            printf("\n\n");
            fclose(saida);
            system("pause");
            break;

        case 4: /* mostra dados em ordem */
            printf("\nMostra Árvore: modo infixado (ordem)\n");
            exibe_ab_infixado(Arvore);
            system("pause");
            printf("\n\n");
            break;

        case 5: /* mostra dados em pre-ordem */
            printf("\n\nMostra Árvore: modo prefixado (pré-ordem)\n");
            exibe_ab_prefixado(Arvore);
            system("pause");
            printf("\n\n");
            break;

        case 6: /* mostra dados em pos-ordem */
            printf("\n\nMostra Árvore: modo posfixado (pós-ordem)\n");
            exibe_ab_posfixado(Arvore);
            printf("\n\n");
            system("pause");
            break;
        case 7: /* verifica balanceamento e altura */
            larg = 0;
            ver_balanc(Arvore, &resp, &alt);
            calc_largura(Arvore, &larg);
            printf("Balanceado (0-nao 1-sim) : %d\n", resp);
            printf("Altura da Árvore : %d\n", alt);
            printf("Largura da Árvore: %d\n", larg);
            system("pause");
            break;

        case 8: /* exibe maiores que um dado */
            printf("Digite dado: ");
            scanf("%d", &x);
            exibe_maiores(Arvore, x, &total);
            printf("Total de Dados maiores que %d : %d\n\n", x, total);
            system("pause");
            break;

        case 9:
            break;

        case 10:
            apaga_arvbin(&Arvore);
            system("pause");
            break;

        case 11:
            ct = 0;
            conta_nodos_arvbin(Arvore, &ct);
            printf("Há %d nós nessa árvore.\n", ct);
            system("pause");
            break;

        case 13:
            menor_arvbin(Arvore, &min);
            printf("O menor dado nessa árvore é %d.\n", min);
            system("pause");
            break;

        case 14:
            maior_arvbin(Arvore, &max);
            printf("O maior dado nessa árvore é %d.\n", max);
            system("pause");
            break;

        case 15:
            printf("Digite um número: ");
            scanf("%d%*c", &aux);
            menor_q_arvbin(Arvore, aux, &min_q);
            printf("O 1º menor dado nessa árvore que %d é %d.\n", aux, min_q);
            system("pause");
            break;

        default:
            printf("\n\nOpção inválida.\n");
            break;
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 9));

    apaga_arvbin(&Arvore); // apagar antes de acabar o prog
    system("pause");
}

//$------------------------------------------- Funções -------------------------------------------//
int gera_dado(int min, int max)
{
    int k;
    double d;
    d = (double)rand() / ((double)RAND_MAX + 1);
    k = d * (max - min + 1);
    return min + k;
}

void imprimeNo(int d, int p, int b)
{
    int i;
    // em tela
    for (i = 1; i < b; i++)
        printf("|------");
    printf("%d(%d)\n", d, p);
    // em arquivo
    for (i = 1; i < b; i++)
        fprintf(saida, "|------");
    fprintf(saida, "%d(%d)\n", d, p);
}

void mostraArvore(Nodo_AB *Pai, Nodo_AB *AB, int b)
{
    if (AB == NULL)
    {
        // imprimeNo(0, Pai->Dado, b);  // não mostra os filhos nulos
        return;
    }
    mostraArvore(AB, AB->FilhoDir, b + 1);
    if ((AB->Pai) != NULL) // se estive não está na raiz
        imprimeNo(AB->Dado, (AB->Pai)->Dado, b);
    else
        imprimeNo(AB->Dado, 0, b);
    mostraArvore(AB, AB->FilhoEsq, b + 1);
}

void calc_largura(Nodo_AB *AB, int *larg)
{
    if (AB->FilhoEsq != NULL)
    {
        calc_largura(AB->FilhoEsq, larg);
        (*larg)++;
    }
    if (AB->FilhoDir != NULL)
    {
        calc_largura(AB->FilhoDir, larg);
        (*larg)++;
    }
}

int inicializa_arvbin(Nodo_AB **AB)
{
    *AB = NULL;
    return 0;
}

int insere_ord_arvbin(Nodo_AB **AB, Tipo_Dado Dado)
{
    /* Árvore binária onde os nós são inseridos de maneira ordenada:   */
    /* - Os nós a esquerda de um nó pai são sempre menores que ele   */
    /* - Os nós a direita de um nó pai são sempre maiores que ele    */

    Nodo_AB *novo, *aux, *temp;

    novo = (Nodo_AB *)malloc(sizeof(Nodo_AB));
    if (novo == NULL) //! malloc da erro quando falta memória
        return 1;

    novo->Dado = Dado;
    novo->FilhoEsq = NULL;
    novo->FilhoDir = NULL;
    aux = *AB;

    while (aux != NULL) /* Acha o ponto onde vai inserir */
    {
        temp = aux;
        if (Dado == (aux->Dado))
            return 1; // inserção não realizada - dado já existe na árvore
        if (Dado > (aux->Dado))
            aux = aux->FilhoDir; /*  insere_ord_arvbin (aux -> FilhoDir, Dado)  */
        else
            aux = aux->FilhoEsq; /*  insere_ord_arvbin (aux -> FilhoEsq, Dado)  */
    }

    if (aux == *AB) // árvore vazia
    {
        novo->Pai = NULL;
        *AB = novo;
    }
    else
    {
        novo->Pai = temp;
        if (Dado > temp->Dado)
            temp->FilhoDir = novo;
        else
            temp->FilhoEsq = novo;
    }
    // chamar verifica balanceamento
    // chamar balacear
    return 0; // inserção realizada
}

int exibe_ab_infixado(Nodo_AB *AB) // ordem
{
    if (AB != NULL)
    {
        exibe_ab_infixado(AB->FilhoEsq); // 1
        printf("%d ", AB->Dado);         // 2
        exibe_ab_infixado(AB->FilhoDir); // 3
    }
}

int exibe_ab_prefixado(Nodo_AB *AB) // pré-ordem
{
    if (AB != NULL)
    {
        printf("%d ", AB->Dado);
        exibe_ab_prefixado(AB->FilhoEsq);
        exibe_ab_prefixado(AB->FilhoDir);
    }
}

int exibe_ab_posfixado(Nodo_AB *AB) // pós-ordem
{
    if (AB != NULL)
    {
        exibe_ab_posfixado(AB->FilhoEsq);
        exibe_ab_posfixado(AB->FilhoDir);
        printf("%d ", AB->Dado);
    }
}

void exibe_maiores(Nodo_AB *AB, int x, int *total)
{
    if (AB != NULL)
    {
        exibe_maiores(AB->FilhoEsq, x, total);
        exibe_maiores(AB->FilhoDir, x, total);
        if (AB->Dado > x)
            (*total)++;
    }
}

void ver_balanc(Nodo_AB *AB, int *resp, int *alt)
{
    int resp_e, resp_d;
    int alt_e, alt_d;
    if (AB != NULL)
    {
        ver_balanc(AB->FilhoEsq, &resp_e, &alt_e);
        ver_balanc(AB->FilhoDir, &resp_d, &alt_d);

        /* Calculando a altura do nível */
        if (alt_e >= alt_d)
            *alt = alt_e + 1;
        else
            *alt = alt_d + 1;

        /* Calculando o balenceamento */
        if (((alt_e == alt_d) || (alt_e == alt_d + 1) || (alt_e + 1 == alt_d)) && (resp_e == 1) && (resp_d == 1))
            *resp = 1; /* sim - balanceado */
        else
            *resp = 0; /* não balanceado */
    }
    else
    {
        *resp = 1; /* sim - balanceado */
        *alt = 0;
    }
}
//$-----------------------------------------------------------------------------------------------//

//! -------------------------- Exercícios -------------------------- !//
int apaga_arvbin(Nodo_AB **AB)
{
    if (*AB != NULL)
    {
        apaga_arvbin(&(*AB)->FilhoEsq);
        apaga_arvbin(&(*AB)->FilhoDir);
        free(*AB);
        *AB = NULL;
    }
}

int conta_nodos_arvbin(Nodo_AB *AB, int *cont)
{
    if (AB != NULL)
    {
        (*cont)++;
        conta_nodos_arvbin(AB->FilhoEsq, cont);
        conta_nodos_arvbin(AB->FilhoDir, cont);
    }
}

// int pesquisa_arvbin     (Nodo_AB   *AB, Tipo_Dado Dado, int *resp); //-- procura por dado na árvore

int menor_arvbin(Nodo_AB *AB, Tipo_Dado *Dado_out)
{
    if (AB->FilhoEsq != NULL)
        menor_arvbin(AB->FilhoEsq, Dado_out);
    else
        *Dado_out = AB->Dado;
}

int maior_arvbin(Nodo_AB *AB, Tipo_Dado *Dado_out)
{
    if (AB->FilhoDir != NULL)
        menor_arvbin(AB->FilhoDir, Dado_out);
    else
        *Dado_out = AB->Dado;
}

int menor_q_arvbin(Nodo_AB *AB, Tipo_Dado Dado, Tipo_Dado *menor) // todo
{
    if (AB != NULL)
    {
        if (AB->Dado > Dado)
            menor_q_arvbin(AB->FilhoEsq, Dado, menor);
        else
            *menor = AB->Dado;
    }
}
//! ---------------------------------------------------------------- !//
