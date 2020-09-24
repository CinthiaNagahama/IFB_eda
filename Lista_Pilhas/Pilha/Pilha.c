#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

#define N 50

// -----------------------------------Implementa��o de Pilha com vetor-----------------------------------------//
/*
struct pilha{
	int n; 
	float vet[N];
};

// Cria pilha
Pilha* Cria_Pilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->n = 0;
	
	return p;
}

// Insere valor ao topo da pilha
void Push(Pilha* p, float v){
	// Checa se h� espa�o na pilha
	if(p->n == N){
		printf("\nCapacidade da pilha estorou.\n");
		exit(1);
	}
	// Insere o valor no topo da pilha
	p->vet[p->n] = v;
	p->n++; // Sempre deixa um espa�o vazio
}

// Retira um valor do topo da pilha
float Pop(Pilha* p){
	float* v;
	// Checa se a pilha est� vazia
	if(Vazia(p)){
		printf("\nA pilha est� vazia.\n");
		exit(1);
	}	
	// Retira o valor do topo da pilha
	v = p->vet[p->n-1];
	p->n--;
	return v;
}

// Checa se a pilha est� vazia
int Vazia(Pilha* p){
	if(p->n == 0) return 1;
	else return 0;
}

// Libera a mem�ria alocada pela pilha
void Libera(Pilha* p){
	free(p);
}
*/

// ------------------------------------Implementa��o de Pilha com Lista----------------------------------------//

typedef struct lista Lista;
struct lista{
	int info; 
	Lista* prox;
};

struct pilha{
	Lista* topo;
};

