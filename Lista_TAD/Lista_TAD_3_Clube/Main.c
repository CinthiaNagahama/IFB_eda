// Questão 3 - Lista TAD - Clube de quadras poliesportivas

#include <stdio.h>
#include <locale.h>
#include "Clube.h"

int main (void){
	setlocale(LC_ALL, "portuguese");
	Clube* c = NovoClube(3);
	
	ReservaQuadra(c, 2);
	ReservaQuadra(c, 2);
	
	CancelaQuadra(c, 2);
	
	Libera(c);
	return 0;
}
