/*
Quest�o 04:
Fazer uma fun��o recursiva que, dado um
n�mero inteiro N, exiba o mesmo na base 2
(bin�ria).
*/

#include <stdio.h>
#include <string.h>

// fun��es
void decimalToBinary (int n, char *binario, int *index);

void main(){
	
	char binario[32]; // string para armazenar o valor binario
	int n, index = 0;
	
	memset(binario, '\0', sizeof(binario));
	
	printf("Insira um valor para converter para base 2: ");
	scanf("%d", &n);
	
	decimalToBinary(n, binario, &index);
	
	printf("O numero %d em bin�rio �: %s\n", n, binario);
}


void decimalToBinary (int n, char *binario, int *index){
	
	if(n<2){
		binario[(*index)++] = n + '0'; // Converte o n�mero para caractere e armazena
		return;
	}else{
		
		// chama a fun��o recursivamente com 'n' dividido por 2	
		decimalToBinary(n/2, binario, index);
		
		binario[(*index)++] = (n % 2) + '0'; // converte o numero em caractere e armazena
	}
}

/*

*/
