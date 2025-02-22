/*
QUESTÃO 05:
Criar um programa que exiba os N
primeiros termos da seguinte série:
1,2,4,8,16,32,...
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
	}
	
	printf("\n\n");
}
