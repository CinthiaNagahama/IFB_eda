#include <stdio.h>
#include "PilhaInteiroCaractere.h"

int main(void){
	Pilha* p = Cria_Pilha();
	
	Push(p, 'i');
	Push(p, 'c');
	// Push(p, 'f');
	
	Imprime(p);
	
	printf("\n%c", Pop_char(p));
	
	Libera(p);
	return 0;
}
