/*
&   "Estruturas com políticas" tem limitações ao q pode fazer com elas

$   Pilhas (stack) -> só se pode adicionar e remover no topo
$   pode ser chamado de LIFO (Last in, First out)

?       inserir/push    ;   remover/pop
*   função de "obter tamanho" da pilha / (ou de ver se está vazia)
*   função de "obter dado do topo"
%   Só se pode programar 5 funções (inicializa, push, pop, obter_tamanho, obter_topo)
?       exemplo -> container de navios
_____________________________________________________________________________________________________

^   Filas -> inserção no final, remoção no início (usa as 2 extremidades)
^   pode ser chamado de FIFO (First in, First out)
%   5 funções (inicializa, inserção, remoção, obter_tamanho, obter_primeiro, *inserção_prior)

@   Fila com prioridade (variação)
?   o com prioridade superior entra na frente dos com inferior
?   porém, entra em último com relação com o msm nível de prioridade
*/

/*
$   Pilha dinâmica é uma lista encadeada de 5 funções   (topo é o início)
*   Pilha estática é um struct para vetor de 5 funções  (topo é o fim)
        typedef struct pilha{
            int topo;           //% saber onde ta o topo
            int item[tamanho];  //% vetor
        } T_PILHA;
____________________________________________________________________________________________________

^   Filas -> lista encadeada ou vetor
^   Fila dinâmica é uma lista encadeada com descritor (tanto faz onde insere e remove)
?   Fila estática é uma struct de vetor
*/

/*
^   Pilha
$ função de POP -> remove e retorna normalmente
*/
