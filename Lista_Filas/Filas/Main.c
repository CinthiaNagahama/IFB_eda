#include <stdio.h>
#include "fila.h"

int main (void)
{
	Fila* f = cria_fila();
	
	insere_fila(f, 20.0);
	insere_fila(f, 20.8);
	insere_fila(f, 21.2);
	insere_fila(f, 24.3);
	insere_fila(f, 5.2);
	insere_fila(f, -3.2);
	
	Fila* f2 = cria_fila();
	
	insere_fila(f2, 1.0);
	insere_fila(f2, 2.8);
	insere_fila(f2, 3.2);
	
	
	Fila* f3 = intercala(f2, f);
	
	imprime(f);
	printf("\n");
	imprime(f2);
	printf("\n");
	imprime(f3);

	/*
	printf("Primeiro elemento: %.2f\n", retira_fila(f));
	printf("Segundo elemento: %.2f\n", retira_fila(f));
	
	printf("Configuracao da fila:\n");
	imprime_fila(f);
	
	printf("Ultimo elemento: %.2f\n", retira_final_fila(f));
	
	printf("Configuracao da fila:\n");
	imprime_fila(f);
	*/
	
	// C�digos de Teste
	// Quest�o 3
	/*
	reverso(&f);
	*/
	
	// Quest�o 4
	/*
	ordena_crescente(&f);
	*/
	
	// Quest�o 5
	/*
	calcula(f);
	*/
	
	// Quest�o 6
	/*
	Fila* f2 = cria_fila();
	
	insere_fila(f2, 20.0);
	insere_fila(f2, 20.8);
	insere_fila(f2, 21.2);
	
	int m = maior(f2, f);
	printf("%i", m);
	*/
	
	// Quest�o 7
	/*
	exclui_negativo(&f);
	*/
	
	// Quest�o 8
	/*
	ordena_crescente(&f);
	
	Fila* f2 = cria_fila();
	
	insere_fila(f2, 1.0);
	insere_fila(f2, 2.8);
	insere_fila(f2, 3.2);
	
	Fila* f3 = cria_fila();
	
	combina_ordenado(f, f2, &f3);
	*/
	
	// Quest�o 9
	/*
	imprime(f);
	*/
	
	// Quest�o 12
	/*
	Fila* f2 = cria_fila();
	
	insere_fila(f2, 1.0);
	insere_fila(f2, 2.8);
	insere_fila(f2, 3.2);
	
	concatena(&f, &f2);
	
	imprime(f);
	printf("\n");
	imprime(f2);
	*/
	
	
	libera_fila(f);
	return 0;
}
