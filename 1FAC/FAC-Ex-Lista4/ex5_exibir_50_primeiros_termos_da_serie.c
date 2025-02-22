/*
Faça um programa que exiba
na tela os 50 primeiros termos da seguinte
série: 1, -2, 3, -4, 5, -6 ...
*/

#include<stdio.h>

int main(){

	int i;
	
	for(i=1; i<=50; i++){			
		i%2==0 ? printf("%d, ", i*(-1)) : printf("%d, ", i);	
	}
	
}
