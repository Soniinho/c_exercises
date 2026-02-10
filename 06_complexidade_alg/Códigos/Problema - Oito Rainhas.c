#include <stdio.h>
#include <stdlib.h>

// ===========================================================================
// Problema das 8 rainhas ----- Força Bruta Simplificado
//  reduzir o espaço de busca sabendo que as rainhas ocupam diferentes colunas (numeradas de zero a sete).
// A rainha R1 tem 8 possibilidades de linhas na coluna 0,
// A rainha R2 tem 8 possibilidades de linhas na coluna 1,
// e assim por diante
// No total temos 8elevado a 8 = 16777216.

// Agora reduzir o espaço de busca ainda mais sabendo que as rainhas não podem ocupar a mesma linha.
// A rainha R1 tem 8 possibilidades de linhas na coluna 0,
// A rainha R2 tem 7 possibilidades de linhas na coluna 1,
// A rainha R3 tem 6 possibilidades de linhas na coluna 2,

// No total temos 8! = 40320
// =============================================================================

// Problema das 8 rainhas ---- Backtracking


// prototipos
void TestaPermutacoes(int linhas[], int k);


// gerar as permutações do vetor
void Troca(int v[], int i, int j) {
  int tmp;
  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

// verifica se uma dada permutação é uma solução do problema
// analisando o vetor de rainhas para determinar se estao em mesmo linha ou diagonal
int SolucaoValida(int linhas[]){
  int i;
  int x,y;
  int xx,yy;

  for(i = 0; i < 8; i++){
    x = i;
    y = linhas[i];

    xx = x;
    yy = y;
    while(1){
      xx += 1;
      yy -= 1;
      if(xx > 7 || yy < 0) break;

      if(yy == linhas[xx])
        return 0;
    }

    xx = x;
    yy = y;
    while(1){
      xx -= 1;
      yy -= 1;
      if(xx < 0 || yy < 0) break;

      if(yy == linhas[xx])
        return 0;
    }
  }
  return 1;
}

// =========================================== imprime nao solucao em força bruta
void ImprimeNaoSolucao(int linhas[]){
  char tabuleiro[8][8];
  int i,j;
  int x,y;
  static int nsols = 0;

  nsols++;
  system("cls");

  printf("\n******** TENTATIVA: %d \n\n",nsols);

  for(i = 0; i < 8; i++)
    for(j = 0; j < 8; j++)
      tabuleiro[i][j] = '.';

  for(i = 0; i < 8; i++){
    x = i;
    y = linhas[i];
    tabuleiro[y][x] = 'R';
  }

  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf("  %c  ",tabuleiro[i][j]);
    }
    printf("\n\n");
  }
  //Sleep(50);
}


// =========================================== imprime nao solucao em Backtracking
void ImprimeNaoSolucao_BT(int linhas[], int k){
  char tabuleiro[8][8];
  int i,j;
  int x,y;
  static int nsols = 0;

  nsols++;
  system("cls");

  printf("\n******** TENTATIVA: %d \n\n",nsols);

  for(i = 0; i < 8; i++)
    for(j = 0; j < 8; j++)
      tabuleiro[i][j] = '.';

  for(i = 0; i <= k; i++){
    x = i;
    y = linhas[i];
    tabuleiro[y][x] = 'R';
  }

  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf("  %c  ",tabuleiro[i][j]);
    }
    printf("\n\n");
  }
  //Sleep(50);
}


// ============================================ imprime solução
void ImprimeSolucao(int linhas[]){
  char tabuleiro[8][8];
  int i,j;
  int x,y;
  static int nsols = 0;

  nsols++;

  system("cls");
  printf("\n******** Solucao: %d \n\n",nsols);

  for(i = 0; i < 8; i++)
    for(j = 0; j < 8; j++)
      tabuleiro[i][j] = '.';

  for(i = 0; i < 8; i++){
    x = i;
    y = linhas[i];
    tabuleiro[y][x] = 'R';
  }

  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf("  %c  ",tabuleiro[i][j]);
    }
    printf("\n\n");
  }
  system("pause");
}

