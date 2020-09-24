// Questão 4 - Lista TAD - Numeros Complexos
#include <stdio.h>
#include <stdlib.h>
#include "Complexos.h"

struct numerocomplexo{
	float x;
	float y;
};

// Cria o número complexo
NumComplexo* CriaNumero (float x, float y){
	NumComplexo* a = (NumComplexo*) malloc(sizeof(NumComplexo));
	if (a == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	a->x = x;
	a->y = y;
	return a;
}

// Destroi o número complexo
void DestroiNumero (NumComplexo* a){
	free(a);
}

// Soma dois números complexos
NumComplexo* Soma(NumComplexo* a, NumComplexo* b){
	NumComplexo* res = (NumComplexo*) malloc(sizeof(NumComplexo));
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	printf("(%.2f + %.2fi) + (%.2f + %.2fi) = (%.2f + %.2fi)\n", a->x, a->y, b->x, b->y, res->x, res->y);
	return res;	
}

// Subtrai dois números complexos
NumComplexo* Subtrai(NumComplexo* a, NumComplexo* b){
	NumComplexo* res = (NumComplexo*) malloc(sizeof(NumComplexo));
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	printf("(%.2f + %.2fi) - (%.2f + %.2fi) = (%.2f + %.2fi)\n", a->x, a->y, b->x, b->y, res->x, res->y);
	return res;	
}

// Multiplica dois números complexos
NumComplexo* Multiplica(NumComplexo* a, NumComplexo* b){
	NumComplexo* res = (NumComplexo*) malloc(sizeof(NumComplexo));
	res->x = a->x * b->x - a->y * b->y;
	res->y = a->x * b->y + a->y * b->x;
	printf("(%.2f + %.2fi) * (%.2f + %.2fi) = (%.2f + %.2fi)\n", a->x, a->y, b->x, b->y, res->x, res->y);
	return res;
}

// Divide dois números complexos
NumComplexo* Divide(NumComplexo* a, NumComplexo* b){
	NumComplexo* res = (NumComplexo*) malloc(sizeof(NumComplexo));
	res->x = (a->x * b->y + a->y * b->x) / (b->x * b->x + b->y * b->y);
	res->y = (a->y * b->x - a->x * b->y) / (b->x * b->x + b->y * b->y);
	printf("(%.2f + %.2fi) / (%.2f + %.2fi) = (%.2f + %.2fi)\n", a->x, a->y, b->x, b->y, res->x, res->y);
	return res;
}

