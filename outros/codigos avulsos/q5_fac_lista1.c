/*
Escrever um algoritmo que, dada uma quantia
em reais, calcule o menor número possível de
notas/moedas (100, 50, 20, 10, 5, 2 e 1) em que
o valor pode ser decomposto.
*/

#include<stdio.h>

int main(){
	int quantia, dec; //dec = guarda o valor decomposto
	
	int n100, n50, n20, n10, n5, n2, n1;
	int r100, r50, r20, r10, r5, r2, r1;
	int res;
	
	printf("Insira a quantia a ser decomposta: ");
	scanf("%d", &quantia);
	
	//pegando os valores da centena
	n100 = quantia / 100;
	r100 = quantia % 100;
	
	n50 = r100 / 50;
	r50 = r100 % 50;
	
	n20 = r50 / 20;
	r20 = r50 % 20;
	
	n10 = r20 / 10;
	r10 = r20 % 10;
	
	n5 = r10 / 5;
	r5 = r10 % 5;
	
	n2 = r5 / 2;
	r2 = r5 % 2;
	
	n1 = r2 / 1;
	r1 = r2 %  1;
	
	printf("Cédulas de 100: %d \nCédulas de 50: %d\nCédulas de 20: %d \nCédulas de 10: %d \nCédulas de 5: %d \nCédulas de 2: %d \nCédulas de 1: %d", n100, n50, n20, n10, n5, n2, n1);
	
	
		
	
}
