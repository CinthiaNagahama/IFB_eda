typedef struct node* BinTree;

// Cria um nó raíz especial que aponta para a raíz real da Árvore Binária| Facilita balanceamento
BinTree* create_tree();

// Destrói uma Árvore Binária
void free_tree(BinTree* root);

// Checa se uma Árvore Binária está vazia
int is_tree_empty(BinTree* root);

// Descobre a altura de uma Árvore Binária
int height(BinTree* root);

// Descobre o total de nós de uma Árvore Binária
int total_nodes(BinTree* root);

// Imprime a Árvore Binária percorrendo do jeito Pré-Ordem
void print_pre_tree(BinTree* root);

// Imprime a Árvore Binária percorrendo do jeito Em-Ordem
void print_in_tree(BinTree* root, int side);

// Imprime a Árvore Binária percorrendo do jeito Pós-Ordem
void print_pos_tree(BinTree* root);

/* ----------------------------------- Árvore Binária de Busca ----------------------------------- */

// Insere um valor em uma Árvore Binária
int insert(BinTree* root, int value);

// Remove um valor de uma Árvore Binária
int remove_value(BinTree* root, int value);

// Consulta se um valor está em uma Árvore Binária
int search(BinTree* root, int value);
