// Questão 5 - Lista TAD - Conjunto de Inteiros
#include <stdio.h>
#include <stdlib.h>
#include "Conjuntos.h"

struct conjuntos{
	int *valores;
};

// União de Conjuntos - retorna o conjunto formado pela união
Conjuntos* Uniao(Conjuntos* a, Conjuntos*b){
	int tamA = Tamanho(a);
	int tamB = Tamanho(b);
	if(a > b){
		int i;
		Conjuntos c = ConjuntoVazio();
		for(i = 0; i < a; i++){
			
		}
	}
	else {
		
	}
	return c;
}

// Cria um Conjunto Vazio
Conjuntos* ConjuntoVazio();

// Insere um valor a um conjunto pré-existente
void Insere(Conjuntos* a, int v);

// Remove um valor de um conjunto pré-existente
void Remove(Conjuntos* a, int v;

// Intersecção de Dois Conjuntos - retorna o conjunto formado pela intersecção
Conjuntos* Interseccao(Conjuntos* a, Conjuntos*b);

// Diferença de Dois Conjuntos - retorna o conjunto formado pela diferença
Conjuntos* Diferença(Conjuntos* a, Conjuntos*b);

// Testa se um Valor Pertence a um Conjunto - retorna 1 se verdadeiro e 0 se falso
int Pertence(Conjuntos* a, int x);

// Encontra o Menor Valor de um Conjunto - retorna o menor valor
int Menor(Conjuntos* a);

// Encontra o Maior Valor de um Conjunto - retorna o maior valor
int Maior(Conjuntos* a);

// Testa se Dois Conjuntos são Iguais - retorna 1 se verdadeiro e 0 se falso
int Iguais(Conjuntos* a, Conjuntos*b);

// Determina o Tamanho de um Conjunto - retorna o tamanho do Conjunto
int Tamanho(Conjuntos* a);

// Testa se o Conjunto é Vazio- retorna 1 se verdadeiro e 0 se falso
int Vazio(Conjuntos* a);

// Libera a memória alocada por um Conjunto
void Destroi(Conjuntos* a);
