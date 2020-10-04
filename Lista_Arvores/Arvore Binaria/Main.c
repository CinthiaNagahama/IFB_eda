#include <stdio.h>
#include "ArvoreBinaria.h"

int main(void){
	BinTree* tree = create_tree();
	insert(tree, 2);
	insert(tree, 0);
	insert(tree, 5);
	insert(tree, 4);
	insert(tree, 7);
	insert(tree, 19);
	
	print_in_tree(tree, 0);
	
	remove_value(tree, 7);
	return 0;
}
