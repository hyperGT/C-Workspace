/*
* Print all the prime numbers from 1 to N
*/

#include <stdio.h>

// functions
void primeNumbersN (int n){
	
	// declara��o de vari�veis
	int i, j, primo;
	
	// percorrendo 1 at� n 
	for(i=1; i<=n; i++){
		
		// inicializando a vari�vel de verifica��o
		primo = 1;
		
		// verificando se � primo ou n�o
		for(j=i-1; j>1; j--){
			// verificando a partir de i-1 pra 2 se o valor de i possui algum outro divisor alem de 1 e ele mesmo
			// desclassificando-o como n�mero primo
			if(i%j==0){
				primo = 0;
				break;
			}
		}
		
		// verificando se � primo ou n�o
		if(primo == 1){
			// exibindo o valor
			printf("%d ", i);
		}		
	}
	
}


int main(){
	
	// declara��o de vari�veis
	int n;
	
	// obtendo os dados 
	printf("Insira N: ");
	scanf("%d", &n);
	
	// chamando a fun��o
	primeNumbersN(n);
	
}
