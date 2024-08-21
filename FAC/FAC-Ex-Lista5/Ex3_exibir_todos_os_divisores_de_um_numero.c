/*
Lista 5
Fazer um programa que exiba todos os
divisores de um número N fornecido pelo
usuário.

divisor de um numero é quando o numero (x) é dividido por (y) e o resto é 0
*/

#include<stdio.h>

int main(){
	
	int n, i;
	
	printf("Insira um numero inteiro: ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		if(n%i==0){
			printf("%d, ", i);
		}
	}
}
