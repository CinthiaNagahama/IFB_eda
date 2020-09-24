// Questão 10 -> Implemente um TAD fila completo com uma lista circular dinâmica e encadeada.

typedef struct fila Fila;

// Cria uma fila
Fila* cria_fila(void);

// Insere um elemento em uma fila
void insere_fila(Fila* f, float v);

// Retira um elemento de uma fila
float retira_fila(Fila* f);

// Checa se a fila está vazia
int vazia_fila(Fila* f);

// Imprime a fila
void imprime_fila(Fila* f);

// Libera a memória alocada por uma fila
void libera_fila(Fila* f);
