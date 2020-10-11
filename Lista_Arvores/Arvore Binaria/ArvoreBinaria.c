#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "ArvoreBinaria.h"
#include "Fila.h"


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

/* -------------------------------------------- Lista -------------------------------------------- */

// Questão 2 -> Escreva uma função que conta o número de nós de uma árvore binária.
int _conta_no(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
    int esq = _conta_no(&((*root)->left));
    int dir = _conta_no(&((*root)->right));
    
	return (esq + dir + 1);
}

// Questão 3 -> Escreva uma função que conta o número de nós não-folha de uma árvore binária.
int _conta_nao_folha(BinTree* root){
	if(root == NULL || *root == NULL || ((*root)->left == NULL && (*root)->right == NULL)) return 0;
                          
    int esq = _conta_nao_folha(&((*root)->left)); 
    int dir = _conta_nao_folha(&((*root)->right));
    return (esq + dir + 1);
}

// Questão 4 -> Escreva uma função que conta o número de folhas de uma árvore binária.
int _conta_folhas(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	if((*root)->left == NULL && (*root)->right == NULL) return 1;
	
	int folhasEsquerda = _folhas(&((*root)->left));
	int folhasDireita = _folhas(&((*root)->right));
	
	return(folhasEsquerda + folhasDireita);
}

// Questão 5 -> Escreva uma função que calcula a altura de uma árvore binária.
// Feita anteriormente (slide)
/*
int height(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int leftHeight = height(&((*root)->left));
	int rightHeight = height(&((*root)->right));
	
	if(leftHeight > rightHeight) return (leftHeight + 1);
	else return (rightHeight + 1);
}
*/

// Questão 6 -> Escreva uma função para buscar um número ímpar em uma árvore binária não ordenada.
int _impar_desordem(BinTree* root){
    if(root == NULL || *root == NULL) return 0;
    struct node* atual = *root;
    if((atual->info % 2) != 0) return atual->info;
    else{
        int x;
        x = _impar_desordem(&(atual->left)); 
        if((x % 2) != 0) 
            return x;
        x = _impar_desordem(&(atual->right));
        if((x % 2) != 0) 
            return x;
        return x;
    }
}

// Questão 7 -> Escreva uma função para achar o MAIOR número em uma árvore binária não ordenada.
int _maior_desordem(BinTree* root){
	if(root == NULL || *root == NULL){
        printf("Arvore vazia.\n");
        return 0;
    }
    
    if((*root)->right == NULL && (*root)->left == NULL)
        return (*root)->info;
        
    int esq, dir;
    esq = _maior_desordem(&((*root)->left));
    dir = _maior_desordem(&((*root)->right));
    
    if((*root)->info > esq && (*root)->info > dir)
        return ((*root)->info);
    else if (esq > dir)
        return esq;
    else
        return dir;
}

// Questão 8 -> Escreva uma função que exclui todos os nós de uma árvore binária não ordenada com ID par
int _exclui_par_desordem(BinTree* root){
    if(root == NULL || *root == NULL) return 0;

    if(_exclui_par_desordem(&((*root)->left))) remove_value(root, (*root)->left->info); 
    if(_exclui_par_desordem(&((*root)->right))) remove_value(root, (*root)->right->info);
        
    if(((*root)->info % 2) == 0) return 1;
    else return 0;
}

// Questão 10 -> Escreva uma função que retorna verdadeiro se uma árvore é binária de busca e falso caso 
//				 contrário
int _e_bb(BinTree* root){
	if(root == NULL) return 0;
	
    if((*root) == NULL) return 1; // Testa se atual é nulo
    
    if((*root)->right == NULL && (*root)->left == NULL) return 1; // Testa se atual é folha
    
    if((*root)->right == NULL){ // testa se filho direito é nulo
        if((*root)->left->info < (*root)->info){ // se sim, testa se filho esquerdo é menor que atual
            if(!_e_bb(&((*root)->left))) // se sim, anda pra esquerda e testa o próximo nó
                return 0;
            return 1;
        }
        return 0;
    }
    if((*root)->left == NULL){ // testa se filho da esquerda é nulo
        if((*root)->right->info > (*root)->info){ // se sim, testa se direito é maior que atual
            if(!_e_bb(&((*root)->right))) // se sim, anda para direita e testa o próximo nó
                return 0;
            return 1;
        }
        return 0;
    }
    else{ // se o nó atual tiver dois filhos
        if((*root)->right->info > (*root)->info){ // testa se o filho da direita é maior que atual
            if((*root)->left->info < (*root)->info){ // se sim, testa se o filho da esquerda é menor que atual
                if(!_e_bb(&((*root)->left))) // anda pra esquerda e testa próximo nó
                    return 0;
                if(!_e_bb(&((*root)->right))) // anda pra direita e testa próximo nó
                    return 0;
                return 1;
            }
            return 0;
        }
        return 0;
    }
}

