// Questão 9 - Lista TAD - Esfera
#include <stdio.h>
#include <locale.h>
#include "Esfera.h"

int main (void){
	setlocale(LC_ALL, "portuguese");
	
	Esfera* E = CriaEsfera (7);
	
	float res = RaioEsfera (E);
	printf("Raio = %.2f\n", res);
	
	res = AreaEsfera (E);
	printf("Área = %.2f\n", res);
	
	res = VolumeEsfera (E);
	printf("Volume = %.2f\n", res);
	
	ApagaEsfera (E);
	return 0;
}
