#include <stdio.h>

#include "Lista_Circular.h"

int main(void){
	Fila* f = cria_fila();
	
	printf("%i\n", vazia_fila(f));
	
	insere_fila(f, 20.0);
	insere_fila(f, 20.8);
	insere_fila(f, 21.2);
	insere_fila(f, 24.3);
	insere_fila(f, 5.2);
	insere_fila(f, -3.2);
	
	printf("Configuracao da fila:\n");
	imprime_fila(f);
	
	printf("Primeiro elemento: %.2f\n", retira_fila(f));
	printf("Segundo elemento: %.2f\n", retira_fila(f));
	
	printf("Configuracao da fila:\n");
	imprime_fila(f);
	
	libera_fila(f);
	return 0;	
}
