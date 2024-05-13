/*
Elabore um algoritmo que, dada a idade de um
nadador, classifique-o em uma das seguintes
categorias:
Categoria  | Faixa de idade
infantil A | 0 - 4 anos
infantil B | 5 - 7 anos
infantil C | 8-10 anos
juvenil  A | 11-13 anos
juvenil  B | 14-17 anos
Adulto     | 18 anos ou mais

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int idadeNadador;
	
	
	printf("Insira a idade do nadador: ");
	scanf("%d", &idadeNadador);
	
	if(idadeNadador < 5){
		printf("infantil A");
	} else if (idadeNadador > 4 && idadeNadador < 8){
		printf("infantil B");
	} else if (idadeNadador > 7 && idadeNadador < 11){
		printf("infantil C");
	} else if (idadeNadador > 10 && idadeNadador < 14){
		printf("juvenil  A");
	} else if (idadeNadador > 13 && idadeNadador < 18){
		printf("juvenil  B");
	} else{
		printf("Adulto");
	}
}
