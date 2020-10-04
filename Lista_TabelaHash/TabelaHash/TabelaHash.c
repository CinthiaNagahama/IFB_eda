#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"

struct hash{
	int qtd, TABLE_SIZE;
	Aluno **itens;
};

// Cria uma tabela hash vazia
Hash* cria_hash(int TABLE_SIZE){
	Hash* h = (Hash*) malloc(sizeof(Hash));
	if(h != NULL){
		int i;
		h->TABLE_SIZE = TABLE_SIZE;
		h->itens = (Aluno**) malloc(TABLE_SIZE * sizeof(Aluno*));
		if(h->itens == NULL){
			free(h);
			printf("Erro: Acesso � mem�ria indispon�vel.");
			return NULL;
		}
		h->qtd = 0;
		for(i = 0; i < h->TABLE_SIZE; i++){
			h->itens[i] = NULL;
		}
	}
	return h;
}

// Libera a mem�ria alocada pela tabela hash
void libera_hash(Hash* h){
	if(h != NULL){
		int i;
		for(i = 0; i < h->TABLE_SIZE; i++){
			if(h->itens[i] != NULL) free(h->itens[i]);
		}
		free(h->itens);
		free(h);
	}
}

/* ---------------------------------------- Fun��o Hashing ---------------------------------------- */
/* M�todo da Divis�o */
/*
int chave_divisao(int chave, int TABLE_SIZE){
	return (chave & 0x7FFFFFFF) % TABLE_SIZE; // (chave & 0x7FFFFFFF) -> Evita overflow (valor negativo)
}
*/
/* M�todo da Multiplica��o / M�todo da Congru�ncia Linar */
/*
int chave_multiplicacao(int chave, int TABLE_SIZE){
	float A = 0.6180339887; //	Constante 0 < A < 1
	float val = chave * A;
	val = val - (int) val
	return (int)(TABLE_SIZE * val);
}
/* M�todo da Soma */
/*
int chave_soma(int chave, int TABLE_SIZE){
	int num_bits = 10;
	int parte1 = chave >> num_bits; // Desloca a chave 10 bits para direita
	int parte2 = chave & (TABLE_SIZE - 1); // Multiplica��o & bit a bit
	return (parte1 ^ parte2); // Faz um ou exclusivo entre a parte1 e a parte2
}
*/
/* Tratando uma string como chave*/
/*
int converte_string(char *str){
	int i, valor = 7; // D� um valor inicial para a soma
	int tam = strlen(str);
	for(i = 0; i < tam; i++){
		valor = 31 * valor + (int) str[i]; // Alguns estudos recomenda o n�mero 31 para a multplica��o
	}
	return valor;
}
*/

// Fun��o de Hashing
int chave_divisao(int chave, int TABLE_SIZE){
	return (chave & 0x7FFFFFFF) % TABLE_SIZE; // (chave & 0x7FFFFFFF) -> Evita overflow (valor negativo)
}

// Insere um valor sem tratamento de colis�o
int insere_sem_colisao(Hash *h, Aluno a){
	if(h == NULL || h->qtd == h->TABLE_SIZE) return 0;
	
	int chave = a.matricula;
	int pos = chave_divisao(chave, h->TABLE_SIZE);
	
	Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
	
	if(novo == NULL) return 0;
	
	*novo = a;
	h->itens[pos] = novo;
	h->qtd++;
	return 1;
}

// Busca um valor sem tratamento de colis�o
int busca_sem_colisao(Hash *h, int mat, Aluno* a){
	if(h == NULL) return 0;
	
	int pos = chave_divisao(mat, h->TABLE_SIZE);
	if(h->itens[pos] == NULL) return 0;
	*a = *(h->itens[pos]);
	return 1;
}

/* ------------------------------------- Tratamento de Colis�o ------------------------------------- */
/* Encadeamento Separado | Separate Chaining 
	-> Utiliza lista encadeadas
	-> Maior tempo de busca
	-> Maior gasto de mem�ria
*/

/* Endere�amento Aberto | Open Adressing | Rehash
	-> Mair tempo de inser��o
	-> Estrat�gias:
		- Sondagem Linear | Rehash Linear -> Problema: Agrupamento prim�rio
		- Sondagem Quadr�tica | Rehash Quadr�tico -> Problema: Agrupamento secund�rio
		- Duplo Hash -> Problema: Gasto de tempo
*/
/* Sondagem Linear */

int rehash_linear(int pos, int i, int TABLE_SIZE){
	return((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

/* Sondagem Quadr�tica */
/*
int rehash_quad(int pos, int i, int TABLE_SIZE){
	pos = pos + 2 * i + 5 * i * i; // Coeficientes aleat�rios
	return(pos & 0x7FFFFFFF) % TABLE_SIZE;
}
*/
/* Duplo Hash */
/*
int duplo_hash(int h1, int chave, int i, int TABLE_SIZE){
	int h2 = chave_divisao(chave, TABLE_SIZE - 1) + 1;
	return((h1 + i * h2) & 0x7FFFFFFF) % TABLE_SIZE;
}
*/

// Insere um valor com tratamento de colis�o
int insere_ender_aberto(Hash *h, Aluno a){
	if(h == NULL || h->qtd == h->TABLE_SIZE) return 0;
	
	int chave = a.matricula;
	int i, pos = chave_divisao(chave, h->TABLE_SIZE), newPos;
	
	for(i = 0; i < h->TABLE_SIZE; i++){
		newPos = rehash_linear(pos, i, h->TABLE_SIZE);
		if(h->itens[newPos] == NULL){
			Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
			if(novo == NULL) return 0;
			
			*novo = a;
			h->itens[newPos] = novo;
			h->qtd++;
			return 1;
		}
	}
	return 0;
}

// Busca um valor com tratamento de colis�o
int busca_ender_aberto(Hash *h, int mat, Aluno* a){
	if(h == NULL) return 0;
	
	int i, pos = chave_divisao(mat, h->TABLE_SIZE), newPos;
	for(i = 0; i < h->TABLE_SIZE; i++){
		newPos = rehash_linear(pos, i, h->TABLE_SIZE);
		
		if(h->itens[newPos] == NULL) return 0;
		
		if(h->itens[newPos]->matricula == mat){
			*a = *(h->itens[newPos]);
			return 1;
		}
	}
	return 0;
}

/* N�o testados

// Quest�o 2 -> Verifica se a tabela est� cheia
int cheia(Hash* h){
	return(h->qtd == h->TABLE_SIZE);
}

// Quest�o 20 -> Considere dois conjuntos de numeros inteiros, S = {s1; s2; ... ; sm} e T = {t1; t2; ...;
// 				 tn}, m = n.
// 					(a) Monte um algoritmo que utiliza uma tabela hash para testar se S � um subconjunto
//						de T.
//					(b) Qual � o tempo m�dio de funcionamento de seu algoritmo?

int subconjunto(int* s, int m, int* t, int n){
	Hash* h = cria_hash(n);
	int i;
	for(i = 0; i < n; i++){
		int x = insere_ender_aberto(h, t[i]);
	}
	for(i = 0; i < m; i++){
		if (!busca_ender_aberto(h, s[i])) return 0;
	}
	return 1;
}
*/

