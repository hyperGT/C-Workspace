/*
Quest�o 01:
Desenvolver uma fun��o que determine o
n�mero de ocorr�ncias de um n�mero inteiro x
em um vetor A.

parametro: vetorA, numero : inteiro
retorno: n ocorrencias : inteiro
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define TAM 10

// prototipo das fun��es
int nOcorrencias(int vetA[], int tam, int numero);

void preencherAleatorio(int vet[], int tam);
void exibir(int vet[], int tam);



void main(){
	
	// declara��o de vari�veis
	// int vetorA[5] = {1, 2, 3, 4, 5}; // forma tradicional de declarar vetor com ou sem o tamanho j� declarado
	int vetorA[TAM];
	int x;
	
	preencherAleatorio(vetorA, TAM);
	
	exibir(vetorA, TAM);
	
	printf("Insira um elemento para contar as ocorrencias(valores ate 4): ");
	scanf("%d", &x);
	
	if(x>4){
		printf("Valor inserido inexistente");
	} else{
		int numOcorrencias = nOcorrencias(vetorA, TAM, x);
		printf("valor: %d\nOcorrencias: %d", x, numOcorrencias);
	}
		
}

int nOcorrencias(int vetA[], int tam, int numero){
	
	int i, cont=0;		
	
	for(i=0; i<tam; i++){
		if(vetA[i]==numero){
			cont++;
		}
	}
	return cont;
}

void preencherAleatorio(int vet[], int tam){
	
	int i;
	srand(time(NULL));
	
	for(i=0; i<=tam; i++){
		// recebendo valores aleat�rios no range de 0 a 5
		vet[i] = rand()%5;
	}
	
}

void exibir(int vet[], int tam){
	
	int i;
	
	for(i=0; i<=tam; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}
