typedef struct pilha Pilha;

// Cria pilha
Pilha* Cria_Pilha();

// Insere valor ao topo da pilha
void Push_Pilha(Pilha* p, float v);

// Retira um valor do topo da pilha
float Pop_Pilha(Pilha* p);

// Checa se a pilha est� vazia
int Is_Vazia_Pilha(Pilha* p);

// Libera a mem�ria alocada pela pilha
void Libera_Pilha(Pilha* p);
