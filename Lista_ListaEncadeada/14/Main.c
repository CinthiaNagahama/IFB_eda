// Projete um TAD para armazenar um polígono
#include <stdio.h>
#include "Poligono.h"

int main(void){
	Aresta* a = Cria();
	a = Inclui(a, 1, 0);
	a = Inclui(a, 3, 5);
	a = Inclui(a, -3, 3);
	a = Inclui(a, -7, -2);
	Imprimi(a);
	
	Retira(a, 3, 5);
	Imprimi(a);
	
	Libera(a);	
	return 0;
}
