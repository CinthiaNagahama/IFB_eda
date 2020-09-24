// Questão 3 - Lista TAD - Clube de quadras poliesportivas
#include <stdio.h>
#include <stdlib.h>
#include "Clube.h"

struct clube{
	int quadras;
};


// Cria clube
Clube* NovoClube(int n){
	Clube* c = (Clube*) malloc(sizeof(Clube));
	if (c == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	c -> quadras = n;
	return c;
}

// Reserva quadra
void ReservaQuadra(Clube* c, int n){
	if (c->quadras - n >= 0){
		c->quadras = c->quadras - n;
		printf("Reservas feitas com sucesso.\n");
	}
	else{
		int aux = c->quadras, r;
		printf("Quadras insuficientes. Quadras disponiveis: %i. Gostaria de continuar a reserva?\nDigite 1 se sim e 0 se não.\n", aux);
		scanf("%i", &r);
		if (r == 0){
			printf("Sentimos muito pela incoveniência.\n");
			exit(2);
		}
		else{
			c->quadras = 0;
			printf("Reserva concluída com sucesso. Obrigado pela preferência.\n");
		}
	}
}

// Cancela Reserva
void CancelaQuadra(Clube* c, int n){
	c->quadras += n;
	printf("Cancelamento de %i quadras executado com sucesso.\n", n);
}

// Libera Clube
void Libera(Clube* c){
	free(c);
}
