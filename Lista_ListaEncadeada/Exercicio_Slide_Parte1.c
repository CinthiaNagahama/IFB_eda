#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Define o tipo Elemento
typedef struct elemento Elemento;

struct elemento{
	int info;
	Elemento* prox;
};
 
// Cria uma lista vazia
Elemento* Cria_Lista(void){
	return NULL;
}

// Insere um valor ao início da lista
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
		printf("info = %d\n", p->info);
	}
}

// Testa se uma lista é vazia - retorna 1 se a lista for vazio e 0 se a lista não for vazia
int Lista_Vazia(Elemento* lst){
	return(lst == NULL);
}

// Busca um elemento na lista - retorna o elemento se ele for encontrado, ou NULL caso o contrário
Elemento* Busca(Elemento* lst, int valor){
	Elemento* p;
	for(p = lst; p != NULL; p = p->prox){
		if(p->info == valor) return p;
	}
	printf("Valor não encontrado.");
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
	
	// Elemento não encontrado
	if(p == NULL){
		printf("Elemento não encontrado");
		return lst;
	}
	// Elemento encontrado é o primeiro da lista
	if (ant == NULL){
		lst = p->prox;
	}
	// Elemento encontrado não é o primeiro da lista
	else{
		ant->prox = p->prox;
	}
	
	free(p);
	return lst;
}

// Libera a memória alocada para a lista
void Libera(Elemento* lst){
	Elemento* p = lst;
	while(p != NULL){
		Elemento* aux = p->prox;
		free(p);
		p = aux;
	}
}

// Insere elemento em ordem crescente (a lista também deve estar ordenada em ordem crescente)
Elemento* Insere_Ordenado(Elemento* lst, int val){
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	novo->info = val;
	
	Elemento* ant = NULL;
	Elemento* p = lst;
	// Procura a posição de inserção
	while (p != NULL && p->info < val){
		ant = p;
		p = p->prox;
	}
	// Encadeia o elemento
	// 		Na primeira posição
	if (ant == NULL){ 
		novo->prox = lst;
		lst = novo;
	}
	// 		No meio da lista
	else{ 
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return lst;
}

// Verifica se duas listas são iguais
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

// Imprime a lista recursivamente ivertida
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

// Verifica se duas listas são iguais recursivamente
int Iguais_Recursiva(Elemento* lst1, Elemento* lst2){
	if(lst1 == NULL && lst2 == NULL ) return 1;
	else if(lst1 == NULL || lst2 == NULL ) return 0;
	else{
		return ((lst1->info == lst2->info) && Iguais_Recursiva(lst1->prox, lst2->prox));
	}
}

int main(void){
	setlocale(LC_ALL, "");
	Elemento* lista = Cria_Lista();
	lista = Insere_Valor(lista, 33);
    lista = Insere_Valor(lista, 12);
    lista = Insere_Valor(lista, 9);
    
	Elemento* lista2 = Cria_Lista();
    lista2 = Insere_Valor(lista2, 33);
    lista2 = Insere_Valor(lista2, 12);
    lista2 = Insere_Valor(lista2, 9);
        
    
    
    /* Códigos de Teste
    
    lista = Insere_Ordenado(lista, 10);
    Imprime_Lista(lista);

	int v = Lista_Vazia(lista);
    if (!v) printf("A lista é vazia.\n");
    else printf("A lista não é vazia.\n");
    
    lista = Busca(lista, 8);
    Imprime_Lista(lista);
    
    lista = Retira(lista, 33);
    Imprime_Lista(lista);
    
    Imprime_Recursiva(lista);
    Imprime_Recursiva_Invertida(lista);
    
    lista = Retira_Recursiva(lista, 33);
    Imprime_Lista(lista);
    
    printf("%i", Iguais_Recursiva(lista, lista2));
    */
	
	
	
    Libera(lista);
    return 0;
}
