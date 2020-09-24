#include <locale.h>
#include "ListaEncadeada.h"

int main(void){
	setlocale(LC_ALL, "");
		
	Elemento* lista = Cria_Lista();
    lista = Insere_Valor(lista, 5);
	lista = Insere_Valor(lista, 4);
	lista = Insere_Valor(lista, 3);
    lista = Insere_Valor(lista, 2);
	lista = Insere_Valor(lista, 1);
	lista = Insere_Valor(lista, 0);

    
	printf("Lista: ");
    Imprime_Lista(lista);    
    
    int primos = Conta_Primos(lista);
    printf("%d", primos);
	
    
//	Elemento* lista2 = Cria_Lista();
//  	lista2 = Insere_Valor(lista2, 6);
//  	lista2 = Insere_Valor(lista2, 5);
//  	lista2 = Insere_Valor(lista2, 4);
//	
//	printf("\nLista2: ");
//	Imprime_Lista(lista2);
	
	
    
	// Códigos de Teste
    //	Questão 6
    
    /* 
	Elemento* lista3 = Concatena(lista, lista2);
    printf("\nLista3: ");
    Imprime_Lista(lista3);
    */
    
    // Questão 7
    
	/*
	int retira = Retira_N(&lista, 1);
	printf("\n%d Lista pós-retirada: ", retira);
    Imprime_Lista(lista);
    */
    
    // Questão 8
    /*
    int posicao, maiorValor;
    int busca = Busca_Maior(lista, &posicao, &maiorValor);
    printf("\n%d | %d | %d", busca, posicao, maiorValor);
	*/
	
	// Questão 9
	/*
	int troca = Troca_Posicao(lista, 1, 3);
	printf("\n%d Lista pós-troca: ", troca);
    Imprime_Lista(lista);
    */
    
    // Questão 11
    /*
    int pares = Conta_Pares(lista);
	printf("%d", pares);
	*/
	
	// Questão 12
	/*
	Elemento* pares = Apenas_Pares(lista);
    Imprime_Lista(pares);
    */
    
    // Questão 13
    /*
    float media = Media(lista);
	printf("%f", media);
	*/
	
	// Questão 15
	/*
	int ordenada = Is_Ordenada(lista);
    printf("%d", ordenada);
    */
    
    // Questaõ 16
    /*
    printf("\nL2: ");
    Elemento* copia = Copia(lista);
    Imprime_Lista(copia);
    */
    
    // Questão 17
    /*
    Elemento* copia = Copia_Sem_Repeticao(lista);
    printf("\n\n\nL2: ");
    Imprime_Lista(copia);
    */
    
    // Questão 18
    /*
    printf("Lista2: ");
	Elemento* lista2 = Copia_Invertido(lista);
	Imprime_Lista(lista2);
	*/
	
	// Questão 19
	/*
	Elemento* merge = Merge(lista2, lista);
    Imprime_Lista(merge);
    */
    
    // Questão 20
    /*
    Elemento* sub = Retorna_Sublista(lista, 0);
    Imprime_Lista(sub);
    */
    
    // Questão 21
    /*
    int vector[] = {11, 22, 33,44, 55};
    Elemento* lst = Para_Lista(vector, 5);
    Imprime_Lista(lst);
    */
    
    // Questão 22
    /*
    int *vector = Para_Vetor(lista);
    int i;
    for(i = 0; i < 3; i++){
    	printf("\n%d", vector[i]);
	}
    free(vector);
    */
    
    // Questão 25 
    /*
    Inverte(&lista);
    Imprime_Lista(lista);
    */
    
    // Questão 26
    /*
    Elemento* lista3 = UNION(lista, lista2);
	Imprime_Lista(lista3);
	*/
	
	// Questão 27
	/*
	Elemento* L3 = INTER(lista, lista2);
	Imprime_Lista(L3);
	*/
	
	// Questão 28
	/*
	Remove(&lista, 1);
    Imprime_Lista(lista);
    */
    
    // Questão 29
	/*
	int qtd = Conta_Nos_Recursivo(lista, qtd);
	printf("%d", qtd);
    */
    
    // Questão 33
    /*
    Ordena_Crescente(&lista);
	printf("Lista: ");
    Imprime_Lista(lista); 
    */
    
    // Questão 34
    /*
    Elemento *par, *impar;
   	Separa_Lista(lista, &par, &impar);
   	printf("Par: \n");
   	Imprime_Recursiva(par);
   	printf("Impar: \n");
   	Imprime_Recursiva(impar);
   	*/
   	
   	// Questão 35
	/*
	Elemento* lista3 = Intercala(lista2, lista);
	printf("\nLista 3: ");
	Imprime_Recursiva(lista3);
	*/
   	
   	// Questão 39
   	/*
   	lista = Retira_K(lista, 3);
	printf("\nLista: \n");
	Imprime_Recursiva(lista);
	*/
	
	// Questão 40
	/*
	int count = Conta_Nos(lista);
	printf("%d", count);
	*/
	
	// Questão 42
	/*
	int e = Is_Maior(lista, 18);
	printf("%d", e);
	*/
	
	// Questão 43
	/*
	int soma = Somatorio(lista);
    printf("%d", soma);
    */
	
	// Questão 44
	/*
	int primos = Conta_Primos(lista);
    printf("%d", primos);
    */
	
    Libera(lista);
	// Libera(lista2);
    return 0;
}
