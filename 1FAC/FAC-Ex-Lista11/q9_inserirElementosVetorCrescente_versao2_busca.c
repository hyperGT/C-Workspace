/*
QUEST�O 09:
Implementar a fun��o de inser��o de
determinado elemento em um vetor ordenado
crescentemente (dica: utilizar a fun��o do item
08 para auxiliar).

capacidade != quantidade
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAP 5

// pfs
int inserirElemento(int vetor[], int *quantidade, int capacidade, int elemento);

int buscar(int vetor[], int tam, int valor); // nova fun��o de busca
void exibir(int vetor[], int tam);

int main(){
	
	// declara��o de vari�veis
	int numero, 
	qnt = 0, // tamanho 
	vet[CAP],
	resp;			
	
	do{
			
		// entrada de dados
		printf("Insira um valor para inserir no vetor: ");
		scanf("%d", &numero);
		
		// fun��o para inserir um elemento no vetor 
		resp = inserirElemento(vet, &qnt, CAP, numero);			
		
		// exibindo o vetor
		exibir(vet, qnt);
		
	}while(resp==1);	
	printf("\nLimite de elementos atingido");
}

int inserirElemento(int vetor[], int *quantidade, int capacidade, int elemento){
	
	// declara��o de vari�veis
	int i, pos;
	
	if(*quantidade<capacidade){
		
		// verificando em que posi��o o elemento deve ser inserido
		pos = buscar(vetor, *quantidade, elemento);				
		
		//deslocando os elementos da posi��o 'pos' � �ltima do vetor antes de inserir o novo elemento		
		for(i=*quantidade-1; i>=pos;i--){
			vetor[i+1] = vetor[i];
		}
		
		// ocupando o espa�o reservado para o valor na posi��o buscada (retornada)
		vetor[pos] = elemento;
		
		// atualizando o valor de quantidade pois o n�mero de elementos existentes no vetor est� crescendo
		(*quantidade)++;
		
		return 1;
		
	}else{
		// extrapolou a capacidade do vetor, logo, n�o poss�vel acrescentar mais elementos.
		return 0;
	}
	
}

int buscar(int vetor[], int tam, int valor){
	
	// declara��o de vari�veis
	int i;
	
	for(i=0; i<tam; i++){
		
		//verificando se um valor igual ou maior do que o elemento foi encontrado na posi��o 'i'
		if(vetor[i]>=valor){
			// retornando a posi��o no qual ele deve estar 
			return i;
		}		
	}
	// n�o foi encontrado valor nessas condi��es, portanto o elemento � maior que todos os elementos
	return tam;
}

void exibir(int vetor[], int tam){
	
	// declara��o de vari�veis
	int i;
	
	printf("\nVetor: ");
	for(i=0 ; i<tam ; i++){
		printf(" %d ", vetor[i]);
	}
	printf("\n\n");
}
