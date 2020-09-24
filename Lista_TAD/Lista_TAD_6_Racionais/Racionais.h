// Questão 6 - Lista TAD - Números Racionais
typedef struct numero_racional Racionais;

// Cria um número racional
Racionais* CriaNumero(int num, int den);

// Apaga números racionais
void ApagaNumero(Racionais* x);

// Soma números racionais
Racionais* Soma(Racionais* x, Racionais* y);

// Multiplica Números Racionais
Racionais* Multiplica(Racionais* x, Racionais* y);

// Testa se os Números Racionais são Iguais
int Iguais(Racionais* x, Racionais* y);
