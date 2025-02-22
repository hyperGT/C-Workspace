/*
QUESTÃO 07:
Desenvolver uma função que remova
determinado elemento (todas as suas
ocorrências) de um vetor de float. Ao final,
retornar o número de remoções realizadas.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAM 10
#define LIM 10

// pf
int removerOcorrencia(int vetor[], int a, int *qnt);

void preencherAleatorio(int vetor[], int tam, int limite);
void exibir(int vetor[], int tam);

int main(){
	
	int vet[TAM], a, remocoes, qnt=TAM;
	
	// Preenchendo o vetor com valores 
	preencherAleatorio(vet, qnt, LIM);
	
	printf("Vetor original: ");
	exibir(vet, qnt);
	
	printf("Insira o valor a ser removido do vetor: ");
	scanf("%d", &a);
	
	remocoes = removerOcorrencia(vet, a, &qnt);
	
	printf("Ocorrencias removidas: %d\n", a);
	exibir(vet, qnt);
	printf("Quantidade de ocorrencias removidas: %d\n", remocoes);
}

int removerOcorrencia(int vetor[], int a, int *qnt){
	
	int i, j, cont=0;
	
	// variando até o tamanho total atual do vetor 
	for(i=0; i<(*qnt); i++){
		
		// se a ocorrencia do valor for achado
		if(vetor[i]==a){
			
			// percorre a partir do i até o tamnho atual do vetor -1 
			for(j=i; j<(*qnt-1);j++){
				// deslocando todos os valores para esquerda
				vetor[j] = vetor[j+1];
			}
			// atualiza a quantidade de elementos existentes no vetor
			(*qnt)--;
			
			// atualiza a quantidade de ocorrencias removidas do vetor
			cont++;
			
			// decrementando o 'i' para testar o valor anterior novamente
			i--; 
		}
		
	}
	return cont; // retorna a qnt de ocorrencias de 'a' removidas
}

void preencherAleatorio(int vetor[], int tam, int limite){
	int i;
	
	srand(time(NULL));
	
	for(i=0; i<tam; i++){
		vetor[i] = rand()%limite;
	}
}

void exibir(int vetor[], int tam){
	
	int i;
	
	printf("\n");
	for(i=0; i<tam;i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
}
