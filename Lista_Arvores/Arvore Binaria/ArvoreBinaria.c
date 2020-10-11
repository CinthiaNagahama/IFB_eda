#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "ArvoreBinaria.h"
#include "Fila.h"


// Cria um n� ra�z especial que aponta para a ra�z real da �rvore | Facilita balanceamento
BinTree* create_tree(){
	BinTree* root = (BinTree*) malloc(sizeof(BinTree));
	if(root != NULL) *root = NULL;
	return root;
}

// Destr�i uma �rvore Bin�ria
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

// Checa se uma �rvore Bin�ria est� vazia
int is_tree_empty(BinTree* root){
	if(root == NULL || *root == NULL) return 1;
	return 0;
}

// Descobre a altura de uma �rvore Bin�ria
int height(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int leftHeight = height(&((*root)->left));
	int rightHeight = height(&((*root)->right));
	
	if(leftHeight > rightHeight) return (leftHeight + 1);
	else return (rightHeight + 1);
}

// Descobre o total de n�s de uma �rvore Bin�ria
int total_nodes(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int leftTotal = total_nodes(&((*root)->left));
	int rightTotal = total_nodes(&((*root)->right));
	
	return (leftTotal + rightTotal + 1);
}

// Imprime a �rvore Bin�ria percorrendo do jeito Pr�-Ordem
void print_pre_tree(BinTree* root){ // Raiz - Esquerda - Direita
	if(root == NULL) return ;
	if(*root != NULL){
		printf("%i\n", (*root)->info);
		print_pre_tree(&((*root)->left));
		print_pre_tree(&((*root)->right));
	}
}

// Imprime a �rvore Bin�ria percorrendo do jeito Em-Ordem
void print_in_tree(BinTree* root, int side){ // Esquerda - Ra�z - Direita
	if(root == NULL) return ;
	if(*root != NULL){
		print_in_tree(&((*root)->left), -1);
		if(side == -1) printf("l: %i\n", (*root)->info);
		else if(side == 1) printf("r: %i\n", (*root)->info);
		else printf("root: %i\n", (*root)->info);
		print_in_tree(&((*root)->right), 1);
	}
}

// Imprime a �rvore Bin�ria percorrendo do jeito P�s-Ordem
void print_pos_tree(BinTree* root){ // Esquerda - Direita - Ra�z
	if(root == NULL) return ;
	if(*root != NULL){
		print_pos_tree(&((*root)->left));
		print_pos_tree(&((*root)->right));
		printf("%i\n", (*root)->info);
	}
}

/* ----------------------------------- �rvore Bin�ria de Busca ----------------------------------- */

