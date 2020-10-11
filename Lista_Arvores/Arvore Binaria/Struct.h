// Structs

struct node{
	int info;
	struct node *left;
	struct node *right;
};

typedef struct lista Lista;
struct lista{
	struct node* infoLista;
	Lista* prox;
};

typedef struct fila Fila;
struct fila{
	Lista* ini;
	Lista* fim;
	int qtd;
};
