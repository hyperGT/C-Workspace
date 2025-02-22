/*
q08 v2
Dado um vetor vet, contendo n�meros inteiros,
implementar uma fun��o que crie o vetor
vetNovo apenas com os elementos de vet que,
na ordem que est�o armazenados, fazem com
que vetNovo esteja ordenado crescentemente.
Todos os demais valores que �atrapalharam�
essa ordena��o ser�o armazenados no vetor
vetDescartados
*/


#include <stdio.h>
#define CAP 11

// prototipos das fun��es
void dividirVetor (int vet[], int cap, int vetNovo[], int *qntNovo, int vetDesc[], int *qntDesc);

void exibir(int vet[], int qnt);

int main()
{
	
	// declara��o de vari�veis	
	int vet[CAP] = {3, 4, 8, 1, 9, 15, 12, 4, 20, 22, 10},
	vetNv[CAP],
	vetDs[CAP],
	qntNovo,
	qntDesc;

	
	// chamando a fun��o dividirVetor
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
	// declara��o de vari�veis
	int i, posNovo=0, posDesc=0;		
	int ultimo = vet[0]; // obtendo o ultimo valor v�lido do vetor original
	
	
	vetNovo[posNovo] = ultimo; // garantindo que o primeiro valor do vetor original esteja no vetor Novo
	posNovo++; // atualizando a posi��o da inser��o de novos valores
	
	// percorrendo o vetor da posi��o 1 (para comparar o valor guardado na variavel 'ultimo')
	// at� o ultimo elemento do vetor original 
	for(i=1; i<cap; i++)
	{
		
		// separando os valores comparando o valor atual com 
		// o ultimo valor v�lido para manter a ordem crescente do vetor novo
		// o ultimo valor valido � um valor que � maior que todos os outros anteriores
		if(vet[i] >= ultimo)
		{			
			vetNovo[posNovo] = vet[i]; // guardando o valor atual no vetor Novo 
			ultimo = vet[i]; // guardando o ultimo valor v�lido obtido
			posNovo++; // atualizando a posi��o de inser��o de novos valores v�lidos
		}
		else
		{
			vetDesc[posDesc] = vet[i]; // guardando o valor n�o v�lido no vetor dos descartados
			posDesc++; // atualizando a posi��o de inser��o de novos valores n�o v�lidos
		}
		
	}
	// guardando o total de posi��es preenchidas em suas respectivas vari�veis
	*qntNovo = posNovo; 
	*qntDesc = posDesc;	
}

void 
exibir(int vet[], int qnt)
{
	
	// declara��o de vari�veis 	
	int i;
	
	for(i=0; i<qnt; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
