/* Considere que a struct abaixo está armazenada na sua lista.
		struct produto{
			int codProd; //c´odigo do produto
			char nomeProd[10]; //nome do produto
			float valor; //valor do produto
			int qtdeEstoque; //quantidade disponível em estoque
		};
Faça uma função para buscar o produto de menor preço */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct produto Produto;
struct produto{
	int codProd;
	char nomeProd[10];
	float valor;
	int qtdeEstoque;
};

typedef struct elemento Elemento;
struct elemento{
	Produto* info;
	Elemento* prox;
};

Elemento* Cria(void){
	return NULL;
}

Elemento* Insere(Elemento* lst, int cod, char *nome, float valor, int estoque){
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	Produto* p = (Produto*) malloc(sizeof(Produto));
	
	p->codProd = cod;
	for(int i = 0; i < (sizeof(nome)/sizeof(char)); i++){
		p->nomeProd[i] = nome[i];
	}
	p->valor = valor;
	p->qtdeEstoque = estoque;
	
	novo->info = p;
	novo->prox = lst;
	
	return novo;
}

void Imprimi(Elemento* lst, char tipo){
	Elemento* e;
	switch (tipo){
		case 'C':
			for(e = lst; e != NULL; e = e->prox){
				printf("\n	%i", e->info->codProd);
			}
			break;
		case 'N':
			for(e = lst; e != NULL; e = e->prox){
				printf("\n	%s", e->info->nomeProd);
			}
			break;
		case 'V':
			for(e = lst; e != NULL; e = e->prox){
				printf("\n	%.2f", e->info->valor);
			}
			break;
		case 'E':
			for(e = lst; e != NULL; e = e->prox){
				printf("\n	%i", e->info->qtdeEstoque);
			}
			break;
		default:
			printf("\nTipo desconhecido");
			break;
	}
}

int Barato(Elemento* lst, int* codBarato){
	if(lst == NULL) return 0;
	
	Elemento* e = lst;
	*codBarato = e->info->codProd;
	float menorPreco = e->info->valor;
	
	while(e != NULL){
		if(menorPreco > e->info->valor) *codBarato = e->info->codProd;
		e = e->prox;
	}
	return 1;
} 

int main (void){
	setlocale(LC_ALL, "");
	
	Elemento* l = Cria();
	l = Insere(l, 5, "Batata", 1.50, 12);
	l = Insere(l, 4, "Arroz", 15.00, 10);
	l = Insere(l, 8, "Brócolis", 5.00, 5);
	
	printf("\nCódigo dos Produtos");
	Imprimi(l, 'C');
	printf("\nNome dos Produtos");
	Imprimi(l, 'N');
	printf("\nValor dos Produtos");
	Imprimi(l, 'V');
	printf("\nQuantidade em Estoque:");
	Imprimi(l, 'E');
	
	int codBarato, barato;
	barato = Barato(l, &codBarato);
	printf("\n\nEncontrou o produto mais barato: %i\nCódigo do produto mais barato: %i", barato, codBarato);
	
	return 0;
}
