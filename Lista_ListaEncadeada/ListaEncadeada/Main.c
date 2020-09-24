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
	
	
    
	// C�digos de Teste
    //	Quest�o 6
    
    /* 
	Elemento* lista3 = Concatena(lista, lista2);
    printf("\nLista3: ");
    Imprime_Lista(lista3);
    */
    
    // Quest�o 7
    
	/*
	int retira = Retira_N(&lista, 1);
	printf("\n%d Lista p�s-retirada: ", retira);
    Imprime_Lista(lista);
    */
    
    // Quest�o 8
    /*
    int posicao, maiorValor;
    int busca = Busca_Maior(lista, &posicao, &maiorValor);
    printf("\n%d | %d | %d", busca, posicao, maiorValor);
	*/
	
	// Quest�o 9
	/*
	int troca = Troca_Posicao(lista, 1, 3);
	printf("\n%d Lista p�s-troca: ", troca);
    Imprime_Lista(lista);
    */
    
    // Quest�o 11
    /*
    int pares = Conta_Pares(lista);
	printf("%d", pares);
	*/
	
	// Quest�o 12
	/*
	Elemento* pares = Apenas_Pares(lista);
    Imprime_Lista(pares);
    */
    
    // Quest�o 13
    /*
    float media = Media(lista);
	printf("%f", media);
	*/
	
	// Quest�o 15
	/*
	int ordenada = Is_Ordenada(lista);
    printf("%d", ordenada);
    */
    
    // Questa� 16
    /*
    printf("\nL2: ");
    Elemento* copia = Copia(lista);
    Imprime_Lista(copia);
    */
    
    // Quest�o 17
    /*
    Elemento* copia = Copia_Sem_Repeticao(lista);
    printf("\n\n\nL2: ");
    Imprime_Lista(copia);
    */
    
    // Quest�o 18
    /*
    printf("Lista2: ");
	Elemento* lista2 = Copia_Invertido(lista);
	Imprime_Lista(lista2);
	*/
	
	// Quest�o 19
	/*
	Elemento* merge = Merge(lista2, lista);
    Imprime_Lista(merge);
    */
    
    // Quest�o 20
    /*
    Elemento* sub = Retorna_Sublista(lista, 0);
    Imprime_Lista(sub);
    */
    
    // Quest�o 21
    /*
    int vector[] = {11, 22, 33,44, 55};
    Elemento* lst = Para_Lista(vector, 5);
    Imprime_Lista(lst);
    */
    
    // Quest�o 22
    /*
    int *vector = Para_Vetor(lista);
    int i;
    for(i = 0; i < 3; i++){
    	printf("\n%d", vector[i]);
	}
    free(vector);
    */
    
    // Quest�o 25 
    /*
    Inverte(&lista);
    Imprime_Lista(lista);
    */
    
    // Quest�o 26
    /*
    Elemento* lista3 = UNION(lista, lista2);
	Imprime_Lista(lista3);
	*/
	
	// Quest�o 27
	/*
	Elemento* L3 = INTER(lista, lista2);
	Imprime_Lista(L3);
	*/
	
	// Quest�o 28
	/*
	Remove(&lista, 1);
    Imprime_Lista(lista);
    */
    
    // Quest�o 29
	/*
	int qtd = Conta_Nos_Recursivo(lista, qtd);
	printf("%d", qtd);
    */
    
    // Quest�o 33
    /*
    Ordena_Crescente(&lista);
	printf("Lista: ");
    Imprime_Lista(lista); 
    */
    
    // Quest�o 34
    /*
    Elemento *par, *impar;
   	Separa_Lista(lista, &par, &impar);
   	printf("Par: \n");
   	Imprime_Recursiva(par);
   	printf("Impar: \n");
   	Imprime_Recursiva(impar);
   	*/
   	
   	// Quest�o 35
	/*
	Elemento* lista3 = Intercala(lista2, lista);
	printf("\nLista 3: ");
	Imprime_Recursiva(lista3);
	*/
   	
   	// Quest�o 39
   	/*
   	lista = Retira_K(lista, 3);
	printf("\nLista: \n");
	Imprime_Recursiva(lista);
	*/
	
	// Quest�o 40
	/*
	int count = Conta_Nos(lista);
	printf("%d", count);
	*/
	
	// Quest�o 42
	/*
	int e = Is_Maior(lista, 18);
	printf("%d", e);
	*/
	
	// Quest�o 43
	/*
	int soma = Somatorio(lista);
    printf("%d", soma);
    */
	
	// Quest�o 44
	/*
	int primos = Conta_Primos(lista);
    printf("%d", primos);
    */
	
    Libera(lista);
	// Libera(lista2);
    return 0;
}
