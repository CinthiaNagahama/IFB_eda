// Questão 8 - Lista TAD - Cilindro
#define PI 3.14159

typedef struct cilindro Cilindro;

// Cria Cilindro
Cilindro* CriaCilindro(float h, float r);

// Apaga o Cilindro
void ApagaCilindro(Cilindro* a);

// Encontra a Altura e o Raio do Cilindro
void AlturaERaio(Cilindro* a, float *h, float *r);

// Encontra a Área do Cilindro
double Area(Cilindro* a);

// Encontra o Volume do Cilindro
double Volume(Cilindro* a);
