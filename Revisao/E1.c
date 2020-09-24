#include <stdio.h>

struct cadastro {
    char nome[50];
    int idade;
    char rua[50];
    int numero;
};
typedef struct cadastro Cadastro;

int main (void) {
	Cadastro c[2];
	int i;
	for(i = 0; i < 2; i++){
		fflush(stdin);
		fgets(c[i].nome, 50, stdin);
		
		fflush(stdin);
		scanf("%d", &c[i].idade);
		
		fflush(stdin);
		fgets(c[i].rua, 50, stdin);
		
		fflush(stdin);
		scanf("%d", &c[i].numero);
	}
	
	while(i > -1){
		printf("\nNome: %s\nIdade: %i\nRua: %s\nNumero: %i\n", c[i].nome, c[i].idade, c[i].rua, c[i].numero);
		i--;
	}
	system("pause");
	return 0;
}
