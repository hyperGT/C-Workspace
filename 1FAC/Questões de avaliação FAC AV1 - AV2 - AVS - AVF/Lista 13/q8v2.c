/*
q08 v2
Dado um vetor vet, contendo números inteiros,
implementar uma função que crie o vetor
vetNovo apenas com os elementos de vet que,
na ordem que estão armazenados, fazem com
que vetNovo esteja ordenado crescentemente.
Todos os demais valores que “atrapalharam”
essa ordenação serão armazenados no vetor
vetDescartados
*/


#include <stdio.h>
#define CAP 11

// prototipos das funções
void dividirVetor (int vet[], int cap, int vetNovo[], int *qntNovo, int vetDesc[], int *qntDesc);

void exibir(int vet[], int qnt);

int main()
{
	
	// declaração de variáveis	
	int vet[CAP] = {3, 4, 8, 1, 9, 15, 12, 4, 20, 22, 10},
	vetNv[CAP],
	vetDs[CAP],
	qntNovo,
	qntDesc;

	
	// chamando a função dividirVetor
	dividirVetor (vet, CAP, vetNv, &qntNovo, vetDs, &qntDesc);
	
	// Exibindo os vetores
    printf("Vetor original: ");
    exibir(vet, CAP);
    printf("Vetor novo: ");
    exibir(vetNv, qntNovo);
    printf("Vetor descartados: ");
    exibir(vetDs, qntDesc);
}

void 
dividirVetor (int vet[], int cap, int vetNovo[], int *qntNovo, int vetDesc[], int *qntDesc)
{
	// declaração de variáveis
	int i, posNovo=0, posDesc=0;		
	int ultimo = vet[0]; // obtendo o ultimo valor válido do vetor original
	
	
	vetNovo[posNovo] = ultimo; // garantindo que o primeiro valor do vetor original esteja no vetor Novo
	posNovo++; // atualizando a posição da inserção de novos valores
	
	// percorrendo o vetor da posição 1 (para comparar o valor guardado na variavel 'ultimo')
	// até o ultimo elemento do vetor original 
	for(i=1; i<cap; i++)
	{
		
		// separando os valores comparando o valor atual com 
		// o ultimo valor válido para manter a ordem crescente do vetor novo
		// o ultimo valor valido é um valor que é maior que todos os outros anteriores
		if(vet[i] >= ultimo)
		{			
			vetNovo[posNovo] = vet[i]; // guardando o valor atual no vetor Novo 
			ultimo = vet[i]; // guardando o ultimo valor válido obtido
			posNovo++; // atualizando a posição de inserção de novos valores válidos
		}
		else
		{
			vetDesc[posDesc] = vet[i]; // guardando o valor não válido no vetor dos descartados
			posDesc++; // atualizando a posição de inserção de novos valores não válidos
		}
		
	}
	// guardando o total de posições preenchidas em suas respectivas variáveis
	*qntNovo = posNovo; 
	*qntDesc = posDesc;	
}

void 
exibir(int vet[], int qnt)
{
	
	// declaração de variáveis 	
	int i;
	
	for(i=0; i<qnt; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
