#include <stdio.h>
#include <limits.h>
#include <locale.h>

/**
* Dado um vetor com n elementos, faça uma função que ordene-o crescentemente
*
* Algoritmo de ordenação: Selection Sort
*
**/

#define TAM 7

int searchSmallest(int vet[], int tam, int index){
	
	int j, smallest = INT_MAX, smallestPos;
			
	for(j=index; j<tam; j++){
		
		if(vet[j] < smallest){
			smallestPos = j;
			smallest = vet[j];
			printf("Menor valor: %d\nPosição: %d\n", smallest, smallestPos);
		}
	}
	
	return smallestPos;
}

void selectionSort(int vet[], int tam){
	
	int i, j, aux, pos = 0, n;
	
	for(i=0; i<tam; i++){
		
		pos = searchSmallest(vet, tam, i);
		
		aux = vet[i];
		vet[i] = vet[pos];
		vet[pos] = aux;		
	}
}

void exibir(int vet[], int tam);

int main(){
		
	int vet[TAM] = {8, 4, 3, 7, 9, 2, 1};
	
	exibir(vet, TAM);
	
	selectionSort(vet, TAM);
	
	exibir(vet, TAM);
	
}


void exibir(int vet[], int tam){
	
	int i;
	
	printf("\n\n=================================\n\n");
	for(i = 0; i < tam; i++){
		printf("%d, ", vet[i]);
	}
	printf("\n\n=================================\n\n");
}
