/*
QUESTÃO 04:
Fazer uma função que calcule o MDC (máximo
divisor comum) entre dois números.

*/

#include <stdio.h>

int calculaMDC(int a, int b);

void main(){
	
	int a, b, resultado, aux;
	
	printf("Informe um valor: ");
	scanf("%d", &a);
	
	printf("Informe outro valor: ");
	scanf("%d", &b);
	
	// trocar os valores caso a seja menor que b
	if(a<b){ 
		aux = b;
		b = a;
		a = aux;		
	}
	
	resultado = calculaMDC(a, b);
	
	printf("MDC de %d e %d: %d", a, b, resultado);
	
}

int calculaMDC(int a, int b){
	
	int resto;
				
		
	do{
		
		resto = a % b; //a=24 b=20 resto = 4 // 0
		a = b; // 20 
		b = resto; 	//4
		
	
	}while(resto!=0);
	
	return a;
}
