/*
^   Árvores Binárias
#   é um conjunto finito de elementos, sendo vazio ou tendo 3 subconjuntos disjuntos:

*   Raiz -> único nó pelo qual a árvore tem início
@   Sub-árvore esquerda -> é uma binary tree
$   Sub-árvore direita  -> é uma binary tree

& Árvore é uma estrutura recursiva -> cada árvore tem raiz e outras 2 árvores, que tem raiz e por aí...
? Associação entre nós são chamadas de "Ligações Pai-Filho"
? Em uma Árvore Binária, 1 Pai só pode ter entre 0 e 2 filhos
? Todo nó filho só pode ter 1 nó Pai

& Ainda com isso, temos mais denominações que Pai e Filho:
$           Ancestral           -> Cima
$             Irmão             -> Lados
$          Descendentes         -> Baixo

~            Nó folha           -> não tem filhos
~         Nível de um nó        -> distância de um nó até a raiz (raiz é nível 0)
~   Profundidade de uma Árvore  -> é o seu nível mais elevado


% Árvore Estritamente Binária   -> Todo nó não folha tem os filhos esquerdo e direito.
% Árvore Binária Completa       -> Todas as folhas estão no mesmo nível.
% Árvore Binária Ordenada       -> A distribuição dos dados pelos nós da árvore segue uma ordem/política.

^ 2^n é o nº de dados por nível da árvore
^ Novo nó é smp folha -> n faz inserção no meio da árvore

&__________________________________________________________________________________________________________&

? Remoção (cód. extenso):

* 1) Remoção de Folha (nó sem filhos): 
* Da free nele e faz o pai de tal direção apontar para NULL (usar só 1 aux [pai da folha])
$ 2) Remoção de Pai com 1 filho:
$ da free nele e faz o avô apontar para neto (q vira filho) (usar só 2 aux [avô e pai_1f])
@ 3) Remoção de Pai com 2 filhos:
@ troca ele pelo mais próximo (menor ou maior) q ele [escolhe o menor ou maior/só implementa 1]
? desce 1 pra esquerda e dps td pra direita -> menor mais próx do "removido"
~ desce 1 pra direita e dps td pra esquerda -> maior mais próx do "removido"
^ dps apaga o nó q foi substituído (vira caso 1 ou 2)

# obs: fzr funcionar pra raiz tbm
& maior dado da árvore -> desce td pra direita
! menor dado da árvore -> desce td pra esquerda

*/