#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct node{
	int info;
	int height;
	struct node *left;
	struct node *right;
};

// Cria um nó raíz especial que aponta para a raíz real da árvore | Facilita balanceamento
AvlTree* create_tree(){
	AvlTree* root = (AvlTree*) malloc(sizeof(AvlTree));
	if(root != NULL) *root = NULL;
	return root;
}

// Calcula a altura de um nó
int node_height(struct node* node){
	return(node == NULL ? -1 : node->height);
}

// Calcula o fator de balanceamento
int calc_bf(struct node* node){
	return labs(node_height(node->left) - node_height(node->right));
}

// Calcula o maior valor
int find_the_biggest(int x, int y){
	return(x > y ? x : y);
}

// Destrói uma Árvore AVL
void free_node(struct node *node){
	if(node == NULL) return ;
	
	free_node(node->left);
	free_node(node->right);
	
	free(node);
	node = NULL;
}

void free_tree(AvlTree* root){
	if(root == NULL) return ;
	free_node(*root);
	free(root);
}

// Checa se uma Árvore AVL está vazia
int is_tree_empty(AvlTree* root){
	if(root == NULL || *root == NULL) return 1;
	return 0;
}

// Descobre a altura de uma Árvore AVL
int height(AvlTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int leftHeight = height(&((*root)->left));
	int rightHeight = height(&((*root)->right));
	
	if(leftHeight > rightHeight) return (leftHeight + 1);
	else return (rightHeight + 1);
}

// Descobre o total de nós de uma Árvore AVL
int total_nodes(AvlTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int leftTotal = total_nodes(&((*root)->left));
	int rightTotal = total_nodes(&((*root)->right));
	
	return (leftTotal + rightTotal + 1);
}

// Imprime a Árvore AVL percorrendo do jeito Pré-Ordem
void print_pre_tree(AvlTree* root){ // Raiz - Esquerda - Direita
	if(root == NULL) return ;
	if(*root != NULL){
		printf("%i\n", (*root)->info);
		print_pre_tree(&((*root)->left));
		print_pre_tree(&((*root)->right));
	}
}

// Imprime a Árvore AVL percorrendo do jeito Em-Ordem
void print_in_tree(AvlTree* root, int side){ // Esquerda - Raíz - Direita
	if(root == NULL) return ;
	if(*root != NULL){
		print_in_tree(&((*root)->left), -1);
		if(side == -1) printf("l: %i\n", (*root)->info);
		else if(side == 1) printf("r: %i\n", (*root)->info);
		else printf("root: %i\n", (*root)->info);
		print_in_tree(&((*root)->right), 1);
	}
}

// Imprime a Árvore AVL percorrendo do jeito Pós-Ordem
void print_pos_tree(AvlTree* root){ // Esquerda - Direita - Raíz
	if(root == NULL) return ;
	if(*root != NULL){
		print_pos_tree(&((*root)->left));
		print_pos_tree(&((*root)->right));
		printf("%i\n", (*root)->info);
	}
}

// Rotação LL
void rotation_LL(AvlTree* root){
	struct node* node = (*root)->left;
	(*root)->left = node->right;
	node->right = *root;
	
	(*root)->height = find_the_biggest(height(&(*root)->left), height(&(*root)->right)) + 1;
	node->height = find_the_biggest(height(&(node)->left), (*root)->height) + 1;
	
	*root = node;
}

// Rotação RR
void rotation_RR(AvlTree* root){
	struct node* node = (*root)->right;
	(*root)->right = node->left;
	node->left = *root;
	
	(*root)->height = find_the_biggest(height(&(*root)->left), height(&(*root)->right)) + 1;
	node->height = find_the_biggest(height(&(node)->right), (*root)->height) + 1;
	
	*root = node;
}

// Rotação LR
void rotation_LR(AvlTree* root){
	rotation_RR(&(*root)->left);
	rotation_LL(root);
}

// Rotação RL
void rotation_RL(AvlTree* root){
	rotation_LL(&(*root)->right);
	rotation_RR(root);
}

// Insere um valor na Árvore AVL
int insert(AvlTree* root, int value){
	int res;
	if(*root == NULL){ // Árvore vazia || folha
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		if(newNode == NULL) return 0;
		
		newNode->info = value;
		newNode->height = 0;
		newNode->left = NULL;
		newNode->right = NULL;
		
		*root = newNode;
		return 1;
	}
	
	struct node* current = *root;
	if(value < current->info){
		if((res = insert(&(current->left), value)) == 1){
			if(calc_bf(current) >= 2){
				if(value < (*root)->left->info){
					rotation_LL(root);
				}
				else{
					rotation_LR(root);
				}
			}	
		}
	}
	else if(value > current->info){
		if((res = insert(&(current->right), value)) == 1){
			if(calc_bf(current) >= 2){
				if(value > (*root)->right->info){
					rotation_RR(root);
				}
				else{
					rotation_RL(root);
				}
			}	
		}
	}
	else{
		printf("Valor Duplicado!\n");
		return 0;
	}
	
	current->height = find_the_biggest(height(&current->left), height(&current->right)) + 1;
	return res;
}

// Remove um valor da Árvore AVL
struct node* find_the_smallest_node(struct node* current){
	struct node *n1 = current, *n2 = current->left;
	while(n2 != NULL){
		n1 = n2;
		n2 = n2->left;
	}
	return n1;
}
int remove_value(AvlTree* root, int value){
	if(*root == NULL){
		printf("Valor não existe.");
		return 0;
	}
	int res;
	if(value < (*root)->info){
		if((res = remove_value(&((*root)->left), value)) == 1){
			if(calc_bf(*root) >= 2){
				if(height(&((*root)->right->left)) <= height(&((*root)->right->right)))
					rotation_RR(root);
				else
					rotation_RL(root);
			}
		}
	}
	else if(value > (*root)->info){
		if((res = remove_value(&(*root)->right, value)) == 1){
			if(calc_bf(*root) >= 2){
				if(height(&((*root)->left->right)) <= height(&((*root)->left->left)))
					rotation_LL(root);
				else
					rotation_LR(root);
			}
		}
	}
	else{
		if((*root)->left == NULL || (*root)->right == NULL){
			struct node* oldNode = (*root);
			if((*root)->left == NULL)
				*root = (*root)->left;
			else
				*root = (*root)->right;
			free(oldNode);
		}
		else{
			struct node* temp = find_the_smallest_node((*root)->right);
			(*root)->info = temp->info;
			remove_value(&((*root)->right), (*root)->info);
			if(calc_bf(*root) >= 2){
				if(height(&((*root)->left->right)) <= height(&((*root)->left->left)))
					rotation_LL(root);
				else
					rotation_LR(root);
			}
		}
		return 1;
	}
	return res;
}
