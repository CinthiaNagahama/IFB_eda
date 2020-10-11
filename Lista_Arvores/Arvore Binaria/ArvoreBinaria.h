typedef struct node* BinTree;
typedef struct lista Lista;

// Cria um n� ra�z especial que aponta para a ra�z real da �rvore Bin�ria| Facilita balanceamento
BinTree* create_tree();

// Destr�i uma �rvore Bin�ria
void free_tree(BinTree* root);

// Checa se uma �rvore Bin�ria est� vazia
int is_tree_empty(BinTree* root);

// Descobre a altura de uma �rvore Bin�ria
int height(BinTree* root);

// Descobre o total de n�s de uma �rvore Bin�ria
int total_nodes(BinTree* root);

// Imprime a �rvore Bin�ria percorrendo do jeito Pr�-Ordem
void print_pre_tree(BinTree* root);

// Imprime a �rvore Bin�ria percorrendo do jeito Em-Ordem
void print_in_tree(BinTree* root, int side);

// Imprime a �rvore Bin�ria percorrendo do jeito P�s-Ordem
void print_pos_tree(BinTree* root);

/* ----------------------------------- �rvore Bin�ria de Busca ----------------------------------- */

// Insere um valor em uma �rvore Bin�ria
int insert(BinTree* root, int value);

// Remove um valor de uma �rvore Bin�ria
int remove_value(BinTree* root, int value);

// Consulta se um valor est� em uma �rvore Bin�ria
int search(BinTree* root, int value);

/* -------------------------------------------- Lista -------------------------------------------- */
// Quest�o 2 -> Escreva uma fun��o que conta o n�mero de n�s de uma �rvore bin�ria.
int _conta_no(BinTree* root);

// Quest�o 3 -> Escreva uma fun��o que conta o n�mero de n�s n�o-folha de uma �rvore bin�ria.
int _conta_nao_folha(BinTree* root);

// Quest�o 4 -> Escreva uma fun��o que conta o n�mero de folhas de uma �rvore bin�ria.
int _conta_folhas(BinTree* root);

// Quest�o 5 -> Escreva uma fun��o que calcula a altura de uma �rvore bin�ria.
// Feita anteriormente (slide)

// Quest�o 6 -> Escreva uma fun��o para buscar um n�mero �mpar em uma �rvore bin�ria n�o ordenada.
int _impar_desordem(BinTree* root);
 
// Quest�o 7 -> Escreva uma fun��o para achar o MAIOR n�mero em uma �rvore bin�ria n�o ordenada.
int _maior_desordem(BinTree* root);

// Quest�o 8 -> Escreva uma fun��o que exclui todos os n�s de uma �rvore bin�ria n�o ordenada com ID par
int _exclui_par_desordem(BinTree* root);

// Quest�o 9 -> Escreva uma fun��o que exclui todos os n�s de uma �rvore bin�ria de busca com ID par.
// Fun��o da Quest�o 8 funciona pra isso tamb�m

// Quest�o 10 -> Escreva uma fun��o que retorna verdadeiro se uma �rvore � bin�ria de busca e falso caso 
//				 contr�rio
int _e_bb(BinTree* root);

// Quest�o 11 -> Escreva uma fun��o que encontra o valor m�ximo em uma �rvore de busca bin�ria
int _maior(BinTree* root);

// Quest�o 12 -> Escreva uma fun��o que obt�m o espelho de uma �rvore, ou seja, troca a sub�rvore direita pela
//				 subarvore esquerda de todos os n�s da �rvore
void _inverte_arvore(BinTree* root);

// Quest�o 13 -> Duas ABBs s�o SIMILARES se possuem a mesma distribui��o de n�s. Em uma defini��o mais formal,
//				 duas ABBs s�o SIMILARES se s�o ambas vazias, ou se suas sub�rvores esquerdas s�o similares, e
//				 suas sub�rvores direitas tambem s�o similares. Implemente a fun��o que verifica se duas �rvores
//				 s�o similares
int _similares(BinTree* r1, BinTree* r2);

// Quest�o 14 -> Duas ABBs s�o IGUAIS se s�o ambas vazias ou ent�o se armazenam valores iguais em suas ra�zes,
//				 suas sub�rvores esquerdas s�o iguais, e suas sub�rvores direitas s�o iguais. Implemente a 
//			 	 fun��o que verifica se duas �rvores s�o iguais.
int _iguais(BinTree* r1, BinTree* r2);

// Quest�o 15 -> Uma ABB � estritamente bin�ria se todos os n�s da �rvore tem 2 filhos. Implemente uma fun��o 
//				 que verifica se uma ABB � estritamente bin�ria.
int _estritamente_binaria(BinTree* root);

// Quest�o 16 -> Implemente uma fun��o para testar se uma �rvore bin�ria � uma ABB.
// Igual a Quest�o 10

// Quest�o 17 -> Pense na implementa��o n�o recursiva dos algoritmos de inser��o, remo��o e busca em uma ABB
// Igual aos Slides

// Quest�o 24 -> Escreva fun��es n�o recursivas para realizar os 3 tipos de percurso na �rvore bin�ria:
//					(a) pr�-ordem
//					(b) em-ordem
// 					(c) p�s-ordem
void _pre_ordem_nao_recursivo(BinTree* root);
void _em_ordem_nao_recursivo(BinTree* root);
void _pos_ordem_nao_recursivo(BinTree* root);

