#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

#define N 100

// Implementa��o de fila com Vetor (Fila est�tica)
/*
struct fila{
	int qtd;		// N�mero de elementos
	int ini;		// Posi��o do pr�ximo elemento a ser retirado da fila (�nicio da fila)
	float vet[N];
};

// Cria uma fila
Fila* cria_fila(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f != NULL){
		f->qtd = 0;
		f->ini = 0;
		return f;
	}
	printf("Error: Espa�o indispon�vel");
	exit(1);
}

// Insere um elemento em uma fila
void insere_fila(Fila* f, float v){
	int fim;
	if(f->qtd == N){
		printf("Error: Capacidade da fila estorou.\n");
		exit(1);
	}
	
	// Insere o elemento na pr�xima posi��o livre
	fim = (f->qtd + f->ini) % N; 
	f->vet[fim] = v;
	f->qtd++;
}

// Retira um elemento de uma fila
float retira_fila(Fila* f){
	float v;
	if(vazia_fila(f)){
		printf("Error: Fila vazia.\n");
		exit(1);
	}
	
	// Retira o elemento do in�cio
	v = f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->qtd--;
	
	return v;
}

// Checa se a fila est� vazia
int vazia_fila(Fila* f){
	return(f->qtd == 0);
}

// Imprime a fila
void imprime_fila(Fila* f){
	int i, fim = (f->qtd + f->ini) % N;
	Fila* aux = f;
	
	for(i = f->ini; i != fim; i = (i + 1) % N){
		printf("%.2f\n", f->vet[i]);
	}
}

// Libera a mem�ria alocada por uma fila
void libera_fila(Fila* f){
	free(f);
}
*/

// Implementa��o de fila com Lista (Fila din�mica)

typedef struct lista Lista;
struct lista{
	float info;
	Lista* prox;
};

struct fila{
	Lista* ini;
	Lista* fim;
	int qtd;
};

// Cria uma fila
Fila* cria_fila(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	if(f != NULL){
		f->ini = f->fim = NULL;
		f->qtd = 0;
		return f;
	}
	printf("Error: Espa�o indispon�vel");
	exit(1);
}

// Insere um elemento em uma fila
void insere_fila(Fila* f, float v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = NULL;
	
	// Checa se a lista esta vazia e insere o novo elemento a lista
	if(f->ini == NULL){
		f->ini = n;
	}
	else{
		f->fim->prox = n;
	}
	f->qtd++;
	
	// Fim da lista aponta para o novo elemento
	f->fim = n;
}

// Retira um elemento de uma fila
float retira_fila(Fila* f){
	Lista* aux;
	float v;
	
	if(f->ini == NULL){
		printf("Error: Fila vazia.\n");
		exit(1);
	}
	
	aux = f->ini;
	v = aux->info;
	f->ini = aux->prox;
	
	// Verifica se a lista ficou vazia
	if(f->ini == NULL){
		f->fim = NULL;
	}
	
	free(aux);
	
	f->qtd--;
	return v;
}

// Checa se a fila est� vazia
int vazia_fila(Fila* f){
	return(f->ini == NULL);
}

// Imprime a fila
void imprime_fila(Fila* f){
	Lista* aux;
	for(aux = f->ini; aux != NULL; aux = aux->prox)	{
		printf("%.2f\n", aux->info);
	}
}

