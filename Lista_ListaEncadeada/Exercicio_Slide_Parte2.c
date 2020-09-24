#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Lista de Tipos Estruturados*//*

typedef struct{
	float b;
	float h;
} Retangulo;

typedef struct elemento Elemento;
struct elemento{
	Retangulo* info;
	Elemento* prox;
};

// Aloca um nó
static Elemento* aloca (float b, float h){
	Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
	Elemento* p = (Elemento*) malloc(sizeof(Elemento));
	r->b = b;
	r->h = h;
	p->info = r;
	p->prox = NULL;
	return p;
}

int main (void){
	setlocale(LC_ALL, "portuguese");
	Elemento* teste = aloca(2, 5);
	printf("Base: %.2f, Altura: %.2f", teste->info->b, teste->info->h);
	
	return 0;
}
*/


/* Listas Circulares *//*
typedef struct elemento Elemento;
struct elemento{
	int info;
	Elemento* prox;
};

// Cria uma lista vazia
Elemento* cria_lista_circular(void){
	return NULL;
}

// Insere um valor à lista
Elemento* insere_valor(Elemento* lst, int valor){
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	novo->info = valor;
	if(lst == NULL){
		novo->prox = novo;
		return novo;
	}
	else{
		novo->prox = lst->prox;
		lst->prox = novo;
		return novo;
	}
}

// Função para imprimir todos os elementos de uma lista circular
void imprime(Elemento* lst){
	Elemento* p = lst;
	if(p != NULL ){
		do{
			printf("%d\n", p->info);
			p = p->prox;
		} while(p != lst);
	}
}

int main(void){
	setlocale(LC_ALL, "portuguese");
	
	Elemento* lista = cria_lista_circular();
	lista = insere_valor(lista, 33);
    lista = insere_valor(lista, 12);
    lista = insere_valor(lista, 9);
    
    imprime(lista);
	return 0;
}
*/

/* Listas Duplamente Encadeadas *//*
typedef struct elemento ElementoDuplo;
struct elemento{
	int info;
	ElementoDuplo* ant;
	ElementoDuplo* prox;
};

// Cria uma lista vazia
ElementoDuplo* cria(void){
	return NULL;
}

// Insere um valor à lista
ElementoDuplo* insere_valor(ElementoDuplo* lst, int valor){
	ElementoDuplo* novo = (ElementoDuplo*) malloc(sizeof(ElementoDuplo));
	novo->info = valor;
	novo->ant = NULL;
	novo->prox = lst;
	
	if(lst != NULL)	lst->ant = novo;
	return novo;
}

// Função para imprimir todos os elementos da lista
void imprime(ElementoDuplo* lst){
	ElementoDuplo* p;
	for(p = lst; p != NULL; p = p->prox){
		printf("info = %d\n", p->info);
	}
}

// Função para buscar um elemento
ElementoDuplo* busca_elemento(ElementoDuplo* lst, int valor){
	ElementoDuplo* p;
	for(p = lst; p != NULL; p = p->prox){
		if(p->info == valor) return p;
	}
	return NULL;
}

// Função para retirar um elemento
ElementoDuplo* retira_elemento(ElementoDuplo* lst, int valor){
 	ElementoDuplo* p = busca_elemento(lst, valor);
 	// Elemento não encontrado
	if (p == NULL) return lst;
	
	// Elemento é o primeiro da lista
	if (lst == p) lst = p->prox;
	// Elemento está no meio da lista - Faz o próximo do elemento anterior ser o próximo do elemento a ser retirado
	else p->ant->prox = p->prox;
	
	// Se o elemento após o elemento a ser retirado for nulo, não há necessidade de volta
	if (p->prox != NULL) p->prox->ant = p->ant;
 	
	free(p);
 	return lst;
}

int main(void){
	setlocale(LC_ALL, "portuguese");
	
	ElementoDuplo* lista = cria();
	lista = insere_valor(lista, 33);
    lista = insere_valor(lista, 12);
    lista = insere_valor(lista, 9);
    
    imprime(lista);
	return 0;
}
*/

/* Listas Heterôgeneas */

#define RET 0
#define TRI 1
#define CIR 2

#define PI 3.14159

typedef struct{
	float b;
	float h;	
} Retangulo;

typedef struct{
	float b;
	float h;
} Triangulo;

typedef struct{
	float r;
} Circulo;

typedef struct lista ListaHeterogenea;
struct lista{
	int tipo;
	void *info;
	ListaHeterogenea* prox;
};

// Cria um nó com retângulo
ListaHeterogenea* cria_retangulo(float b, float h){
	Retangulo r = (Retangulo*) malloc(sizeof(Retangulo));
	r->b = b;
	r->h = h;
	
	ListaHeterogenea* p = (ListaHeterogenea*) malloc(sizeof(ListaHeterogenea));
	p->tipo = RET;
	p->info = r;
	p->prox = NULL;
	return p;
}

// Cria um nó com triângulo
ListaHeterogenea* cria_triangulo(float b, float h){
	Triangulo t = (Triangulo*) malloc(sizeof(Triangulo));
	t->b = b;
	t->h = h;
	
	ListaHeterogenea* p = (ListaHeterogenea*) malloc(sizeof(ListaHeterogenea));
	p->tipo = TRI;
	p->info = t;
	p->prox = NULL;
	return p;
}

// Cria um nó com circulo
ListaHeterogenea* cria_circulo(float r){
	Circulo c = (Circulo*) malloc(sizeof(Circulo));
	c->b = b;
	c->h = h;
	
	ListaHeterogenea* p = (ListaHeterogenea*) malloc(sizeof(ListaHeterogenea));
	p->tipo = CIR;
	p->info = c;
	p->prox = NULL;
	return p;
}

// Calcula a área do retângulo
static float area_retangulo(Retangulo* r){
	return (r->b * r->h);
}
// Calcula a área do triângulo
static float area_triangulo(Triangulo* t){
	return (t->b * t->h / 2);
}
// Calcula a área do círculo
static float area_circulo(Circulo* c){
	return (PI * c->r * c->r);
}

// Calcula a área de um nó
static float area(ListaHeterogenea* lst){
	float a;
	switch(lst->tipo){
		case RET:
			a = area_retangulo((Retangulo*)lst->info);
			break;
		case TRI:
			a = area_triangulo((Triangulo*)lst->info);
			break;
		case CIR:
			a = area_circulo((Circulo*)lst->info);
			break;
	}
	return a;
}

int main(void){
	setlocale(LC_ALL; "portuguese");
	
	return 0;
}
