typedef struct fila Fila;
typedef struct lista Lista;

// Cria uma fila
Fila* cria_fila(void);

// Insere um elemento em uma fila
void insere_fila(Fila* f, struct node* v);

// Retira um elemento de uma fila
struct node* retira_fila(Fila* f);

// Checa se a fila está vazia
int vazia_fila(Fila* f);

/* ----------------------------------------- Lista ------------------------------------- */

// Cria uma lista vazia
Lista* Cria_Lista(void);

// Insere um valor ao início da lista
Lista* Insere_Valor(Lista* lst, struct node* valor);

// Imprime os valores da lista
void Imprime_Lista(Lista* lst);
