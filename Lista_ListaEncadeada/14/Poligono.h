// Projete um TAD para armazenar um polígono

typedef struct aresta Aresta;

// Cria poligono
Aresta* Cria(void);

// Incluir arestas
Aresta* Inclui(Aresta* a, float x, float y);

// Imprimi as coordenadas
void Imprimi(Aresta* a);

// Eliminar arestas
Aresta* Retira (Aresta* a, float x, float y);

// Libera poligono
void Libera(Aresta* a);

