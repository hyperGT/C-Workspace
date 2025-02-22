/*
Questão 09:
Desenvolver uma função recursiva que, dado
um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão
aritmética.
*/

#include <stdio.h>

void verificaPA(int vet[], int tam);
int auxVerPA(int vet[], int tam, int i, int r);


void main(){
	
	int vetor1[5] = {2, 4, 6, 8, 10}, // razao 2 -> PA
	vetor2[5] = {15, 10, 5, 0, -5},  // razao -5 -> PA
	vetor3[6] = {15, 10, 5, 20, 8, 0};  // Nem todos os valores tem a mesma razao -> Não é uma PA
	
	verificaPA(vetor1, 5);
	
	printf("\n\n\n-------------\n\n\n");
	
	verificaPA(vetor2, 5);
	
	printf("\n\n\n-------------\n\n\n");
	
	verificaPA(vetor3, 6);
}

void verificaPA(int vet[], int tam){
	
	int razao = vet[1] - vet[0], res;
	
	res = auxVerPA(vet, tam, 2, razao);
	
	if(res == 1){
		printf("Eh uma PA");
	}else{
		printf("Nao eh uma PA");
	}
	
}

int auxVerPA(int vet[], int tam, int i, int r){
	
	if(i >= tam){ // caso geral: razao é a mesma entre todos os elementos
		return 1; 
	}else{
		
		int razao = vet[i] - vet[i-1];  // 2 4 6 -> 6 - 4 = 2 r = 2 -> compara
		if(razao == r){	
			return auxVerPA(vet, tam, i+1, r); // retorno da chamada recursiva
		}else{	// caso base: razao diferente encontrada 
			return 0;
		}
	}
}
