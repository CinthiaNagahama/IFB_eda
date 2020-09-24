#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calculadora.h"
#include "Pilha.h"

struct calc{
	char f[21]; //Formato para impressão
	Pilha* p; // Pilha de operandos
};

// Cria a calculadora
Calculadora* Cria(char* formato){
	Calculadora* c = (Calculadora*) malloc(sizeof(Calculadora));
	strcpy(c->f, formato);
	
	c->p = Cria_Pilha();

	return c;
}

// Insere um operando
void Operando(Calculadora* c, float v){
	Push_Pilha(c->p, v);
	printf(c->f, v);
	
}

// Insere um operador
void Operador(Calculadora* c, char o){
	float v1, v2, v;
	
	if(Is_Vazia_Pilha(c->p)) v2 = 0.0;
	else v2 = Pop_Pilha(c->p);
	
	if(Is_Vazia_Pilha(c->p)) v1 = 0.0;
	else v1 = Pop_Pilha(c->p);
	
	switch(o){
		case '+': 
			v = v1 + v2;
			break;
		case '-': 
			v = v1 - v2;
			break;
		case '*': 
			v = v1 * v2;
			break;
		case '/': 
			v = v1 / v2;
			break;
	}
	
	Push_Pilha(c->p, v);
	printf(c->f, v);
}

// Libera a memória alocada pela calculadora
void Libera(Calculadora* c){
	Libera_Pilha(c->p);
	free(c);
}

