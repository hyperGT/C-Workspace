/*
Quest�o da AV2 2023.2 FAC A 
Considere que um vetor de inteiros armazene o numero 0 em algumas de suas posi��es objetivando 
"separar subconjuntos de valores", como no exemplo a seguir:

Subconjunto:  1			  2 	  	   3	  4
Vetor:	   	| 5 | 7 | 3 | 0 | 5 | 9 | 0 | 1 | 0 | 3 | 4 | 8
Indice:      0   1   2   3   4   5   6   7   8   9   10  11

Desenvolver uma fun��o que, dados um vetor como definido anteriormente e um n�mero inteiro n, retorne um
vetor contendo o n-�simo subconjunto do vetor.
*/

#include<stdio.h>
#define TAM 20

//prototypes
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB);

void exibir (int vetor[], int tamanho);


int main(){
	
	int n, // aqui entra o subconjunto a ser buscado
	vetA[TAM] = {5, 7, 3, 0, 5, 9, 0, 1, 0, 3, 4, 8, 1, 0, 7, 7, 7, 0, 2, 1}, // vetor original (conjunto A)
	vetB[5], // vetor que cont�m um subconjunto de elementos de A
	tamVetB; // guarda a quantidade de elementos do subconjunto 
	
	exibir(vetA, TAM); // fun��o pra exibir o conjunto A
	
	// obtendo n
	printf("Escolha um subconjunto para ver os valores [1 a 6]: ");
	scanf("%d", &n);	
	printf("\n");
		
	retornaSC(vetA, vetB, n, TAM, &tamVetB); // fun��o de busca de subconjuntos
	
	printf("Quantidade de elementos do sub-conjunto: %d\n\n", tamVetB); // mostrando o tamanho do subconjunto
	exibir(vetB, tamVetB); // exibindo o subconjunto obtido
	
}

//isso � uma esp�cie de vetor de busca e retorno, s� que um pouquinho mais complexo
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB){
	
	int i, j=0, subConj=1;
	
	//loop variando at� o tamanho do vetor
	for(i=0; i<tamanho; i++){
		
		//verificando se o subconjunto NAO � maior que n
		if(!(subConj > n)){
			
			// a cada zero do vetor contabiliza o subconjunto no qual se encontra o for atualmente
			if(vetor[i] == 0){
							 
				subConj++;
				
			}
			
			// verificando se o subconjunto � o requisitado
			if(subConj == n)  //sc == n (3)
			{					
					if(vetor[i]!=0){
						vetRetorno[j] = vetor[i];
						j++;
					}
			}
		}else{
			break;
		}
		*tamVetB = j;
	}
}
	


void exibir (int vetor[], int tamanho){
	
	int i;
	printf("Exibindo Vetor: ");
	for(i=0; i<tamanho; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n\n");
}


