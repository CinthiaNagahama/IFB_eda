#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"

int main(void){
	setlocale(LC_ALL, "portuguese");
	Pilha* p = Cria_Pilha();
	
	/*
	Push(p, 'A');
	Push(p, 'B');
	Push(p, 'C');
	Push(p, 'D');
	Push(p, ' ');
	Push(p, 'D');
	Push(p, 'C');
	Push(p, 'B');
	Push(p, 'A');
	Push(p, '.');
	*/
	
	Push(p, -9);
	Push(p, -1);
	Push(p, 1);
	Push(p, 3);
	Push(p, 5);
	
	/*
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i\n", Pop(p));
	*/
	
	
	// Códigos de Teste
	// Questão 4
	/*	 
	int v = seq_valida("IIEE", 4, 0);
	printf("\nPilha vazia: %i", v);
	v = seq_valida("IIEE", 4, 1);
	printf("\nIIEE: %i", v);
	v = seq_valida("E", 1, 1);
	printf("\nE: %i", v);
	v = seq_valida("I", 1, 1);
	printf("\nI: %i", v);
	*/
	
	// Questão 5
	/*
	char a[4] = "BBCD";
	char b[4] = "DCBB";
	
	int v = XY(p, a, b);
	printf("%i", v);
	*/
	
	// Questão 6
	/*
	char c[100] = "ESTE EXERCÍCIO E MUITO FÁCIL.";
	inverte_letras(c);
	*/
	
	// Questão 7
	/*
	char c[100] = "amorA";
	printf("%i", checa_palindromo(c));
	*/
	
	// Questão 8 -> O programa deve verificar expressões para ver se cada “abre parênteses” tem um 
	//				“fecha parênteses” correspondente.
	/*
	Pilha* P = Cria_Pilha();
	char c[100] = "( ( ) ) – ( ( )( ) ) – ( ) ( )";
	int i = 0, bom = 1;
	for(; c[i] != '\0'; i++){
		if(c[i] == '(') Push(P, '(');
		else if(c[i] == ')' && Vazia(P)){
			printf("Está faltando abrir algum(ns) parêntese(s)\n");
			bom = 0;
			break;
		}
		else if(c[i] == ')') Pop(P);
	}
	if(Vazia(P) && bom) printf("\nExpressão Válida! Bom trabalho\n");
	else if(!Vazia(P))printf("\nVocê esqueceu de fechar algum(ns) parênte(s)\n");
	*/
	
	// Questão 9
	/*
	p = ordena(p);
	
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	*/
	
	// Questão 10
	/*
	calcula(p);
	*/
	
	// Questão 11
	/*
	p = inverte_posicao(p);
	*/
	
	// Questão 12
	/*
	Pilha* p2 = Cria_Pilha();
	
	Push(p2, -9);
	Push(p2, -1);
	Push(p2, 1);
	Push(p2, 3);
	Push(p2, 5);
	
	printf("%i", maior(p, p2));
	*/
	
	// Questão 13
	/*
	Pilha* p2 = Cria_Pilha();
	
	Push(p2, -9);
	Push(p2, -1);
	Push(p2, 1);
	Push(p2, 3);
	Push(p2, 5);
	
	printf("%i", iguais(p, p2));
	*/
	
	// Questão 14
	/*
	Pilha* p2 = Cria_Pilha(); 
	p2 = copia(p);
	
	printf("%i ", Pop(p2));
	printf("%i ", Pop(p2));
	printf("%i ", Pop(p2));
	printf("%i ", Pop(p2));
	printf("%i\n", Pop(p2));
	*/
	
	// Questão 15
	Fila* f = cria_fila();
	
	insere_fila(f, 1);
	insere_fila(f, 2);
	insere_fila(f, 3);
	insere_fila(f, 4);
	insere_fila(f, 5);
	
	f = inverte_fila(f);
	imprime_fila(f);
	
	Libera(p);
	return 0;
}
