typedef struct calc Calculadora;

// Cria a calculadora
Calculadora* Cria(char* formato);

// Insere um operando
void Operando(Calculadora* c, float v);

// Insere um operador
void Operador(Calculadora* c, char o);

// Libera a mem�ria alocada pela calculadora
void Libera(Calculadora* c);