// Insere um valor em uma �rvore Bin�ria
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
			if(value == current->info){ // Checa se o valor j� est� na �rvore
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

// Remove um valor de uma �rvore Bin�ria
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
// Consulta se um valor est� em uma �rvore Bin�ria
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

// Quest�o 2 -> Escreva uma fun��o que conta o n�mero de n�s de uma �rvore bin�ria.
int _conta_no(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
    int esq = _conta_no(&((*root)->left));
    int dir = _conta_no(&((*root)->right));
    
	return (esq + dir + 1);
}

// Quest�o 3 -> Escreva uma fun��o que conta o n�mero de n�s n�o-folha de uma �rvore bin�ria.
int _conta_nao_folha(BinTree* root){
	if(root == NULL || *root == NULL || ((*root)->left == NULL && (*root)->right == NULL)) return 0;
                          
    int esq = _conta_nao_folha(&((*root)->left)); 
    int dir = _conta_nao_folha(&((*root)->right));
    return (esq + dir + 1);
}

// Quest�o 4 -> Escreva uma fun��o que conta o n�mero de folhas de uma �rvore bin�ria.
int _conta_folhas(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	if((*root)->left == NULL && (*root)->right == NULL) return 1;
	
	int folhasEsquerda = _folhas(&((*root)->left));
	int folhasDireita = _folhas(&((*root)->right));
	
	return(folhasEsquerda + folhasDireita);
}

// Quest�o 5 -> Escreva uma fun��o que calcula a altura de uma �rvore bin�ria.
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

// Quest�o 6 -> Escreva uma fun��o para buscar um n�mero �mpar em uma �rvore bin�ria n�o ordenada.
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

// Quest�o 7 -> Escreva uma fun��o para achar o MAIOR n�mero em uma �rvore bin�ria n�o ordenada.
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

// Quest�o 8 -> Escreva uma fun��o que exclui todos os n�s de uma �rvore bin�ria n�o ordenada com ID par
int _exclui_par_desordem(BinTree* root){
    if(root == NULL || *root == NULL) return 0;

    if(_exclui_par_desordem(&((*root)->left))) remove_value(root, (*root)->left->info); 
    if(_exclui_par_desordem(&((*root)->right))) remove_value(root, (*root)->right->info);
        
    if(((*root)->info % 2) == 0) return 1;
    else return 0;
}

// Quest�o 10 -> Escreva uma fun��o que retorna verdadeiro se uma �rvore � bin�ria de busca e falso caso 
//				 contr�rio
int _e_bb(BinTree* root){
	if(root == NULL) return 0;
	
    if((*root) == NULL) return 1; // Testa se atual � nulo
    
    if((*root)->right == NULL && (*root)->left == NULL) return 1; // Testa se atual � folha
    
    if((*root)->right == NULL){ // testa se filho direito � nulo
        if((*root)->left->info < (*root)->info){ // se sim, testa se filho esquerdo � menor que atual
            if(!_e_bb(&((*root)->left))) // se sim, anda pra esquerda e testa o pr�ximo n�
                return 0;
            return 1;
        }
        return 0;
    }
    if((*root)->left == NULL){ // testa se filho da esquerda � nulo
        if((*root)->right->info > (*root)->info){ // se sim, testa se direito � maior que atual
            if(!_e_bb(&((*root)->right))) // se sim, anda para direita e testa o pr�ximo n�
                return 0;
            return 1;
        }
        return 0;
    }
    else{ // se o n� atual tiver dois filhos
        if((*root)->right->info > (*root)->info){ // testa se o filho da direita � maior que atual
            if((*root)->left->info < (*root)->info){ // se sim, testa se o filho da esquerda � menor que atual
                if(!_e_bb(&((*root)->left))) // anda pra esquerda e testa pr�ximo n�
                    return 0;
                if(!_e_bb(&((*root)->right))) // anda pra direita e testa pr�ximo n�
                    return 0;
                return 1;
            }
            return 0;
        }
        return 0;
    }
}

// Quest�o 11 -> Escreva uma fun��o que encontra o valor m�ximo em uma �rvore de busca bin�ria
int _maior(BinTree* root){
    if(root == NULL || *root == NULL) return 0;
    
    if((*root)->right == NULL) return ((*root)->info);
    return _maior(&((*root)->right));
}

// Quest�o 12 -> Escreva uma fun��o que obt�m o espelho de uma �rvore, ou seja, troca a sub�rvore direita pela
//				 subarvore esquerda de todos os n�s da �rvore
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

// Quest�o 13 -> Duas ABBs s�o SIMILARES se possuem a mesma distribui��o de n�s. Em uma defini��o mais formal,
//				 duas ABBs s�o SIMILARES se s�o ambas vazias, ou se suas sub�rvores esquerdas s�o similares, e
//				 suas sub�rvores direitas tambem s�o similares. Implemente a fun��o que verifica se duas �rvores
//				 s�o similares
int _similares(BinTree* r1, BinTree* r2){
	if((r1 == NULL && r2 == NULL) || ((*r1) == NULL && (*r2) == NULL)) return 1;

    if((r1 == NULL || r2 == NULL) || ((*r1) == NULL || (*r2) == NULL)) return 0;

    if(_similares(&((*r1)->left), &((*r2)->left)) && _similares(&((*r1)->right), &((*r2)->right))) return 1;
    else return 0;
}

// Quest�o 14 -> Duas ABBs s�o IGUAIS se s�o ambas vazias ou ent�o se armazenam valores iguais em suas ra�zes,
//				 suas sub�rvores esquerdas s�o iguais, e suas sub�rvores direitas s�o iguais. Implemente a 
//			 	 fun��o que verifica se duas �rvores s�o iguais.
int _iguais(BinTree* r1, BinTree* r2){
	if((r1 == NULL && r2 == NULL) || (*r1 == NULL && *r2 == NULL)) return 1;
	else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) return 0;
	else if((*r1 == NULL && *r2 != NULL) || (*r1 != NULL && *r2 == NULL)) return 0;
	
	int iguais_esquerda = _iguais(&((*r1)->left), &((*r2)->left));
	int iguais_direita = _iguais(&((*r1)->right), &((*r2)->right));
	
	if(!iguais_esquerda || !iguais_direita || (*r1)->info != (*r2)->info) return 0;
	else return 1;
}

