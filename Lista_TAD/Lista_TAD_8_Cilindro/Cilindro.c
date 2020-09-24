// Questão 8 - Lista TAD - Cilindro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Cilindro.h"

struct cilindro{
	float altura, raio;
};

// Cria Cilindro
Cilindro* CriaCilindro(float h, float r){
	Cilindro* a = (Cilindro*) malloc(sizeof(Cilindro));
	if(!a){
		printf("Memória Insuficiente!\n");
		exit(1);
	}
	a->altura = h;
	a->raio = r;
	return(a);
}

// Apaga o Cilindro
void ApagaCilindro(Cilindro* a){
	free(a);
}

// Encontra a Altura e o Raio do Cilindro
void AlturaERaio(Cilindro* a, float *h, float *r){
	printf("A altura do cilindro é %.2f e o raio é %.2f.\n", a->altura, a->raio);
	
	*h = a->altura;
	*r = a->raio;
}

// Encontra a Área do Cilindro
double Area(Cilindro* a){
	double base = PI * a->raio * a->raio;
	double sup = 2 * PI * a->altura * a->raio;
	double area = 2 * base + sup;
	
	printf("A área do cilindro é: %.2f.\n", area);
	return area;
}

// Encontra o Volume do Cilindro
double Volume(Cilindro* a){
	double volume = PI * a->altura * a->raio * a->raio;
	
	printf("O volume do cilindro é: %.2f.\n", volume);
	return volume;
}
