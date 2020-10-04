#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "BeO.h"

/* ----------------------------------------------- Busca ----------------------------------------------- */

/* ------------------------------------------ Vetores Simples ------------------------------------------ */

// Busca Linear -> Para cada posi��o do array, o algoritmo compara se a posi��o atual do array � igual ao 
//				   valor buscado.
int buscaLinear (int *v, int tam, int elem){
	int i;
	for (i = 0; i < tam; i++){
		if(elem == v[i]) return i; // Elemento encontrado -> Retorna posi��o
	}
	return -1; // Elemento n�o encontrado
}

// Busca Sequencial Ordenada -> Assume que os dados est�o ordenados. Se o elemento procurado for menor do 
// 								que o valor em uma determinada posi��o do array, temos a certeza de que ele 
//								n�o estar� no restante do array
int buscaOrdenada(int *v, int tam, int elem){
	int i;
	for(i = 0; i < tam; i++){
		if(elem == v[i]) return i; // Elemento encontrado
		
		else if(elem < v[i]) return -1; // Para a busca
	}
	return -1;
}

// Busca Bin�ria -> � uma estrat�gia baseada na id�ia de dividir para conquistar
//					A cada passo, esse algoritmo analisa o valor do meio do array
int buscaBinaria(int *v, int tam, int elem){
	int i, inicio = 0, meio, fim = tam - 1;
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		
		if(elem < v[meio]) fim = meio - 1;
		
		else if(elem > v[meio]) inicio = meio + 1;
		
		else return meio;
	}
	return -1;
}

/* --------------------------------------- Vetores de Estrutura --------------------------------------- */

// Busca Sequncial/Linear -> Para cada posi��o do array, o algoritmo compara se a posi��o atual do array 
//				   			 � igual ao valor buscado.
int buscaLinearEstrutura(Aluno *v, int tam, int mat){
	int i;
	for (i = 0; i < tam; i++){
		if(mat == v[i].matricula) return i; // Elemento encontrado -> Retorna posi��o
	}
	return -1; // Elemento n�o encontrado
}

/* Busca pelo nome - N�o esquecer de importar <string.h>
int buscaLinearEstrutura(Aluno *v, int tam, char* nome){
	int i;
	for (i = 0; i < tam; i++){
		if(strcmp(nome, v[i].nome) == 0) return i; // Elemento encontrado -> Retorna posi��o
	}
	return -1; // Elemento n�o encontrado
}
*/

// Busca Sequencial Ordenada -> Assume que os dados est�o ordenados. Se o elemento procurado for menor do 
// 								que o valor em uma determinada posi��o do array, temos a certeza de que ele 
//								n�o estar� no restante do array
int buscaOrdenadaEstrutura(Aluno *v, int tam, int mat){
	int i;
	for(i = 0; i < tam; i++){
		if(mat == v[i].matricula) return i; // Elemento encontrado
		
		else if(mat < v[i].matricula) return -1; // Para a busca
	}
	return -1;
}

// Busca Bin�ria -> � uma estrat�gia baseada na id�ia de dividir para conquistar
//					A cada passo, esse algoritmo analisa o valor do meio do array
int buscaBinariaEstrutura(Aluno *v, int tam, int mat){
	int i, inicio = 0, meio, fim = tam - 1;
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		
		if(mat < v[meio].matricula) fim = meio - 1;
		
		else if(mat > v[meio].matricula) inicio = meio + 1;
		
		else return meio;
	}
	return -1;
}

/* --------------------------------------------- Ordena��o --------------------------------------------- */

// Bubble Sort -> Compara pares de valores adjacentes e os troca de lugar se estiverem na ordem errada. 
//				  Esse processo se repete at� que mais nenhuma troca seja necess�ria.
void bubbleSort(int*v, int tam){
	int i, continua, aux, fim = tam - 1;
	do{
		continua = 0;
		for(i = 0; i < fim; i++){
			if(v[i] > v[i+1]){
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				continua = i;
			}
		}
		fim--;
	} while(continua != 0);
}

// Selection Sort -> A cada passo ele seleciona o melhor elemento para ocupar aquela posi��o do array
void selectionSort(int *v, int tam){
	int i, j, k, menor, troca;
	for(i = 0; i < tam-1; i++){
		menor = i;
		for(j = i + 1; j < tam; j++){
			if(v[j] < v[menor]) menor = j;
		}
		if(i != menor){
			troca = v[i];
			v[i] = v[menor];
			v[menor] = troca;
		}
		/* Quest�o 8
		printf("\ntroca: %i\n", i);
		for(k = 0; k < tam; k++) printf("%i ", v[k]);
		*/
	}
}

