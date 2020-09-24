// Questão 10 -> Implemente um TAD fila completo com uma lista circular dinâmica e encadeada.

#include <stdio.h>
#include <stdlib.h>
#include "Lista_Circular.h"

typedef struct lista Lista;
struct lista{
	float info;
	Lista* prox;	
};

struct fila{
	Lista* fim;
	float qtd;
};

// Cria uma fila
Fila* cria_fila(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f != NULL){
		f->fim = NULL;
		f->qtd = 0;
		return f;
	}
	printf("Error: Espaço indisponível");
	exit(1);
}

// Insere um elemento em uma fila
void insere_fila(Fila* f, float v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	
	// Checa se a lista esta vazia e insere o novo elemento a lista
	if(f->fim == NULL){
		n->prox = n;
		f->fim = n;
	}
	else{
		n->prox = f->fim->prox;
		f->fim->prox = n;
	}
	f->qtd++;
	
	// Fim da lista aponta para o novo elemento
	f->fim = n;
}

// Retira um elemento de uma fila
float retira_fila(Fila* f){
	Lista* aux;
	float v;
	
	if(f->fim == NULL){
		printf("Error: Fila vazia.\n");
		exit(1);
	}
	
	aux = f->fim->prox;
	v = aux->info;
	f->fim->prox = aux->prox;
	
	free(aux);
	
	f->qtd--;
	return v;
}

// Checa se a fila está vazia
int vazia_fila(Fila* f){
	return(f->fim == NULL);
}

// Imprime a fila
void imprime_fila(Fila* f){
	Lista* aux = f->fim->prox;
	int i;
	for(i = 0; i < f->qtd; i++, aux = aux->prox){
		printf("%.2f\n", aux->info);
	}
}

// Libera a memória alocada por uma fila
void libera_fila(Fila* f){
	Lista* ini = f->fim->prox;
		
	if (ini->prox == ini) free(ini);
	
	Lista* aux = ini->prox;
	
	while(aux != ini){
	    Lista* t = aux->prox;
	    free(aux);
	    aux = t;
	}
	free(ini);
	free(f);
}
