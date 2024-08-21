/*
QUESTÃO 05: 
Elabore um programa que
calcule a média ponderada de n elementos.
Observação: na média ponderada, cada
elemento possui um peso que representa a
sua contribuição no cálculo da média final.

fórmula:
	M = P1*N1 + P2*N2 ... Pi*Ni
  	--------------------------
  		P1 + P2 ... Pi
*/

#include<stdio.h>

int main(){
	
	float M, numElementos, n, p, numerador=0, denominador=0; 

	printf("Insira quantos elementos serao calculados: ");
	scanf("%f", &numElementos);
	
	int i;
	for(i=1; i<=numElementos; i++){
		
		printf("insira o valor do elemento: ");
		scanf("%f", &n);
		
		printf("insira o peso do elemento: ");
		scanf("%f", &p);
		//somando os valores com os seus respectivos pesos
		numerador += (p*n);
		//somando os pesos
		denominador += p;				
	}
	M = numerador/denominador;
	printf("Media = %.2f", M);
}