/* ---------------------------------------------- Filas -------------------------------------------------------- */
 
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
void insere_fila(Fila* f, int v){
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
int retira_fila(Fila* f){
	Lista* aux;
	int v;
	
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
		printf("%i\n", aux->info);
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

 /* -------------------------------------------------------------------------------------------------------------*/



// Cria pilha
Pilha* Cria_Pilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

// Insere valor ao topo da pilha
void Push(Pilha* p, int v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->topo;
	p->topo = n;
}

// Retira um valor do topo da pilha
int Pop(Pilha* p){
	Lista* t;
	int v;
	if(Vazia(p)){
		printf("\nA pilha est� vazia.\n");
		exit(1);
	}
	// Pega o valor no topo da pilha
	t = p->topo;
	v = t->info;
	
	// Passa o topo para o pr�ximo elemento
	p->topo = t->prox;
	
	// Libera o topo original e retorna o valor
	free(t);
	return v;
}

// Checa se a pilha est� vazia
int Vazia(Pilha* p){
	return (p->topo == NULL);
}

// Libera a mem�ria alocada pela pilha
void Libera(Pilha* p){
	Lista* t = p->topo;
	while(t != NULL){
		Lista* u = t->prox;
		free(t);
		t = u;
	}
	free(p);
}

// Quest�o 4 -> Formule uma regra que determine se uma sequ�ncia de inser��es (I) e Elimina��es � v�lida
int seq_valida(char *seq, int tam_seq, int pilha_vazia){
	int count_i = 0, count_e = 0, i;
	
	if(!pilha_vazia) return 0;
	
	for(i = 0; i < tam_seq; i++){
		if(seq[i] == 'i' || seq[i] == 'I') count_i++;
		else count_e++;
	}
	
	return (count_i == count_e);
}

// Quest�o 5-> Fa�a uma fun��o para determinar se uma string � da forma XY, onde X � uma cadeia formada por 
// 			   caracteres arbitr�rios e Y � o reverso de X.
int XY(Pilha* p, char* x, char* y){
	int i;
	Lista* t = p->topo;
	
	for(i = 0; i < strlen(x); i++, t = t->prox){
		if(t == NULL || t->info != x[i]) return 0;
	}
	for(i = 0; i < strlen(y); i++, t = t->prox){
		if(t == NULL || t->info != y[i]) return 0;
	}
	
	return 1;
}

// Quest�o 6 -> Inverte as letras de cada palavra de um texto terminado por ponto (.) preservando a ordem das 
//				palavras.
void inverte_letras(char* c){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	int i;

	for (i = 0; c[i] != '.' && c[i] != '\0'; i++) {
		// Cria uma pilha com uma palavra
		for (; c[i] != '.' && c[i] != ' ' && c[i] != '\0'; i++) {
			Push(p, c[i]);
		}
		// Imprime as letras enquanto esvazia a pilha
		while (p->topo != NULL) {
            printf("%c", Pop(p));
        }
        putchar(c[i] == ' ' ? ' ' : '\n');
    }
}

// Quest�o 7 -> Escreva uma fun��o que verifique se uma palavra � um pal�ndromo.
int checa_palindromo(char* c){
	int i;
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	
	// Empilha
	for(i = 0; c[i] != '\0'; i++){
		char aux = tolower(c[i]);
		Push(p, aux);
	}
	
	// Compara
	for(i = 0; c[i] != '\0'; i++){
		char aux = tolower(c[i]);
		if(aux != Pop(p)) return 0;
	}
	return 1;
}

// Quest�o 9 -> Ordena os valores da pilha em ordem crescente.
Pilha* ordena(Pilha* p){	
	Lista* q = p->topo, *t;
	for(; q != NULL; q = q->prox){
		for(t = q->prox; t != NULL; t = t->prox){
			if(q->info < t->info){
				int aux = q->info;
				q->info = t->info;
				t->info = aux;
			}
		}
	}
	
	Pilha* l = Cria_Pilha();
	for(q = p->topo; q != NULL; q = q->prox){
		Push(l, q->info);
	}
	
	return l;
}

// Quest�o 10 -> Fornece o maior, o menor e a media aritm�tica dos elementos da pilha
void calcula(Pilha* p){
	int qtd = 0;
	int menor = p->topo->info, maior = p->topo->info;
	float media = 0;
	
	Lista* q = p->topo, *x;
	
	for(; q->prox != NULL; q = q->prox){
		for(x = q->prox; x!= NULL; x = x->prox){
			if(x->info < q->info){
				menor = x->info;
			}
			else maior = x->info;
		}
		media += q->info;
		qtd++;
	}
	
	media += q->info;
	media /= (qtd + 1);
	
	printf("\nMenor valor: %i | Maior valor: %i | Media: %.2f", menor, maior, media);
}

// Quest�o 11 -> Inverter a posi��o dos elementos de uma pilha P.
Pilha* inverte_posicao(Pilha *p){
	Pilha* l = Cria_Pilha();
	for(; p->topo != NULL; p->topo = p->topo->prox){
		Push(l, p->topo->info);
		free(p->topo);
	}
	free(p);
	return l;
}

// Quest� 12 -> Testa se P1 tem mais elementos que uma pilha P2.
int maior(Pilha* p1, Pilha* p2){
	Lista* q1 = p1->topo, *q2 = p2->topo;
	
	// Checa listas vazias
	if(q1 == NULL && q2 == NULL) return 1;
	else if(q1 == NULL && q2 != NULL || q1 != NULL && q2 == NULL) return 0;
	
	// Checa se P1 � menor
	while(q1 != NULL && q2 != NULL){
		if(q1 == NULL) return 0;
		q1 = q1->prox;
		q2 = q2->prox;
	}
	
	// Checa se P1 e P2 tem a mesma quantidade de elementos
	if(q1 == NULL && q2 == NULL) return 0;
	
	// P1 � maior
	else return 1;
}

// Quest�o 13 -> Testa se duas pilhas P1 e P2 s�o iguais
int iguais(Pilha* p1, Pilha* p2){
	Lista* q1 = p1->topo, *q2 = p2->topo;
	
	// Checa listas vazias
	if(q1 == NULL && q2 == NULL) return 1;
	else if(q1 == NULL && q2 != NULL || q1 != NULL && q2 == NULL) return 0;
	
	// Checa se P1 � tem menos elemento ou se h� elementos diferentes
	while(q1 != NULL && q2 != NULL){
		if(q1 == NULL || q1->info != q2->info) return 0;
		q1 = q1->prox;
		q2 = q2->prox;
	}
	
	// Checa se P1 e P2 est�o vazias
	if(q1 == NULL && q2 == NULL) return 1;
	else return 0;
}

// Quest�o 14 -> Copia elementos de uma pilha P1 para uma pilha P2
Pilha* copia(Pilha* p){
	Lista* q = p->topo, *t;
	for(; q != NULL; q = q->prox){
		for(t = q->prox; t != NULL; t = t->prox){
			int aux = q->info;
			q->info = t->info;
			t->info = aux;
		}
	}
	
	Pilha* l = Cria_Pilha();
	for(q = p->topo; q != NULL; q = q->prox){
		Push(l, q->info);
	}
	
	return l;
}

// Quest�o 15 -> Considere uma pilha P vazia e uma fila F nao vazia. Utilizando apenas as fun��es da 
// 				 fila e da pilha, escreva uma fun��o que inverta a ordem dos elementos da fila.
Fila* inverte_fila(Fila* f){
	Pilha* p = Cria_Pilha();
	Lista* q = f->ini;
	
	for(; q != NULL; q = q->prox){
		Push(p, retira_fila(f));
	}
	
	q = p->topo;
	for(; q != NULL; q = q->prox){
		insere_fila(f, Pop(p));
	}
	
	return f;
}
