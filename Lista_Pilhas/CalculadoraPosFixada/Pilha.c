#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define N 50

// -----------------------------------Implementação de Pilha com vetor-----------------------------------------//
/*
struct pilha{
	int n; 
	float vet[N];
};

// Cria pilha
Pilha* Cria_Pilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->n = 0;
	
	return p;
}

// Insere valor ao topo da pilha
void Push_Pilha(Pilha* p, float v){
	// Checa se há espaço na pilha
	if(p->n == N){
		printf("\nCapacidade da pilha estorou.\n");
		exit(1);
	}
	// Insere o valor no topo da pilha
	p->vet[p->n] = v;
	p->n++; // Sempre deixa um espaço vazio
}

// Retira um valor do topo da pilha
float Pop_Pilha(Pilha* p){
	float* v;
	// Checa se a pilha está vazia
	if(Vazia(p)){
		printf("\nA pilha está vazia.\n");
		exit(1);
	}	
	// Retira o valor do topo da pilha
	v = p->vet[p->n-1];
	p->n--;
	return v;
}

// Checa se a pilha está vazia
int IS_Vazia_Pilha(Pilha* p){
	return (p->n == 0);
}

// Libera a memória alocada pela pilha
void Libera_Pilha(Pilha* p){
	free(p);
}
*/

// ------------------------------------Implementação de Pilha com Lista----------------------------------------//

typedef struct lista Lista;
struct lista{
	float info; 
	Lista* prox;
};

struct pilha{
	Lista* topo;
};

// Cria pilha
Pilha* Cria_Pilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

// Insere valor ao topo da pilha
void Push_Pilha(Pilha* p, float v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->topo;
	p->topo = n;
}

// Retira um valor do topo da pilha
float Pop_Pilha(Pilha* p){
	Lista* t;
	float v;
	if(Is_Vazia_Pilha(p)){
		printf("\nA pilha está vazia.\n");
		exit(1);
	}
	// Pega o valor no topo da pilha
	t = p->topo;
	v = t->info;
	
	// Passa o topo para o próximo elemento
	p->topo = t->prox;
	
	// Libera o topo original e retorna o valor
	free(t);
	return v;
}

// Checa se a pilha está vazia
int Is_Vazia_Pilha(Pilha* p){
	return (p->topo == NULL);
}

// Libera a memória alocada pela pilha
void Libera_Pilha(Pilha* p){
	Lista* t = p->topo;
	while(t != NULL){
		Lista* u = t->prox;
		free(t);
		t = u;
	}
	free(p);
}
