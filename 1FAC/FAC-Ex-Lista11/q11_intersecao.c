/*
Quest�o 11:
Fazer uma fun��o que, dados dois vetores A e B
com n�meros inteiros, gerar o vetor C que
consiste na intersec��o dos dois primeiros.
Nota: considerar que n�o existe repeti��o no
conjunto A, nem no conjunto B.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAP1 7
#define CAP2 4

// pfs

void interseccao (int vetA[], int capA, int vetB[], int capB, int vetC[], int *qntC);

int busca(int vetor[], int tam, int elemento);
void exibir(int vetor[], int tam);

int main(){
	
	// declara��o de vari�veis
	int vetA[CAP1] = {4, 6, 3, 1, 2, 9, 8},
	vetB[CAP2] = {0, 1, 5, 3},
	tamC = CAP1+CAP2,
	vetC[tamC];
	
	// realizando a intersec��o dos vetores
	interseccao (vetA, CAP1, vetB, CAP2, vetC, &tamC);
	
	// exibindo os vetores
	exibir(vetA, CAP1);
	exibir(vetB, CAP2);
	exibir(vetC, tamC);
	
}


void interseccao (int vetA[], int capA, int vetB[], int capB, int vetC[], int *qntC){
	
	// declara��o de vari�veis
	int i, j;
	
	// para caso precisarmos verificar qual dos dois vetores � maior (mas nesse caso n�o � necess�rio)
	// maiorCap = (capA>capB) ? capA : capB;
	
	// percorrendo todo vetor A
	for(i=0, j=0; i<capA; i++){
		
		// verificando se o vetor MENOR est� contido no MAIOR comparando cada elemento de A com B
		if(busca(vetB, capB, vetA[i]) >= 0){
			vetC[j] = vetA[i];
			j++;
		}
	}
	// armazenando a quantidade de elementos existentes no vetor C
	*qntC = j;
}

int busca(int vet[], int tam, int elemento){
	
	// declara��o de vari�veis
	int i;
	
	// objetivo: verificar a exist�ncia de um certo valor e retornar algo caso sim
		
	for(i=0; i<tam; i++){
		
		if(vet[i]==elemento){
			return i;
		}
		
	}
	return -1;
}
void exibir(int vet[], int tam){
	
	// declara��o de vari�veis
	int i;
	
	for(i=0;i<tam;i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
	
}
