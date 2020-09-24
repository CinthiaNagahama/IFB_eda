// Quest�o 6 - Lista TAD - N�meros Racionais
/*
Um n�mero racional � todo n�mero que pode ser representado por uma fra��o a/b de dois n�meros inteiros
*/


#include <stdio.h>
#include <stdlib.h>
#include "Racionais.h"

struct numero_racional{
	double valor;
};

// Cria um n�mero racional
Racionais* CriaNumero(int num, int den){
	Racionais* a = (Racionais*) malloc(sizeof(Racionais));
	if(a == NULL){
		printf("Mem�ria Insuficiente!\n");
		exit(1);
	}
	a->valor = (double) (num)/den;
	return a;
}

// Apaga n�meros racionais
void ApagaNumero(Racionais* x){
	free(x);
}

// Soma n�meros racionais. 
Racionais* Soma(Racionais* x, Racionais* y){
	Racionais* res = (Racionais*) malloc(sizeof(Racionais));
	if(res == NULL){
		printf("Mem�ria Insuficiente!\n");
		exit(2);
	}
	res->valor = x->valor + y->valor;
	printf("%f + %f = %f\n", x->valor, y->valor, res->valor);
	return res;
}

// Multiplica N�meros Racionais
Racionais* Multiplica(Racionais* x, Racionais* y){
	Racionais* res = (Racionais*) malloc(sizeof(Racionais));
	if(res == NULL){
		printf("Mem�ria Insuficiente!\n");
		exit(3);
	}
	res->valor = x->valor * y->valor;
	printf("%f * %f = %f\n", x->valor, y->valor, res->valor);
	return res;
}

// Testa se os N�meros Racionais s�o Iguais
int Iguais(Racionais* x, Racionais* y){
	if(x->valor == y->valor){
		printf("S�o iguais.\n");
		return 1;
	}
	else{
		printf("N�o s�o iguais.\n");
		return 0;
	}
}
