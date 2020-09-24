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

// Questão 3 -> Reposiciona os elemento na fila de tal forma que o início se torna o fim e vice-versa
void reverso(Fila **f);

// Questão 4 -> Escreva uma função para ordenar um fila de inteiros em ordem crescente
void ordena_crescente(Fila **f);

// Questão 5 -> Escreva uma função que calcule o menor, o maior e a média aritmética dos elementos
void calcula(Fila *f);

// Questão 6 ->	Testa se uma fila F1 é tem mais elementos que uma fila F2
int maior(Fila *f1, Fila *f2);

// Questão 7 -> Exclui todos os negativos sem alterar a posição dos outros elementos da fila
void exclui_negativo(Fila **f);

// Questão 8 -> Recebe 3 filas, duas ordenadas e preenche a última ordenadamente com os elementos 
// 				das duas filas
void combina_ordenado(Fila* f, Fila* f2, Fila **res);

// Questão 9 -> Imprime os elementos de uma fila
void imprime(Fila* f);

// Questão 12 -> Concatena duas filas na primeira e deixa a segunda vazia
void concatena(Fila **f, Fila **f2);

// Questão 14 -> Faça uma função que receba uma fila como argumento e retorne o valor armazenado
// 				 em seu início. A função deve remover também esse elemento.
// Feita anteriormente(slide)

// Questão 15 -> Faça uma função que inverta a ordem dos elementos da fila
// Feita anteriormente(Questão 3)

// Questão 16 -> Faça uma função para retornar o número de elementos da fila que possuem valor ímpar
int impar(Fila *f);

// Questão 17 -> Faça uma função para retornar o número de elementos da fila que possuem valor par
int par(Fila *f);

// Questão 18 -> Faça um função que intercala filas
Fila* intercala(Fila *f, Fila *f2);

// Questão 19 -> Faça uma função para retornar o número de elementos da fila que possuem valor ímpar
// Feita anteriormente(Questão 16)

// Questão 20 -> Faça uma função para retornar o número de elementos da fila que possuem valor par
// Feita anteriormente(Questão 17)

/* ------------------------------------------------------------------------------------------------------------*/
// Lista dupla com Vetor

/*
// Insere um elemento no inicio de uma fila
void insere_inicio_fila(Fila* f, float v);

// Retira um elemento do final de uma fila
float retira_final_fila(Fila* f);
*/
