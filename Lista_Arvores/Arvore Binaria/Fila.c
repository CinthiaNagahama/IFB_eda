#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "Fila.h"

// Implementa��o de fila com Lista (Fila din�mica)

// Cria uma fila
Fila* cria_fila(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f != NULL){
		f->ini = f->fim = NULL;
		f->qtd = 0;
		return f;
	}
	printf("Error: Espa�o indispon�vel");
	exit(1);
}

// Insere um elemento em uma fila
void insere_fila(Fila* f, struct node* v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->infoLista = v;
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
struct node* retira_fila(Fila* f){
	Lista* aux;
	struct node* v;
	
	if(f->ini == NULL){
		printf("Error: Fila vazia.\n");
		exit(1);
	}
	
	aux = f->ini;
	v = aux->infoLista;
	f->ini = aux->prox;
	
	// Verifica se a lista ficou vazia
	if(f->ini == NULL){
		f->fim = NULL;
	}
	
	free(aux);
	
	f->qtd--;
	return v;
}

// Checa se a fila est� vazia
int vazia_fila(Fila* f){
	return(f->ini == NULL);
}

/* ----------------------------------------- Lista ------------------------------------- */

// Cria uma lista vazia
Lista* Cria_Lista(void){
	return NULL;
}

// Insere um valor ao in�cio da lista
Lista* Insere_Valor(Lista* lst, struct node* valor){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->infoLista = valor;
	novo->prox = lst;
	return novo;
}

// Imprime os valores da lista
void Imprime_Lista(Lista* lst){
	Lista* p;
	for(p = lst; p != NULL; p = p->prox){
		printf("\ninfo = %d", p->infoLista->info);
	}
	printf("\n");
}
