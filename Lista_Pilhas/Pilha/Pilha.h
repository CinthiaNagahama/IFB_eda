typedef struct pilha Pilha;
typedef struct fila Fila;

/* Coisas de Fila */
// Cria uma fila
Fila* cria_fila(void);

// Insere um elemento em uma fila
void insere_fila(Fila* f, int v);

// Retira um elemento de uma fila
int retira_fila(Fila* f);

// Checa se a fila está vazia
int vazia_fila(Fila* f);

// Imprime a fila
void imprime_fila(Fila* f);

// Libera a memória alocada por uma fila
void libera_fila(Fila* f);


/* Coisas de Pilha */
// Cria pilha
Pilha* Cria_Pilha();

// Insere valor ao topo da pilha
void Push(Pilha* p, int v);

// Retira um valor do topo da pilha
int Pop(Pilha* p);

// Checa se a pilha está vazia
int Vazia(Pilha* p);

// Libera a memória alocada pela pilha
void Libera(Pilha* p);

// Questão 4 -> Formule uma regra que determine se uma sequência de inserções (I) e Eliminações é válida
int seq_valida(char *seq, int tam_seq, int pilha_vazia);

// Questão 5-> Faça uma função para determinar se uma string e da forma XY, onde X é uma cadeia formada por 
// 			   caracteres arbitrários e Y é o reverso de X
int XY(Pilha* p, char *x, char* y);

// Questão 6 -> Inverte as letras de cada palavra de um texto terminado por ponto (.) preservando a ordem das 
//				palavras
void inverte_letras(char* c);

// Questão 7 -> Escreva uma função que verifique se uma palavra é um palíndromo
int checa_palindromo(char* c);

// Questão 9 -> Ordena os valores da pilha em ordem crescente
Pilha* ordena(Pilha* p);

// Questão 10 -> Fornece o maior, o menor e a media aritmética dos elementos da pilha
void calcula(Pilha* p);

// Questão 11 -> Inverter a posição dos elementos de uma pilha P
Pilha* inverte_posicao(Pilha *p);

// Questõ 12 -> Testa se P1 tem mais elementos que uma pilha P2
int maior(Pilha* p1, Pilha* p2);

// Questão 13 -> Testa se duas pilhas P1 e P2 são iguais
int iguais(Pilha* p1, Pilha* p2);

// Questão 14 -> Copia elementos de uma pilha P1 para uma pilha P2
Pilha* copia(Pilha* p);

// Questão 15 -> Considere uma pilha P vazia e uma fila F nao vazia. Utilizando apenas as funções da 
// 				 fila e da pilha, escreva uma função que inverta a ordem dos elementos da fila.
Fila* inverte_fila(Fila* f);
