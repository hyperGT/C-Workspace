/*
QUEST�O 04: Fa�a um programa que leia
um n�mero inteiro N e informe se o
mesmo � ou n�o primo.
Nota: um n�mero � dito primo quando for
divis�vel apenas por 1 e por ele mesmo.

//2, 3, 5, 11...
*/

#include<stdio.h>

int main(){
	
	int n, i, divisores=0;
	
	printf("Insira um valor inteiro N: ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		
		if(n%i==0){ //5%2 nao e 0 //5%3 != 0 5%4 != 0 5%5==0
			divisores++;
		}		
	}
	
	if(divisores==2){
		printf("%d e um numero primo ", n);
	}
	else{
		printf("%d NAO e um numero primo ", n);
	}
	
}
