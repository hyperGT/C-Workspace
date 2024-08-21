/*
QUESTÃO 09:
Implementar a função de inserção de
determinado elemento em um vetor ordenado
crescentemente (dica: utilizar a função do item
08 para auxiliar).

capacidade != quantidade
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAP 5

// pfs
int inserirElemento(int vetor[], int *quantidade, int capacidade, int elemento);

int buscar(int vetor[], int tam, int valor); // nova função de busca
void exibir(int vetor[], int tam);

int main(){
	
	// declaração de variáveis
	int numero, 
	qnt = 0, // tamanho 
	vet[CAP],
	resp;			
	
	do{
			
		// entrada de dados
		printf("Insira um valor para inserir no vetor: ");
		scanf("%d", &numero);
		
		// função para inserir um elemento no vetor 
		resp = inserirElemento(vet, &qnt, CAP, numero);			
		
		// exibindo o vetor
		exibir(vet, qnt);
		
	}while(resp==1);	
	printf("\nLimite de elementos atingido");
}

int inserirElemento(int vetor[], int *quantidade, int capacidade, int elemento){
	
	// declaração de variáveis
	int i, pos;
	
	if(*quantidade<capacidade){
		
		// verificando em que posição o elemento deve ser inserido
		pos = buscar(vetor, *quantidade, elemento);				
		
		//deslocando os elementos da posição 'pos' à última do vetor antes de inserir o novo elemento		
		for(i=*quantidade-1; i>=pos;i--){
			vetor[i+1] = vetor[i];
		}
		
		// ocupando o espaço reservado para o valor na posição buscada (retornada)
		vetor[pos] = elemento;
		
		// atualizando o valor de quantidade pois o número de elementos existentes no vetor está crescendo
		(*quantidade)++;
		
		return 1;
		
	}else{
		// extrapolou a capacidade do vetor, logo, não possível acrescentar mais elementos.
		return 0;
	}
	
}

int buscar(int vetor[], int tam, int valor){
	
	// declaração de variáveis
	int i;
	
	for(i=0; i<tam; i++){
		
		//verificando se um valor igual ou maior do que o elemento foi encontrado na posição 'i'
		if(vetor[i]>=valor){
			// retornando a posição no qual ele deve estar 
			return i;
		}		
	}
	// não foi encontrado valor nessas condições, portanto o elemento é maior que todos os elementos
	return tam;
}

void exibir(int vetor[], int tam){
	
	// declaração de variáveis
	int i;
	
	printf("\nVetor: ");
	for(i=0 ; i<tam ; i++){
		printf(" %d ", vetor[i]);
	}
	printf("\n\n");
}
