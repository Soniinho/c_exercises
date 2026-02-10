#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

/* //% ---------------------------- Explicações ---------------------------------
$ Matriz Esparsa é "excessivo" número de elementos nulos (0 cm valor simbólico)

& Em matriz estática
^ vantagem -> navegabilidade fácil -> algoritmo simples
! desvantagem -> muito espaço pra armazenar 0

? Em matriz esparsa
* solução 1 -> LS encadeadas [põe a linha e coluna junto do dado na lista (l1, c4, "biscoito")]
# uso de nó marcador pra falar que acabou a linha [EX: nó q marca linha acabou, nó q fala q pág acabou]

% solução 2 -> Listas Cruzadas (listas duplamente encadeadas)
$ para cada matriz, usam-se2 vetores com N *pt para linhas e M *pt para colunas
& cada dimensão criara para matriz, são mais 2 ponteiros
% ---------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------
^                       Estrutura MATRIZ ESPARSA -> LISTA CRUZADA
-------------------------------------------------------------------------------*/

//$-------------------------------- Structs -----------------------------------//
typedef struct no_matriz
{
	int dado;
	int poslinha, poscoluna; /* posição do nó em relação aos vetores */
	struct no_matriz *dir, *esq, *acima, *abaixo;
} Tipo_no_matriz;

typedef struct vetor
{
	int pos;
	struct no_matriz *pont; // inicío da lista
} Vetor_de_matriz;

//& Vetores (2 vetores -> 1 matriz)
Vetor_de_matriz vlinha[10], vcoluna[10]; //% "moldura" de 1 matriz -> pra n ser estática usa Lista Enc
//!  os vet de 10 são uma matriz de 9x9 pq n usou as linhas/colunas 0
//$----------------------------------------------------------------------------//

//@-------------------------- Protótipos das funções --------------------------//
void Navegar_Mat(int x, int y);
int Listar();
int Listar2();
int Inicializar();
int Ver_Utili(int linha, int coluna);
int Inserir(int info, int linha, int coluna);
//@----------------------------------------------------------------------------//

int main(void)
{
	setlocale(LC_ALL, "portuguese");
	int info, linha, coluna;
	int q, erro;
	do
	{
		fflush(stdin);
		system("cls");
		printf("MATRIZ ESPARSA\n");
		printf("\n\nOpções:\n");
		// printf(" Opções:\n");
		printf("1. Inserir\n");
		printf("2. Inicializar\n");
		printf("3. Listar\n");
		printf("4. Sair\n");
		printf(":");

		scanf("%d", &q);
		printf("\n");
		if (q == 1)
		{
			printf("Dados: ");
			scanf("%d", &info);
			printf("Linha: ");
			scanf("%d", &linha);
			printf("Coluna: ");
			scanf("%d", &coluna);
			erro = Inserir(info, linha, coluna);
			if (erro != 0)
				printf("\nInserção impossível.\n");
			system("pause");
		}
		else if (q == 2)
		{
			Inicializar();
		}
		else if (q == 3)
		{
			Listar2();
			system("pause");
		}
	} while (q != 4);
}

