/*
Faça um programa que leia um
número inteiro positivo N e exiba todos os
múltiplos de Y inferiores a N, onde N e Y são
fornecidos pelo usuário.

exemplo: m(6) = { 0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 6 . k, ...}
então, se o valor de N é 20, eu só posso exibir o 0, o 6, o 12 e o 18.
*/

#include<stdio.h>

int main(){
	
	int n, y, i;
	
	
	//lendo um número inteiro positivo N
	printf("Entre com um numero inteiro positivo (N): ");
	scanf("%d",&n);
	
	//lendo o valor de Y 
	printf("Entre com o valor de (Y): ");
	scanf("%d",&y);
	
	//exibindo todos os múltiplos de Y inferiores a N
	for(i = 0; i<=n; i++){
		
		if(y*i<n){		
		printf(" %d", y*i); 
		}
		else{
			break;
		}
	}
		
}
