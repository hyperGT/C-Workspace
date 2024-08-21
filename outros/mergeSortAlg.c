/*
Escrevendo um algoritmo de 'Merge Sort'

Dado um valor de entrada e um vetor com 100 posições preenchidas, escrever um algoritmo que 
busque esse valor dentro do vetor, e, depois, a partir desse valor,
ordene o resto do vetor usando um algoritmo chamado Merge Sort, criado por Von Neumann.
*/


#include <stdio.h>
#define QNT 100

// func. prototype
int busca(int vetor[], int vBusca, int tamanho);

void mergeSort(int vetor[], int vBusca, int tamanho);

int main(){
	
	int vet[QNT];
	int v; // valor a ser buscado dentro do vetor
	
	printf("Insira um valor a ser buscado no vetor: ")
	
	busca(vet[], v, QNT);
	
	int valSort = busca();
	mergeSort(vet[], valSort, tamanho);
}

// algoritmo pra busca
int busca(){
	
}

void mergeSort(int vetor[], int vBusca, int tamanho){
	
	int i, j, metTamanho=tamanho/2, subVet[metTamanho],	subVet2[metTamanho];
	
}


