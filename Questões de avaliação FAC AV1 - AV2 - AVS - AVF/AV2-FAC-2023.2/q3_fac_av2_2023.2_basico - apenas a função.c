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

//prototipo da função
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB);

//isso é uma espécie de algoritmo de busca e retorno, simples pra quem já entende mas dificil de sacar pra iniciantes
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB){
	
	int i, j=0, subConj=1;
	
	//loop variando até o tamanho do vetor
	for(i=0; i<tamanho; i++){
		
		//verificando se o subconjunto é maior que n
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
			break; // já atingimos o objetivo
		}
		//*tamVetB = j;
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


