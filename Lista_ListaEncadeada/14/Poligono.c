// Projete um TAD para armazenar um polígono
#include <stdio.h>
#include <stdlib.h>
#include "Poligono.h"

typedef struct coordenadas Coordenadas;
struct coordenadas{
	float x;
	float y;
};

struct aresta{
	Coordenadas* info;
	Aresta* prox;
};

// Cria poligono
Aresta* Cria(void){
	return NULL;
}

// Incluir arestas
Aresta* Inclui(Aresta* a, float x, float y){
	Aresta* novaAresta = (Aresta*) malloc(sizeof(Aresta));
	Coordenadas* novaCoor = (Coordenadas*) malloc(sizeof(Coordenadas));
	novaCoor->x = x;
	novaCoor->y = y;
	novaAresta->info = novaCoor;
	novaAresta->prox = a;
	return novaAresta;
}

// Imprimi coordenadas
void Imprimi(Aresta* a){
	Aresta* p = a;
	while(p != NULL){
		printf("\nx: %.2f | y: %.2f", p->info->x, p->info->y);
		p = p->prox;
	}
}

// Eliminar arestas
Aresta* Retira (Aresta* a, float x, float y){
	Aresta* ant = NULL;
	Aresta* p = a;
	// Busca o elemento a ser retirado enquanto guarda o elemento anterior
	while(p != NULL && p->info->x != x && p->info->y){
		ant = p;
		p = p->prox;
	}
	if(p == NULL){
		printf("Aresta não encontrada");
		return a;
	}
	if (ant == NULL){
		a = p->prox;
	}
	else{
		ant->prox = p->prox;
	}
	free(p);
	return a;
}

// Libera poligono
void Libera(Aresta* a){
	Aresta* p = a;
	while(p != NULL){
		Aresta* aux = p->prox;
		free(p);
		p = aux;
	}
}
