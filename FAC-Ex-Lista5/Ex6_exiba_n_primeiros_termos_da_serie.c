/*
QUESTÃO 06:
Criar um programa que exiba os N
primeiros termos da seguinte série:
1,2,8,64,1024,...
*/

#include<stdio.h>

int main(){
	
	int n, a1=1, r=2, i;
	
	printf("Insira o valor de n: ");
	scanf("%d", &n);
	
	printf("\n\n");
	
	for(i=1; i<=n; i++){
		
		printf("%d ", a1);
		a1*=r;
		r*=2;
	}
	
	printf("\n\n");
}
