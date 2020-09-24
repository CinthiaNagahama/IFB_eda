#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

// Define o tipo Elemento
struct elemento{
	int info;
	Elemento* prox;
};
 
// Cria uma lista vazia
Elemento* Cria_Lista(void){
	return NULL;
}

// Insere um valor ao in�cio da lista
Elemento* Insere_Valor(Elemento* lst, int valor){
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	novo->info = valor;
	novo->prox = lst;
	return novo;
}

// Imprime os valores da lista
void Imprime_Lista(Elemento* lst){
	Elemento* p;
	for(p = lst; p != NULL; p = p->prox){
		printf("\ninfo = %d", p->info);
	}
	printf("\n");
}

// Testa se uma lista � vazia - retorna 1 se a lista for vazio e 0 se a lista n�o for vazia
int Lista_Vazia(Elemento* lst){
	return(lst == NULL);
}

// Busca um elemento na lista - retorna o elemento se ele for encontrado, ou NULL caso o contr�rio
Elemento* Busca(Elemento* lst, int valor){
	Elemento* p;
	for(p = lst; p != NULL; p = p->prox){
		if(p->info == valor) return p;
	}
	printf("Valor n�o encontrado.");
	return NULL;
}

// Retira um elemento da lista
Elemento* Retira (Elemento* lst, int valor){
	Elemento* ant = NULL;
	Elemento* p = lst;
	
	// Busca o elemento a ser retirado enquanto guarda o elemento anterior
	while(p != NULL && p->info != valor){
		ant = p;
		p = p->prox;
	}
	
	// Elemento n�o encontrado
	if(p == NULL){
		printf("Elemento n�o encontrado");
		return lst;
	}
	// Elemento encontrado � o primeiro da lista
	if (ant == NULL){
		lst = p->prox;
	}
	// Elemento encontrado n�o � o primeiro da lista
	else{
		ant->prox = p->prox;
	}
	
	free(p);
	return lst;
}

// Libera a mem�ria alocada para a lista
void Libera(Elemento* lst){
	Elemento* p = lst;
	while(p != NULL){
		Elemento* aux = p->prox;
		free(p);
		p = aux;
	}
}