// Quest�o 15 -> Uma ABB � estritamente bin�ria se todos os n�s da �rvore tem 2 filhos. Implemente uma fun��o 
//				 que verifica se uma ABB � estritamente bin�ria.
int _binaria(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int esquerda = _binaria(&((*root)->left));
	int direita = _binaria(&((*root)->right));
	
	if(((*root)->left == NULL && (*root)->right != NULL) || ((*root)->left != NULL && (*root)->right == NULL)) return -1;
	else return(esquerda == direita);
}

// Quest�o 24 -> Escreva fun��es n�o recursivas para realizar os 3 tipos de percurso na �rvore bin�ria:
//					(a) pr�-ordem
//					(b) em-ordem
// 					(c) p�s-ordem

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

// Quest�o 25 -> Escreva uma fun��o n�o-recursiva que retorne o menor valor de uma �rvore bin�ria (n�o ordenada)
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

// Quest�o 26 -> Escreva uma fun��o n�o-recursiva que retorne o menor valor de uma �rvore bin�ria de busca;
int _menor_nao_recursivo(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
    struct node* atual = *root;
    while(atual->left != NULL) atual = atual->left;
    return atual->info;
}

// Quest�o 28 -> Escreva uma fun��o que retorne o elemento menor ou igual(floor) que um de refer�ncia x em 
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
    // testa se x � menor ou igual ao menor valor da �rvore
    if(min > x){
    	printf("%i � maior que o menor valor existente na �rvore", x);
    	return min;
	}
    if(min == x) return min;

    // testa se x � maior ou igual ao maior valor da �rvore
    if(max <= x) return max;
    
    return _busca_floor(root, x);
}

// Quest�o 29 -> Escreva uma fun��o n�o-recursiva que verifique a exist�ncia de um valor X na �rvore bin�ria.
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

// Quest�o 30 -> Escreva uma fun��o n�o-recursiva que verifique a exist�ncia de um valor negativo na �rvore 
//				 bin�ria.
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

// Quest�o 31 -> Escreva uma fun��o n�o-recursiva que verifique se uma �rvore bin�ria � tamb�m de busca.
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

// Quest�o 34 -> Escreva e implemente um algoritmo que dada uma ABB, construa uma outra �rvore ABB 
// 				 aproximadamente completa. Para isso, obtenha todas as chaves e valores e insira na nova �rvore
//				 sempre o elemento mediano das chaves ainda n�o inseridas.
/*
BinTree* _copia(BinTree* root){
	
}
*/

// Quest�o 35 ->  Fa�a uma fun��o que retorne a quantidade de folhas de uma �rvore bin�ria de busca.
int _folhas(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	if((*root)->left == NULL && (*root)->right == NULL) return 1;
	
	int folhasEsquerda = _folhas(&((*root)->left));
	int folhasDireita = _folhas(&((*root)->right));
	
	return(folhasEsquerda + folhasDireita);
}

// Quest�o 36 -> Fa�a uma fun��o que retorne a quantidade de n�s de uma �rvore bin�ria de busca que possuem 
//				 apenas um filho.
int _um_filho(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int nos_esquerda = _um_filho(&((*root)->left));
	int nos_direita = _um_filho(&((*root)->right));
	
	if(((*root)->left == NULL && (*root)->right != NULL) || ((*root)->left != NULL && (*root)->right == NULL)) return(nos_esquerda + nos_direita + 1);
	else return(nos_esquerda + nos_direita);
}

