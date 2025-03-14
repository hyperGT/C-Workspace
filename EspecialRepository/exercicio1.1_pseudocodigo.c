#include<stdio.h>
#define TAM 6

/*
* Realize a an�lise da fun��o 'funcVersaoOriginal' abaixo e descreva qual seu objetivo
*/

void funcVersaoOriginal(int *A, int n){
	int j, i, ch;
	for(j=2;j<n;j++){
		ch = A[j];	
		i=j-1;
		while(i>=1 && A[i] > ch){			
			A[i+1] = A[i];		
			i=i-1;
		}		
		A[i+1] = ch;
	}
}

void exibirVetor(int *A, int n){
	int i;
	for(i=0;i<n;i++) 
		printf("%i, ", A[i]);
		
	printf("\n\n");
}

// a implementa��o est� abaixo da main junto com a resposta do exerc�cio
void funcMinhaVersao(int *A, int n);

int main(){
	
	int vet[TAM] = {9, 6, 2, 7, 1, 8};
	
	exibirVetor(vet, TAM);
	funcVersaoOriginal(vet, TAM);
	
	exibirVetor(vet, TAM);
}


void funcMinhaVersao(int *A, int n){
	int j, i, ch;
	for(j=1;j<n;j++){
		ch = A[j];	// ch guarda o elemento armazenado no indice atual do vetor
		i=j-1;	// i aponta para a posi��o anterior ao j
		while(i>=0 && A[i] > ch){	
			// realiza a troca do valor posterior (posi��o j) pelo valor anterior (na posi��o i)	
			A[i+1] = A[i];			
			// aponta o i para o seu valor anterior atual
			i=i-1;
		}
		// (i = 1 chegaria aqui como i=0 e o indice voltaria a ser i=1 para que a troca possa ser realizada) 
		A[i+1] = ch;
	}
}
/*
* Resposta: o objetivo da fun��o 'funcVersaoOriginal' � 
* ordenar crescentemente o vetor passado por par�metro a partir 
* do segundo elemento do vetor.
*/
