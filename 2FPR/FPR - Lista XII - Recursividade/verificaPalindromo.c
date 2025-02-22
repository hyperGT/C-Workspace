/*

Questão 06:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.

*/

// bibliotecas
#include <stdio.h>
#include <string.h>

// protótipo da função
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

// Implementação da função
int isPalindromo (char *str, int inicio, int fim){
	
	if(inicio >= fim){
		return 1; // É um palindromo
	}else{
		
		if(str[inicio] != str[fim]){
			return 0; // não é palíndromo
		}
		
		return isPalindromo(str, inicio+1, fim-1); // chama recursivamente 
	}
}