// Questão 11 -> Escreva uma função que encontra o valor máximo em uma árvore de busca binária
int _maior(BinTree* root){
    if(root == NULL || *root == NULL) return 0;
    
    if((*root)->right == NULL) return ((*root)->info);
    return _maior(&((*root)->right));
}

// Questão 12 -> Escreva uma função que obtém o espelho de uma árvore, ou seja, troca a subárvore direita pela
//				 subarvore esquerda de todos os nós da árvore
struct node* _inverte(BinTree* root){
    if(*root == NULL) return NULL;
    
    BinTree aux = (*root)->right;
    (*root)->right = _inverte(&((*root)->left));
    (*root)->left = _inverte(&aux);
    return *root;
}
void _inverte_arvore(BinTree* root){
    if(root == NULL) return;
    *root = _inverte(root);
}

// Questão 13 -> Duas ABBs são SIMILARES se possuem a mesma distribuição de nós. Em uma definição mais formal,
//				 duas ABBs são SIMILARES se são ambas vazias, ou se suas subárvores esquerdas são similares, e
//				 suas subárvores direitas tambem são similares. Implemente a função que verifica se duas árvores
//				 são similares
int _similares(BinTree* r1, BinTree* r2){
	if((r1 == NULL && r2 == NULL) || ((*r1) == NULL && (*r2) == NULL)) return 1;

    if((r1 == NULL || r2 == NULL) || ((*r1) == NULL || (*r2) == NULL)) return 0;

    if(_similares(&((*r1)->left), &((*r2)->left)) && _similares(&((*r1)->right), &((*r2)->right))) return 1;
    else return 0;
}

// Questão 14 -> Duas ABBs são IGUAIS se são ambas vazias ou então se armazenam valores iguais em suas raízes,
//				 suas subárvores esquerdas são iguais, e suas subárvores direitas são iguais. Implemente a 
//			 	 função que verifica se duas árvores são iguais.
int _iguais(BinTree* r1, BinTree* r2){
	if((r1 == NULL && r2 == NULL) || (*r1 == NULL && *r2 == NULL)) return 1;
	else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) return 0;
	else if((*r1 == NULL && *r2 != NULL) || (*r1 != NULL && *r2 == NULL)) return 0;
	
	int iguais_esquerda = _iguais(&((*r1)->left), &((*r2)->left));
	int iguais_direita = _iguais(&((*r1)->right), &((*r2)->right));
	
	if(!iguais_esquerda || !iguais_direita || (*r1)->info != (*r2)->info) return 0;
	else return 1;
}

// Questão 15 -> Uma ABB é estritamente binária se todos os nós da árvore tem 2 filhos. Implemente uma função 
//				 que verifica se uma ABB é estritamente binária.
int _binaria(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int esquerda = _binaria(&((*root)->left));
	int direita = _binaria(&((*root)->right));
	
	if(((*root)->left == NULL && (*root)->right != NULL) || ((*root)->left != NULL && (*root)->right == NULL)) return -1;
	else return(esquerda == direita);
}

// Questão 24 -> Escreva funções não recursivas para realizar os 3 tipos de percurso na árvore binária:
//					(a) pré-ordem
//					(b) em-ordem
// 					(c) pós-ordem

void _pre_ordem_nao_recursivo(BinTree* root){
	if(root == NULL) return ;
	
    struct node* atual = *root;
    Pilha* p;
    p = cria_pilha();
    
    while(atual != NULL){
        printf("%i ", atual->info);
        if(atual->right != NULL) insere_pilha(p, atual->right);
        if(atual->left != NULL) atual = atual->left;
        else{
            atual = consulta_pilha(p);
            remove_pilha(p);
        }
    }
    libera_pilha(p);
}