// Insertion Sort -> O algoritmo percorre o array e para cada posi��o X verifica se o seu valor est� na 
//					 posi��o correta 
int insertionSort(int *v, int tam){
	int i, j, aux, count = 0;
	for(i = 1; i < tam; i++){
		aux = v[i];
		for(j = i; (j > 0) && (aux < v[j - 1]); j--)
			v[j] = v[j - 1];
			count++;
		v[j] = aux;
		count++;
	}
	return count;
}

// Merge Sort -> O algoritmo divide os dados em conjuntos cada vez menores para depois orden�-los e 
//				 combinalos por meio de intercala��o (merge)

/*  intercala os dados de forma ordenada em um array maior */
void merge(int* v, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	
	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio + 1;
	temp = (int*) malloc(tamanho*sizeof(int));
	
	if(temp != NULL){
		for(i = 0; i < tamanho; i++){
			if(!fim1 && !fim2){
				if(v[p1] < v[p2]) 
					temp[i] = v[p1++];
				else 
					temp[i] = v[p2++];
					
				if(p1 > meio) fim1 = 1;
				if(p2 > fim) fim2 = 1;
			}
			else {
				if(!fim1)
					temp[i] = v[p1++];
				else
					temp[i] = v[p2++];
			}
		}
		for(j = 0, k = inicio; j < tamanho; j++, k++){
			v[k] = temp[j];
		}
	}
	free(temp);
}

/*  divide os dados em arrays cada vez menores */
void mergeSort(int *v, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = floor((inicio + fim) / 2);
		
		mergeSort(v, inicio, meio);
		printf("\nmergeSort esquerda:");
		imprime(v, inicio, meio);
		
		mergeSort(v, meio + 1, fim);
		printf("\nmergeSort direita:");
		imprime(v, meio + 1, fim);
		
		merge(v, inicio, meio, fim);
		printf("\nmerge:");
		imprime(v, inicio, fim);
	}
}

// Quick Sort -> Consiste em rearranjar o array usando um valor como piv�

/* divide os dados em arrays cada vez menores */
void quickSort(int *v, int inicio, int fim){
	int pivo;
	if(fim > inicio){
		pivo = particiona(v, inicio, fim);
		printf("\n\npivo: %i\nparticiona:", v[pivo]);
		imprime(v, inicio, fim);
		
		quickSort(v, inicio, pivo - 1);
		printf("\nquickSort esquerda:");
		imprime(v, inicio, pivo - 1);
		
		quickSort(v, pivo + 1, fim);
		printf("\nquickSort direita:");
		imprime(v, pivo + 1, fim);
	}
}

