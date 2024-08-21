/*
Questão 06:
Dado um vetor contendo números reais,
desenvolver uma função que determine o maior
valor do vetor inferior à média de seus
elementos, assim como o menor que seja
superior a esta média.
Nota: apresentar a função main chamando a função
desenvolvida.
*/

#include <stdio.h>
#include <float.h>

// funções
void questao06(float vet[], int qnt, float *maiorMed, float *menorMed){
	
	// declaração de variáveis
	int i, somaEl=0;
	float mediaEl;
	
	*maiorMed = FLT_MIN; // menor valor possível para um float
	*menorMed = FLT_MAX; // maior valor possível para um float
	
	// percorrendo o vetor para obter a soma de tds os elementos
	for(i=0; i<qnt; i++){
		somaEl += vet[i]; // soma de tds os elementos
	}
	mediaEl = somaEl/qnt; // obtendo a média 
	
	for(i=0; i<qnt;i++){
		
		// obtendo o maior valor do vetor inferior à média de seus elementos
		if(vet[i]<mediaEl){
			if(vet[i]>*maiorMed){				
				*maiorMed = vet[i];
			}
		}else{ // não é menor que a média, logo é superior(ou igual) a ela
			
			// obtendo o menor que seja superior a esta média
			if(vet[i]<*menorMed){
				*menorMed = vet[i];
			}
		}
	}	
}


int main(){
	
	float vet[5] = {2, 4, 9, 10, 7}, tam = 5;
	float maiorInfMedia, menorSupMedia; 
	
	// chamando a função
	questao06(vet, tam, &maiorInfMedia, &menorSupMedia);

	printf("Exibindo:\nO maior valor do vetor inferior a media de seus elementos: %.0f", maiorInfMedia);	
	printf("\nO menor que seja superior a esta media: %.0f", menorSupMedia);
}