void _em_ordem_nao_recursivo(BinTree* root){
	if(root == NULL) return ;
	
    struct node* atual = *root;
    Pilha* p;
    p = cria_pilha();
    
    while(atual != NULL){
        if(atual->rigth != NULL && atual->left == NULL){
            printf("%i ", atual->info);
            atual = atual->right;
            continue;
        }
        if(atual->right != NULL) insere_pilha(p, atual->right);
        if(atual->left != NULL){
            insere_pilha(p, atual);
            atual = atual->left;
        }
        else{
            printf("%i ", atual->info);
            atual = consulta_pilha(p);
            remove_pilha_dn(p);
            if(atual == NULL) break;
            printf("%i ", atual->info);
            atual = consulta_pilha(p);
            remove_pilha(p);
        }
    }
    libera_pilha(p);
}

void _pos_ordem_nao_recursivo(BinTree* root){
	if(root == NULL) return ;
	
    struct node* atual = *root;
    Pilha* p1, *p2;
    p1 = cria_pilha();
    p2 = cria_pilha();
    
    while(atual != NULL){
        insere_pilha(p1, atual);
        if(atual->left == NULL){
            if(atual->right == NULL){
                printf("%i ", atual->info);
                remove_pilha(p1);
                atual = consulta_pilha(p1);
                if(atual == NULL) break;
                
                // loop enquanto p1 e p2 forem iguais e p2 nao for nulo
                // volta se ja tiver visitado todos os filhos do no
                while(consulta_pilha(p1) == consulta_pilha(p2) && consulta_pilha(p2) != NULL){
                    printf("%i ", atual->info);
                    remove_pilha(p1);
                    remove_pilha(p2);
                    atual = consulta_pilha(p1);
                    if(atual == NULL) break;
                }
            }
            
            if(atual == NULL) break;
            
            insere_pilha(p2, atual);
            if(atual->right == NULL) printf("%i ", atual->info);
            
            atual = atual->right;
            while(atual == NULL){
            	
                // loop enquanto p1 e p2 forem iguais e p2 nao for nulo
                // volta se ja tiver visitado todos os filhos do no
                while(consulta_pilha(p1) == consulta_pilha(p2) && consulta_pilha(p2) != NULL){
                    if(atual != NULL) printf("%i ", atual->info);
                    remove_pilha(p1);
                    remove_pilha(p2);
                    atual = consulta_pilha(p1);
                    if(atual == NULL) break;
                }
                if(atual == NULL) break;
                insere_pilha(p2, atual);
                if(atual->right == NULL) printf("%i ", atual->info);
                atual = atual->right;
            }
        }
        else
            atual = atual->left;
    }
    libera_pilha(p1);
    libera_pilha(p2);
}

// Questão 25 -> Escreva uma função não-recursiva que retorne o menor valor de uma árvore binária (não ordenada)
int _menor_nao_recursivo_desordem(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
    Pilha* p;
    p = cria_pilha();
    struct node* atual = *root;
    int menor = (*root)->info;
    
    while(atual != NULL){
        if(menor > atual->info) menor = atual->info;
        
        if(atual->right != NULL) insere_pilha(p, atual->right);
        if(atual->left != NULL) atual = atual->left;
        else{
            atual = consulta_pilha(p);
            remove_pilha(p);
        }
    }
    libera_pilha(p);
    return menor;
}

// Questão 26 -> Escreva uma função não-recursiva que retorne o menor valor de uma árvore binária de busca;
int _menor_nao_recursivo(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
    struct node* atual = *root;
    while(atual->left != NULL) atual = atual->left;
    return atual->info;
}

