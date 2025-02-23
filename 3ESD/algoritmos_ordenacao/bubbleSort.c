#include <stdio.h>
#include <locale.h>
#include <limits.h>

#define TAM 9

/*
* Desenvolver um algoritmo de ordenação bubble sort
*/

void exibirVetor(int vet[], int tam);

void bubbleSort(int vet[], int tam){
	
	int i, j, aux;
	
	for(i=0;i<tam;i++){
		
		// move o menor valor pro inicio
		for(j=tam-1;j>i;j--){
			
			if(vet[j] < vet[j-1]){	//  realiza a troca do valor da posição atual com o da posição seguinte(anterior) caso seja menor que este
				printf("\n\nValor Atual: %d\n\nValor Posterior: %d", vet[j], vet[j-1]);
				aux = vet[j];
				vet[j] = vet[j-1];
				vet[j-1] = aux;			
			}
		}
	}
}

int main(){
	
	int vet[TAM] = {5, 6, 8, 7, 9, 3, 4, 2, 12};
	
	exibirVetor(vet, TAM);
	
	bubbleSort(vet, TAM);
	
	exibirVetor(vet, TAM);
}

void exibirVetor(int vet[], int tam){
	
	int i;
	
	printf("\n\n=================================\n\n");
	for(i = 0; i < tam; i++){
		printf("%d, ", vet[i]);
	}
	printf("\n\n=================================\n\n");
}
