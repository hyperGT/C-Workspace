/*
QUEST�O 08:
Desenvolver uma fun��o que exiba todos os
n�meros primos inferiores a determinado valor
inteiro N.
*/

#include <stdio.h>

// prot�tipos das fun��es
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
		
		ehPrimo = 2; // ja assumindo que � primo
		j=2; // iniciando o valor divisor
		
		// variando j at� i para poder fazer as divis�es
		while(j<i){
			
			// verificando se i n�o � primo
			if(i%j==0){ 
				ehPrimo++; // ehPrimo == 3 ou seja n�o � primo
				break;
			}
			j++; // incrementa o j caso n�o tenha entrado na condicional ainda
		}
		
		if(ehPrimo==2){
			printf("\nvalor primo: %d", i);
		}
		
	}
}