// Questão 28 -> Escreva uma função que retorne o elemento menor ou igual(floor) que um de referência x em 
//				 uma ABB.
int _minimo(BinTree* root){
    if(root == NULL || *root == NULL) return 0;
    
    if((*root)->left == NULL) return ((*root)->info);
    return _minimo(&((*root)->left));
}
int _busca_floor(BinTree* root, int x){
    if((*root)->info == x || ((*root)->left == NULL && (*root)->right == NULL)) return (*root)->info;
    
	int aux;
    if(x > (*root)->info){ 
        if((*root)->right != NULL){
            aux = _busca_floor(&((*root)->right), x);
            if(aux <= x) return aux;
        }
        return (*root)->info;
    }
    else{
        if((*root)->left != NULL){ 
            aux = _busca_floor(&((*root)->left), x);
            if(aux <= x) return aux;
        }
        return (*root)->info;
    }
}
int _floor(BinTree* root, int x){
	if(root == NULL || *root == NULL) return 0;
	
    int min = _minimo(root), max = _maior(root);
    // testa se x é menor ou igual ao menor valor da árvore
    if(min > x){
    	printf("%i é maior que o menor valor existente na árvore", x);
    	return min;
	}
    if(min == x) return min;

    // testa se x é maior ou igual ao maior valor da árvore
    if(max <= x) return max;
    
    return _busca_floor(root, x);
}

// Questão 29 -> Escreva uma função não-recursiva que verifique a existência de um valor X na árvore binária.
int _existe_x(BinTree* root, int x){
	if(root == NULL || *root == NULL) return 0;

    struct node* atual = *root;
    Fila* f;
    f = cria_fila();
    
    while(atual != NULL){
        if(atual->info == x) return 1;
        
        if(atual->right != NULL) insere_fila(f, atual->right);
        if(atual->left != NULL) insere_fila(f, atual->left);
        atual = retira(f);
    }
    libera_fila(f);
    return 0;
}

// Questão 30 -> Escreva uma função não-recursiva que verifique a existência de um valor negativo na árvore 
//				 binária.
int _existe_negativo(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
    struct node* atual = *root;
    Fila* f;
    f = cria_fila();
    
    while(atual != NULL){
        if(atual->info < 0) return 1;

        if(atual->right != NULL) insere_fila(f, atual->right);
        if(atual->left != NULL) insere_fila(f, atual->left);
        atual = retira(f);
    }
    libera_fila(f);
    return 0;
}

// Questão 31 -> Escreva uma função não-recursiva que verifique se uma árvore binária é também de busca.
int _e_bb_nao_recursiva(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
    struct node* atual = *root;
    Fila* f;
    f = cria_fila();
    
    while(atual != NULL){
        if(atual->right != NULL){
            if(atual->right->info > atual->info) insere_fila(f, atual->right);
            else{
                libera_fila(f);
                return 0;
            }
        }
        if(atual->left != NULL){
            if(atual->left->info < atual->info) insere_fila(f, atual->left); 
			else{
                libera_fila(f);
                return 0;
            }
        }
        atual = retira(f);
    }
    
    libera_fila(f);
    return 1;
}

// Questão 34 -> Escreva e implemente um algoritmo que dada uma ABB, construa uma outra árvore ABB 
// 				 aproximadamente completa. Para isso, obtenha todas as chaves e valores e insira na nova árvore
//				 sempre o elemento mediano das chaves ainda não inseridas.
/*
BinTree* _copia(BinTree* root){
	
}
*/

// Questão 35 ->  Faça uma função que retorne a quantidade de folhas de uma árvore binária de busca.
int _folhas(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	if((*root)->left == NULL && (*root)->right == NULL) return 1;
	
	int folhasEsquerda = _folhas(&((*root)->left));
	int folhasDireita = _folhas(&((*root)->right));
	
	return(folhasEsquerda + folhasDireita);
}

// Questão 36 -> Faça uma função que retorne a quantidade de nós de uma árvore binária de busca que possuem 
//				 apenas um filho.
int _um_filho(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int nos_esquerda = _um_filho(&((*root)->left));
	int nos_direita = _um_filho(&((*root)->right));
	
	if(((*root)->left == NULL && (*root)->right != NULL) || ((*root)->left != NULL && (*root)->right == NULL)) return(nos_esquerda + nos_direita + 1);
	else return(nos_esquerda + nos_direita);
}

// Questão 37 -> Faça uma função que, dada uma árvore binária de busca, retorne a quantidade de nós que guardam
//				 números primos
int _primos(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int primos_esquerda = _primos(&((*root)->left));
	int primos_direita = _primos(&((*root)->right));
	
	int i, primo = 1, num = (*root)->info;
	if(num == 0 || num == 1) primo = 0;
	for(i = 2; i <= num / 2; i++){
		if(num % i == 0){
			primo = 0;
			break;
		}
	}
	
	if(primo) return(primos_esquerda + primos_direita + 1);
	else return(primos_esquerda + primos_direita);
}

