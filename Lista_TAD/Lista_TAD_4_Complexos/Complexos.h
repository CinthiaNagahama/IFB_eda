// Quest�o 4 - Lista TAD - Numeros Complexos
typedef struct numerocomplexo NumComplexo;

// Cria o n�mero complexo
NumComplexo* CriaNumero (float x, float y);

// Destroi o n�mero complexo
void DestroiNumero (NumComplexo* n);

// Soma dois n�meros complexos
NumComplexo* Soma(NumComplexo* a, NumComplexo* b);

// Subtrai dois n�meros complexos
NumComplexo* Subtrai(NumComplexo* a, NumComplexo* b);

// Multiplica dois n�meros complexos
NumComplexo* Multiplica(NumComplexo* a, NumComplexo* b);

// Divide dois n�meros complexos
NumComplexo* Divide(NumComplexo* a, NumComplexo* b);
