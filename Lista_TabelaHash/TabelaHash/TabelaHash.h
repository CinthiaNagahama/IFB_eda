typedef struct aluno Aluno;
struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};

typedef struct hash Hash;

// Cria uma tabela hash vazia
Hash* cria_hash(int TABLE_SIZE);

// Libera a mem�ria alocada pela tabela hash
void libera_hash(Hash* h);

// Converte string para um valor
int converte_string(char *str);

// Insere um valor sem tratamento de colis�o
int insere_sem_colisao(Hash *h, Aluno a);

// Busca um valor sem tratamento de colis�o
int busca_sem_colisao(Hash *h, int mat, Aluno* a);

// Insere um valor com tratamento de colis�o
int rehash_linear(int pos, int i, int TABLE_SIZE);
int insere_ender_aberto(Hash *h, Aluno a);

// Busca um valor com tratamento de colis�o
int busca_ender_aberto(Hash *h, int mat, Aluno* a);

// Quest�o 2 -> Verifica se a tabela est� cheia
int cheia(Hash* h);

// Quest�o 20 -> Considere dois conjuntos de numeros inteiros, S = {s1; s2; ... ; sm} e T = {t1; t2; ...;
// 				 tn}, m = n.
// 					(a) Monte um algoritmo que utiliza uma tabela hash para testar se S e um subconjunto
//						de T.
//					(b) Qual � o tempo m�dio de funcionamento de seu algoritmo?
int subconjunto(int* s, int* t);