// Questão 38 ->  Faça uma função que compare se duas árvores binárias de busca são iguais.
/* // Igual a Questão 14
int _iguais(BinTree* r1, BinTree* r2){
	if((r1 == NULL && r2 == NULL) || (*r1 == NULL && *r2 == NULL)) return 1;
	else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) return 0;
	else if((*r1 == NULL && *r2 != NULL) || (*r1 != NULL && *r2 == NULL)) return 0;
	
	int iguais_esquerda = _iguais(&((*r1)->left), &((*r2)->left));
	int iguais_direita = _iguais(&((*r1)->right), &((*r2)->right));
	
	if(!iguais_esquerda || !iguais_direita || (*r1)->info != (*r2)->info) return 0;
	else return 1;
}
*/

// Questão 39 -> Faça uma função que retorna a lista de caminhos da raiz até cada folha.
void _caminho(struct node* no, int* caminho, int tam){
	if(no == NULL) return ;
	
	caminho[tam] = no->info;
	tam++;
	
	if(no->left == NULL && no->right == NULL){
		int i;
		for(i = 0; i < tam; i++) printf("%i ", caminho[i]);
		printf("\n\t");
	}
	else {
		_caminho(no->left, caminho, tam);
		_caminho(no->right, caminho, tam);
	}
}

void _encontra_caminho(BinTree* root){
	int caminho[1000];
	printf("Caminhos raiz-folha: \n\t");
	_caminho((*root), caminho, 0);
}

// Questão 40 -> Escreva uma função que faça o percurso em nível em uma árvore binária.
void _imprime_em_nivel(BinTree* root){
	int altura = height(root), i;
	for(i = 0; i < altura; i++){
		printf("Nivel %d: \n ", i);
		_imprime_nivel(*root, i);
		printf("\n");
	}
}

// Questão 46 -> Implemente uma função que verifica se uma árvore binária de busca é estritamente binária.
/* Igual a 15
int _binaria(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int esquerda = _binaria(&((*root)->left));
	int direita = _binaria(&((*root)->right));
	
	if(((*root)->left == NULL && (*root)->right != NULL) || ((*root)->left != NULL && (*root)->right == NULL)) return -1;
	else return(esquerda == direita);
}
*/

// Questão 47 -> Escreva um programa para copiar uma árvore binária.
int _valor_no(BinTree* novo, struct node* no, int nivel){
	if(no == NULL) return ;
	if(nivel == 0) insert(novo, no->info);
	else{
		_valor_no(novo, no->left, nivel-1);
		_valor_no(novo, no->right, nivel-1);
	}
}

BinTree* _copia(BinTree* root){
	BinTree* novo = create_tree();
	int altura = height(root), i;
	for(i = 0; i < altura; i++){
		_valor_no(novo, *root, i);
	}
	return novo;
}

// Questão 49 -> Modifique a implementação da árvore de busca binária para que ela lide corretamente com chaves
// 				 duplicadas. Isto é, se uma chave já está na árvore, a nova deverá substituir a antiga.
int _insere(BinTree* root, int value){
	if(root == NULL) return 0;
	
	struct node *novo;
	novo = (struct node*) malloc(sizeof(struct node));
	
	if(novo == NULL) return 0;
	
	novo->info = value;
	novo->left = NULL;
	novo->right = NULL;
	
	if(*root == NULL) *root = novo;
	else{
		struct node* current = *root;
		struct node* pre = NULL;
		
		while(current != NULL){
			pre = current;
			if(value == current->info){
				novo->left = current->left;
				novo->right = current->right;
				current = novo;
				return 1;
			}
			if(value > current->info) current = current->right;
			else current = current->left;
		}
		
		if(value > pre->info) pre->right = novo;
		else pre->left = novo;
	}
	return 1;
}

// Questão 58 -> Projete um algoritmo para determinar o menor número em uma árvore AVL.
int _encontra_menor(BinTree* root){
	struct node *n1 = (*root), *n2 = (*root)->left;
	while(n2 != NULL){
		n1 = n2;
		n2 = n2->left;
	}
	return n1->info;
}

