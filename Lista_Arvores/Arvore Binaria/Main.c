#include <stdio.h>
#include "ArvoreBinaria.h"
#include "Fila.h"

int main(void){
	BinTree* tree = create_tree();
	insert(tree, 3); // *root
	insert(tree, 1);
	insert(tree, 5);
	insert(tree, 0); // folha
	insert(tree, 2); // folha
	insert(tree, 4); 
	insert(tree, 7); // folha
	insert(tree, 8); // folha
	
	// print_pre_tree(tree);
	
	// Quest�o 35
	/*
	printf("%i", _folhas(tree));
	*/
	
	// Quest�o 36
	/*
	printf("%i", _um_filho(tree));
	*/
	
	// Quest�o 37
	/*
	printf("%i", _primos(tree));
	*/
	
	// Quest�o 38
	/*
	printf("%i", _iguais(tree, tree2));
	*/
	
	// Quest�o 39
	/*
	_encontra_caminho(tree);
	*/
	
	// Quest�o 40
	/*
	_imprime_em_nivel(tree);
	*/
	
	// Quest�o 46
	/*
	printf("%i", _binaria(tree));
	*/
	
	// Quest�o 47
	/*
	BinTree* tree2 = create_tree();
	tree2 = _copia(tree);
	_imprime_em_nivel(tree2);
	*/
	
	// Quest�o 49
	/*
	printf("\n%i\n\n", _insere(tree, 3));
	print_pre_tree(tree);
	*/
	
	// Quest�o 58
	/*
	printf("%i", _encontra_menor(tree));
	*/
	
	// Quest�o 59
	/*
	_imprime_nivel(*tree, 2);
	*/
	
	// Quest�o 60
	/*
	printf("\nNumero de Divisores: %i", _divisores(tree));
	*/
	
	// Quest�o 62
	/*
	_vira_soma(tree);
	_imprime_em_nivel(tree);
	*/
	
	// Quest�o 64
	/*
	print_in_tree(tree, 0);
	printf("\n\n");
	Lista* arvore = _lista(tree);
	Imprime_Lista(arvore);
	*/
	
	// Quest�o 65
	/*
	printf("%i", _soma_impares(tree));
	*/
	
	// Quest�o 66
	/*
	printf("%i | %i", height(tree), _altura(tree));
	*/
	
	free_tree(tree);
	return 0;
}
