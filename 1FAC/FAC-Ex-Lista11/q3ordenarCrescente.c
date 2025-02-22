/*
QUESTÃO 03:
Pede-se a implementação de uma função que,
dado um vetor contendo números reais,
determine se o mesmo encontra-se ordenado
de forma crescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int verificaOrdem(int vet[], int tam);

void exibir(int vet[], int tam);
void preencherAleatorio(int vet[], int tam);

void preencherAleatorioCrescente(int vet[], int tam);

void main(){
	
	int vetor[TAM], //{9, 3, 1, 2, 6, 8, 7, 4, 5, 10}
	vetor2[TAM],
	result; 
	
	
	// chamadas de funções
	
	// preenchendo vetor 1
	preencherAleatorio(vetor, TAM);
	
	// preenchendo vetor 2
	preencherAleatorioCrescente(vetor2, TAM);
	
	printf("Exibindo vetor 1\n");
	exibir(vetor, TAM);
	
	printf("Exibindo vetor 2\n");
	exibir(vetor2, TAM);
		
	result = verificaOrdem(vetor2, TAM);
	
	
	if(result==0){		
		printf("NAO esta ordenado de forma crescente");
	}else{
		printf("Esta ordenado de forma crescente");
	}
	
}


int verificaOrdem(int vet[], int tam){
	int i;
	
	
	
	
	
	for(i=1; i<tam; i++){
							
			// verificando se está ordenado
			if(vet[i]<vet[i-1]){
				return 0;
			}			
		
		
	}
	return 1;
}


void preencherAleatorio(int vet[], int tam){
	
	int i;
	srand(time(NULL));
	
	for(i=0; i<tam; i++){
		vet[i] = rand()%100;
	}
}

void preencherAleatorioCrescente(int vet[], int tam){
	
	int i; 
	srand(time(NULL));
	
	vet[0] = rand()%10;
	
	for(i=1; i<tam; i++){
		vet[i] = vet[i-1] + rand()%5;
	}
}

void exibir(int vet[], int tam){
	int i;
	
	for(i=0; i<tam; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
