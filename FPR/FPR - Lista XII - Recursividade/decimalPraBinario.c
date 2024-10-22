/*
Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).
*/

#include <stdio.h>

// funções
void decimalToBinary (int n);

void main(){
	
	int n = 10;
	
	decimalToBinary(n);
}


void decimalToBinary (int n){
	
	if(n<2){
		printf("%d", n);
		return 0;
	}else{
		
		
		decimalToBinary(n/2);
		
		printf("%d", n % 2);
	}
}

/*
	decimalToBinary(10/2) -> n = 5 resto = 0
		decimalToBinary(5/2) -> n = 2 resto = 1
			decimalToBinary(2/2) -> n = 1 resto = 0
				decimalToBinary(1/2) -> n = 1  resto = 1
				
Relembrando conversão decimal para binário:
	10/2
	0  5/2
	   1 2/2
	   	 0 1 <- ultimo quociente
*/
