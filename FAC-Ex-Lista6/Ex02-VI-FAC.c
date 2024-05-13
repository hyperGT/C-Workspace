/*
QUESTÃO 02: 
Pede-se o desenvolvimento
de um programa que leia n valores e
determine o maior e o menor elementos
do conjunto fornecido.
*/

#include<stdio.h>
#include<limits.h>

int main(){
	
	int i, qnt, n, maior = INT_MIN, menor = INT_MAX;
	
	printf("Insira quantos valores serao fornecidos: ");
	scanf("%d", &qnt);
	
	//lendo n valores 
	i=1;
	while(i<=qnt){
		
		printf("Insira um valor: ");
		scanf("%d", &n);
		
		if(n>maior){
			maior = n;
		}
		if(n<menor){
			menor = n;
		}
		
		i++;
	}
	//menor valor
	printf("Menor valor = %d\n", menor);	
	//maior valor
	printf("Maior valor = %d", maior);
}