/* calcula o piv� e rearranja os dados */
int particiona(int *v, int inicio, int final){
	int esq = inicio, dir = final, pivo = v[inicio], aux;
	while(esq < dir){
		while(esq <= final && v[esq] <= pivo)
			esq++;
			
		while(dir >= 0 && v[dir] > pivo)
			dir--;
		
		if(esq < dir){
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}
	v[inicio] = v[dir];
	v[dir] = pivo;
	return dir;
}

// Counting Sort -> Usa um array auxiliar de tamanho igual ao maior valor a ser ordenado, K.
//					O array auxiliar � usado para contar quantas vezes cada valor ocorre.
// 					Valor a ser ordenado � tratado como �ndice.
//					Percorre o array auxiliar verificando quais valores existem e os coloca no array ordenado
void countingSort(int *v, int tam){
	int i, j, k;
	int baldes[K];
	
	for(i = 0; i < K; i++)
		baldes[i] = 0;
		
	for(i = 0; i < tam; i++)
		baldes[v[i]]++;
	
	for(i = 0, j = 0; j < K; j++)
		for(k = baldes[j]; k > 0; k--)
			v[i++] = j;		
}

// Bucket Sort -> Algoritmo de ordena��o para valores inteiros. Usa um conjunto de K baldes para separar os
//	dados. A ordena��o dos valores � feita por balde
struct balde{
	int qtd;
	int valores[TAM];
};

void bucketSort(int *v, int n){
	int i, j, maior, menor, nBaldes, pos;
	Balde *balde;
	
	maior = menor = v[0];
	for(i = 1; i < n; i++){
		if(v[i] > maior) maior = v[i];
		if(v[i] < menor) menor = v[i];
	}
	
	nBaldes = (maior - menor) / TAM + 1;
	balde = (Balde*) malloc(nBaldes * sizeof(Balde));
	for(i = 0; i < nBaldes; i++)
		balde[i].qtd = 0;
		
	for(i = 0; i < n; i++){
		pos = (v[i] - menor) / TAM;
		balde[pos].valores[balde[pos].qtd] = v[i];
		balde[pos].qtd++;
	}
	
	pos = 0;
	for(i = 0; i < nBaldes; i++){
		insertionSort(balde[i].valores, balde[i].qtd);
		for(j = 0; j < balde[i].qtd; j++){
			v[pos] = balde[i].valores[j];
			pos++;
		}
	}
	free(balde);
}

// Heap Sort -> heap: vetor que simula uma �rvore bin�ria com exce��o do �ltimo n�vel
void heapSort(int *v, int n){
	int i, aux;
	for(i = (n - 1) / 2; i >= 0; i--){
		criaHeap(v, i, n - 1);
		printf("\nVetor auxiliar: ");
		imprime(v, i, n - 1);
	}
	printf("\n\n");
	for(i = n - 1; i >= 1; i--){
		aux = v[0];
		v[0] = v[i];
		v[i] = aux;
		criaHeap(v, 0, i - 1);
		printf("\nInsere o pai no vetor: ");
		imprime(v, 0, i - 1);
	}
}

void criaHeap(int *v, int i, int f){
	int aux = v[i];
	int j = i * 2 + 1;
	
	while(j <= f){
		if(j < f){
			if(v[j] < v[j + 1]){
				j += 1;
			}
		}
		if(aux < v[j]){
			v[i] = v[j];
			i = j;
			j = 2 * i + 1;
		}
		else{
			j = f + 1;
		}
	}
	v[i] = aux;
}

/* ------------------------------------------------ Lista ------------------------------------------------ */

// Quest�o 4 -> Escreva um algoritmo que receba valores em um vetor e imprima ORDENADO se o vetor estiver 
//				em ordem crescente
void ordenado(int* v, int tam){
	int i;
	for(i = 0; i < tam - 1; i++){
		if(v[i] > v[i + 1]) return ;
	}
	printf("\nORDENADO\n");
}

// Quest�o 5 -> Escreva um algoritmo que ordene de maneira descrescente (do maior para o menor).
void selection_sort_decrescente(int *v, int tam){
	int i, j, maior, troca;
	for(i = 0; i < tam-1; i++){
		maior = i;
		for(j = i + 1; j < tam; j++){
			if(v[j] > v[maior]) maior = j;
		}
		if(i != maior){
			troca = v[i];
			v[i] = v[maior];
			v[maior] = troca;
		}
	}
}

// Quest�o 6 -> Escreva um algoritmo que receba um vetor ordenado e um n�mero extra e insira esse n�mero na 
//				sua posi��o correta no vetor ordenado, deslocando os outros n�meros se necess�rio
void insere_ordenado(int *v, int qtd, int tam, int num){
	if(qtd == tam) return ;
	
	if(qtd == 0){
		v[0] = num;
		return ;
	}
	
	int i = 0, pos = -1;
	while ((i < tam) && (pos == -1)){
		if (num == v[i]) pos = i;
		else if (v[i] < num) i++;
		else pos = i;
	}
	
	if(pos == -1){
		v[qtd] = num;
		return ;
	}
	
	int ant = v[i], prox;
	v[i] = num;
	for(i = pos; i < tam - 1; i++){
		prox = v[i + 1];
		v[i + 1] = ant;
		ant = prox;
	}
}

// Quest�o 7 -> Escreva um algoritmo que procure por um dado n�mero em vetor ordenado
/* Feita anteriormente (slide) */

// Quest�o 12 -> Dada a sequ�ncia de n�meros: -> Mexer nos prints
	//				 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1
	//				 ordene-a em ordem n�o decrescente segundo os seguintes algoritmos, apresentando a 
	// 				 sequ�ncia obtida ap�s cada passo do algoritmo:
	//	(a) MergeSort
	//	(b) QuickSort
	//	(c) HeapSort
void imprime(int *v, int ini, int fim){
	int i;
	printf("\n");
	for(i = ini; i <= fim; i++){
		printf("%i ", v[i]);
	}
}

// Quest�o 17 -> Fa�a um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a 
//				 ideia do algoritmo insertion sort. No final, o programa deve mostrar todos os nomes 
//  			 ordenados alfabeticamente
void insertion_sort_nomes(char (*nomes) [100], int qtd, int tam, char *nome){
	if(qtd == tam){
		printf("Lista cheia");
		return ;
	}
	
	if(qtd == 0){
		strcpy(nomes[0], nome);
		return ;
	}

	int i, j;
	char aux[100];
	for(i = 1; i < qtd; i++){
		strcpy(aux, nomes[i]);	
		for(j = i; (j > 0) && (strcmp(aux, nomes[j - 1]) < 0); j--)
			strcpy(nomes[j], nomes[j - 1]);
		strcpy(nomes[j], aux);
	}

	strcpy(aux, nome);	
	for(j = i; (j > 0) && (strcmp(aux, nomes[j - 1]) < 0); j--)
		strcpy(nomes[j], nomes[j - 1]);
	strcpy(nomes[j], aux);
}

// Quest�o 18 -> Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo 
//				 algoritmo bubble sort
void bubble_sort_palavra(char *str, int tam){
	int i, continua, fim = tam - 1;
	char aux;
	do{
		continua = 0;
		for(i = 0; i < fim; i++){
			if(tolower(str[i]) > tolower(str[i+1])){
				aux = str[i];
				str[i] = str[i + 1];
				str[i + 1] = aux;
				continua = i;
			}
		}
		fim--;
	} while(continua != 0);
}

// Quest�o 19 -> Fa�a um programa que leia n nomes e ordene-os pelo tamanho utilizando o algoritmo 
//				 selection sort
void selection_sort_nomes(char (*str) [100], int tam){
	int i, j, k, menor;
	char troca[100];

	for(i = 0; i < tam - 1; i++){
		menor = i;
		for(j = i + 1; j < tam; j++){
			if(strcmp(str[j], str[menor]) < 0) menor = j;
		}
		if(i != menor){
			strcpy(troca, str[i]);
			strcpy(str[i], str[menor]);
			strcpy(str[menor], troca);
		}
	}
}

// Quest�o 20 -> Crie um programa que dado uma string, coloque as letras dela em ordem decrescente usando o 
//				 algoritmo quick sort.

void quick_sort_palavra(char *palavra, int inicio, int fim){
	int pivo;
	if(fim > inicio){
		pivo = particiona_palavra(palavra, inicio, fim);
		quick_sort_palavra(palavra, inicio, pivo - 1);
		quick_sort_palavra(palavra, pivo + 1, fim);
	}
}

int particiona_palavra(char *palavra, int inicio, int final){
	int esq = inicio, dir = final;
	char pivo = palavra[inicio], aux;
	while(esq < dir){
		while(esq <= final && tolower(palavra[esq]) <= tolower(pivo))
			esq++;
			
		while(dir >= 0 && tolower(palavra[dir]) > tolower(pivo))
			dir--;
		
		if(esq < dir){
			aux = palavra[esq];
			palavra[esq] = palavra[dir];
			palavra[dir] = aux;
		}
	}
	palavra[inicio] = palavra[dir];
	palavra[dir] = pivo;
	return dir;
}


// Quest�o 21 -> Considere a seguinte estrutura:
struct pessoa{
	int Matricula;
	char Nome[30];
	float Nota;
};
// 				 Fa�a uma fun��o que dado um array de tamanho N dessa estrutura, ordene o array pelo campo 
//				 escolhido pelo usu�rio.
void insertion_sort_matricula(Pessoa *p, int tam){
	int i, j;
	Pessoa aux;
	for(i = 1; i < tam; i++){
		aux = p[i];
		for(j = i; (j > 0) && (aux.Matricula < p[j - 1].Matricula); j--)
			p[j] = p[j - 1];
		p[j] = aux;
	}
}

void insertion_sort_nome(Pessoa *p, int tam){
	int i, j;
	Pessoa aux;
	for(i = 1; i < tam; i++){
		aux = p[i];
		for(j = i; (j > 0) && (strcmp(aux.Nome, p[j - 1].Nome) < 0); j--)
			p[j] = p[j - 1];
		p[j] = aux;
	}
}

void ordena(Pessoa *p, int tam, int campo){
	if(campo == 1) insertion_sort_matricula(p, tam);
	if(campo == 2) insertion_sort_nome(p, tam);
	else printf("Campo n�o reconhecido.\nDigite:\n\t1 -> Para matr�cula\n\t2 -> Para nome");
}
