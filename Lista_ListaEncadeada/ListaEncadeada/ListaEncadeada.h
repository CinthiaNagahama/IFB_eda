// TAD lista encadeada

#include<stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;

// Cria uma lista vazia
Elemento* Cria_Lista(void);

// Insere um valor ao início da lista
Elemento* Insere_Valor(Elemento* lst, int valor);

// Imprime os valores da lista
void Imprime_Lista(Elemento* lst);

// Testa se uma lista é vazia - retorna 1 se a lista for vazio e 0 se a lista não for vazia
int Lista_Vazia(Elemento* lst);

// Busca um elemento na lista - retorna o elemento se ele for encontrado, ou NULL caso o contrário
Elemento* Busca(Elemento* lst, int valor);

// Retira um elemento da lista
Elemento* Retira (Elemento* lst, int valor);

// Libera a memória alocada para a lista
void Libera(Elemento* lst);

// Insere elemento em ordem crescente (a lista também deve estar ordenada em ordem crescente)
Elemento* Insere_Ordenado(Elemento* lst, int val);

// Verifica se duas listas são iguais
int Iguais(Elemento* lst1, Elemento* lst2);

// Imprime a lista recursivamente
void Imprime_Recursiva(Elemento* lst);

// Imprime a lista invertida recursivamente
void Imprime_Recursiva_Invertida(Elemento* lst);

// Retira um elemento em chamadas recursivas
Elemento* Retira_Recursiva(Elemento* lst, int val);

// Verifica se duas listas são iguais recursivamente
int Iguais_Recursiva(Elemento* lst1, Elemento* lst2);

// Questão 6 -> Faça uma função para concatenar duas listas em uma terceira lista que deverÃ£o ser retornada pela função.
Elemento* Concatena(Elemento* lst1, Elemento* lst2);

// Questão 7 -> Faça uma função para remover os n primeiro elementos de uma lista.
int Retira_N(Elemento** lst, int n);

// Questão 8 -> Faça uma função para buscar a posição e o valor do maior elemento da lista
int Busca_Maior(Elemento* lst, int *pos, int *maior);

// Questão 9 -> Faça uma função para trocar de posição dois elementos de uma lista.
int Troca_Posicao(Elemento* lst, int val1, int val2);

// Questão 11 -> Considere uma lista contendo números inteiros positivos. 
//				 Faça uma função que retorne quantos números pares existem na lista
int Conta_Pares(Elemento* lst);

// Questão 12 ->Considere uma lista contendo números inteiros positivos.
// 				Faça uma função que retorne uma nova lista contendo apenas os números pares da lista
Elemento* Apenas_Pares(Elemento* lst);

// Questão 13 -> Considere uma lista contendo números inteiros positivos. Faça uma função que retorne a média da lista.
float Media(Elemento* lst);

// Questão 15 -> Fazer uma função para verificar se uma lista está ordenada ou não
int Is_Ordenada(Elemento* lst);

// Questão 16 -> Fazer uma função que copia uma lista L1 em outra lista L2
Elemento* Copia(Elemento* L1);

// Questão 17 -> Fazer uma função que copia uma lista L1 em outra L2, eliminando os elementos repetidos.
Elemento* Copia_Sem_Repeticao(Elemento* L1);

// Questão 18 -> Fazer uma função para inverter uma lista L1 colocando o resultado em L2.
Elemento* Copia_Invertido(Elemento* L1);

// Questão 19 -> Fazer uma função que realiza o merge de duas listas ordenadas.
// A função assume listas ordenadas de forma crescente
Elemento* Merge(Elemento* lst, Elemento* lst2);

// Questão 20 -> Considerando listas de valores inteiros, implemente uma função que receba como 
// 				 parâmetro uma lista e um valor n e divida a lista em duas, de tal forma que a 
// 				 segunda lista começa no primeiro nó após o valor n.
Elemento* Retorna_Sublista(Elemento* lst, int n);

// Questão 21 -> Escreva uma função que crie uma lista encadeada a partir de um vetor
Elemento* Para_Lista(int* v, int tam);

// Questão 22 -> Escreva uma função que copie uma lista encadeada para um vetor.
int* Para_Vetor(Elemento* lst);

// Questão 25 -> Escreva uma função que inverte a ordem das células de uma lista encadeada 
// 				 Faça isso sem usar espaço auxiliar; apenas altere os ponteiros.
void Inverte(Elemento** lst);

// Questão 26 -> Dadas duas listas encadeadas e dinamicas L1 e L2, implemente a operação UNION,
// 				 que cria uma terceira lista L3 com a união entre as duas listas.
Elemento* UNION(Elemento* L1, Elemento* L2);

// Questão 27 -> Dadas duas listas encadeadas e dinamicas L1 e L2, sêm elementos repetidos, implemente
// 				 a operação INTER, que cria uma terceira lista L3 com a intersecçãao entre as duas
// 				 listas, tambem sem elementos repetidos 
Elemento* INTER(Elemento* L1, Elemento* L2);

// Questão 28 -> Seja uma lista dinâmica e encadeada com elementos repetidos, implemente uma rotina 
// 				 para eliminar todos as ocorrencias de X da lista.
void Remove(Elemento** lst, int x);

// Questão 29 -> Implemente uma rotina recursiva para calcular o tamanho de uma lista dinamica e encadeada.
int Conta_Nos_Recursivo(Elemento* lst, int count);

// Questão 33 -> Seja uma lista encadeada cujos registros possuam informação do tipo inteiro. 
// 				 Escreva um programa que ordena a lista em ordem crescente em relação a informação.
void Ordena_Crescente(Elemento** lst);

// Questão 34 -> Dada uma lista encadeada que armazena numeros inteiros, escreva uma função que transforma a lista
// 				 dada em duas listas encadeadas: a primeira contendo os elementos cujo conteudo é par e a segunda 
//				 contendo os elementos com conteúdos impares
void Separa_Lista(Elemento* lst, Elemento** pares, Elemento** impares);

// Questão 35 -> Faça uma função para intercalar listas: a função recebe as duas listas ordenadas e retorna a lista 
// 				 com os elementos das duas listas intercalados conforme a ordem com que elas se dispõe na lista.
Elemento* Intercala(Elemento* lst, Elemento* lst2);

// Questão 39 -> Escreva uma função que remove o k-ésimo nó da lista encadeada
Elemento* Retira_K (Elemento* lst, int no);

// Questão 40 -> Escreva uma função recursiva (Idêntica a questão 29) e outra não recursiva para contar o número de 
// 				 elementos na lista.
int Conta_Nos(Elemento* lst);

// Questão 42 -> Faça uma função para retornar o número de nós da lista que possuem valor maior que n.
int Is_Maior(Elemento* lst, int n);

// Questão 43 -> Considere uma lista de inteiros. Faça uma função para somar os valores contidos em uma lista.
int Somatorio(Elemento* lst);

// Questão 44 -> Considere uma lista de inteiros. Faça uma função para retornar o número de nós da lista que 
// 				 possuem um numero primo armazenado. 
int Conta_Primos(Elemento* lst);


