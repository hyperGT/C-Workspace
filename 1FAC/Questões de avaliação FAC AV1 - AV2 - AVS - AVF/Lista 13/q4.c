/*
Quest�o 04:
Fazer uma fun��o que, dados dois n�meros
inteiros num1 e num2, determine se num2 �
uma pot�ncia de num1.

para n2 ser potencia de n1, ele tem que ser 
1. maior que n1
2. multiplicando n1 x vezes o resultado em algum momento tem que ser igual a n2
*/

#include <stdio.h>

// fun��es
int pot(int n1, int n2){
	
	int i;
	
	i=n1;
	while(i<n2){
		printf("i = %d\n", i);
		i*=n1;
	}
	
	printf("i = %d\n", i);
	
	// verificando se s�o iguais 
	if(i==n2){
		return 1; // � pot�ncia
	}else{
		return -1; // n�o � pot�ncia
	}
	
}

int main(){
	
	int n1, n2, result;
	
	printf("Insira n1: ");
	scanf("%d", &n1);
	
	printf("Insira n2: ");
	scanf("%d", &n2);
	
	result = pot(n1, n2);
	
	if(result == 1){
		printf("n2 e potencia de n1");
	}else{
		printf("n2 NAO e potencia de n1");
	}
}
