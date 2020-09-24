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
	
	
	// C�digos de Teste
	// Quest�o 4
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
	
	// Quest�o 5
	/*
	char a[4] = "BBCD";
	char b[4] = "DCBB";
	
	int v = XY(p, a, b);
	printf("%i", v);
	*/
	
	// Quest�o 6
	/*
	char c[100] = "ESTE EXERC�CIO E MUITO F�CIL.";
	inverte_letras(c);
	*/
	
	// Quest�o 7
	/*
	char c[100] = "amorA";
	printf("%i", checa_palindromo(c));
	*/
	
	// Quest�o 8 -> O programa deve verificar express�es para ver se cada �abre par�nteses� tem um 
	//				�fecha par�nteses� correspondente.
	/*
	Pilha* P = Cria_Pilha();
	char c[100] = "( ( ) ) � ( ( )( ) ) � ( ) ( )";
	int i = 0, bom = 1;
	for(; c[i] != '\0'; i++){
		if(c[i] == '(') Push(P, '(');
		else if(c[i] == ')' && Vazia(P)){
			printf("Est� faltando abrir algum(ns) par�ntese(s)\n");
			bom = 0;
			break;
		}
		else if(c[i] == ')') Pop(P);
	}
	if(Vazia(P) && bom) printf("\nExpress�o V�lida! Bom trabalho\n");
	else if(!Vazia(P))printf("\nVoc� esqueceu de fechar algum(ns) par�nte(s)\n");
	*/
	
	// Quest�o 9
	/*
	p = ordena(p);
	
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	printf("%i ", Pop(p));
	*/
	
	// Quest�o 10
	/*
	calcula(p);
	*/
	
	// Quest�o 11
	/*
	p = inverte_posicao(p);
	*/
	
	// Quest�o 12
	/*
	Pilha* p2 = Cria_Pilha();
	
	Push(p2, -9);
	Push(p2, -1);
	Push(p2, 1);
	Push(p2, 3);
	Push(p2, 5);
	
	printf("%i", maior(p, p2));
	*/
	
	// Quest�o 13
	/*
	Pilha* p2 = Cria_Pilha();
	
	Push(p2, -9);
	Push(p2, -1);
	Push(p2, 1);
	Push(p2, 3);
	Push(p2, 5);
	
	printf("%i", iguais(p, p2));
	*/
	
	// Quest�o 14
	/*
	Pilha* p2 = Cria_Pilha(); 
	p2 = copia(p);
	
	printf("%i ", Pop(p2));
	printf("%i ", Pop(p2));
	printf("%i ", Pop(p2));
	printf("%i ", Pop(p2));
	printf("%i\n", Pop(p2));
	*/
	
	// Quest�o 15
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
