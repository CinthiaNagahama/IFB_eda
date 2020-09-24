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

// Quest�o 3 -> Reposiciona os elemento na fila de tal forma que o in�cio se torna o fim e vice-versa
void reverso(Fila **f);

// Quest�o 4 -> Escreva uma fun��o para ordenar um fila de inteiros em ordem crescente
void ordena_crescente(Fila **f);

// Quest�o 5 -> Escreva uma fun��o que calcule o menor, o maior e a m�dia aritm�tica dos elementos
void calcula(Fila *f);

// Quest�o 6 ->	Testa se uma fila F1 � tem mais elementos que uma fila F2
int maior(Fila *f1, Fila *f2);

// Quest�o 7 -> Exclui todos os negativos sem alterar a posi��o dos outros elementos da fila
void exclui_negativo(Fila **f);

// Quest�o 8 -> Recebe 3 filas, duas ordenadas e preenche a �ltima ordenadamente com os elementos 
// 				das duas filas
void combina_ordenado(Fila* f, Fila* f2, Fila **res);

// Quest�o 9 -> Imprime os elementos de uma fila
void imprime(Fila* f);

// Quest�o 12 -> Concatena duas filas na primeira e deixa a segunda vazia
void concatena(Fila **f, Fila **f2);

// Quest�o 14 -> Fa�a uma fun��o que receba uma fila como argumento e retorne o valor armazenado
// 				 em seu in�cio. A fun��o deve remover tamb�m esse elemento.
// Feita anteriormente(slide)

// Quest�o 15 -> Fa�a uma fun��o que inverta a ordem dos elementos da fila
// Feita anteriormente(Quest�o 3)

// Quest�o 16 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor �mpar
int impar(Fila *f);

// Quest�o 17 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor par
int par(Fila *f);

// Quest�o 18 -> Fa�a um fun��o que intercala filas
Fila* intercala(Fila *f, Fila *f2);

// Quest�o 19 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor �mpar
// Feita anteriormente(Quest�o 16)

// Quest�o 20 -> Fa�a uma fun��o para retornar o n�mero de elementos da fila que possuem valor par
// Feita anteriormente(Quest�o 17)

/* ------------------------------------------------------------------------------------------------------------*/
// Lista dupla com Vetor

/*
// Insere um elemento no inicio de uma fila
void insere_inicio_fila(Fila* f, float v);

// Retira um elemento do final de uma fila
float retira_final_fila(Fila* f);
*/
