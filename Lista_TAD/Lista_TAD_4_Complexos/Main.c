// Questão 4 - Lista TAD - Numeros Complexos
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Complexos.h"

int main (void){
	setlocale(LC_ALL, "portuguese");
	
	NumComplexo* a = CriaNumero(2, 3);
	NumComplexo* b = CriaNumero(1, 5);
	
	NumComplexo* c = Soma(a, b);
	
	c = Subtrai(a, b);
	
	c = Multiplica(a, b);
	
	c = Divide(a, b);
	
	DestroiNumero(a);
	DestroiNumero(b);
	
	return 0;
}