// Libera a mem�ria alocada por uma fila
void libera_fila(Fila* f){
	Lista* aux = f->ini;
	while(aux != NULL){
		Lista* aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
	free(f);
}

// Quest�o 3 -> Reposiciona os elemento na fila de tal forma que o in�cio se torna o fim e vice-versa
void reverso(Fila **f){
	int i;
	float v[(*f)->qtd];
	Lista* q = (*f)->ini;
	
	for(i = 0; i < (*f)->qtd; i++){
		v[i] = q->info;
		q = q->prox;
	}
	
	(*f)->ini->info = v[(*f)->qtd - 1];
	(*f)->fim = (*f)->ini;
	
	for(i = ((*f)->qtd - 2); i >= 0; i--){
		(*f)->fim = (*f)->fim->prox;
		if((*f)->fim != NULL) (*f)->fim->info = v[i];
		
	}
	/*
	printf("\n----------------------------\n");
	for(i = 0; i < (*f)->qtd; i++){
		printf("%.2f ", (*f)->ini->info);
		(*f)->ini = (*f)->ini->prox;
	}
	*/
}

// Quest�o 4 -> Escreva uma fun��o para ordenar um fila de inteiros em ordem crescente
void ordena_crescente(Fila **f){
	int i;
	Lista* q = (*f)->ini, *x;
	
	for(; q->prox != NULL; q = q->prox){
		for(x = q->prox; x!= NULL; x = x->prox){
			if(x->info < q->info){
				float aux = x->info;
				x->info = q->info;
				q->info = aux;
			}
		}
	}
	
	/*
	printf("\n----------------------------\n");
	for(i = 0; i < (*f)->qtd; i++){
		printf("%.2f ", (*f)->ini->info);
		(*f)->ini = (*f)->ini->prox;
	}
	*/
}

// Quest�o 5 -> Escreva uma fun��o que calcule o menor, o maior e a m�dia aritm�tica dos elementos
void calcula(Fila *f){
	int i;
	int menor = f->ini->info, maior = f->ini->info;
	// float menor = f->ini->info, maior = f->ini->info;
	float media = f->ini->info;
	
	Lista* q = f->ini->prox, *x;
	
	for(; q->prox != NULL; q = q->prox){
		for(x = q->prox; x!= NULL; x = x->prox){
			if(x->info < q->info){
				menor = x->info;
			}
			else maior = x->info;
		}
		media += q->info;
	}
	
	media += q->info;
	media /= f->qtd;
	
	printf("\nMenor valor: %i | Maior valor: %i | Media: %.2f", menor, maior, media);
	// printf("\nMenor valor: %.2f | Maior valor: %.2f | Media: %.2f", menor, maior, media);
}

// Quest�o 6 ->	Testa se uma fila F1 � tem mais elementos que uma fila F2
int maior(Fila *f1, Fila *f2){
	return (f1->qtd > f2->qtd);
}

// Quest�o 7 -> Exclui todos os negativos sem alterar a posi��o dos outros elementos da fila
void exclui_negativo(Fila **f){
	int i, negativos = 0;
	Lista* q = (*f)->ini->prox, *ant = (*f)->ini;
	
	if(ant->info < 0){
		(*f)->ini = q;
		ant = q;
		q = q->prox;
		negativos++;
	}
	
	for(; q != NULL; q = q->prox){
		if(q->info < 0.0){
			ant->prox = q->prox;
			negativos++;
		}
		ant = q;
	}
	
	(*f)->fim = ant;
	/*
	printf("\n----------------------------\n");
	for(i = 0; i < ((*f)->qtd - negativos); i++){
		printf("%.2f ", (*f)->ini->info);
		(*f)->ini = (*f)->ini->prox;
	}
	*/
}

// Quest�o 8 -> Recebe 3 filas, duas ordenadas e preenche a fila vazia ordenadamente com os
// 				elementos das duas filas
void combina_ordenado(Fila* f, Fila* f2, Fila **res){
	int i;
	Lista* l1 = f->ini, *l2 = f2->ini;
	
	for(i = 0; i < (f->qtd + f2->qtd); i++){
		// Checa se alguma das filas chegou ao fim
		if(l1 == NULL){
			int j;
			for(j = 0; j < (f->qtd + f2->qtd - i); j++){
				Lista* menor = (Lista*) malloc(sizeof(Lista));
				menor->info = l2->info;
				menor->prox = NULL;
			
				if((*res)->ini == NULL) (*res)->ini = menor;
				else (*res)->fim->prox = menor;
				
				(*res)->qtd++;
				(*res)->fim = menor;
				l2 = l2->prox;
			}
			break;
		}
		else if(l2 == NULL){
			int j;
			for(j = 0; j < (f->qtd + f2->qtd - i); j++){
				Lista* menor = (Lista*) malloc(sizeof(Lista));
				menor->info = l1->info;
				menor->prox = NULL;
			
				if((*res)->ini == NULL) (*res)->ini = menor;
				else (*res)->fim->prox = menor;
				
				(*res)->qtd++;
				(*res)->fim = menor;
				l1 = l1->prox;
			}
			break;
		}
		// Sen�o, continua a procurar o menor valor
		else if(l1->info < l2->info){
			Lista* menor = (Lista*) malloc(sizeof(Lista));
			menor->info = l1->info;
			menor->prox = NULL;
			
			if((*res)->ini == NULL) (*res)->ini = menor;
			else (*res)->fim->prox = menor;
			
			(*res)->qtd++;
			(*res)->fim = menor;
			l1 = l1->prox;
		}
		else{
			Lista* menor = (Lista*) malloc(sizeof(Lista));
			menor->info = l2->info;
			menor->prox = NULL;
			
			if((*res)->ini == NULL) (*res)->ini = menor;
			else (*res)->fim->prox = menor;
			
			(*res)->qtd++;
			(*res)->fim = menor;
			l2 = l2->prox;
		}
	}
	/*
	printf("\n----------------------------\n");
	for(i = 0; i < ((*res)->qtd); i++){
		printf("%.2f ", (*res)->ini->info);
		(*res)->ini = (*res)->ini->prox;
	}
	*/
}

// Quest�o 9 -> Imprime os elementos de uma fila de reais
void imprime(Fila* f){
	int i;
	Lista* q = f->ini;
	
	if(q == NULL) printf("\nLista Vazia");
	
	for(i = 0; i < f->qtd; i++){
		printf("%.2f ", q->info);
		q = q->prox;
	}
}

// Quest�o 12 -> Concatena duas filas na primeira e deixa a segunda vazia
void concatena(Fila **f, Fila **f2){	
	for(; (*f2)->ini != NULL; (*f2)->ini = (*f2)->ini->prox, (*f2)->qtd--){
		// Cria um elemento do tipo lista com o valor de f2
		Lista* aux = (Lista*) malloc(sizeof(Lista));
		aux->info = (*f2)->ini->info;
		aux->prox = NULL;
		
		// Insere o elemento no final da fila 1
		(*f)->fim->prox = aux;
		(*f)->qtd++;
		(*f)->fim = aux;
	}
	// Com a Fila 2 vazia, fim � NULL
	(*f2)->fim = NULL;
}

// Quest�o 14 -> Fa�a uma fun��o que receba uma fila como argumento e retorne o valor armazenado
// 				 em seu in�cio. A fun��o deve remover tamb�m esse elemento.
/* Feita anteriormente(slide)
float retira_fila(Fila* f){
	Lista* aux;
	float v;
	
	if(f->ini == NULL){
		printf("Error: Fila vazia.\n");
		exit(1);
	}
	
	aux = f->ini;
	v = aux->info;
	f->ini = aux->prox;
	
	// Verifica se a lista ficou vazia
	if(f->ini == NULL){
		f->fim = NULL;
	}
	
	free(aux);
	
	f->qtd--;
	return v;
}
*/

// Quest�o 15 -> Fa�a uma fun��o que inverta a ordem dos elementos da fila
/* Feita anteriormente(Quest�o 3) | Troquei o nome para inverte
void inverte(Fila **f){
	int i;
	float v[(*f)->qtd];
	Lista* q = (*f)->ini;
	
	for(i = 0; i < (*f)->qtd; i++){
		v[i] = q->info;
		q = q->prox;
	}
	
	(*f)->ini->info = v[(*f)->qtd - 1];
	(*f)->fim = (*f)->ini;
	
	for(i = ((*f)->qtd - 2); i >= 0; i--){
		(*f)->fim = (*f)->fim->prox;
		if((*f)->fim != NULL) (*f)->fim->info = v[i];
	}
}
*/

// Quest�o 16 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor �mpar
/* N�o funciona nas minhas filas de reais
int impar(Fila *f){
	Lista* aux = f->ini;
	int impar = 0;
	
	for(; aux != NULL; aux = aux->prox){
		if(!(aux->info % 2)) impar++;
	}
	
	return impar;
}
*/

// Quest�o 17 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor �mpar
/* N�o funciona nas minhas filas de reais
int par(Fila *f){
	Lista* aux = f->ini;
	int par = 0;
	
	for(; aux != NULL; aux = aux->prox){
		if(aux->info % 2) par++;
	}
	
	return par;
}
*/

// Quest�o 18 -> Fa�a um fun��o que intercala filas
Fila* intercala(Fila *f, Fila *f2){
	int i = 0;
	
	// Inicia uma fila vazia
	Fila *f3 = (Fila*) malloc(sizeof(Fila));
	f3->ini = f3->fim = NULL;
	f3->qtd = 0;
	
	Lista* q = f->ini, *q2 = f2->ini;
	
	while(q != NULL || q2 != NULL){
		if(q == NULL){
			int j;
			if(i == 0){
				Lista *q3 = (Lista*) malloc(sizeof(Lista));
				q3->info = q2->info;
				q3->prox = NULL;
				
				f3->ini = f3->fim = q3;
				f3->qtd++;
				
				q2 = q2->prox;
				i++;
			}
			for(j = 0; j < (f->qtd + f2->qtd - i); j++, q2 = q2->prox){
				Lista *q3 = (Lista*) malloc(sizeof(Lista));
				q3->info = q2->info;
				q3->prox = NULL;
				
				f3->fim->prox = q3;
				f3->qtd++;
				f3->fim = q3;
			}
			break;
		}
		else if(q2 == NULL){
			int j;
			if(i == 0){
				Lista *q3 = (Lista*) malloc(sizeof(Lista));
				q3->info = q->info;
				q3->prox = NULL;
				
				f3->ini = f3->fim = q3;
				f3->qtd++;
				
				q = q->prox;
				i++;
			}
			for(j = 0; j < (f->qtd + f2->qtd - i); j++, q = q->prox){
				Lista *q3 = (Lista*) malloc(sizeof(Lista));
				q3->info = q->info;
				q3->prox = NULL;
				
				f3->fim->prox = q3;
				f3->qtd++;
				f3->fim = q3;
			}
			break;
		}
		else if(i % 2 == 0){
			Lista *q3 = (Lista*) malloc(sizeof(Lista));
			if(i == 0){
				q3->info = q->info;
				q3->prox = NULL;
				
				f3->ini = f3->fim = q3;
				f3->qtd++;
			}
			else {
				Lista *q3 = (Lista*) malloc(sizeof(Lista));
				q3->info = q->info;
				q3->prox = NULL;
				
				f3->fim->prox = q3;
				f3->qtd++;
				f3->fim = q3;
			}
			
			q = q->prox;
			i++;
		}
		else{
			Lista *q3 = (Lista*) malloc(sizeof(Lista));
			q3->info = q2->info;
			q3->prox = NULL;
			
			f3->fim->prox = q3;
			f3->qtd++;
			f3->fim = q3;
				
			q2 = q2->prox;
			i++;
		}
	}
	return f3;
}

// Quest�o 19 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor �mpar
// Feita anteriormente(Quest�o 16)

// Quest�o 20 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor par
// Feita anteriormente(Quest�o 17)

// Filas Duplas*

/*
// Filas duplas com vetor
// Insere um elemento no inicio de uma fila
void insere_inicio_fila(Fila* f, float v){
	if(f->qtd == N){
		printf("Error: Capacidade da fila estorou.\n");
		exit(1);
	}
	int prec;
	prec = (f->ini - 1 + N) % N;
	f->vet[prec] = v;
	f->ini = prec;
	f->qtd++;
}

// Retira um elemento do final de uma fila
float retira_final_fila(Fila* f){
	if(f->qtd == 0){
		printf("Error: Fila vazia.\n");
		exit(1);
	}
	
	int fim = (f->qtd + f->ini) % N;
	float v = f->vet[fim - 1];
	f->qtd--;
	
	return v;
}
*/

/*
// Filas duplas com Lista Duplamente Encadeada -> N�o testadas
typedef struct lista Lista;
struct lista{
	float info;
	Lista* ant;
	Lista* prox;
};

struct fila{
	Lista* ini;
	Lista* fim;
	int qtd;
};

// Insere um elemento no inicio de uma fila
void insere_inicio_fila(Fila* f, float v){
	Lista* p = (Lista*) malloc(sizeof(Lista));
	p->info = v;
	p->prox = ini;
	p->ant = NULL;
	
	if(f->ini != NULL){
		f->ini->ant = p;
	}
	return p;
}

// Insere um elemento no final de uma fila
void insere_final_fila(Fila* f, float v){
	Lista* p = (Lista*) malloc(sizeof(Lista));
	p->info = v;
	p->prox = NULL;
	p->ant = f->fim;
	
	if(f->ini != NULL){
		f->fim->prox = p;
	}
	return p;
}

// Retira um elemento do inicio de uma fila
float retira_inicio_fila(Fila* f){
	Lista* aux = f->ini->prox;
	if(aux != NULL){
		aux->ant = NULL;
	}
	free(f->ini);
	f->ini = aux;
	return aux->info;
}

// Retira um elemento do final de uma fila
float retira_final_fila(Fila* f){
	float v;
	Lista* aux = f->fim->ant;
	if(aux->prox != NULL){
		v = aux->prox;
		aux->prox = NULL;
	}
	free(f->fim);
	f->fim = aux;
	return v;
}
*/
