#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct polinomio Polinomio;
struct polinomio{
	int potencia;
	int coeficiente;
	Polinomio* prox;
};

// Cria um elemento do tipo Polinomio
Polinomio* Cria_Polinomio(){
	return NULL;
}

// Insere um novo termo ao Polinomio, de forma que a ordem dos coeficientes seja decrescente
Polinomio* Insere_Termo(Polinomio* pol, int valor){
	if(valor == 0) {
		printf("Valor não pode ser 0");
		return NULL;
	}
	
	Polinomio* novo = (Polinomio*) malloc(sizeof(Polinomio));
	novo->coeficiente = novo->potencia = valor;
			
	Polinomio* p = pol, *ant = NULL;
	
	while (p != NULL && p->coeficiente > valor){
		ant = p;
		p = p->prox;
	}
	
	// Encadeia o elemento na primeira posição
	if (ant == NULL){ 
		novo->prox = pol;
		pol = novo;
	}
	// Encadeia o elemento no meio da lista
	else{ 
		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return pol;
}

// Imprime o polinômio
void Imprime_Polinomio(Polinomio* pol){
	Polinomio* p;
	printf("\n");
	for(p = pol; p->prox != NULL; p = p->prox){
		printf("a%dx^%d + ", p->coeficiente, p->potencia);
	}
	printf("a%dx^%d\n", p->coeficiente, p->potencia);
	free(p);
}

// Retira o termo associada à n-ésima potência
Polinomio* Retira_No (Polinomio* pol, int no){
	Polinomio* ant = NULL;
	Polinomio* p = pol;
	int count = 0;
	
	// Busca o elemento a ser retirado enquanto guarda o elemento anterior
	while(p != NULL && count < no){
		ant = p;
		p = p->prox;
		count ++;
	}
	
	// Elemento não encontrado
	if(p == NULL){
		printf("\nError: list index out of range\n");
		return pol;
	}
	// Elemento encontrado é o primeiro da lista
	if (ant == NULL){
		pol = p->prox;
	}
	// Elemento encontrado não é o primeiro da lista
	else{
		ant->prox = p->prox;
	}
	
	free(p);
	return pol;
}

// Libera a memória alocada para o polinômio
void Libera_Polinomio(Polinomio* pol){
	while(pol != NULL){
		Polinomio* aux = pol->prox;
		free(pol);
		pol = aux;
	}
}

int main(void){
	setlocale(LC_ALL, "portuguese");
	Polinomio* teste = Cria_Polinomio();
	teste = Insere_Termo(teste, 2);
	teste = Insere_Termo(teste, 3);
	teste = Insere_Termo(teste, 1);
	
	teste = Retira_No(teste, 0);
	Imprime_Polinomio(teste);
	
	Libera_Polinomio(teste);
	return 0;
}
