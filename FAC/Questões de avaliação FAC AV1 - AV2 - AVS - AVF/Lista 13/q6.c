/*
Quest�o 06:
Dado um vetor contendo n�meros reais,
desenvolver uma fun��o que determine o maior
valor do vetor inferior � m�dia de seus
elementos, assim como o menor que seja
superior a esta m�dia.
Nota: apresentar a fun��o main chamando a fun��o
desenvolvida.
*/

#include <stdio.h>
#include <float.h>

// fun��es
void questao06(float vet[], int qnt, float *maiorMed, float *menorMed){
	
	// declara��o de vari�veis
	int i, somaEl=0;
	float mediaEl;
	
	*maiorMed = FLT_MIN; // menor valor poss�vel para um float
	*menorMed = FLT_MAX; // maior valor poss�vel para um float
	
	// percorrendo o vetor para obter a soma de tds os elementos
	for(i=0; i<qnt; i++){
		somaEl += vet[i]; // soma de tds os elementos
	}
	mediaEl = somaEl/qnt; // obtendo a m�dia 
	
	for(i=0; i<qnt;i++){
		
		// obtendo o maior valor do vetor inferior � m�dia de seus elementos
		if(vet[i]<mediaEl){
			if(vet[i]>*maiorMed){				
				*maiorMed = vet[i];
			}
		}else{ // n�o � menor que a m�dia, logo � superior(ou igual) a ela
			
			// obtendo o menor que seja superior a esta m�dia
			if(vet[i]<*menorMed){
				*menorMed = vet[i];
			}
		}
	}	
}


int main(){
	
	float vet[5] = {2, 4, 9, 10, 7}, tam = 5;
	float maiorInfMedia, menorSupMedia; 
	
	// chamando a fun��o
	questao06(vet, tam, &maiorInfMedia, &menorSupMedia);

	printf("Exibindo:\nO maior valor do vetor inferior a media de seus elementos: %.0f", maiorInfMedia);	
	printf("\nO menor que seja superior a esta media: %.0f", menorSupMedia);
}
