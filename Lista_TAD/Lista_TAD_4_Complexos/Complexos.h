// Questão 4 - Lista TAD - Numeros Complexos
typedef struct numerocomplexo NumComplexo;

// Cria o número complexo
NumComplexo* CriaNumero (float x, float y);

// Destroi o número complexo
void DestroiNumero (NumComplexo* n);

// Soma dois números complexos
NumComplexo* Soma(NumComplexo* a, NumComplexo* b);

// Subtrai dois números complexos
NumComplexo* Subtrai(NumComplexo* a, NumComplexo* b);

// Multiplica dois números complexos
NumComplexo* Multiplica(NumComplexo* a, NumComplexo* b);

// Divide dois números complexos
NumComplexo* Divide(NumComplexo* a, NumComplexo* b);
