/*

Ativ 5 - Recursividade

Implementar uma função recursiva que, dado um número inteiro num, preencha um vetor, de 10 posições, com as
quantidades que cada possível algarismo aparece em num.
*/


#include <stdio.h>
#define TAM 10

// protótipos das funções
int qntDigitos(int vet[], int num);
void exibirVet(int vet[]);

void main(){
	// declaração de variáveis
	int vet[TAM] = {0}, n;
	
	printf("Insira um numero: ");
	scanf("%d", &n);			
	
	qntDigitos(vet, n);
	
	exibirVet(vet);
	
	
	printf("Valor digitado: %d", n);
	
}

int qntDigitos(int vet[], int num){
	
	if(num == 0){
		return;
	}else{
		// 22412412  2 pos = 2
		
		// obtendo o ultimo digito
		int ultDigito = num % 10;
		
		// atualiza a qnt de ocorrencias do digito encontrado de acordo com a posição no vetor
		vet[ultDigito]++;
		
		// chama a função novamente para pegar o proximo digito
		qntDigitos(vet, num / 10);
	}
}

void exibirVet(int vet[]){
	
	int i;
	
	printf("\n");
	for(i=0; i<TAM; i++){
		printf("Vetor[%d]: o digito %d aparece %d vezes\n", i, i, vet[i]);		
	}
	printf("\n");
}
