/*
QUESTÃO 08:
Desenvolver uma função que exiba todos os
números primos inferiores a determinado valor
inteiro N.
*/

#include <stdio.h>

// protótipos das funções
void primosInferioresN(int n);


void main(){
	
	int n;
	
	printf("Insira um valor inteiro n: ");
	scanf("%d", &n);
	
	primosInferioresN(n);
}

void primosInferioresN(int n){
	
	int i, ehPrimo, j;
		
	
	for(i=2; i<=n; i++){
		
		ehPrimo = 2; // ja assumindo que é primo
		j=2; // iniciando o valor divisor
		
		// variando j até i para poder fazer as divisões
		while(j<i){
			
			// verificando se i não é primo
			if(i%j==0){ 
				ehPrimo++; // ehPrimo == 3 ou seja não é primo
				break;
			}
			j++; // incrementa o j caso não tenha entrado na condicional ainda
		}
		
		if(ehPrimo==2){
			printf("\nvalor primo: %d", i);
		}
		
	}
}
