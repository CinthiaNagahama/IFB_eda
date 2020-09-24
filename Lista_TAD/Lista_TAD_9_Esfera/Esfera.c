// Questão 9 - Lista TAD - Esfera// Cria a Esfera
#include <stdio.h>
#include <stdlib.h>
#include "Esfera.h"

struct esfera{
	float raio;
};

// Cria a Esfera
Esfera* CriaEsfera (float r){
	Esfera* a = (Esfera*) malloc(sizeof(Esfera));
	if(!a){
		printf("Memória Insuficiente!\n");
		exit(1);
	}
	a->raio = r;
	return a;
}

// Apaga a Esfera
void ApagaEsfera (Esfera* a){
	free(a);
}

// Encontra o Raio de Esfera
float RaioEsfera (Esfera* a){
	return a->raio;
}

// Encontra a Área de Esfera
float AreaEsfera (Esfera* a){
	return(4 * 3.14 * a->raio * a->raio);
}

// Encontra o Volume da Esfera
float VolumeEsfera (Esfera* a){
	return(4 * 3.14 * a->raio * a->raio / 3);	
}
