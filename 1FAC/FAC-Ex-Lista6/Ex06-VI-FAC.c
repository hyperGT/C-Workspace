/*
Quest�o 06:
Fa�a um programa que leia
200 n�meros inteiros. Ao final, exibir:
a) O maior n�mero fornecido, de
ordem par (isto �, o maior dentre o
segundo, quarto, sexto, oitavo, etc
valores fornecidos).
b) A m�dia dos valores pares.
*/

#include<stdio.h>

int main(){
	
	int n, i, qnt, maior=0, soma=0, contPar=0;
	float media;
	
	printf("Quantidade de numeros inteiros a serem lidos: ");
	scanf("%d", &qnt);
	
	for(i=1; i<=qnt; i++){
		
		printf("Insira o valor: ");
		scanf("%d", &n);
		
		//o maior numero fornecido de todos
		if(n%2==0){ //se for par
			if(n>maior){
				maior=n;
			}
			contPar++;
			soma+=n;
		}
	}
	//obtendo a m�dia
	media = ((float)soma/contPar);
	printf("Media = %.2f", media);
}
