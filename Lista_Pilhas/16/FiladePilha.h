// Questão 16 -> Escreva rotinas para implementar as operações corretas de inserção e remoção de 
// 				 números inteiros na pilha e de inserção e remoção de pilhas na fila.

typedef struct pilha Pilha;
typedef struct fila Fila;

/* --------------------------------------- Coisas de Fila --------------------------------------- */
// Cria uma fila
Fila* cria_fila(void);

// Insere um elemento em uma fila
void insere_fila(Fila* f, Pilha* p);

// Retira um elemento de uma fila
int retira_fila(Fila* f);

// Checa se a fila está vazia
int vazia_fila(Fila* f);

// Imprime a fila
void imprime_fila(Fila* f);

// Libera a memória alocada por uma fila
void libera_fila(Fila* f);


/*  --------------------------------------- Coisas de Pilha --------------------------------------- */
// Cria pilha
Pilha* cria_pilha();

// Insere valor ao topo da pilha
void push(Pilha* p, int v);

// Retira um valor do topo da pilha
int pop(Pilha* p);

// Imprime a pilha
void imprime_pilha(Pilha* p)

// Checa se a pilha está vazia
int vazia_pilha(Pilha* p);

// Libera a memória alocada pela pilha
void libera_pilha(Pilha* p);
