/*
Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).
*/

#include <stdio.h>
#include <string.h>

// funções
void decimalToBinary (int n, char *binario, int *index);

void main(){
	
	char binario[32]; // string para armazenar o valor binario
	int n, index = 0;
	
	memset(binario, '\0', sizeof(binario));
	
	printf("Insira um valor para converter para base 2: ");
	scanf("%d", &n);
	
	decimalToBinary(n, binario, &index);
	
	printf("O numero %d em binário é: %s\n", n, binario);
}


void decimalToBinary (int n, char *binario, int *index){
	
	if(n<2){
		binario[(*index)++] = n + '0'; // Converte o número para caractere e armazena
		return;
	}else{
		
		// chama a função recursivamente com 'n' dividido por 2	
		decimalToBinary(n/2, binario, index);
		
		binario[(*index)++] = (n % 2) + '0'; // converte o numero em caractere e armazena
	}
}

/*

*/
