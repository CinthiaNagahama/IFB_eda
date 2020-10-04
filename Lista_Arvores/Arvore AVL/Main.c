#include <stdio.h>
#include "avl.h"

int main(void){
	AvlTree* tree = create_tree();
	
	free_tree(tree);
	return 0;
}
