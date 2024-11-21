/*

Ativ 5 - Recursividade

Implementar uma fun��o recursiva que, dado um n�mero inteiro num, preencha um vetor, de 10 posi��es, com as
quantidades que cada poss�vel algarismo aparece em num.
*/


#include <stdio.h>
#define TAM 10

// prot�tipos das fun��es
int qntDigitos(int vet[], int num);
void exibirVet(int vet[]);

void main(){
	// declara��o de vari�veis
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
		
		// atualiza a qnt de ocorrencias do digito encontrado de acordo com a posi��o no vetor
		vet[ultDigito]++;
		
		// chama a fun��o novamente para pegar o proximo digito
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
