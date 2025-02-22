/*
QUESTÃO 02:
Implementar uma função que, dado um vetor
de reais, troque o 1° e o 2° elementos, em
seguida o 3° e o 4° elementos e assim
sucessivamente, até se chegar ao final do vetor.

parametro: vetor: real, tamanho: inteiro
retorno: nenhum
objetivo: exibir novo vetor com os valores trocados da forma descrita acima
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

// prototipos/head das functions
void trocarPosicao(float vetor[], int tamanho);

void exibir(float vetor[], int tamanho);
 
void main(){
	
	
	float vetorA[TAM] = {5, 4, 3, 2, 1};
	
	
	exibir(vetorA, TAM);
	trocarPosicao(vetorA, TAM);
	exibir(vetorA, TAM);
	
}

void trocarPosicao(float vetor[], int tamanho){
	
	int i;
	float aux;
	
	
	
	for(i=0; i<tamanho; i+=2){
		aux=vetor[i];
		vetor[i] = vetor[i+1];
		vetor[i+1] = aux;
	}
}

void exibir(float vetor[], int tamanho){
	
	int i;
	
	for(i=0; i<=tamanho; i++){
		printf("%.0f ", vetor[i]);
	}
	printf("\n\n");
}
