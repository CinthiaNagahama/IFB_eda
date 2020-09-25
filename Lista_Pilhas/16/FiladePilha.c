#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FiladePilha"

typedef struct lista Lista;
struct lista{
	Pilha* info; 
	Lista* prox;
};

struct pilha{
	Lista* topo;
};

struct fila{
	Lista* ini;
	Lista* fim;
	int qtd;
};

/* ------------------------------------------- Pilhas ------------------------------------------- */
// Cria pilha
Pilha* cria_pilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

// Insere valor ao topo da pilha
void push(Pilha* p, int v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->topo;
	p->topo = n;
}

// Retira um valor do topo da pilha
int pop(Pilha* p){
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

// Imprime a pilha
void imprime_pilha(Pilha* p){
	Lista* q;
	for(q = p->topo; q != NULL; q = q->prox){
		if(q->tipo == 'i') printf("%i ", q->info);
		else printf("%c ", (char)q->info);
	}
}

// Checa se a pilha está vazia
int vazia_pilha(Pilha* p){
	return (p->topo == NULL);
}

// Libera a memória alocada pela pilha
void libera_pilha(Pilha* p){
	Lista* t = p->topo;
	while(t != NULL){
		Lista* u = t->prox;
		free(t);
		t = u;
	}
	free(p);
}

/* ---------------------------------------------- Filas ----------------------------------------- */
// Cria uma fila
Fila* cria_fila(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f != NULL){
		f->ini = f->fim = NULL;
		f->qtd = 0;
		return f;
	}
	printf("Error: Espaço indisponível");
	exit(1);
}

// Insere um elemento em uma fila
void insere_fila(Fila* f, Pilha* p){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = NULL;
	
	// Checa se a lista esta vazia e insere o novo elemento a lista
	if(f->ini == NULL){
		f->ini = n;
	}
	else{
		f->fim->prox = n;
	}
	f->qtd++;
	
	// Fim da lista aponta para o novo elemento
	f->fim = n;
}

// Retira um elemento de uma fila
Pilha* retira_fila(Fila* f){
	Lista* aux;
	Pilha* p;
	
	if(f->ini == NULL){
		printf("Error: Fila vazia.\n");
		exit(1);
	}
	
	aux = f->ini;
	p = aux->info;
	f->ini = aux->prox;
	
	// Verifica se a lista ficou vazia
	if(f->ini == NULL){
		f->fim = NULL;
	}
	
	free(aux);
	
	f->qtd--;
	return p;
}

// Checa se a fila está vazia
int vazia_fila(Fila* f){
	return(f->ini == NULL);
}

// Imprime a fila
void imprime_fila(Fila* f){
	Lista* aux;
	for(aux = f->ini; aux != NULL; aux = aux->prox)	{
		imprime_pilha(aux);
	}
}

// Libera a memória alocada por uma fila
void libera_fila(Fila* f){
	Lista* aux = f->ini;
	while(aux != NULL){
		Lista* aux2 = aux->prox;
		libera_pilha(aux);
		aux = aux2;
	}
	free(f);
}
