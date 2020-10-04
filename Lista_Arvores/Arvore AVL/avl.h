typedef struct node* AvlTree;

// Cria um nó raíz especial que aponta para a raíz real da Árvore AVL| Facilita balanceamento
AvlTree* create_tree();

// Destrói uma Árvore AVL
void free_tree(AvlTree* root);

// Checa se uma Árvore AVL está vazia
int is_tree_empty(AvlTree* root);

// Descobre a altura de uma Árvore AVL
int height(AvlTree* root);

// Descobre o total de nós de uma Árvore AVL
int total_nodes(AvlTree* root);

// Imprime a Árvore AVL percorrendo do jeito Pré-Ordem
void print_pre_tree(AvlTree* root);

// Imprime a Árvore AVL percorrendo do jeito Em-Ordem
void print_in_tree(AvlTree* root, int side);

// Imprime a Árvore AVL percorrendo do jeito Pós-Ordem
void print_pos_tree(AvlTree* root);

// Rotação LL
void rotation_LL(AvlTree* root);

// Rotação RR
void rotation_RR(AvlTree* root);

// Rotação LR
void rotation_LR(AvlTree* root);

// Rotação RL
void rotation_RL(AvlTree* root);

// Insere um valor na Árvore AVL
int insert(AvlTree* root, int value);

// Remove um valor da Árvore AVL
int remove_value(AvlTree* root, int value);
