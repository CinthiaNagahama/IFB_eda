#include <stdio.h>
#include "BeO.h"

int main(void){
	/*
	int v[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	
	printf("Vetor Simples:\n%i", buscaLinear(v, 8, 2));
	printf("\n%i", buscaOrdenada(v, 8, 4));
	printf("\n%i", buscaBinaria(v, 8, 8));
	
	Aluno a[6];
	a[0].matricula = 000;
	a[1].matricula = 111;
	a[2].matricula = 222;
	a[3].matricula = 333;
	a[4].matricula = 444;
	a[5].matricula = 555;
	
	printf("\nVetor Estrutura:\n%i", buscaLinearEstrutura(a, 8, 000));
	printf("\n%i", buscaOrdenadaEstrutura(a, 8, 888));
	printf("\n%i", buscaBinariaEstrutura(a, 8, 222));
	*/
	
	// int i, v[10] = {2, 5, 55, 3, 5, 39, 67, 0};
	
	// bubbleSort(v, 8); -> okay
	// selectionSort(v, 8); -> okay
	// insertionSort(v, 8); -> okay
	// mergeSort(v, 0, 7); -> okay
	// quickSort(v, 0, 7); // -> okay
	// countingSort(v, 8); -> okay
	// bucketSort(v, 8); ->okay
	// heapSort(v, 8); -> okay
	
	// Questão 4
	/*
	ordenado(v, 8);
	*/
	
	// Questão 5
	/*
	selection_sort_decrescente(v, 8);
	*/
	
	// Questão 6
	/*
	for(i = 0; i < 8; i++) printf("%i ", v[i]);
	
	insere_ordenado(v, 8, 10, 70); // Buscando posição -> okay

	for(i = 0; i < 9; i++) printf("%i ", v[i]);	
	*/
	
	// Questão 8 -> Qual é o vetor resultante após as 4 primeiras trocas ao executar ordenação por seleção 
	// 				com o seguinte array inicial? 
	/*
	int vetor[] = {9, 7, 8, 1, 2, 0, 4};
	selectionSort(vetor, 7);
	*/
	
	// Questão 9 -> Implemente o algoritmo de ordenação por inserção visto em aula e conte o número total de
	// 				cópias de valores do vetor dentro do while ao executar no seguinte array:
	/*
	int vetor[] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};
	int copias = insertionSort(vetor, 10);
	printf("%i", copias);
	*/
	
	// Questão 10 -> Escreva o vetor resultante ao aplicar o algoritmo de particionamento em duas partes no
	// 				 vetor seguinte: 26 65 45 73 10 18 78 93 70 49 23 22
	/*
	int vetor[] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
	quickSort(vetor, 0, 11);
	for(i = 0; i < 12; i++) printf("%i ", vetor[i]);
	*/
	
	// Questão 12 -> Dada a sequência de números: 
	//				 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1
	//				 ordene-a em ordem não decrescente segundo os seguintes algoritmos, apresentando a 
	// 				 sequência obtida após cada passo do algoritmo:
	//	(a) MergeSort
	//	(b) QuickSort
	//	(c) HeapSort
	/*
	int vetor[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
	imprime(vetor, 0, 15);
	// mergeSort(vetor, 0, 15);
	// quickSort(vetor, 0, 15);
	// heapSort(vetor, 16);
	imprime(vetor, 0, 15);
	*/
	
	// Questão 17
	/*
	int tam = 10, qtd = 0;
	char nomes[10][100] = {};
	char nome[100];
	printf("Insira um nome. (Digite $ para sair)");
	scanf("%s", &nome);
	while(nome[0] != '$' && qtd <= tam){
		insertion_sort_nomes(nomes, qtd, tam, nome);
		qtd++;
		printf("\nInsira um nome. (Digite $ para sair)");
		scanf("%s", &nome);
	}
	int i;
	for(i = 0; i < qtd; i++){
		printf("%s ", nomes[i]);
	}
	*/
	
	// Questão 18
	/*
	char palavra[] = "Testando";
	bubble_sort_palavra(palavra, 8);
	printf("%s", palavra);
	*/
	
	// Questão 19
	/*
	char nomes[8][100] = {"Eduardo", "Alice", "Bruno", "Bianca", "Rafael", "Zuri", "Xavier", "Ronia"};
	selection_sort_nomes(nomes, 8);
	int i;
	
	printf("\n");
	for(i = 0; i < 8; i++){
		printf("%s ", nomes[i]);
	}
	*/
	
	// Questão 20
	
	char palavra[] = "Aleluia";
	quick_sort_palavra(palavra, 0, 6);
	printf("%s", palavra);
	
	
	
	return 0;
}
