/*
QUESTÃO 03: 
Implementar um programa
que calcule o valor de base^expoente, onde
base e expoente são números inteiros
dados pelo usuário.
*/

#include<stdio.h>

int main(){
	
	int potencia = 1, base, exp, i;
	
	printf("insira a base: ");
	scanf("%d", &base);
	
	printf("insira o expoente: ");
	scanf("%d", &exp);
	
	//calculando o valor de base^expoente
	for(i=1; i<=exp; i++){
		potencia *= base;		
	}
	printf("Resultado = %d", potencia);
	
}
