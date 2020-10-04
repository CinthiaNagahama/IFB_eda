/* ----------------------------------------------- Busca ----------------------------------------------- */

/* ------------------------------------------ Vetores Simples ------------------------------------------ */

// Busca Sequncial/Linear -> Para cada posi��o do array, o algoritmo compara se a posi��o atual do array 
//				   			 � igual ao valor buscado.
int buscaLinear(int *v, int tam, int elem);

// Busca Sequencial Ordenada -> Assume que os dados est�o ordenados. Se o elemento procurado for menor do 
// 								que o valor em uma determinada posi��o do array, temos a certeza de que ele 
//								n�o estar� no restante do array
int buscaOrdenada(int *v, int tam, int elem);

// Busca Bin�ria -> � uma estrat�gia baseada na id�ia de dividir para conquistar
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

/* --------------------------------------------- Ordena��o --------------------------------------------- */

// Bubble Sort -> Compara pares de valores adjacentes e os troca de lugar se estiverem na ordem errada. 
//				  Esse processo se repete at� que mais nenhuma troca seja necess�ria.
void bubbleSort(int *v, int tam);

// Selection Sort -> A cada passo ele seleciona o melhor elemento para ocupar aquela posi��o do array
void selectionSort(int *v, int tam);

// Insertion Sort -> O algoritmo percorre o array e para cada posi��o X verifica se o seu valor est� na 
//					 posi��o correta 
int insertionSort(int *v, int tam);

// Merge Sort -> O algoritmo divide os dados em conjuntos cada vez menores para depois orden�-los e 
//				 combinalos por meio de intercala��o (merge)

/*  intercala os dados de forma ordenada em um array maior */
void merge(int* v, int inicio, int meio, int fim);

/*  divide os dados em arrays cada vez menores */
void mergeSort(int *v, int inicio, int fim);

// Quick Sort -> Consiste em rearranjar o array usando um valor como piv�

/* divide os dados em arrays cada vez menores */
void quickSort(int *v, int inicio, int fim);

/* calcula o piv� e rearranja os dados */
int particiona(int *v, int inicio, int final);

// Counting Sort -> Usa um array auxiliar de tamanho igual ao maior valor a ser ordenado, K.
//					O array auxiliar � usado para contar quantas vezes cada valor ocorre.
// 					Valor a ser ordenado � tratado como �ndice.
//					Percorre o array auxiliar verificando quais valores existem e os coloca no array ordenado
#define K 100
void countingSort(int *v, int tam);

// Bucket Sort -> Algoritmo de ordena��o para valores inteiros. Usa um conjunto de K baldes para separar os
//	dados. A ordena��o dos valores � feita por balde
#define TAM 5
typedef struct balde Balde;
void bucketSort(int *v, int n);

// Heap Sort -> heap: vetor que simula uma �rvore bin�ria com exce��o do �ltimo n�vel
void heapSort(int *v, int n);

void criaHeap(int *v, int i, int f);

/* ------------------------------------------------ Lista ------------------------------------------------ */

// Quest�o 4 -> Escreva um algoritmo que receba valores em um vetor e imprima ORDENADO se o vetor estiver 
//				em ordem crescente
void ordenado(int* v, int tam);

// Quest�o 5 -> Escreva um algoritmo que ordene de maneira descrescente (do maior para o menor).
void selection_sort_decrescente(int *v, int tam);

// Quest�o 6 -> Escreva um algoritmo que receba um vetor ordenado e um n�mero extra e insira esse n�mero na 
//				sua posi��o correta no vetor ordenado, deslocando os outros n�meros se necess�rio
void insere_ordenado(int *v, int qtd, int tam, int num);

// Quest�o 7 -> Escreva um algoritmo que procure por um dado n�mero em vetor ordenado
/* Feita anteriormente (slide) */

// Quest�o 12 -> Dada a sequ�ncia de n�meros: -> Mexer nos prints
	//				 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1
	//				 ordene-a em ordem n�o decrescente segundo os seguintes algoritmos, apresentando a 
	// 				 sequ�ncia obtida ap�s cada passo do algoritmo:
	//	(a) MergeSort
	//	(b) QuickSort
	//	(c) HeapSort
void imprime(int *v, int ini, int fim);
	
// Quest�o 14 -> Uma ordena��o por contagem de um vetor x de tamanho n � executada da seguinte forma: 
// 				 declare um vetor count e defina count[i] como o n�mero de elementos menores que x[i]. 
//				 Em seguida, coloque x[i] na posi��o count[i] de um vetor de sa�da (leve em considera��o a
//				 possibilidade de elementos iguais). Escreva uma fun��o para ordenar um vetor x de tamanho 
//				 n usando esse metodo
/* Feita anteriormente (slide) */

// Quest�o 17 -> Fa�a um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a 
//				 ideia do algoritmo insertion sort. No final, o programa deve mostrar todos os nomes 
//  			 ordenados alfabeticamente
void insertion_sort_nomes(char (*nomes) [100], int qtd, int tam, char *nome);

// Quest�o 18 -> Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo 
//				 algoritmo bubble sort
void bubble_sort_palavra(char *str, int tam);

// Quest�o 19 -> Fa�a um programa que leia n nomes e ordene-os pelo tamanho utilizando o algoritmo 
//				 selection sort
void selection_sort_nomes(char (*str) [100], int tam);

// Quest�o 20 -> Crie um programa que dado uma string, coloque as letras dela em ordem decrescente usando o 
//				 algoritmo quick sort.
void quick_sort_palavra(char *palavra, int inicio, int fim);
int particiona_palavra(char *palavra, int inicio, int final);

// Quest�o 21 -> Considere a seguinte estrutura:
//						struct pessoa{
//						int Matricula;
//						char Nome[30];
//						float Nota;
// 					};
// 				 Fa�a uma fun��o que dado um array de tamanho N dessa estrutura, ordene o array pelo campo 
//				 escolhido pelo usu�rio.
typedef struct pessoa Pessoa;
void insertion_sort_matricula(Pessoa *p, int tam);
void insertion_sort_nome(Pessoa *p, int tam);
void ordena(Pessoa *p, int tam, int campo);
