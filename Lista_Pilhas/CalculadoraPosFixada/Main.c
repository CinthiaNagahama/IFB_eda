#include <stdio.h>
#include "Calculadora.h"

int main(void){
	char c; 
	float v; 
	Calculadora* calc;
	
	calc = Cria("%.2f\n");
	
	do{
		scanf(" %c", &c);
		if(c == '+' || c == '-' || c == '*' || c == '/'){
			Operador(calc, c);
		}
		else{
			ungetc(c, stdin);
			if(scanf("%f", &v) == 1) Operando(calc, v);
		}
	} while (c != 'q');
	
	Libera(calc);
	return 0;
}
