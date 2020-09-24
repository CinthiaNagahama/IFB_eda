// Quest�o 10 -> Implemente um TAD fila completo com uma lista circular din�mica e encadeada.

typedef struct fila Fila;

// Cria uma fila
Fila* cria_fila(void);

// Insere um elemento em uma fila
void insere_fila(Fila* f, float v);

// Retira um elemento de uma fila
float retira_fila(Fila* f);

// Checa se a fila est� vazia
int vazia_fila(Fila* f);

// Imprime a fila
void imprime_fila(Fila* f);

// Libera a mem�ria alocada por uma fila
void libera_fila(Fila* f);
