/*
Lista 5
Fazer um programa que exiba todos os
divisores de um n�mero N fornecido pelo
usu�rio.

divisor de um numero � quando o numero (x) � dividido por (y) e o resto � 0
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
