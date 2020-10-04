#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct node{
	int info;
	struct node *left;
	struct node *right;
};

// Cria um nó raíz especial que aponta para a raíz real da árvore | Facilita balanceamento
BinTree* create_tree(){
	BinTree* root = (BinTree*) malloc(sizeof(BinTree));
	if(root != NULL) *root = NULL;
	return root;
}

// Destrói uma Árvore Binária
void free_node(struct node *node){
	if(node == NULL) return ;
	
	free_node(node->left);
	free_node(node->right);
	
	free(node);
	node = NULL;
}

void free_tree(BinTree* root){
	if(root == NULL) return ;
	free_node(*root);
	free(root);
}

// Checa se uma Árvore Binária está vazia
int is_tree_empty(BinTree* root){
	if(root == NULL || *root == NULL) return 1;
	return 0;
}

// Descobre a altura de uma Árvore Binária
int height(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int leftHeight = height(&((*root)->left));
	int rightHeight = height(&((*root)->right));
	
	if(leftHeight > rightHeight) return (leftHeight + 1);
	else return (rightHeight + 1);
}

// Descobre o total de nós de uma Árvore Binária
int total_nodes(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int leftTotal = total_nodes(&((*root)->left));
	int rightTotal = total_nodes(&((*root)->right));
	
	return (leftTotal + rightTotal + 1);
}

// Imprime a Árvore Binária percorrendo do jeito Pré-Ordem
void print_pre_tree(BinTree* root){ // Raiz - Esquerda - Direita
	if(root == NULL) return ;
	if(*root != NULL){
		printf("%i\n", (*root)->info);
		print_pre_tree(&((*root)->left));
		print_pre_tree(&((*root)->right));
	}
}

// Imprime a Árvore Binária percorrendo do jeito Em-Ordem
void print_in_tree(BinTree* root, int side){ // Esquerda - Raíz - Direita
	if(root == NULL) return ;
	if(*root != NULL){
		print_in_tree(&((*root)->left), -1);
		if(side == -1) printf("l: %i\n", (*root)->info);
		else if(side == 1) printf("r: %i\n", (*root)->info);
		else printf("root: %i\n", (*root)->info);
		print_in_tree(&((*root)->right), 1);
	}
}

// Imprime a Árvore Binária percorrendo do jeito Pós-Ordem
void print_pos_tree(BinTree* root){ // Esquerda - Direita - Raíz
	if(root == NULL) return ;
	if(*root != NULL){
		print_pos_tree(&((*root)->left));
		print_pos_tree(&((*root)->right));
		printf("%i\n", (*root)->info);
	}
}

/* ----------------------------------- Árvore Binária de Busca ----------------------------------- */

// Insere um valor em uma Árvore Binária
int insert(BinTree* root, int value){
	if(root == NULL) return 0;
	
	struct node *newNode;
	newNode = (struct node*) malloc(sizeof(struct node));
	
	if(newNode == NULL) return 0;
	
	newNode->info = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	if(*root == NULL) *root = newNode;
	else{
		struct node* current = *root;
		struct node* pre = NULL;
		
		while(current != NULL){
			pre = current;
			if(value == current->info){ // Checa se o valor já está na Árvore
				free(newNode);
				return 0;
			}
			if(value > current->info) current = current->right;
			else current = current->left;
		}
		
		if(value > pre->info) pre->right = newNode;
		else pre->left = newNode;
	}
	return 1;
}

// Remove um valor de uma Árvore Binária
struct node* remove_current(struct node* current){
	struct node *n1, *n2;
	
	if(current->left == NULL){
		n2 = current->right;
		free(current);
		return n2;
	}
	
	n1 = current;
	n2 = current->left;
	while(n2->right != NULL){
		n1 = n2;
		n2 = n2->right;
	}
	
	if(n1 != current){
		n1->right = n2->left;
		n2->left = current->left;
	}
	n2->right = current->right;
	free(current);
	return n2;
}

int remove_value(BinTree* root, int value){
	if(root == NULL) return 0;
	
	struct node* pre = NULL;
	struct node* current = *root;
	
	while(current != NULL){
		if(value == current->info){
			if(current == *root) *root = remove_current(current);
			else if(pre->right == current) pre->right = remove_current(current);
			else pre->left = remove_current(current);
			return 1;
		}
		pre = current;
		if(value > current->info) current = current->right;
		else current = current->left;
	}
	return 0;
}
// Consulta se um valor está em uma Árvore Binária
int search(BinTree* root, int value){
	if(root == NULL) return 0;
	struct node* current = *root;
	while(current != NULL){
		if(value == current->info) return 1;
		if(value > current->info) current = current->right;
		else current = current->left;
	}
	return 0;
}
