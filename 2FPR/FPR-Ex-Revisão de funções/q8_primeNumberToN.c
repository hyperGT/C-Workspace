/*
* Print all the prime numbers from 1 to N
*/

#include <stdio.h>

// functions
void primeNumbersN (int n){
	
	// declaração de variáveis
	int i, j, primo;
	
	// percorrendo 1 até n 
	for(i=1; i<=n; i++){
		
		// inicializando a variável de verificação
		primo = 1;
		
		// verificando se é primo ou não
		for(j=i-1; j>1; j--){
			// verificando a partir de i-1 pra 2 se o valor de i possui algum outro divisor alem de 1 e ele mesmo
			// desclassificando-o como número primo
			if(i%j==0){
				primo = 0;
				break;
			}
		}
		
		// verificando se é primo ou não
		if(primo == 1){
			// exibindo o valor
			printf("%d ", i);
		}		
	}
	
}


int main(){
	
	// declaração de variáveis
	int n;
	
	// obtendo os dados 
	printf("Insira N: ");
	scanf("%d", &n);
	
	// chamando a função
	primeNumbersN(n);
	
}
