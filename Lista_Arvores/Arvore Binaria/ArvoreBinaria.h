typedef struct node* BinTree;

// Cria um n� ra�z especial que aponta para a ra�z real da �rvore Bin�ria| Facilita balanceamento
BinTree* create_tree();

// Destr�i uma �rvore Bin�ria
void free_tree(BinTree* root);

// Checa se uma �rvore Bin�ria est� vazia
int is_tree_empty(BinTree* root);

// Descobre a altura de uma �rvore Bin�ria
int height(BinTree* root);

// Descobre o total de n�s de uma �rvore Bin�ria
int total_nodes(BinTree* root);

// Imprime a �rvore Bin�ria percorrendo do jeito Pr�-Ordem
void print_pre_tree(BinTree* root);

// Imprime a �rvore Bin�ria percorrendo do jeito Em-Ordem
void print_in_tree(BinTree* root, int side);

// Imprime a �rvore Bin�ria percorrendo do jeito P�s-Ordem
void print_pos_tree(BinTree* root);

/* ----------------------------------- �rvore Bin�ria de Busca ----------------------------------- */

// Insere um valor em uma �rvore Bin�ria
int insert(BinTree* root, int value);

// Remove um valor de uma �rvore Bin�ria
int remove_value(BinTree* root, int value);

// Consulta se um valor est� em uma �rvore Bin�ria
int search(BinTree* root, int value);
