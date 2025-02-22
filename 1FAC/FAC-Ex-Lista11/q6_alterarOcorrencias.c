/*
QUESTÃO 06:
Faça uma função que, dado um vetor de reais,
altere todas as ocorrências do número A pelo
número B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define TAM 10

// pf (fun prototypes)
void trocarOcorrencias(int vetor[], int tam, int a, int b);
void exibir(int vetor[], int tam);

int main(){
	
	int vet[TAM] = {5, 5, 6, 7, 7, 6, 8, 9, 11, 7},
	a,
	b;
	
	// exibindo vetor
	exibir(vet, TAM);
	printf("Insira o valor a ser trocado: ");
	scanf("%d", &a);
	
	printf("\nInsira por qual valor sera alterado: ");
	scanf("%d", &b);
	
	// func pra alterar a por b
	trocarOcorrencias(vet, TAM, a, b);
	
	// exibindo vetor alterado
	exibir(vet, TAM);
}

void trocarOcorrencias(int vetor[], int tam, int a, int b){
	int i=0;
	
	while(i<tam){
		
		if(vetor[i]==a){
			vetor[i] = b;
		}
		
		i++;
	}
}

void exibir(int vetor[], int tam){
	
	int i;
	
	for(i=0; i<tam;i++){
		printf("%d ", vetor[i]);		
	}
	printf("\n\n");
}