//?----------------------------- Funções já feitas ----------------------------//
void Navegar_Mat(int x, int y) // gotoxy
{
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Listar()
{
	Tipo_no_matriz *percorre;
	int i;
	for (i = 1; i <= 9; i++)
	{
		printf("Linha [%d] ", i);
		percorre = vlinha[i].pont;
		while (percorre != NULL)
		{
			printf(" (%d.%d,%d) ", percorre->dado, percorre->poslinha, percorre->poscoluna);
			percorre = percorre->dir;
		}
		printf("\n");
	}
	getchar();
	return 0;
}

int Listar2()
{
	Tipo_no_matriz *percorre;
	int i, j, x;
	x = 1;
	for (j = 0; j < 81; j += 9)
	{
		Navegar_Mat(j, 10); //Navegar_Mat(j, 6);
		printf("[%d]", x);
		x++;
	}

	printf("\n");
	for (i = 1; i <= 9; i++)
	{
		percorre = vlinha[i].pont;
		while (percorre != NULL)
		{
			//Navegar_Mat((percorre->poscoluna - 1) * 9, percorre->poslinha + 7 + i);
			Navegar_Mat((percorre->poscoluna - 1) * 9, percorre->poslinha + 10 + i);
			printf("(%d)", percorre->dado);
			percorre = percorre->dir;
		}
	}
	printf("\n");
	getchar();
	return 0;
}

int Inicializar()
{
	int i;
	for (i = 1; i <= 9; i++)
	{
		vcoluna[i].pont = NULL;
		vlinha[i].pont = NULL;
		vcoluna[i].pos = i;
		vlinha[i].pos = i;
	}
	return 0;
}

int Ver_Utili(int linha, int coluna) // Verifica se célula já foi usada
{
	Tipo_no_matriz *percorre;
	percorre = vlinha[linha].pont;
	/*	// a linha n muda
	while ((percorre != NULL) &&
		((percorre->poscoluna != coluna) ||
			(percorre->poslinha != linha)))	*/

	while (percorre != NULL && percorre->poscoluna != coluna)
	{
		percorre = percorre->dir;
	}
	if (percorre == NULL)
		return 0; // célula não usada
	else
		return 1; // célula já existe
}

int Inserir(int info, int linha, int coluna)
{
	int erro;
	erro = Ver_Utili(linha, coluna); // Verifica se célula já está ocupada
	if (erro == 1)
		return 1;

	Tipo_no_matriz *percorre, *percorreantes, *no_novo;

	/* criar novo nó */
	no_novo = (Tipo_no_matriz *)malloc(sizeof(Tipo_no_matriz));
	no_novo->dado = info;
	no_novo->dir = NULL;
	no_novo->esq = NULL;
	no_novo->acima = NULL;
	no_novo->abaixo = NULL;
	no_novo->poslinha = linha;
	no_novo->poscoluna = coluna;

	/* linha vazia */
	if (vlinha[linha].pont == NULL)
	{
		vlinha[linha].pont = no_novo;
	}
	else
	{
		percorre = vlinha[linha].pont;
		percorreantes = NULL;
		while ((percorre != NULL) && (percorre->poscoluna < coluna))
		{
			percorreantes = percorre;
			percorre = percorre->dir;
		}
		if (percorre == NULL)
		{
			/* inserção no final */
			percorreantes->dir = no_novo;
			no_novo->esq = percorreantes;
		}
		else
		{
			/* inserção no início */
			if (percorreantes == NULL)
			{
				vlinha[linha].pont = no_novo;
				no_novo->dir = percorre;
				percorre->esq = no_novo;
			}
			else
			{
				/* inserção no meio */
				percorreantes->dir = no_novo;
				no_novo->esq = percorreantes;
				percorre->esq = no_novo;
				no_novo->dir = percorre;
			}
		}
	}

	/* coluna vazia */
	if (vcoluna[coluna].pont == NULL)
	{
		vcoluna[coluna].pont = no_novo;
	}
	else
	{
		percorre = vcoluna[coluna].pont;
		percorreantes = NULL;
		while ((percorre != NULL) && (percorre->poslinha < linha))
		{
			percorreantes = percorre;
			percorre = percorre->abaixo;
		}
		if (percorre == NULL)
		{
			/* inserção no final */
			percorreantes->abaixo = no_novo;
			no_novo->acima = percorreantes;
		}
		else
		{
			/* inserção no início */
			if (percorreantes == NULL)
			{
				vcoluna[coluna].pont = no_novo;
				no_novo->abaixo = percorre;
				percorre->acima = no_novo;
			}
			else
			{
				/* inserção no meio */
				percorreantes->abaixo = no_novo;
				no_novo->acima = percorreantes;
				percorre->acima = no_novo;
				no_novo->abaixo = percorre;
			}
		}
	}

	return 0;
}
//?----------------------------------------------------------------------------//

//todo: fazer o Remove