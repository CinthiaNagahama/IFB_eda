// Questão 3 - Lista TAD - Clube de quadras poliesportivas
typedef struct clube Clube;

// Cria clube
Clube* NovoClube(int n);

// Reserva quadra
void ReservaQuadra(Clube* q, int n);

// Cancela Reserva
void CancelaQuadra(Clube* q, int n);

// Libera Clube
void Libera(Clube* c);