// Questão 59 -> Escreva uma função que receba um nível da árvore e imprima todos os nós nesse nível
void _imprime_nivel(struct node* no, int nivel){
	if(no == NULL) return ;
	if(nivel == 0) printf(" %d ", no->info);
	else{
		_imprime_nivel(no->left, nivel-1);
		_imprime_nivel(no->right, nivel-1);
	}
}

// Questão 60 -> Escreva a função que retorna o número de nós que são divisores da soma de seus filhos. Leve em
//				 conta apenas os nós com dois filhos.
void _divisor(struct node* no, int nivel, int* divisores){
	if(no == NULL) return ;
	if(nivel == 0) {
		if(no->left == NULL || no->right == NULL) return ;
		if (((no->left->info + no->right->info) % no->info) == 0) (*divisores)++;
	}
	else{
		_divisor(no->left, nivel-1, &(*divisores));
		_divisor(no->right, nivel-1, &(*divisores));
	}
}

int _divisores(BinTree* root){
	int i, divisores = 0;
	for(i = 0; i < height(root); i++){
		_divisor(*root, i, &divisores);
	}
	return divisores;
}

// Questão 62 -> Em uma árvore binária, faça um algoritmo para alterar o valor de cada nó (exceto nó folha) para
//				 a soma dos valores dos nós esquerda e direita
int _soma(struct node* no){
	if(no == NULL) return ;
	// Se for folha não mexe
	if(no->left == NULL && no->right == NULL) return no->info; 
	// Se só tiver um filho
	if(no->left == NULL && no->right != NULL) return no->right->info;
	else if(no->left != NULL && no->right == NULL) return no->left->info;
	// Se tiver dois filhos
	else return (no->left->info + no->right->info);
}

void _troca_em_nivel(struct node* no, int nivel){
	if(no == NULL) return ;
	if(nivel == 0) no->info = _soma(no);
	else{
		_troca_em_nivel(no->left, nivel-1);
		_troca_em_nivel(no->right, nivel-1);
	}
}

void _vira_soma(BinTree* root){
	int i;
	for(i = 0; i < height(root); i++){
		_troca_em_nivel(*root, i);
	}
}

// Questão 64 -> Faça um algoritmo que crie uma lista ligada com os nós de uma árvore binária em um percurso
//				 em-ordem.
void _no_em_ordem(BinTree* root, Lista** lst){
	if(root == NULL) return ;
	if(*root != NULL){
		// Ao contrário para a lista ficar certa
		_no_em_ordem(&((*root)->right), &(*lst));
		*lst = Insere_Valor(*lst, *root);
		_no_em_ordem(&((*root)->left), &(*lst));
	}
}

Lista* _lista(BinTree* root){
	Lista* lst = Cria_Lista();
	_no_em_ordem(root, &lst);
	return lst;
}


// Questão 65 -> Faça um algoritmo para somar os nós presentes nos níveis ímpares de uma árvore binária
void _nos_por_nivel(struct node* no, int nivel, int* soma){
	if(no == NULL) return ;
	if(nivel == 0) *soma += no->info;
	else{
		_nos_por_nivel(no->left, nivel-1, &(*soma));
		_nos_por_nivel(no->right, nivel-1, &(*soma));
	}
}

int _soma_impares(BinTree* root){
	int i, soma = 0;
	for(i = 1; i < height(root); i += 2){
		_nos_por_nivel(*root, i, &soma);
	}
	return soma;
}

// Questão 66 -> Implementar uma função não-recursiva para calcular o tamanho de uma árvore binária.
int _altura(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	Fila* f = cria_fila();
	insere_fila(f, *root);
	int altura = 0;

	while(1){
		int qtd = f->qtd; // qtd -> quantidade de nós em um nível
		// Se não houver nós no nível
		if(qtd == 0) return altura;
		
		// Se houver nós no nível
		altura++;
		while(qtd > 0){
			// Retira o pai da fila
			struct node* no = retira_fila(f); 
			
			// Aloca os filhos na fila
			if(no->left != NULL) insere_fila(f, no->left);
			if(no->right != NULL) insere_fila(f, no->right);
			qtd--;
		}
	}
}
