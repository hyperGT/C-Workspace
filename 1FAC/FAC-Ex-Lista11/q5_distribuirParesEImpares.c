/*
QUESTÃO 05:
Elaborar uma função que, dado um conjunto de
300 valores inteiros, distribua-os em 2 vetores
conforme forem pares ou ímpares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
# define LIM 10

// pf
void separarVetor(int vetor[], int tam, int vetorPar[], int *quantPares, int vetorImpar[], int *quantImpares);

void preencherAleatorio(int vetor[], int tam, int limite);
void exibir(int vetor[], int tam);

int main(){
	
	int vetor[TAM],
	vetorPar[TAM],
	vetorImpar[TAM],
	qntP,
	qntI;
	
	preencherAleatorio(vetor, TAM, LIM);
	
	separarVetor(vetor, TAM, vetorPar, &qntP, vetorImpar, &qntI);
	
	// exibindo os vetores
	printf("Exibindo o vetor original\n");
	exibir(vetor, TAM);
	printf("Exibindo o vetor somente com valores pares\n");
	exibir(vetorPar, qntP);	
	printf("Exibindo o vetor somente com valores impares\n");
	exibir(vetorImpar, qntI);
	
}

void separarVetor(int vetor[], int tam, int vetorPar[], int *quantPares, int vetorImpar[], int *quantImpares){
	
	int i, contPar=0, contImp=0;
	
	for(i=0; i<tam;i++){
		
		if(vetor[i]%2==0){
			vetorPar[contPar] = vetor[i];
			contPar++;
		}else{
			vetorImpar[contImp] = vetor[i];
			contImp++;
		}
		(*quantPares) = contPar;
		(*quantImpares) = contImp;
	}
}


void preencherAleatorio(int vetor[], int tam, int limite){
	
	int i;
	
	srand(time(NULL));
	
	for(i=0; i<tam; i++){
		vetor[i] = rand()%10;
	}
	
}

void exibir(int vetor[], int tam){
	
	int i;
	
	for(i=0; i < tam ; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
}
