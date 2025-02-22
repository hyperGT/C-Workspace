/*
QUESTÃO 10:
Fazer uma função que, dados dois vetores A e B
com números inteiros, gerar o vetor C que
consiste na união dos dois primeiros.
Nota: considerar que não existe repetição no
conjunto A, nem no conjunto B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM1 5
#define TAM2 8
#define TAM3 TAM1+TAM2

// pfs
void unirVetores(int vetA[], int tamA, int vetB[], int tamB, int vetC[], int *tamC);

void exibir(int vet[], int tam);


int main(){
	
	// declaração de variáveis
	int vetA[TAM1] = {9, 7, 6, 1, 2},
	vetB[TAM2] = {3, 2, 6, 11, 1, 4, 9, 8, 10},
	tamC,
	vetC[TAM3];			
	
	// realizando a união de A e B U=(A+B)
	unirVetores(vetA, TAM1, vetB, TAM2, vetC, &tamC);
	
	// exibindo vetores A, B e C
	printf("Vetor A: \n");
	exibir(vetA, TAM1);
	printf("Vetor B: \n");
	exibir(vetB, TAM2);
	printf("Vetor C: \n");
	exibir(vetC, tamC);
}

void unirVetores(int vetA[], int tamA, int vetB[], int tamB, int vetC[], int *tamC){
	
	int i, j, contC, verify;	
	
	// colocando o vetor A no vetor C
	for(i=0;i<tamA;i++){
		vetC[i] = vetA[i];		
	}
	
	contC = tamA;
	
	for(i=0;i<tamB;i++){
		
		// inicializando o verify
		verify=0;
		
		// varrendo para identificar se o valor da posição 'i' do vetor B já está presente no vetor A
		for(j=0;j<tamA;j++){
			
			if(vetB[i]==vetA[j]){
				verify=1; // foi encontrado valor repetido				
			}
		}
		
		//	se não existir valor repetido
		if(verify==0){
			vetC[contC] = vetB[i]; 
			contC++;
		}
	}
	*tamC = contC;	
}
	
void exibir(int vet[], int tam){
	int i;
	
	for(i=0;i<tam;i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}

void preencherAleatorio(int vet[], int tam){
	int i;
	
	//srand(time(NULL)); // faz com que sejam gerados os mesmo valores sempre por execução
	
	for(i=0;i<tam;i++){
		vet[i] = rand()%10;
	}
}
