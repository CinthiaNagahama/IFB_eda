typedef struct pilha Pilha;
typedef struct fila Fila;

/* Coisas de Fila */
// Cria uma fila
Fila* cria_fila(void);

// Insere um elemento em uma fila
void insere_fila(Fila* f, int v);

// Retira um elemento de uma fila
int retira_fila(Fila* f);

// Checa se a fila est� vazia
int vazia_fila(Fila* f);

// Imprime a fila
void imprime_fila(Fila* f);

// Libera a mem�ria alocada por uma fila
void libera_fila(Fila* f);


/* Coisas de Pilha */
// Cria pilha
Pilha* Cria_Pilha();

// Insere valor ao topo da pilha
void Push(Pilha* p, int v);

// Retira um valor do topo da pilha
int Pop(Pilha* p);

// Checa se a pilha est� vazia
int Vazia(Pilha* p);

// Libera a mem�ria alocada pela pilha
void Libera(Pilha* p);

// Quest�o 4 -> Formule uma regra que determine se uma sequ�ncia de inser��es (I) e Elimina��es � v�lida
int seq_valida(char *seq, int tam_seq, int pilha_vazia);

// Quest�o 5-> Fa�a uma fun��o para determinar se uma string e da forma XY, onde X � uma cadeia formada por 
// 			   caracteres arbitr�rios e Y � o reverso de X
int XY(Pilha* p, char *x, char* y);

// Quest�o 6 -> Inverte as letras de cada palavra de um texto terminado por ponto (.) preservando a ordem das 
//				palavras
void inverte_letras(char* c);

// Quest�o 7 -> Escreva uma fun��o que verifique se uma palavra � um pal�ndromo
int checa_palindromo(char* c);

// Quest�o 9 -> Ordena os valores da pilha em ordem crescente
Pilha* ordena(Pilha* p);

// Quest�o 10 -> Fornece o maior, o menor e a media aritm�tica dos elementos da pilha
void calcula(Pilha* p);

// Quest�o 11 -> Inverter a posi��o dos elementos de uma pilha P
Pilha* inverte_posicao(Pilha *p);

// Quest� 12 -> Testa se P1 tem mais elementos que uma pilha P2
int maior(Pilha* p1, Pilha* p2);

// Quest�o 13 -> Testa se duas pilhas P1 e P2 s�o iguais
int iguais(Pilha* p1, Pilha* p2);

// Quest�o 14 -> Copia elementos de uma pilha P1 para uma pilha P2
Pilha* copia(Pilha* p);

// Quest�o 15 -> Considere uma pilha P vazia e uma fila F nao vazia. Utilizando apenas as fun��es da 
// 				 fila e da pilha, escreva uma fun��o que inverta a ordem dos elementos da fila.
Fila* inverte_fila(Fila* f);

// Quest�o 17 -> Acumula n valores da sequencia de Fibonacci em uma pilha
Pilha* fibonacci(int n);

// Quest�o 18 -> Escreva um algoritmo que leia um n�mero indeterminado de valores inteiros. 
// 				 O valor 0 finaliza a entrada de dados. 
//				 Se o numero for par, ent�o inclu�-lo na FILA PAR;
//				 caso contrario, inclu�-lo na FILA �MPAR. 
// 				 Ap�s o t�rmino da entrada de dados, retirar um elemento de cada fila alternadamente 
// 				 (iniciando-se pela FILA �MPAR) at� que ambas as filas estejam vazias.
// 				 Se o elemento retirado de uma das filas for um valor positivo, entao inclu�-lo em uma 
//				 PILHA; caso contr�rio, remover um elemento da PILHA.
//				 Finalmente, escrever o conte�do da pilha.
void balburdia();

// Quest�o 22 -> Fa�a uma fun��o que receba uma pilha como argumento e retorne o valor armazenado em 
//				 seu topo. A fun��o deve remover tamb�m esse elemento.
/* Feita anteriormente (slide) */

// Quest�o 23 -> Retorna o n�mero de elementos da pilha que possuem valor �mpar.
int impar(Pilha* p);

// Quest�o 24 -> Retorna o n�mero de elementos da pilha que possuem valor par.
int par(Pilha* p);

// Quest�o 25 -> Fa�a uma fun��o que receba uma pilha como argumento e retorne o valor armazenado em 
//				 seu topo. A fun��o deve remover tamb�m esse elemento.
/* Feita anteriormente (slide) */ 

// Quest�o 26 -> A conversao de n�meros inteiros, na base 10, para outras bases num�ricas se d� 
// 				 atrav�s de sucessivas divis�es de um dado valor n pelo valor da base na qual se 
// 				 queira converter. Fa�a um programa para obter a convers�o num�rica, de acordo com a
// 				 op��o do usu�rio, utilizando a uma pilha:
// 					(a) Decimal para Binario
// 					(b) Decimal para Octal
// 					(c) Decimal para Hexadecimal
void conversao(int n);
