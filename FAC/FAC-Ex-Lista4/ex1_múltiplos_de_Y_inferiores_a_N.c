/*
Fa�a um programa que leia um
n�mero inteiro positivo N e exiba todos os
m�ltiplos de Y inferiores a N, onde N e Y s�o
fornecidos pelo usu�rio.

exemplo: m(6) = { 0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 6 . k, ...}
ent�o, se o valor de N � 20, eu s� posso exibir o 0, o 6, o 12 e o 18.
*/

#include<stdio.h>

int main(){
	
	int n, y, i;
	
	
	//lendo um n�mero inteiro positivo N
	printf("Entre com um numero inteiro positivo (N): ");
	scanf("%d",&n);
	
	//lendo o valor de Y 
	printf("Entre com o valor de (Y): ");
	scanf("%d",&y);
	
	//exibindo todos os m�ltiplos de Y inferiores a N
	for(i = 0; i<=n; i++){
		
		if(y*i<n){		
		printf(" %d", y*i); 
		}
		else{
			break;
		}
	}
		
}
