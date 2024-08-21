/*
QUESTÃO 08:
Dados um vetor de inteiros (cujos elementos
estão ordenados crescentemente) e um
número x, retornar a posição da primeira
ocorrência de x (caso encontre-se no vetor) ou
a posição na qual deveria estar (caso contrário).

parametros: int vetor[], int tam , int x 
retorno: posicao da ocorrencia 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15

// pfs 
int retornarOcorrenciaX(int vetor[], int tam , int x);

void preencherCrescente(int vetor[], int tam);
void exibir(int vetor[], int tam);

int main(){
	
	int vet[TAM], x, posicaoX;
	
	preencherCrescente(vet, TAM);
	
	exibir(vet, TAM);
	
	printf("Insira o valor a ser buscado: ");
	scanf("%d", &x);
	
	posicaoX = retornarOcorrenciaX(vet, TAM, x);
	
	printf("Posicao em que X foi encontrado(ou deveria estar): %d", posicaoX);
		
}

int retornarOcorrenciaX(int vetor[], int tam , int x){
	int i; 
	
	for(i=0; i<tam; i++){
		
		// comparando para ver se ainda há a possibilidade de achar uma ocorrencia de x
		if(vetor[i]>=x){
			
			/* Solução antiga
			// comparando para ver se o valor atual é uma ocorrencia de x
			if(vetor[i]==x){
				// se for retorna a posicao + 1
				return i;
			}
		}else{ // se o valor for maior que x, interrompe a execução e retorna a posicao que o valor deveria estar
			return i+1;
		}*/
		
			return i;
		}
	}
	return i;
	
}

void preencherCrescente(int vetor[], int tam){
	
	int i;
	
	srand(time(NULL));
	
	vetor[0] = rand()%10;
	
	for(i=1; i<tam; i++){
		vetor[i] = vetor[i-1] + rand()%5; // o valor seguinte sempre será maior, formando um vetor ordenado crescentemente
	}
}

void exibir(int vetor[], int tam){
	int i;
	
	for(i=0; i<tam; i++){
		printf("%d ", vetor[i]);
	}	
	printf("\n\n");
}

