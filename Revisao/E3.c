#include<stdio.h>

void Troca(int *a, int*b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main (void){
	int a, b;
	printf("Insira dois valores: ");
	scanf("%d %d", &a, &b);
	Troca(&a, &b);
	printf("a = %d, b = %d", a, b);
}
