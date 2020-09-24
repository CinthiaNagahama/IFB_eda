// Questão 6 - Lista TAD - Números Racionais
#include <stdio.h>
#include <locale.h>
#include "Racionais.h"

int main (void){
	setlocale(LC_ALL, "portuguese");
	
	Racionais* a = CriaNumero(10,8);
	Racionais* b = CriaNumero(5,4);
	
	Racionais* c = Soma(a,b);
	
	c = Multiplica(a,b);
	
	int igual = Iguais(a,b);
	
	ApagaNumero(a);
	ApagaNumero(b);
	ApagaNumero(c);
	
	return 0;
}
