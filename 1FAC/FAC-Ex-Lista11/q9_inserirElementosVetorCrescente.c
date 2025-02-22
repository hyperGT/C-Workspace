/*
QUESTÃO 09:
Implementar a função de inserção de
determinado elemento em um vetor ordenado
crescentemente (dica: utilizar a função do item
08 para auxiliar).
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// pfs
void inserirElemento(int vetor[], int cap, int *qnt, int elemento);

void preencherCrescente(int vetor[], int tam);
void exibir(int vetor[], int tam);

int main(){
	
	// declaração de variáveis
	int n, 
	qntE=0, // tamanho 
	vet[TAM];
	
	// preenchendo o vetor de forma crescente 
	//preencherCrescente(vet, qntE);
	
	do{
		
		
		// entrada de dados
		printf("Insira um valor para inserir no vetor: ");
		scanf("%d", &n);
		
		// função para inserir um elemento no vetor 
		inserirElemento(vet, TAM, &qntE, n);
		
		// exibindo o vetor
		exibir(vet, qntE);
		
	}while(n==0);
	
	// exibindo o vetor com as alterações feitas
	exibir(vet, qntE);
	
	
}

void inserirElemento(int vetor[], int cap, int *qnt, int elemento){
	
	int i, j;
	
	// percorrer até o tamanho inicial do vetor
	for(i=0;i<(*qnt);i++){
		
		if(vetor[i] >= elemento){
			
			// acresce a quantidade de elementos totais do vetor
			(*qnt)++;
								
			// variando o j até o i para deslocar os valores (depois do i) para a direita
			for(j=(*qnt);j>i;j--){
				vetor[j] = vetor[j-1];
			}
			printf("\nInsercao no meio\n"); // feedback
			vetor[i] = elemento;
			
			return 0; // fim função
		}
	}
	// caso o elemento seja maior que todos os outros do vetor, adiciona ele no final
	// acrescenta +1 espaço no vetor
	(*qnt)++;
	// preenchendo a posicao recem-criada e vazia pelo valor
	vetor[i] = elemento;
	printf("\nInsercao no final\n"); // feedback
	
	return 0; // fim função
}

void preencherCrescente(int vetor[], int tam){
	
	int i;
	
	srand(time(NULL));
	
	vetor[0] = rand()%10;
	
	for(i=1;i<tam;i++){
		vetor[i] = vetor[i-1] + rand()%5;
	}
}

void exibir(int vetor[], int tam){
	
	int i;
	
	for(i=0;i<tam;i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
}
