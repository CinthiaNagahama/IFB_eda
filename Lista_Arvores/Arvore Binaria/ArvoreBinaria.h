typedef struct node* BinTree;
typedef struct lista Lista;

// Cria um nó raíz especial que aponta para a raíz real da Árvore Binária| Facilita balanceamento
BinTree* create_tree();

// Destrói uma Árvore Binária
void free_tree(BinTree* root);

// Checa se uma Árvore Binária está vazia
int is_tree_empty(BinTree* root);

// Descobre a altura de uma Árvore Binária
int height(BinTree* root);

// Descobre o total de nós de uma Árvore Binária
int total_nodes(BinTree* root);

// Imprime a Árvore Binária percorrendo do jeito Pré-Ordem
void print_pre_tree(BinTree* root);

// Imprime a Árvore Binária percorrendo do jeito Em-Ordem
void print_in_tree(BinTree* root, int side);

// Imprime a Árvore Binária percorrendo do jeito Pós-Ordem
void print_pos_tree(BinTree* root);

/* ----------------------------------- Árvore Binária de Busca ----------------------------------- */

// Insere um valor em uma Árvore Binária
int insert(BinTree* root, int value);

// Remove um valor de uma Árvore Binária
int remove_value(BinTree* root, int value);

// Consulta se um valor está em uma Árvore Binária
int search(BinTree* root, int value);

/* -------------------------------------------- Lista -------------------------------------------- */
// Questão 2 -> Escreva uma função que conta o número de nós de uma árvore binária.
int _conta_no(BinTree* root);

// Questão 3 -> Escreva uma função que conta o número de nós não-folha de uma árvore binária.
int _conta_nao_folha(BinTree* root);

// Questão 4 -> Escreva uma função que conta o número de folhas de uma árvore binária.
int _conta_folhas(BinTree* root);

// Questão 5 -> Escreva uma função que calcula a altura de uma árvore binária.
// Feita anteriormente (slide)

// Questão 6 -> Escreva uma função para buscar um número ímpar em uma árvore binária não ordenada.
int _impar_desordem(BinTree* root);
 
// Questão 7 -> Escreva uma função para achar o MAIOR número em uma árvore binária não ordenada.
int _maior_desordem(BinTree* root);

// Questão 8 -> Escreva uma função que exclui todos os nós de uma árvore binária não ordenada com ID par
int _exclui_par_desordem(BinTree* root);

// Questão 9 -> Escreva uma função que exclui todos os nós de uma árvore binária de busca com ID par.
// Função da Questão 8 funciona pra isso também

// Questão 10 -> Escreva uma função que retorna verdadeiro se uma árvore é binária de busca e falso caso 
//				 contrário
int _e_bb(BinTree* root);

// Questão 11 -> Escreva uma função que encontra o valor máximo em uma árvore de busca binária
int _maior(BinTree* root);

// Questão 12 -> Escreva uma função que obtém o espelho de uma árvore, ou seja, troca a subárvore direita pela
//				 subarvore esquerda de todos os nós da árvore
void _inverte_arvore(BinTree* root);

// Questão 13 -> Duas ABBs são SIMILARES se possuem a mesma distribuição de nós. Em uma definição mais formal,
//				 duas ABBs são SIMILARES se são ambas vazias, ou se suas subárvores esquerdas são similares, e
//				 suas subárvores direitas tambem são similares. Implemente a função que verifica se duas árvores
//				 são similares
int _similares(BinTree* r1, BinTree* r2);

// Questão 14 -> Duas ABBs são IGUAIS se são ambas vazias ou então se armazenam valores iguais em suas raízes,
//				 suas subárvores esquerdas são iguais, e suas subárvores direitas são iguais. Implemente a 
//			 	 função que verifica se duas árvores são iguais.
int _iguais(BinTree* r1, BinTree* r2);

// Questão 15 -> Uma ABB é estritamente binária se todos os nós da árvore tem 2 filhos. Implemente uma função 
//				 que verifica se uma ABB é estritamente binária.
int _estritamente_binaria(BinTree* root);

// Questão 16 -> Implemente uma função para testar se uma árvore binária é uma ABB.
// Igual a Questão 10

// Questão 17 -> Pense na implementação não recursiva dos algoritmos de inserção, remoção e busca em uma ABB
// Igual aos Slides

// Questão 24 -> Escreva funções não recursivas para realizar os 3 tipos de percurso na árvore binária:
//					(a) pré-ordem
//					(b) em-ordem
// 					(c) pós-ordem
void _pre_ordem_nao_recursivo(BinTree* root);
void _em_ordem_nao_recursivo(BinTree* root);
void _pos_ordem_nao_recursivo(BinTree* root);

