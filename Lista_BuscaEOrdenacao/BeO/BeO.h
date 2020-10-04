/* ----------------------------------------------- Busca ----------------------------------------------- */

/* ------------------------------------------ Vetores Simples ------------------------------------------ */

// Busca Sequncial/Linear -> Para cada posição do array, o algoritmo compara se a posição atual do array 
//				   			 é igual ao valor buscado.
int buscaLinear(int *v, int tam, int elem);

// Busca Sequencial Ordenada -> Assume que os dados estão ordenados. Se o elemento procurado for menor do 
// 								que o valor em uma determinada posição do array, temos a certeza de que ele 
//								não estará no restante do array
int buscaOrdenada(int *v, int tam, int elem);

// Busca Binária -> É uma estratégia baseada na idéia de dividir para conquistar
//					A cada passo, esse algoritmo analisa o valor do meio do array
int buscaBinaria(int *v, int tam, int elem);


/* --------------------------------------- Vetores de Estrutura --------------------------------------- */

typedef struct aluno Aluno;

struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};

int buscaLinearEstrutura(Aluno *v, int tam, int mat);

int buscaOrdenadaEstrutura(Aluno *v, int tam, int mat);

int buscaBinariaEstrutura(Aluno *v, int tam, int mat);

/* --------------------------------------------- Ordenação --------------------------------------------- */

// Bubble Sort -> Compara pares de valores adjacentes e os troca de lugar se estiverem na ordem errada. 
//				  Esse processo se repete até que mais nenhuma troca seja necessária.
void bubbleSort(int *v, int tam);

// Selection Sort -> A cada passo ele seleciona o melhor elemento para ocupar aquela posição do array
void selectionSort(int *v, int tam);

// Insertion Sort -> O algoritmo percorre o array e para cada posição X verifica se o seu valor está na 
//					 posição correta 
int insertionSort(int *v, int tam);

// Merge Sort -> O algoritmo divide os dados em conjuntos cada vez menores para depois ordená-los e 
//				 combinalos por meio de intercalação (merge)

/*  intercala os dados de forma ordenada em um array maior */
void merge(int* v, int inicio, int meio, int fim);

/*  divide os dados em arrays cada vez menores */
void mergeSort(int *v, int inicio, int fim);

// Quick Sort -> Consiste em rearranjar o array usando um valor como pivô

/* divide os dados em arrays cada vez menores */
void quickSort(int *v, int inicio, int fim);

/* calcula o pivô e rearranja os dados */
int particiona(int *v, int inicio, int final);

// Counting Sort -> Usa um array auxiliar de tamanho igual ao maior valor a ser ordenado, K.
//					O array auxiliar é usado para contar quantas vezes cada valor ocorre.
// 					Valor a ser ordenado é tratado como índice.
//					Percorre o array auxiliar verificando quais valores existem e os coloca no array ordenado
#define K 100
void countingSort(int *v, int tam);

// Bucket Sort -> Algoritmo de ordenação para valores inteiros. Usa um conjunto de K baldes para separar os
//	dados. A ordenação dos valores é feita por balde
#define TAM 5
typedef struct balde Balde;
void bucketSort(int *v, int n);

// Heap Sort -> heap: vetor que simula uma árvore binária com exceção do último nível
void heapSort(int *v, int n);

void criaHeap(int *v, int i, int f);

/* ------------------------------------------------ Lista ------------------------------------------------ */

// Questão 4 -> Escreva um algoritmo que receba valores em um vetor e imprima ORDENADO se o vetor estiver 
//				em ordem crescente
void ordenado(int* v, int tam);

// Questão 5 -> Escreva um algoritmo que ordene de maneira descrescente (do maior para o menor).
void selection_sort_decrescente(int *v, int tam);

// Questão 6 -> Escreva um algoritmo que receba um vetor ordenado e um número extra e insira esse número na 
//				sua posição correta no vetor ordenado, deslocando os outros números se necessário
void insere_ordenado(int *v, int qtd, int tam, int num);

// Questão 7 -> Escreva um algoritmo que procure por um dado número em vetor ordenado
/* Feita anteriormente (slide) */

// Questão 12 -> Dada a sequência de números: -> Mexer nos prints
	//				 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1
	//				 ordene-a em ordem não decrescente segundo os seguintes algoritmos, apresentando a 
	// 				 sequência obtida após cada passo do algoritmo:
	//	(a) MergeSort
	//	(b) QuickSort
	//	(c) HeapSort
void imprime(int *v, int ini, int fim);
	
// Questão 14 -> Uma ordenação por contagem de um vetor x de tamanho n é executada da seguinte forma: 
// 				 declare um vetor count e defina count[i] como o número de elementos menores que x[i]. 
//				 Em seguida, coloque x[i] na posição count[i] de um vetor de saída (leve em consideração a
//				 possibilidade de elementos iguais). Escreva uma função para ordenar um vetor x de tamanho 
//				 n usando esse metodo
/* Feita anteriormente (slide) */

// Questão 17 -> Faça um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a 
//				 ideia do algoritmo insertion sort. No final, o programa deve mostrar todos os nomes 
//  			 ordenados alfabeticamente
void insertion_sort_nomes(char (*nomes) [100], int qtd, int tam, char *nome);

// Questão 18 -> Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo 
//				 algoritmo bubble sort
void bubble_sort_palavra(char *str, int tam);

// Questão 19 -> Faça um programa que leia n nomes e ordene-os pelo tamanho utilizando o algoritmo 
//				 selection sort
void selection_sort_nomes(char (*str) [100], int tam);

// Questão 20 -> Crie um programa que dado uma string, coloque as letras dela em ordem decrescente usando o 
//				 algoritmo quick sort.
void quick_sort_palavra(char *palavra, int inicio, int fim);
int particiona_palavra(char *palavra, int inicio, int final);

// Questão 21 -> Considere a seguinte estrutura:
//						struct pessoa{
//						int Matricula;
//						char Nome[30];
//						float Nota;
// 					};
// 				 Faça uma função que dado um array de tamanho N dessa estrutura, ordene o array pelo campo 
//				 escolhido pelo usuário.
typedef struct pessoa Pessoa;
void insertion_sort_matricula(Pessoa *p, int tam);
void insertion_sort_nome(Pessoa *p, int tam);
void ordena(Pessoa *p, int tam, int campo);
