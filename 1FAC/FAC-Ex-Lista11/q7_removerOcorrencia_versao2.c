/*
QUESTÃO 07:
Desenvolver uma função que remova
determinado elemento (todas as suas
ocorrências) de um vetor de float. Ao final,
retornar o número de remoções realizadas.
*/

// versao 2 com código otimizado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define CAP 10
#define LIM 10

// pf 
int removerOcorrencia(int vetor[], int numero, int *qnt);


void preencherAleatorio(int vetor[], int cap, int limite);
void exibir(int vetor[], int cap);

int main(){
	
	int vet[CAP], n, remocoes, qnt=CAP;
	
	// Preenchendo o vetor com valores 
	preencherAleatorio(vet, qnt, LIM);
	
	printf("Vetor original: ");
	exibir(vet, qnt);
	
	printf("Insira o valor a ser removido do vetor: ");
	scanf("%d", &n);
	
	remocoes = removerOcorrencia(vet, n, &qnt);
	
	printf("Ocorrencias removidas: %d\n", n);
	exibir(vet, qnt);
	printf("Quantidade de ocorrencias removidas: %d\n", remocoes);
}

int removerOcorrencia(int vetor[], int numero, int *qnt){
	
	int i, pos, cont=0;
	
	// inicializando o 'i'
	i=0;
	
	// variando até o tamanho total atual do vetor 
	while(i<*qnt){
		
		// se a ocorrencia do valor for achado
		if(vetor[i]==numero){
			
			// posicao recebe i+1 para depois alocar essa posicao á posição atual do i
			for(pos=i+1; pos<(*qnt);pos++){
				// deslocando todos os valores para esquerda
				vetor[pos-1] = vetor[pos];
			}
			
			// atualiza a quantidade de elementos existentes no vetor
			(*qnt)--;
			
			// atualiza a quantidade de ocorrencias removidas do vetor
			cont++;					
							
		}else{
			// atualiza o 'i' quando naquela posição não houver mais ocorrências seguidas
			i++;
		}
		
	}
	return cont; // retorna a qnt de ocorrencias de 'a' removidas
}


void preencherAleatorio(int vetor[], int cap, int limite){
	int i;
	
	srand(time(NULL));
	
	for(i=0; i<cap; i++){
		vetor[i] = rand()%limite;
	}
}

void exibir(int vetor[], int cap){
	
	int i;
	
	printf("\n");
	for(i=0; i<cap;i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
}
