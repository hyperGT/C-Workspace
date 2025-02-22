/*
Quest�o 04:
Desenvolver uma fun��o que, dado um arquivo
texto contendo n�meros, determine se estes
encontram-se ordenados crescentemente.
*/

// bibliotecas
#include <stdio.h>
#include <limits.h>

// fun��es
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

// implementa��o
int verificarOrdem (char *nomeArq){
	
	FILE *arq;
	int num, anterior = INT_MIN;
	   
	arq = fopen(nomeArq, "r");
	   
	if(arq == NULL){
		return -1; // Erro ao abrir o arquivo
	}else{
		
		// percorrendo os valores escritos no arquivo
		while(fscanf(arq, "%d", &num) != EOF){
			
			// verificando se o valor atual � maior que o anterior
			if(num >= anterior){
				anterior = num;
			}else{
				return 0; // os valores n�o est�o em ordem crescente
			}
		}
	}
	// o valores est�o em ordem crescente
	return 1;
}
