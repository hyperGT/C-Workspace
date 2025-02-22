/*
Questão 04:
Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.
*/

// bibliotecas
#include <stdio.h>
#include <limits.h>

// funções
int verificarOrdem (char *nomeArq);

void main(){
	
	int r;
	
	r = verificarOrdem("teste.txt");
	
	if(r > 0){
		printf("Esta ordenado");
	}else if(r == 0){
		printf("Nao esta ordenado");
	}else{
		printf("Erro ao abrir o arquivo");
	}
}

// implementação
int verificarOrdem (char *nomeArq){
	
	FILE *arq;
	int num, anterior = INT_MIN;
	   
	arq = fopen(nomeArq, "r");
	   
	if(arq == NULL){
		return -1; // Erro ao abrir o arquivo
	}else{
		
		// percorrendo os valores escritos no arquivo
		while(fscanf(arq, "%d", &num) != EOF){
			
			// verificando se o valor atual é maior que o anterior
			if(num >= anterior){
				anterior = num;
			}else{
				return 0; // os valores não estão em ordem crescente
			}
		}
	}
	// o valores estão em ordem crescente
	return 1;
}
