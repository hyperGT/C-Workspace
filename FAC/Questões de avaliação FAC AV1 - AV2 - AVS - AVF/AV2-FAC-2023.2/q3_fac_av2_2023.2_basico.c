/*
Questão da AV2 2023.2 FAC A 
Considere que um vetor de inteiros armazene o numero 0 em algumas de suas posições objetivando 
"separar subconjuntos de valores", como no exemplo a seguir:

Subconjunto:  1			  2 	  	   3	  4
Vetor:	   	| 5 | 7 | 3 | 0 | 5 | 9 | 0 | 1 | 0 | 3 | 4 | 8
Indice:      0   1   2   3   4   5   6   7   8   9   10  11

Desenvolver uma função que, dados um vetor como definido anteriormente e um número inteiro n, retorne um
vetor contendo o n-ésimo subconjunto do vetor.
*/

#include<stdio.h>
#define TAM 20

//prototypes
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB);

void exibir (int vetor[], int tamanho);


int main(){
	
	int n, // aqui entra o subconjunto a ser buscado
	vetA[TAM] = {5, 7, 3, 0, 5, 9, 0, 1, 0, 3, 4, 8, 1, 0, 7, 7, 7, 0, 2, 1}, // vetor original (conjunto A)
	vetB[5], // vetor que contém um subconjunto de elementos de A
	tamVetB; // guarda a quantidade de elementos do subconjunto 
	
	exibir(vetA, TAM); // função pra exibir o conjunto A
	
	// obtendo n
	printf("Escolha um subconjunto para ver os valores [1 a 6]: ");
	scanf("%d", &n);	
	printf("\n");
		
	retornaSC(vetA, vetB, n, TAM, &tamVetB); // função de busca de subconjuntos
	
	printf("Quantidade de elementos do sub-conjunto: %d\n\n", tamVetB); // mostrando o tamanho do subconjunto
	exibir(vetB, tamVetB); // exibindo o subconjunto obtido
	
}

//isso é uma espécie de vetor de busca e retorno, só que um pouquinho mais complexo
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB){
	
	int i, j=0, subConj=1;
	
	//loop variando até o tamanho do vetor
	for(i=0; i<tamanho; i++){
		
		//verificando se o subconjunto NAO é maior que n
		if(!(subConj > n)){
			
			// a cada zero do vetor contabiliza o subconjunto no qual se encontra o for atualmente
			if(vetor[i] == 0){
							 
				subConj++;
				
			}
			
			// verificando se o subconjunto é o requisitado
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


