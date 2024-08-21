/*
QUESTÃO 04:
Fazer uma função que armazene em um vetor
os 50 primeiros termos da seguinte sequência:
S = 1, 2, 4, 7, 11, 16, ...
*/

#include <stdio.h>

#define TAM 50

//pfs
void armazenaSequencia(int vetor[], int tam);

void exibir(int vetor[], int tam);

void main(){
	
	int vet[TAM];
	
	armazenaSequencia(vet, TAM);
	exibir(vet, TAM);
}

void armazenaSequencia(int vetor[], int tam){
	int i;
	
	// armazenando a seguinte sequencia
	// S = 1, 2, 4, 7, 11, 16, ... A razão acresce em 1 a cada termo encontrado R = 1, 2, 3, 4, ..., 50
	vetor[0] = 1;
	
	for(i=1; i<tam; i++){
		vetor[i] = vetor[i-1] + i;
	}
	
}

void exibir(int vetor[], int tam){
	int i; 
	
	for(i=0; i<tam; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
}
