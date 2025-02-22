/*
Lista 5
Dado um número inteiro N, fazer um
programa que exiba os números pares
iguais ou inferiores a N.
*/


#include<stdio.h>

int main(){
	
	int n, i;
	
	printf("Insira um numero inteiro: ");
	scanf("%d", &n);
	
	
	while(i<=n){
		
		if(i%2==0){
			printf("%d, ", i);
		}
		i++;
	}
}
