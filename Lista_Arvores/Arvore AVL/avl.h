typedef struct node* AvlTree;

// Cria um n� ra�z especial que aponta para a ra�z real da �rvore AVL| Facilita balanceamento
AvlTree* create_tree();

// Destr�i uma �rvore AVL
void free_tree(AvlTree* root);

// Checa se uma �rvore AVL est� vazia
int is_tree_empty(AvlTree* root);

// Descobre a altura de uma �rvore AVL
int height(AvlTree* root);

// Descobre o total de n�s de uma �rvore AVL
int total_nodes(AvlTree* root);

// Imprime a �rvore AVL percorrendo do jeito Pr�-Ordem
void print_pre_tree(AvlTree* root);

// Imprime a �rvore AVL percorrendo do jeito Em-Ordem
void print_in_tree(AvlTree* root, int side);

// Imprime a �rvore AVL percorrendo do jeito P�s-Ordem
void print_pos_tree(AvlTree* root);

// Rota��o LL
void rotation_LL(AvlTree* root);

// Rota��o RR
void rotation_RR(AvlTree* root);

// Rota��o LR
void rotation_LR(AvlTree* root);

// Rota��o RL
void rotation_RL(AvlTree* root);

// Insere um valor na �rvore AVL
int insert(AvlTree* root, int value);

// Remove um valor da �rvore AVL
int remove_value(AvlTree* root, int value);
