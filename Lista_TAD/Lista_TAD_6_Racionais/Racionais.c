// Questão 6 - Lista TAD - Números Racionais
/*
Um número racional é todo número que pode ser representado por uma fração a/b de dois números inteiros
*/


#include <stdio.h>
#include <stdlib.h>
#include "Racionais.h"

struct numero_racional{
	double valor;
};

// Cria um número racional
Racionais* CriaNumero(int num, int den){
	Racionais* a = (Racionais*) malloc(sizeof(Racionais));
	if(a == NULL){
		printf("Memória Insuficiente!\n");
		exit(1);
	}
	a->valor = (double) (num)/den;
	return a;
}

// Apaga números racionais
void ApagaNumero(Racionais* x){
	free(x);
}

// Soma números racionais. 
Racionais* Soma(Racionais* x, Racionais* y){
	Racionais* res = (Racionais*) malloc(sizeof(Racionais));
	if(res == NULL){
		printf("Memória Insuficiente!\n");
		exit(2);
	}
	res->valor = x->valor + y->valor;
	printf("%f + %f = %f\n", x->valor, y->valor, res->valor);
	return res;
}

// Multiplica Números Racionais
Racionais* Multiplica(Racionais* x, Racionais* y){
	Racionais* res = (Racionais*) malloc(sizeof(Racionais));
	if(res == NULL){
		printf("Memória Insuficiente!\n");
		exit(3);
	}
	res->valor = x->valor * y->valor;
	printf("%f * %f = %f\n", x->valor, y->valor, res->valor);
	return res;
}

// Testa se os Números Racionais são Iguais
int Iguais(Racionais* x, Racionais* y){
	if(x->valor == y->valor){
		printf("São iguais.\n");
		return 1;
	}
	else{
		printf("Não são iguais.\n");
		return 0;
	}
}