// Questão 25 -> Escreva uma função não-recursiva que retorne o menor valor de uma árvore binária (não ordenada)
int _menor_nao_recursivo_desordem(BinTree* root);

// Questão 26 -> Escreva uma função não-recursiva que retorne o menor valor de uma árvore binária de busca;
int _menor_nao_recursivo(BinTree* root);

// Questão 27 -> Escreva uma função não-recursiva que retorne o k-ésimo menor valor de uma árvore binária de
//				 busca.

// Questão 28 -> Escreva uma função que retorne o elemento menor ou igual(floor) que um de referência x em 
//				 uma ABB.
int _floor(BinTree* root, int x);

// Questão 29 -> Escreva uma função não-recursiva que verifique a existência de um valor X na árvore binária.
int _existe_x(BinTree* root, int x);

// Questão 30 -> Escreva uma função não-recursiva que verifique a existência de um valor negativo na árvore 
//				 binária.
int _existe_negativo(BinTree* root);

// Questão 31 -> Escreva uma função não-recursiva que verifique se uma árvore binária é também de busca.
int _e_bb_nao_recursiva(BinTree* root);

// Questão 33 -> Escreva e implemente um algoritmo não-recursivo para obter a altura de uma ABB.
// Igual a Questão 66

// Questão 34 -> Escreva e implemente um algoritmo que dada uma ABB, construa uma outra árvore ABB 
// 				 aproximadamente completa. Para isso, obtenha todas as chaves e valores e insira na nova árvore
//				 sempre o elemento mediano das chaves ainda não inseridas.
/* BinTree* _copia_mediano(BinTree* root); */

// Questão 35 ->  Faça uma função que retorne a quantidade de folhas de uma árvore binária de busca.
int _folhas(BinTree* root); // -> okay

// Questão 36 -> Faça uma função que retorne a quantidade de nós de uma árvore binária de busca que possuem 
//				 apenas um filho.
int _um_filho(BinTree* root); // -> okay

// Questão 37 -> Faça uma função que, dada uma árvore binária de busca, retorne a quantidade de nós que guardam
//				 números primos
int _primos(BinTree* root); // -> okay

// Questão 38 ->  Faça uma função que compare se duas árvores binárias de busca são iguais.
// int _iguais(BinTree* r1, BinTree* r2); // -> okay

// Questão 39 -> Faça uma função que retorna a lista de caminhos da raiz até cada folha.
void _encontra_caminho(BinTree* root); // -> okay

// Questão 40 -> Escreva uma função que faça o percurso em nível em uma árvore binária.
void _imprime_em_nivel(BinTree* root); //-> okay

// Questão 46 -> Implemente uma função que verifica se uma árvore binária de busca é estritamente binária.
int _binaria(BinTree* root); // -> okay

// Questão 47 -> Escreva um programa para copiar uma árvore binária.
BinTree* _copia(BinTree* root); //-> okay

// Questão 49 -> Modifique a implementação da árvore de busca binária para que ela lide corretamente com chaves
// 				 duplicadas. Isto é, se uma chave já está na árvore, a nova deverá substituir a antiga.
int _insere(BinTree* root, int value); // -> okay

// Questão 58 -> Projete um algoritmo para determinar o menor número em uma árvore AVL.
int _encontra_menor(BinTree* root); // -> okay

// Questão 59 -> Escreva uma função que receba um nível da árvore e imprima todos os nós nesse nível
void _imprime_nivel(struct node* no, int nivel); // -> okay

// Questão 60 -> Escreva a função que retorna o número de nós que são divisores da soma de seus filhos. Leve em
//				 conta apenas os nós com dois filhos.
int _divisores(BinTree* root); // -> okay

// Questão 61 -> Dada uma árvore binária e dois nós dela, desenvolva um algoritmo para achar o ancestral comum
//				 mais baixo dos dois nos dados. O ancestral comum é um nó que possua os outros dois nós em suas
//				 subárvores. O ancestral comum mais baixo é o ancestral comum que tem a maior profundidade

// Questão 62 -> Em uma árvore binária, faça um algoritmo para alterar o valor de cada nó (exceto nó folha) para
//				 a soma dos valores dos nós esquerda e direita
void _vira_soma(BinTree* root); // -> okay

// Questão 64 -> Faça um algoritmo que crie uma lista ligada com os nós de uma árvore binária em um percurso
//				 em-ordem.
Lista* _lista(BinTree* root); // -> okay

// Questão 65 -> Faça um algoritmo para somar os nós presentes nos níveis ímpares de uma árvore binária
int _soma_impares(BinTree* root); // -> okay

// Questão 66 -> Implementar uma função não-recursiva para calcular o tamanho de uma árvore binária.
int _altura(BinTree* root); //-> okay