// Quest�o 25 -> Escreva uma fun��o n�o-recursiva que retorne o menor valor de uma �rvore bin�ria (n�o ordenada)
int _menor_nao_recursivo_desordem(BinTree* root);

// Quest�o 26 -> Escreva uma fun��o n�o-recursiva que retorne o menor valor de uma �rvore bin�ria de busca;
int _menor_nao_recursivo(BinTree* root);

// Quest�o 27 -> Escreva uma fun��o n�o-recursiva que retorne o k-�simo menor valor de uma �rvore bin�ria de
//				 busca.

// Quest�o 28 -> Escreva uma fun��o que retorne o elemento menor ou igual(floor) que um de refer�ncia x em 
//				 uma ABB.
int _floor(BinTree* root, int x);

// Quest�o 29 -> Escreva uma fun��o n�o-recursiva que verifique a exist�ncia de um valor X na �rvore bin�ria.
int _existe_x(BinTree* root, int x);

// Quest�o 30 -> Escreva uma fun��o n�o-recursiva que verifique a exist�ncia de um valor negativo na �rvore 
//				 bin�ria.
int _existe_negativo(BinTree* root);

// Quest�o 31 -> Escreva uma fun��o n�o-recursiva que verifique se uma �rvore bin�ria � tamb�m de busca.
int _e_bb_nao_recursiva(BinTree* root);

// Quest�o 33 -> Escreva e implemente um algoritmo n�o-recursivo para obter a altura de uma ABB.
// Igual a Quest�o 66

// Quest�o 34 -> Escreva e implemente um algoritmo que dada uma ABB, construa uma outra �rvore ABB 
// 				 aproximadamente completa. Para isso, obtenha todas as chaves e valores e insira na nova �rvore
//				 sempre o elemento mediano das chaves ainda n�o inseridas.
/* BinTree* _copia_mediano(BinTree* root); */

// Quest�o 35 ->  Fa�a uma fun��o que retorne a quantidade de folhas de uma �rvore bin�ria de busca.
int _folhas(BinTree* root); // -> okay

// Quest�o 36 -> Fa�a uma fun��o que retorne a quantidade de n�s de uma �rvore bin�ria de busca que possuem 
//				 apenas um filho.
int _um_filho(BinTree* root); // -> okay

// Quest�o 37 -> Fa�a uma fun��o que, dada uma �rvore bin�ria de busca, retorne a quantidade de n�s que guardam
//				 n�meros primos
int _primos(BinTree* root); // -> okay

// Quest�o 38 ->  Fa�a uma fun��o que compare se duas �rvores bin�rias de busca s�o iguais.
// int _iguais(BinTree* r1, BinTree* r2); // -> okay

// Quest�o 39 -> Fa�a uma fun��o que retorna a lista de caminhos da raiz at� cada folha.
void _encontra_caminho(BinTree* root); // -> okay

// Quest�o 40 -> Escreva uma fun��o que fa�a o percurso em n�vel em uma �rvore bin�ria.
void _imprime_em_nivel(BinTree* root); //-> okay

// Quest�o 46 -> Implemente uma fun��o que verifica se uma �rvore bin�ria de busca � estritamente bin�ria.
int _binaria(BinTree* root); // -> okay

// Quest�o 47 -> Escreva um programa para copiar uma �rvore bin�ria.
BinTree* _copia(BinTree* root); //-> okay

// Quest�o 49 -> Modifique a implementa��o da �rvore de busca bin�ria para que ela lide corretamente com chaves
// 				 duplicadas. Isto �, se uma chave j� est� na �rvore, a nova dever� substituir a antiga.
int _insere(BinTree* root, int value); // -> okay

// Quest�o 58 -> Projete um algoritmo para determinar o menor n�mero em uma �rvore AVL.
int _encontra_menor(BinTree* root); // -> okay

// Quest�o 59 -> Escreva uma fun��o que receba um n�vel da �rvore e imprima todos os n�s nesse n�vel
void _imprime_nivel(struct node* no, int nivel); // -> okay

// Quest�o 60 -> Escreva a fun��o que retorna o n�mero de n�s que s�o divisores da soma de seus filhos. Leve em
//				 conta apenas os n�s com dois filhos.
int _divisores(BinTree* root); // -> okay

// Quest�o 61 -> Dada uma �rvore bin�ria e dois n�s dela, desenvolva um algoritmo para achar o ancestral comum
//				 mais baixo dos dois nos dados. O ancestral comum � um n� que possua os outros dois n�s em suas
//				 sub�rvores. O ancestral comum mais baixo � o ancestral comum que tem a maior profundidade

// Quest�o 62 -> Em uma �rvore bin�ria, fa�a um algoritmo para alterar o valor de cada n� (exceto n� folha) para
//				 a soma dos valores dos n�s esquerda e direita
void _vira_soma(BinTree* root); // -> okay

// Quest�o 64 -> Fa�a um algoritmo que crie uma lista ligada com os n�s de uma �rvore bin�ria em um percurso
//				 em-ordem.
Lista* _lista(BinTree* root); // -> okay

// Quest�o 65 -> Fa�a um algoritmo para somar os n�s presentes nos n�veis �mpares de uma �rvore bin�ria
int _soma_impares(BinTree* root); // -> okay

// Quest�o 66 -> Implementar uma fun��o n�o-recursiva para calcular o tamanho de uma �rvore bin�ria.
int _altura(BinTree* root); //-> okay
