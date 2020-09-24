// Quest�o 6 - Lista TAD - N�meros Racionais
typedef struct numero_racional Racionais;

// Cria um n�mero racional
Racionais* CriaNumero(int num, int den);

// Apaga n�meros racionais
void ApagaNumero(Racionais* x);

// Soma n�meros racionais
Racionais* Soma(Racionais* x, Racionais* y);

// Multiplica N�meros Racionais
Racionais* Multiplica(Racionais* x, Racionais* y);

// Testa se os N�meros Racionais s�o Iguais
int Iguais(Racionais* x, Racionais* y);
