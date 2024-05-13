/*
Escrever um programa que encontre o
quinto número maior que 1000, cuja
divisão por 11 tenha resto 5.
*/

#include<stdio.h>

int main(){
	
	int n=1000, cont=0;
	
	while(cont!=5){
		
		n++;
		
		if(n%11==5){
			cont++;
		}
		
	}
	printf("\n\n  Resposta: %d", n);
}