// Insere elemento em ordem crescente (a lista tamb�m deve estar ordenada em ordem crescente)
Elemento* Insere_Ordenado(Elemento* lst, int val){
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	novo->info = val;
	
	Elemento* ant = NULL;
	Elemento* p = lst;
	// Procura a posi��o de inser��o
	while (p != NULL && p->info < val){
		ant = p;
		p = p->prox;
	}
	// Encadeia o elemento na primeira posi��o
	if (ant == NULL){ 
		novo->prox = lst;
		lst = novo;
	}
	// Encadeia o elemento no meio da lista
	else{ 
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return lst;
}

// Verifica se duas listas s�o iguais
int Iguais(Elemento* lst1, Elemento* lst2){
	Elemento* p1;
	Elemento* p2;
	for(p1 = lst1, p2 = lst2; p1 != NULL, p2 != NULL; p1 = p1->prox, p2 = p2->prox){
		if(p1->info != p2->info) {
			free(p1);
			free(p2);
			return 0;
		}
	}
	free(p1);
	free(p2);
	return 1;
}

// Imprime a lista recursivamente
void Imprime_Recursiva(Elemento* lst){
	if(!Lista_Vazia(lst)){
		printf("info = %i\n", lst->info);
		Imprime_Recursiva(lst->prox);
	}
}

// Imprime a lista invertida recursivamente
void Imprime_Recursiva_Invertida(Elemento* lst){
	if(!Lista_Vazia(lst)){
		Imprime_Recursiva_Invertida(lst->prox);
		printf("info = %i\n", lst->info);
	}
}

// Retira um elemento em chamadas recursivas
Elemento* Retira_Recursiva(Elemento* lst, int val){
	if(!Lista_Vazia(lst)){
		if(lst->info == val){
			Elemento* t = lst;
			lst = lst->prox;
			free(t);
		}
		else{
			lst->prox = Retira_Recursiva(lst->prox, val);
		}
	}
	return lst;
}

// Verifica se duas listas s�o iguais recursivamente
int Iguais_Recursiva(Elemento* lst1, Elemento* lst2){
	if(lst1 == NULL && lst2 == NULL ) return 1;
	else if(lst1 == NULL || lst2 == NULL ) return 0;
	else{
		return ((lst1->info == lst2->info) && Iguais_Recursiva(lst1->prox, lst2->prox));
	}
}

// Quest�o 6 -> Fa�a uma fun��o para concatenar duas listas em uma terceira lista que
// 				dever� ser retornada pela fun��o.
Elemento* Concatena(Elemento* lst1, Elemento* lst2){
	if(lst1 == NULL && lst2 == NULL) return NULL;
	
	Elemento* p;
	Elemento* lst_concatenada = NULL;
	
	for(p = lst1; p != NULL; p = p->prox){
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = p->info;
		novo->prox = lst_concatenada;
		
		lst_concatenada = novo;	
	}
	
	for(p = lst2; p != NULL; p = p->prox){
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = p->info;
		novo->prox = lst_concatenada;
		
		lst_concatenada = novo;	
	}
	
	free(p);
	return lst_concatenada;
}

// Quest�o 7 -> Fa�a uma fun��o para remover os n primeiro elementos de uma lista.
int Retira_N(Elemento** lst, int n){
	if((*lst) == NULL) {
		printf("\nError: Empty list.\n");
		return 0;
	}
	else{
		Elemento* p = (*lst);
		int len;
		for(len = 0; len < n; len++, p = p->prox){
			if(p == NULL){
				printf("\nError: List index out of range.\n");
				return 0;
			}
		}
		
		p = (*lst);
		for(len = 0; len < n; len++, p = p->prox){
			(*lst) = p->prox;
		}
		return 1;
	}
}

// Quest�o 8 -> Fa�a uma fun��o para buscar a posi��o e o valor do maior elemento da lista
int Busca_Maior(Elemento* lst, int *pos, int *maior){
	if(lst == NULL){
		printf("Lista vazia.");
		return 0;
	} 
	Elemento* p = lst;
	int count = 0;
	*maior = p->info;
	
	for(; p != NULL; p = p->prox, count++){
		if(p->info > *maior){
			*maior = p->info;
			*pos = count;
		}
	}
	return 1;
}

// Quest�o 9 -> Fa�a uma fun��o para trocar de posi��o dois elementos de uma lista.
int Troca_Posicao(Elemento* lst, int val1, int val2){
	if(lst == NULL) return 0;
	if(val1 == val2) return 1;
	Elemento* p;
	Elemento* p2;
	for(p = lst; p != NULL; p = p->prox){
		if(p->info == val1){
			for(p2 = lst; p2 != NULL; p2 = p2->prox){
				if(p2->info == val2){
					p->info = p2->info;
					p2->info = val1;
					return 1;
				}
			}
		}
	}
}

// Quest�o 11 -> Considere uma lista contendo n�meros inteiros positivos. 
//				 Fa�a uma fun��o que retorne quantos n�meros pares existem na lista
int Conta_Pares(Elemento* lst){
	if(lst == NULL) return 0;
	int count = 0;
	Elemento* p;
	for(p = lst; p != NULL; p = p->prox){
		if(p->info % 2 == 0) count++;
	}
	return count;
}

// Quest�o 12 ->Considere uma lista contendo n�meros inteiros positivos.
// 				Fa�a uma fun��o que retorne uma nova lista contendo apenas os n�meros pares da lista
Elemento* Apenas_Pares(Elemento* lst){
	if(lst == NULL) return NULL;
	
	Elemento* par = NULL;
	Elemento* p;
	int count = 0;
	
	for(p = lst; p != NULL; p = p->prox){
		if(p->info % 2 == 0){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = par;
			
			par = novo;
		}
	}
	return par;
}

// Quest�o 13 -> Considere uma lista contendo n�meros inteiros positivos. 
// 				 Fa�a uma fun��o que retorne a m�dia da lista.
float Media(Elemento* lst){
	if(lst == NULL) return 0;
	Elemento* p = lst;
	int count = 0;
	float media = 0;
	while(p != NULL){
		media += p->info;
		count++;
		p = p->prox;
	}
	return (media / count);
}

// Quest�o 15 -> Fazer uma fun��o para verificar se uma lista est� ordenada ou n�o
int Is_Ordenada(Elemento* lst){
	if(lst == NULL) return 0;
	Elemento* p = lst;
	int ant = p->info;
	int crescente = 0, decrescente = 0;
	for(p = p->prox; p != NULL; ant = p->info, p = p->prox){
		if(ant < p->info && decrescente == 0){
			crescente = 1;
		} 
		else if(ant > p->info && crescente == 0){
			decrescente = 1;
		} 
		else if (ant == p->info){
			continue;
		} 
		else {
			return 0;
		}
	}
	return 1;
}

// Quest�o 16 -> Fazer uma fun��o que copia uma lista L1 em outra lista L2
Elemento* Copia(Elemento* L1){	
	if(L1 != NULL){
		Elemento* L2 = (Copia(L1->prox));
		
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = L1->info;
		novo->prox = L2;			
		
		L2 = novo;
		return L2;
	}
	else return NULL;
}

// Quest�o 17 -> Fazer uma fun��o que copia uma lista L1 em outra L2, eliminando os elementos 
//				 repetidos.
Elemento* Copia_Sem_Repeticao(Elemento* L1){	
	if(L1->prox != NULL){ // Sen�o d� erro ao tentar comparar o �ltimo elemento com NULL
		Elemento* L2 = (Copia_Sem_Repeticao(L1->prox));
		if(L1->info != L2->info){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = L1->info;
			novo->prox = L2;			
		
			L2 = novo;
			return L2;
		}
		else return L2;
	}
	else if(L1 != NULL){
		Elemento* L2 = NULL;
		
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = L1->info;
		novo->prox = L2;			
		
		L2 = novo;	
		return L2;
	}
	else return NULL;
}

// Quest�o 18 -> Fazer uma fun��o para inverter uma lista L1 colocando o resultado em L2.
Elemento* Copia_Invertido(Elemento* L1){	
	if(L1 == NULL) return NULL;
	Elemento* p;
	Elemento* L2;
	for(p = L1; p != NULL; p = p->prox){
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = p->info;
		novo->prox = L2;
		
		L2 = novo;
	}
	return L2;
}

// Quest�o 19 -> Fazer uma fun��o que realiza o merge de duas listas ordenadas.
// A fun��o assume listas ordenadas n�o vazias ordenadas de forma crescente
Elemento* Merge(Elemento* lst, Elemento* lst2){
	Elemento* aux = NULL, *p, *p2;
	// Encontra o tamanho das listas
	int n = 0, m = 0;
	for (p = lst; p != NULL; p = p->prox){
		n++;
	}
	for (p2 = lst2; p2 != NULL; p2 = p2->prox){
		m++;
	}
	// Concatena em ordem
	int i, j; p = lst; p2 = lst2;
	for(i = 0; i < (n + m); i++){
		if(p == NULL){
			for(j = 0; j < (n + m - i); j++){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p2->info;
				novo->prox = aux;
		
				aux = novo;
				p2 = p2->prox;
			}
			// Inverte a lista auxiliar
			Elemento* merge = NULL;
			for(p = aux; p != NULL; p = p->prox){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p->info;
				novo->prox = merge;
		
				merge = novo;
			}
			return merge;
		}
		else if(p2 == NULL){
			for(j = 0; j < (n + m - i); j++){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p->info;
				novo->prox = aux;
		
				aux = novo;
				p = p->prox;
			}
			// Inverte a lista auxiliar
			Elemento* merge = NULL;
			for(p = aux; p != NULL; p = p->prox){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p->info;
				novo->prox = merge;
		
				merge = novo;
			}
			return merge;
		}
		else if(p->info < p2->info){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = aux;
		
			aux = novo;
			p = p->prox;
		}
		else if(p2->info < p->info){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p2->info;
			novo->prox = aux;
		
			aux = novo;
			p2 = p2->prox;
		}
	}
}

// Quest�o 20 -> Considerando listas de valores inteiros, implemente uma fun��o que receba como 
// 				 par�metro uma lista e um valor n e divida a lista em duas, de tal forma que a 
// 				 segunda lista come�a no primeiro n� ap�s o valor n.
Elemento* Retorna_Sublista(Elemento* lst, int n){
	if(lst == NULL) return NULL;
	
	Elemento *p = lst, *aux = NULL;
	int i;
	for(i = 0; i < n; i++){
		if(p == NULL) return NULL;
		p = p->prox;
	}
	for(; p != NULL; p = p->prox){
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
		novo->info = p->info;
		novo->prox = aux;
		
		aux = novo;
	}
	// Inverte a lista auxiliar
	Elemento* sublista = NULL;
	for(p = aux; p != NULL; p = p->prox){
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = p->info;
		novo->prox = sublista;
	
		sublista = novo;
	}

	free(p);
	return sublista;
}

// Quest�o 21 -> Escreva uma fun��o que crie uma lista encadeada a partir de um vetor
Elemento* Para_Lista(int* v, int tam){
	int i;
	Elemento* lst = NULL;
	
	for(i = tam - 1; i >= 0; i--){
		Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
		novo->info = v[i];
		novo->prox = lst;
		
		lst = novo;
	}
	return lst;
}

// Quest�o 22 -> Escreva uma fun��o que copie uma lista encadeada para um vetor.
int* Para_Vetor(Elemento* lst){
	int tam = 0, i;
	Elemento* p;
	for(p = lst; p != NULL; p = p->prox){
		tam++;
	}
	int *v = malloc(tam * sizeof(int));
	
	for(i = 0, p = lst; i < tam; i++, p = p->prox){
		v[i] = p->info;
	}
	return v;
}

// Quest�o 23 -> Escreva uma fun��o que concatena duas listas encadeadas e retorna um ponteiro
//				 para a lista concatenada. As listas originais nao devem ser alteradas.
/* Feita anteriormente (Id�ntica a quest�o 6)
Elemento* Concatena(Elemento* lst1, Elemento* lst2){
	if(lst1 == NULL && lst2 == NULL) return NULL;
	
	Elemento* p;
	Elemento* lst_concatenada = NULL;
	
	for(p = lst1; p != NULL; p = p->prox){
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = p->info;
		novo->prox = lst_concatenada;
		
		lst_concatenada = novo;	
	}
	
	for(p = lst2; p != NULL; p = p->prox){
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = p->info;
		novo->prox = lst_concatenada;
		
		lst_concatenada = novo;	
	}
	
	free(p);
	return lst_concatenada;
}
*/

// Quest�o 24 -> Escreva uma fun��o que verifica se duas listas dadas s�o iguais
/* Feita anteriormente (id�ntica ao slide)
int Iguais(Elemento* lst1, Elemento* lst2){
	Elemento* p1;
	Elemento* p2;
	for(p1 = lst1, p2 = lst2; p1 != NULL, p2 != NULL; p1 = p1->prox, p2 = p2->prox){
		if(p1->info != p2->info) {
			free(p1);
			free(p2);
			return 0;
		}
	}
	free(p1);
	free(p2);
	return 1;
}
*/

// Quest�o 25 -> Escreva uma fun��o que inverte a ordem das c�lulas de uma lista encadeada 
// 				 Fa�a isso sem usar espa�o auxiliar; apenas altere os ponteiros.
void Inverte(Elemento** lst){
    if (*lst == NULL) return;
    
    Elemento* atual; // Elemento atual
    Elemento* resto; // Restante da lista
    
    
    atual = *lst;
    resto = atual->prox;
    
    // Checa se chegou ao final da lista
    if (resto == NULL) return;

    Inverte(&resto);
	
    atual->prox->prox = atual; // Coloca o valor atual duas posi��es para a direita
    atual->prox = NULL; // Colocar NULL na posi��o seguinte
    *lst = resto; // Coloca o �ltimo n� na primeira posi��o
}

// Quest�o 26 -> Dadas duas listas encadeadas e dinamicas L1 e L2, implemente a opera��o UNION,
// 				 que cria uma terceira lista L3 com a uni�o entre as duas listas.
Elemento* UNION(Elemento* L1, Elemento* L2){
	if(L1 == NULL && L2 == NULL) return NULL;
	
	Elemento* p;
	Elemento* L3 = NULL;
	
	int repetido = 0;
	for(p = L1; p != NULL; p = p->prox){
		Elemento* aux = L3;
		for(; aux != NULL; aux = aux->prox){
			if(p->info == aux->info)repetido = 1;
		}
		if(repetido == 0){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = L3;
			
			L3 = novo;
		}
		repetido = 0;	
	}
	
	repetido = 0;
	for(p = L2; p != NULL; p = p->prox){
		Elemento* aux = L3;
		for(; aux != NULL; aux = aux->prox){
			if(p->info == aux->info)repetido = 1;
		}
		if(repetido == 0){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = L3;

			L3 = novo;	
		}
		repetido = 0;
	}
	
	free(p);
	return L3;
}

// Quest�o 27 -> Dadas duas listas encadeadas e dinamicas L1 e L2, s�m elementos repetidos, implemente
// 				 a opera��o INTER, que cria uma terceira lista L3 com a intersec��ao entre as duas
// 				 listas, tambem sem elementos repetidos 
Elemento* INTER(Elemento* L1, Elemento* L2){
	if(L1 == NULL && L2 == NULL) return NULL;
	
	Elemento* p, *p2;
	Elemento* L3 = NULL;
	
	for(p = L1; p != NULL; p = p->prox){
		for(p2 = L2; p2 != NULL; p2 = p2->prox){
			if(p->info == p2->info){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p->info;
				novo->prox = L3;
				
				L3 = novo;
			}
		}
	}
	return L3;
}

// Quest�o 28 -> Seja uma lista din�mica e encadeada com elementos repetidos, implemente uma rotina 
// 				 para eliminar todos as ocorrencias de X da lista.
void Remove(Elemento** lst, int x){
	Elemento* i = *lst;
	int ePrimeiro = 0;
	
	for(; i != NULL; i = i->prox, ePrimeiro++){
		Elemento* ant = NULL;
		Elemento* p = *lst;
		
		// Checa se x � o primeiro da lista
		if (ePrimeiro == 0 && p->info == x){
			*lst = p->prox;
		}
		
		// Busca x em outras posi��es
		else{
			while(p != NULL){
				ant = p;
				p = p->prox;
				if(p != NULL && p->info == x){
					ant->prox = p->prox;
					break;
				}
			}
		}
	}
}

// Quest�o 29 -> Implemente uma rotina recursiva para calcular o tamanho de uma lista dinamica e encadeada.
int Conta_Nos_Recursivo(Elemento* lst, int count){
	if(lst != NULL){
		count++;
		Conta_Nos_Recursivo(lst->prox, count);
	}
	else{
		return count;
	}
}

// Quest�o 30 -> Implemente uma fun��o n�o recursiva para verificar se duas listas din�micas e encadeadas sao iguais.
/* Feita anteriormente (Id�ntica ao slide)
int Iguais(Elemento* lst1, Elemento* lst2){
	Elemento* p1;
	Elemento* p2;
	for(p1 = lst1, p2 = lst2; p1 != NULL, p2 != NULL; p1 = p1->prox, p2 = p2->prox){
		if(p1->info != p2->info) {
			free(p1);
			free(p2);
			return 0;
		}
	}
	free(p1);
	free(p2);
	return 1;
}
*/

// Quest�o 31 -> Implemente uma fun��o recursiva para verificar se duas listas din�micas e encadeadas s�o iguais.
/* Feita anteriormente (Id�ntica ao slide)
int Iguais_Recursiva(Elemento* lst1, Elemento* lst2){
	if(lst1 == NULL && lst2 == NULL ) return 1;
	else if(lst1 == NULL || lst2 == NULL ) return 0;
	else{
		return ((lst1->info == lst2->info) && Iguais_Recursiva(lst1->prox, lst2->prox));
	}
}
*/

// Quest�o 32 ->  Fa�a uma fun��o recursiva para imprimir uma lista encadeada 
/* Feita anteriormente (Id�ntica ao slide)
void Imprime_Recursiva(Elemento* lst){
	if(!Lista_Vazia(lst)){
		printf("info = %i\n", lst->info);
		Imprime_Recursiva(lst->prox);
	}
}
*/

// Quest�o 33 -> Seja uma lista encadeada cujos registros possuam informa��o do tipo inteiro. 
// 				 Escreva um programa que ordena a lista em ordem crescente em rela��o a informa��o.
void Ordena_Crescente(Elemento** lst){
	Elemento* p, *x;
	for(p = *lst; p->prox != NULL; p = p->prox){
		for(x = p->prox; x!= NULL; x = x->prox){
			if(x->info < p->info){
				int aux = x->info;
				x->info = p->info;
				p->info = aux;
			}
		}
	}
}

// Quest�o 34 -> Dada uma lista encadeada que armazena numeros inteiros, escreva uma fun��o que transforma a lista
// 				 dada em duas listas encadeadas: a primeira contendo os elementos cujo conteudo � par e a segunda 
//				 contendo os elementos com conte�dos impares
void Separa_Lista(Elemento* lst, Elemento** pares, Elemento** impares){
	Elemento* p;
	*pares = NULL;
	*impares = NULL;
	for(p = lst; p != NULL; p = p->prox){
		if(p->info % 2 == 0){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = *pares;
			
			*pares = novo;
		}
		else{
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = *impares;
			
			*impares = novo;
		}
	}
}

// Quest�o 35 -> Fa�a uma fun��o para intercalar listas: a fun��o recebe as duas listas ordenadas e retorna a lista 
// 				 com os elementos das duas listas intercalados conforme a ordem com que elas se disp�e na lista.
Elemento* Intercala(Elemento* lst, Elemento* lst2){
	Elemento* p, *p2, *lst3 = NULL;
	int tam = 0, tam2 = 0;
	
	for(p = lst; p != NULL; p = p->prox){
		tam++;
	}
	for(p2 = lst2; p2 != NULL; p2 = p2->prox){
		tam2++;
	}
	
	p = lst; p2 = lst2;
	int i, prov[tam + tam2];
	for(i = 0; i < tam + tam2; i++){
		if(tam2 >= tam){
			if(i % 2 == 0 && p != NULL){
				prov[i] = p->info;
				p = p->prox;
			}
			else {
				prov[i] = p2->info;
				p2 = p2->prox;
			}
		} 
		else {
			if(i % 2 != 0 && p2 != NULL){
				prov[i] = p2->info;
				p2 = p2->prox;
				
			}
			else {
				prov[i] = p->info;
				p = p->prox;
			}
		}
	}
	
	for(i = (tam + tam2 - 1); i >= 0; i--){
		Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
		novo->info = prov[i];
		novo->prox = lst3;
		
		lst3 = novo;
	}
	return lst3;
}


// Quest�o 36 -> Fa�a uma fun��o para intercalar listas ordenadamente: a fun��o recebe as duas listas ordenadas e 
// 				 retorna a lista com os elementos das duas listas intercalados, porem obedecendo a ordem crescente 
//				 dos n�meros.
/* Feita anteriormente (Id�ntica a quest�o 19)
Elemento* Merge(Elemento* lst, Elemento* lst2){
	Elemento* aux = NULL, *p, *p2;
	// Encontra o tamanho das listas
	int n = 0, m = 0;
	for (p = lst; p != NULL; p = p->prox){
		n++;
	}
	for (p2 = lst2; p2 != NULL; p2 = p2->prox){
		m++;
	}
	// Concatena em ordem
	int i, j; p = lst; p2 = lst2;
	for(i = 0; i < (n + m); i++){
		if(p == NULL){
			for(j = 0; j < (n + m - i); j++){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p2->info;
				novo->prox = aux;
		
				aux = novo;
				p2 = p2->prox;
			}
			// Inverte a lista auxiliar
			Elemento* merge = NULL;
			for(p = aux; p != NULL; p = p->prox){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p->info;
				novo->prox = merge;
		
				merge = novo;
			}
			return merge;
		}
		else if(p2 == NULL){
			for(j = 0; j < (n + m - i); j++){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p->info;
				novo->prox = aux;
		
				aux = novo;
				p = p->prox;
			}
			// Inverte a lista auxiliar
			Elemento* merge = NULL;
			for(p = aux; p != NULL; p = p->prox){
				Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
				novo->info = p->info;
				novo->prox = merge;
		
				merge = novo;
			}
			return merge;
		}
		else if(p->info < p2->info){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = aux;
		
			aux = novo;
			p = p->prox;
		}
		else if(p2->info < p->info){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p2->info;
			novo->prox = aux;
		
			aux = novo;
			p2 = p2->prox;
		}
	}
}
*/

// Quest�o 37 -> Dada uma lista encadeada que armazena numeros inteiros, escreva uma fun��o que transforma a lista
// 				 dada em duas listas encadeadas: a primeira contendo os elementos cujo conteudo � par e a segunda 
//				 contendo os elementos com conte�dos impares
/* Feita anteriormente (Id�ntica a quest�o 34)
void Separa_Lista(Elemento* lst, Elemento** pares, Elemento** impares){
	Elemento* p;
	*pares = NULL;
	*impares = NULL;
	for(p = lst; p != NULL; p = p->prox){
		if(p->info % 2 == 0){
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = *pares;
			
			*pares = novo;
		}
		else{
			Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
			novo->info = p->info;
			novo->prox = *impares;
			
			*impares = novo;
		}
	}
}
*/

// Quest�o 39 -> Escreva uma fun��o que remove o k-�simo n� da lista encadeada
Elemento* Retira_K (Elemento* lst, int no){
	Elemento* ant = NULL;
	Elemento* p = lst;
	int count = 0;
	
	// Busca o elemento a ser retirado enquanto guarda o elemento anterior
	while(p != NULL && count < no){
		ant = p;
		p = p->prox;
		count ++;
	}
	
	// Elemento n�o encontrado
	if(p == NULL){
		printf("\nError: list index out of range\n");
		return lst;
	}
	// Elemento encontrado � o primeiro da lista
	if (ant == NULL){
		lst = p->prox;
	}
	// Elemento encontrado n�o � o primeiro da lista
	else{
		ant->prox = p->prox;
	}
	
	free(p);
	return lst;
}

// Quest�o 40 -> Escreva uma fun��o recursiva (Id�ntica a quest�o 29) e outra n�o recursiva para contar o n�mero de 
// 				 elementos na lista.
int Conta_Nos(Elemento* lst){
	if(lst == NULL) return 0;
	int count = 0;
	Elemento* p;
	for(p = lst; p != NULL; p = p->prox){
		count++;
	}
	return count;
}

// Quest�o 41 -> Generalize o conceito de lista circular para Lista Circular Duplamente Encadeada. 
// 				 Implemente as fun��es necess�rias para o gerenciamento da mesma.
/* Feita anteriormente (Id�ntica ao slide pt2)
*/

// Quest�o 42 -> Fa�a uma fun��o para retornar o n�mero de n�s da lista que possuem valor maior que n.
int Is_Maior(Elemento* lst, int n){
	if(lst == NULL) return 0;
	Elemento* p = lst;
	int count = 0;
	while(p != NULL){
		if(p->info > n){
			count++;
		}
		p = p->prox;
	}
	return count;
}

// Quest�o 43 -> Considere uma lista de inteiros. Fa�a uma fun��o para somar os valores contidos em uma lista.
int Somatorio(Elemento* lst){
	if(lst == NULL) return 0;
	Elemento* p = lst;
	int soma = 0;
	while(p != NULL){
		soma+= p->info;
		p = p->prox;
	}
	return soma;
}

// Quest�o 44 -> Considere uma lista de inteiros. Fa�a uma fun��o para retornar o n�mero de n�s da lista que 
// 				 possuem um numero primo armazenado. 
int Conta_Primos(Elemento* lst){
	if(lst == NULL) return 0;
	
	int count = 0, i;
	Elemento* p;
	
	for(p = lst; p != NULL; p = p->prox){
		int primo = 0, num = p->info;
		
		if(num == 0 || num == 1) primo = 1;
		for(i = 2; i <= num / 2; i++){
			if(num % i == 0){
				primo = 1;
				break;
			}
		}
		
		if(primo == 0) count++;
	}
	return count;
}
