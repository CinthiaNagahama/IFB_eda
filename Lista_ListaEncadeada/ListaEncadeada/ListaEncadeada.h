// TAD lista encadeada

#include<stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;

// Cria uma lista vazia
Elemento* Cria_Lista(void);

// Insere um valor ao in�cio da lista
Elemento* Insere_Valor(Elemento* lst, int valor);

// Imprime os valores da lista
void Imprime_Lista(Elemento* lst);

// Testa se uma lista � vazia - retorna 1 se a lista for vazio e 0 se a lista n�o for vazia
int Lista_Vazia(Elemento* lst);

// Busca um elemento na lista - retorna o elemento se ele for encontrado, ou NULL caso o contr�rio
Elemento* Busca(Elemento* lst, int valor);

// Retira um elemento da lista
Elemento* Retira (Elemento* lst, int valor);

// Libera a mem�ria alocada para a lista
void Libera(Elemento* lst);

// Insere elemento em ordem crescente (a lista tamb�m deve estar ordenada em ordem crescente)
Elemento* Insere_Ordenado(Elemento* lst, int val);

// Verifica se duas listas s�o iguais
int Iguais(Elemento* lst1, Elemento* lst2);

// Imprime a lista recursivamente
void Imprime_Recursiva(Elemento* lst);

// Imprime a lista invertida recursivamente
void Imprime_Recursiva_Invertida(Elemento* lst);

// Retira um elemento em chamadas recursivas
Elemento* Retira_Recursiva(Elemento* lst, int val);

// Verifica se duas listas s�o iguais recursivamente
int Iguais_Recursiva(Elemento* lst1, Elemento* lst2);

// Quest�o 6 -> Fa�a uma fun��o para concatenar duas listas em uma terceira lista que deverão ser retornada pela fun��o.
Elemento* Concatena(Elemento* lst1, Elemento* lst2);

// Quest�o 7 -> Fa�a uma fun��o para remover os n primeiro elementos de uma lista.
int Retira_N(Elemento** lst, int n);

// Quest�o 8 -> Fa�a uma fun��o para buscar a posi��o e o valor do maior elemento da lista
int Busca_Maior(Elemento* lst, int *pos, int *maior);

// Quest�o 9 -> Fa�a uma fun��o para trocar de posi��o dois elementos de uma lista.
int Troca_Posicao(Elemento* lst, int val1, int val2);

// Quest�o 11 -> Considere uma lista contendo n�meros inteiros positivos. 
//				 Fa�a uma fun��o que retorne quantos n�meros pares existem na lista
int Conta_Pares(Elemento* lst);

// Quest�o 12 ->Considere uma lista contendo n�meros inteiros positivos.
// 				Fa�a uma fun��o que retorne uma nova lista contendo apenas os n�meros pares da lista
Elemento* Apenas_Pares(Elemento* lst);

// Quest�o 13 -> Considere uma lista contendo n�meros inteiros positivos. Fa�a uma fun��o que retorne a m�dia da lista.
float Media(Elemento* lst);

// Quest�o 15 -> Fazer uma fun��o para verificar se uma lista est� ordenada ou n�o
int Is_Ordenada(Elemento* lst);

// Quest�o 16 -> Fazer uma fun��o que copia uma lista L1 em outra lista L2
Elemento* Copia(Elemento* L1);

// Quest�o 17 -> Fazer uma fun��o que copia uma lista L1 em outra L2, eliminando os elementos repetidos.
Elemento* Copia_Sem_Repeticao(Elemento* L1);

// Quest�o 18 -> Fazer uma fun��o para inverter uma lista L1 colocando o resultado em L2.
Elemento* Copia_Invertido(Elemento* L1);

// Quest�o 19 -> Fazer uma fun��o que realiza o merge de duas listas ordenadas.
// A fun��o assume listas ordenadas de forma crescente
Elemento* Merge(Elemento* lst, Elemento* lst2);

// Quest�o 20 -> Considerando listas de valores inteiros, implemente uma fun��o que receba como 
// 				 par�metro uma lista e um valor n e divida a lista em duas, de tal forma que a 
// 				 segunda lista come�a no primeiro n� ap�s o valor n.
Elemento* Retorna_Sublista(Elemento* lst, int n);

// Quest�o 21 -> Escreva uma fun��o que crie uma lista encadeada a partir de um vetor
Elemento* Para_Lista(int* v, int tam);

// Quest�o 22 -> Escreva uma fun��o que copie uma lista encadeada para um vetor.
int* Para_Vetor(Elemento* lst);

// Quest�o 25 -> Escreva uma fun��o que inverte a ordem das c�lulas de uma lista encadeada 
// 				 Fa�a isso sem usar espa�o auxiliar; apenas altere os ponteiros.
void Inverte(Elemento** lst);

// Quest�o 26 -> Dadas duas listas encadeadas e dinamicas L1 e L2, implemente a opera��o UNION,
// 				 que cria uma terceira lista L3 com a uni�o entre as duas listas.
Elemento* UNION(Elemento* L1, Elemento* L2);

// Quest�o 27 -> Dadas duas listas encadeadas e dinamicas L1 e L2, s�m elementos repetidos, implemente
// 				 a opera��o INTER, que cria uma terceira lista L3 com a intersec��ao entre as duas
// 				 listas, tambem sem elementos repetidos 
Elemento* INTER(Elemento* L1, Elemento* L2);

// Quest�o 28 -> Seja uma lista din�mica e encadeada com elementos repetidos, implemente uma rotina 
// 				 para eliminar todos as ocorrencias de X da lista.
void Remove(Elemento** lst, int x);

// Quest�o 29 -> Implemente uma rotina recursiva para calcular o tamanho de uma lista dinamica e encadeada.
int Conta_Nos_Recursivo(Elemento* lst, int count);

// Quest�o 33 -> Seja uma lista encadeada cujos registros possuam informa��o do tipo inteiro. 
// 				 Escreva um programa que ordena a lista em ordem crescente em rela��o a informa��o.
void Ordena_Crescente(Elemento** lst);

// Quest�o 34 -> Dada uma lista encadeada que armazena numeros inteiros, escreva uma fun��o que transforma a lista
// 				 dada em duas listas encadeadas: a primeira contendo os elementos cujo conteudo � par e a segunda 
//				 contendo os elementos com conte�dos impares
void Separa_Lista(Elemento* lst, Elemento** pares, Elemento** impares);

// Quest�o 35 -> Fa�a uma fun��o para intercalar listas: a fun��o recebe as duas listas ordenadas e retorna a lista 
// 				 com os elementos das duas listas intercalados conforme a ordem com que elas se disp�e na lista.
Elemento* Intercala(Elemento* lst, Elemento* lst2);

// Quest�o 39 -> Escreva uma fun��o que remove o k-�simo n� da lista encadeada
Elemento* Retira_K (Elemento* lst, int no);

// Quest�o 40 -> Escreva uma fun��o recursiva (Id�ntica a quest�o 29) e outra n�o recursiva para contar o n�mero de 
// 				 elementos na lista.
int Conta_Nos(Elemento* lst);

// Quest�o 42 -> Fa�a uma fun��o para retornar o n�mero de n�s da lista que possuem valor maior que n.
int Is_Maior(Elemento* lst, int n);

// Quest�o 43 -> Considere uma lista de inteiros. Fa�a uma fun��o para somar os valores contidos em uma lista.
int Somatorio(Elemento* lst);

// Quest�o 44 -> Considere uma lista de inteiros. Fa�a uma fun��o para retornar o n�mero de n�s da lista que 
// 				 possuem um numero primo armazenado. 
int Conta_Primos(Elemento* lst);


