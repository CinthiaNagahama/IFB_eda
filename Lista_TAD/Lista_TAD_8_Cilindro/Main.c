// Questão 8 - Lista TAD - Cilindro
#include <stdio.h>
#include <locale.h>
#include "Cilindro.h"

int main (void) {
	setlocale(LC_ALL, "portuguese");
	
	Cilindro* C = CriaCilindro(10, 2);
	float *h, *r;
	
	AlturaERaio(C, h, r);
	
	double res; // Dá erro a partir daqui...
	
	res = Area(C);

	res = Volume(C);
	
	ApagaCilindro(C);
	
	return 0;
}