// ==========================================================
void Solucoes8Rainhas_FB() {  /* FB - Força Bruta */
  int linhas[8];
  int i;
  // inicializa posicao das rainhas
  for(i = 0; i < 8; i++)
    linhas[i] = i;

  // realiza as trocas
  TestaPermutacoes(linhas, 0);
}

// ==========================================================
void Solucoes8Rainhas_BT() {   /* BT - Backtracking */
  int linhas[8];
  int i;
  // inicializa posicao das rainhas - um cada linha
  for(i = 0; i < 8; i++)
    linhas[i] = i;

    nRainhas (0, 8, linhas);
}

// ===========================================================
void TestaPermutacoes(int linhas[], int k)
/* k -> quantas rainhas já estão posicionadas */
{
  int i;

  if(k == 8) {
    if(SolucaoValida(linhas))
      ImprimeSolucao(linhas);
  }
  else{
    for(i = k; i < 8; i++) {
      Troca(linhas, k, i);
      TestaPermutacoes(linhas, k + 1);
      ImprimeNaoSolucao(linhas);
      Troca(linhas, i, k);
    }
  }
}

int valida (int k, int rainhas[]) {

int i;
for (i = 0; i < k; i++)
   /* se duas rainhas na mesma coluna ou duas rainhas na mesma diagonal  */
  if ((rainhas[i] == rainhas[k]) || (k - i ==abs(rainhas[i] - rainhas[k])))
    	return 0; /* solução invalida */
 return 1;      /* solução valida */
}

void nRainhas (int k, int n, int rainhas[])
{
int i;
if (k == n) /* solução completa */
    ImprimeSolucao(rainhas);
else
	/* posiciona a rainha k + 1 */
	for (i = 0; i < n; i++) {
		rainhas[k] = i;
		if (valida(k, rainhas))
			nRainhas (k + 1, n, rainhas);
        ImprimeNaoSolucao_BT(rainhas, k);
	}
}

void TestaPermutacoes_FB_total(int linhas[])
{
  int a,b,c,d,e,f,g,h;

    // não considera a colocação das rainhas em outras colunas
    // portanto a quantidade de casos e muuuuuuuuuuuuuuito menor que 4.426.165.368

    for(a = 0; a < 8; a++)              // 8x
     for(b = 0; b < 8; b++)             // 64x
      for(c = 0; c < 8; c++)            // 512x
       for(d = 0; d < 8; d++)           // 4.096x
        for(e = 0; e < 8; e++)          // 32.780x
          for(f = 0; f < 8; f++)            // 262.144x
            for(g = 0; g < 8; g++)      // 2.097.152x
              for(h = 0; h < 8; h++)    // 16.777.216x
                {
                linhas[0]=a;
                linhas[1]=b;
                linhas[2]=c;
                linhas[3]=d;
                linhas[4]=e;
                linhas[5]=f;
                linhas[6]=g;
                linhas[7]=h;
                if(valida(8,linhas))
                    ImprimeNaoSolucao(linhas);
                else
                    ImprimeSolucao(linhas);
               }
}

// ==========================================================
void Solucoes8Rainhas_FB_quasetotal() {
  int linhas[8];
  int i;

  // realiza os trocas
  TestaPermutacoes_FB_total(linhas);
}

void main()
{
    int op;
    printf("1- Força bruta parcial (versao 1)\n");
    printf("2- Força bruta quase total (versao 2)\n");
    printf("3- Backtracking\n");
    printf("\nEscolha a opção de Solucao do Problema da 8 Rainhas:  ");
    scanf("%d",&op);

   if (op ==1) Solucoes8Rainhas_FB();       // força bruta parcial
   if (op ==2) Solucoes8Rainhas_FB_quasetotal(); // força bruta quase total
   if (op ==3) Solucoes8Rainhas_BT();       // backtracking

}
