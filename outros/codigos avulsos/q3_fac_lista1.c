/*
Construir um algoritmo que calcule o peso ideal
de uma pessoa, de acordo com o seu gênero e
altura, utilizando as seguintes fórmulas:
* para homens: (72.7*h)-58
* para mulheres: (62.1*h)-44.7
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	// variaveis 
	float pesoIdeal;
	float altura;
	char sexo;
	
	printf("Insira seu sexo M/F: ");
	scanf(" %c", &sexo);
	
	printf("sexo: %c\n", sexo);
	
	printf("Insira sua altura: ");
	scanf("%f", &altura);
	
	printf("Sua altura: %.2f\n", altura);
	
	if(sexo == 'M' || sexo == 'm'){
		pesoIdeal = (72.7*altura)-58;
	} 
	if(sexo == 'F' || sexo == 'f'){
		pesoIdeal = (62.1*altura)-44.7;
	}
	
	printf("Seu peso ideal: %.2f", pesoIdeal);	
	
}