// Quest�o 37 -> Fa�a uma fun��o que, dada uma �rvore bin�ria de busca, retorne a quantidade de n�s que guardam
//				 n�meros primos
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

// Quest�o 38 ->  Fa�a uma fun��o que compare se duas �rvores bin�rias de busca s�o iguais.
/* // Igual a Quest�o 14
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

// Quest�o 39 -> Fa�a uma fun��o que retorna a lista de caminhos da raiz at� cada folha.
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

// Quest�o 40 -> Escreva uma fun��o que fa�a o percurso em n�vel em uma �rvore bin�ria.
void _imprime_em_nivel(BinTree* root){
	int altura = height(root), i;
	for(i = 0; i < altura; i++){
		printf("Nivel %d: \n ", i);
		_imprime_nivel(*root, i);
		printf("\n");
	}
}

// Quest�o 46 -> Implemente uma fun��o que verifica se uma �rvore bin�ria de busca � estritamente bin�ria.
/* Igual a 15
int _binaria(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	int esquerda = _binaria(&((*root)->left));
	int direita = _binaria(&((*root)->right));
	
	if(((*root)->left == NULL && (*root)->right != NULL) || ((*root)->left != NULL && (*root)->right == NULL)) return -1;
	else return(esquerda == direita);
}
*/

// Quest�o 47 -> Escreva um programa para copiar uma �rvore bin�ria.
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

// Quest�o 49 -> Modifique a implementa��o da �rvore de busca bin�ria para que ela lide corretamente com chaves
// 				 duplicadas. Isto �, se uma chave j� est� na �rvore, a nova dever� substituir a antiga.
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

// Quest�o 58 -> Projete um algoritmo para determinar o menor n�mero em uma �rvore AVL.
int _encontra_menor(BinTree* root){
	struct node *n1 = (*root), *n2 = (*root)->left;
	while(n2 != NULL){
		n1 = n2;
		n2 = n2->left;
	}
	return n1->info;
}

// Quest�o 59 -> Escreva uma fun��o que receba um n�vel da �rvore e imprima todos os n�s nesse n�vel
void _imprime_nivel(struct node* no, int nivel){
	if(no == NULL) return ;
	if(nivel == 0) printf(" %d ", no->info);
	else{
		_imprime_nivel(no->left, nivel-1);
		_imprime_nivel(no->right, nivel-1);
	}
}

// Quest�o 60 -> Escreva a fun��o que retorna o n�mero de n�s que s�o divisores da soma de seus filhos. Leve em
//				 conta apenas os n�s com dois filhos.
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

// Quest�o 62 -> Em uma �rvore bin�ria, fa�a um algoritmo para alterar o valor de cada n� (exceto n� folha) para
//				 a soma dos valores dos n�s esquerda e direita
int _soma(struct node* no){
	if(no == NULL) return ;
	// Se for folha n�o mexe
	if(no->left == NULL && no->right == NULL) return no->info; 
	// Se s� tiver um filho
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

// Quest�o 64 -> Fa�a um algoritmo que crie uma lista ligada com os n�s de uma �rvore bin�ria em um percurso
//				 em-ordem.
void _no_em_ordem(BinTree* root, Lista** lst){
	if(root == NULL) return ;
	if(*root != NULL){
		// Ao contr�rio para a lista ficar certa
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


// Quest�o 65 -> Fa�a um algoritmo para somar os n�s presentes nos n�veis �mpares de uma �rvore bin�ria
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

// Quest�o 66 -> Implementar uma fun��o n�o-recursiva para calcular o tamanho de uma �rvore bin�ria.
int _altura(BinTree* root){
	if(root == NULL || *root == NULL) return 0;
	
	Fila* f = cria_fila();
	insere_fila(f, *root);
	int altura = 0;

	while(1){
		int qtd = f->qtd; // qtd -> quantidade de n�s em um n�vel
		// Se n�o houver n�s no n�vel
		if(qtd == 0) return altura;
		
		// Se houver n�s no n�vel
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
