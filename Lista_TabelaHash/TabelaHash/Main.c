#include <stdio.h>
#include <locale.h>
#include "TabelaHash.h"

int main(void){
	setlocale(LC_ALL, "Portuguese");
	Hash *h = cria_hash(1427); // Ideal: TABLE_SIZE == número primo && TABLE_SIZE != potência de 2
	
	// printf(insere_sem_colisao(h, a)?"Aluno inserido com sucesso.":"Ocorreu um erro na inserção do aluno.");
	// printf(busca_sem_colisao(h, hmat, &a)?"Busca efetuada com sucesso.":"Ocorreu um erro na busca.");
	
	libera_hash(h);
	return 0;
}
