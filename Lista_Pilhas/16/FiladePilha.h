// Quest�o 16 -> Escreva rotinas para implementar as opera��es corretas de inser��o e remo��o de 
// 				 n�meros inteiros na pilha e de inser��o e remo��o de pilhas na fila.

typedef struct pilha Pilha;
typedef struct fila Fila;

/* --------------------------------------- Coisas de Fila --------------------------------------- */
// Cria uma fila
Fila* cria_fila(void);

// Insere um elemento em uma fila
void insere_fila(Fila* f, Pilha* p);

// Retira um elemento de uma fila
int retira_fila(Fila* f);

// Checa se a fila est� vazia
int vazia_fila(Fila* f);

// Imprime a fila
void imprime_fila(Fila* f);

// Libera a mem�ria alocada por uma fila
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

// Checa se a pilha est� vazia
int vazia_pilha(Pilha* p);

// Libera a mem�ria alocada pela pilha
void libera_pilha(Pilha* p);
