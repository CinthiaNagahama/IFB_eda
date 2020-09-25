typedef struct lista Lista;
struct lista{
	int info;
	Lista* ant;
	Lista* prox;
};

typedef struct pilha Pilha;
struct pilha{
	Lista* topo;
};

// Cria pilha
Pilha* Cria_Pilha();

// Insere valor ao topo da pilha
void Push(Pilha* p, int v);

// Retira um valor do topo da pilha
int Pop_int(Pilha* p);

// Checa se a pilha está vazia
int Vazia(Pilha* p);

// Libera a memória alocada pela pilha
void Libera(Pilha* p);

// Imprime pilha
void Imprime(Pilha* p);
