// Questão 7 - Lista TAD - Cubo
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Cubo.h"

struct cubo {
	float lado;
};

// Cria um Cubo
Cubo* CriaCubo(float l){
	Cubo* a = (Cubo*) malloc(sizeof(Cubo));
	if(!a){
		printf("Memória Insuficiente!\n");
		exit(1);
	}
	a->lado = l;
	return a;
}

// Destroi um Cubo
void DestroiCubo(Cubo* a){
	free(a);
}

// Encontra o Lado do Cubo
float LadoCubo(Cubo* a){
	printf("Lado do cubo: %.3fm\n", a->lado);
	return a->lado;
}

// Encontra a Área do Cubo
float AreaCubo(Cubo* a){
	double area = 6 * pow(a->lado, 2);
	printf("Área do cubo: %.3fm^2\n", area);
	return area;
}

// Encontra o Volume do Cubo
float VolumeCubo(Cubo* a){
	double volume = pow(a->lado, 3);
	printf("Volume do cubo: %.3fm^3\n", volume);
	return volume;
}

