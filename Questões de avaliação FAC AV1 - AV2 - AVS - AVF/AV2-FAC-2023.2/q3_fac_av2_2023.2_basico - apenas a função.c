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

//prototipo da fun��o
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB);

//isso � uma esp�cie de algoritmo de busca e retorno, simples pra quem j� entende mas dificil de sacar pra iniciantes
void retornaSC(int vetor[], int vetRetorno[], int n, int tamanho, int * tamVetB){
	
	int i, j=0, subConj=1;
	
	//loop variando at� o tamanho do vetor
	for(i=0; i<tamanho; i++){
		
		//verificando se o subconjunto � maior que n
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
			break; // j� atingimos o objetivo
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


