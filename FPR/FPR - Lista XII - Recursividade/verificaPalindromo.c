/*

Quest�o 06:
Dada uma string s, desenvolver uma fun��o
recursiva que determine se s � ou n�o um
pal�ndromo.

*/

// bibliotecas
#include <stdio.h>
#include <string.h>

// prot�tipo da fun��o
int isPalindromo (char *str, int inicio, int fim);

void main(){
	
	char str[31];	
	int tam;
	
	printf("Insira o texto: ");
	fflush(stdin);
	gets(str);
	
	// guarda o tamanho da string como um inteiro
	tam = strlen(str);
		
	if(isPalindromo(str, 0, tam-1)){
		printf("E um palindromo\n");
	}else{
		printf("Nao e um palindromo\n");
	}
}

// Implementa��o da fun��o
int isPalindromo (char *str, int inicio, int fim){
	
	if(inicio >= fim){
		return 1; // � um palindromo
	}else{
		
		if(str[inicio] != str[fim]){
			return 0; // n�o � pal�ndromo
		}
		
		return isPalindromo(str, inicio+1, fim-1); // chama recursivamente 
	}
}

