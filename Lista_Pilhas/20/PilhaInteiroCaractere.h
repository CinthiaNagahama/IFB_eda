typedef struct pilha Pilha;

// Cria pilha
Pilha* Cria_Pilha();

// Insere valor ao topo da pilha
void Push(Pilha* p, char tipo);

// Retira um valor do topo da pilha
int Pop_int(Pilha* p);
char Pop_char(Pilha* p);

// Checa se a pilha está vazia
int Vazia(Pilha* p);

// Libera a memória alocada pela pilha
void Libera(Pilha* p);

// Imprime pilha
void Imprime(Pilha* p);
