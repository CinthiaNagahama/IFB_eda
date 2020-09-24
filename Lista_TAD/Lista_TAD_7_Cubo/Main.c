// Questão 7 - Lista TAD - Cubo | Medidas em metros
#include <stdio.h>
#include <locale.h>
#include "Cubo.h"

int main (void){
	setlocale(LC_ALL, "portuguese");
	Cubo* C = CriaCubo(2);
	
	double res = LadoCubo(C);
	
	res = AreaCubo(C);
	
	res = VolumeCubo(C);
	
	DestroiCubo(C);
	
	return 0;
}
