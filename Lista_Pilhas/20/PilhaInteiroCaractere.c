#include <stdio.h>
#include <stdlib.h>
#include "PilhaInteiroCaractere.h"

typedef struct lista Lista;
struct lista{
	int info;
	char tipo;
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
void Push(Pilha* p, char tipo){ // Tipo = i, para inteiros | Tipo = c, para caracteres
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->tipo = tipo;
	if(tipo == 'i'){
		int v;
		printf("Digite o valor: ");
		scanf("%i", &v);
		n->info = v;
		n->prox = p->topo;
		p->topo = n;
	}
	else if(tipo == 'c'){
		char v;
		printf("Digite o caractere: ");
		scanf("\n%c", &v);
		n->info = (int)v;
		n->prox = p->topo;
		p->topo = n;
	}
	else printf("Tipo desconhecido. Por favor utilizar 'i' para inteiros e 'c' para caracteres.\n");
}

// Retira um valor do topo da pilha
int Pop_int(Pilha* p){
	Lista* t;
	int v;
	if(Vazia(p)){
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

char Pop_char(Pilha* p){
	Lista* t;
	char v;
	if(Vazia(p)){
		printf("\nA pilha está vazia.\n");
		exit(1);
	}
	// Pega o valor no topo da pilha
	t = p->topo;
	v = (char)t->info;
	
	// Passa o topo para o próximo elemento
	p->topo = t->prox;
	
	// Libera o topo original e retorna o valor
	free(t);
	return v;
}
// Checa se a pilha está vazia
int Vazia(Pilha* p){
	return (p->topo == NULL);
}

// Imprime pilha
void Imprime(Pilha* p){
	Lista* q;
	for(q = p->topo; q != NULL; q = q->prox){
		if(q->tipo == 'i') printf("%i ", q->info);
		else printf("%c ", (char)q->info);
	}
}

// Libera a memória alocada pela pilha
void Libera(Pilha* p){
	Lista* t = p->topo;
	while(t != NULL){
		Lista* u = t->prox;
		free(t);
		t = u;
	}
	free(p);
}

