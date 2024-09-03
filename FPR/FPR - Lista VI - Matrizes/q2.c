/*
	QUESTÃO 02:
		Desenvolver uma função que, dada uma matriz
		Mm×n, determine se um número X se encontra
		na linha L da matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaM(int n, int lBusca, int row, int column, int m[row][column]);
void preencherM(int row, int column, int m[row][column]);
void exibirM(int row, int column, int m[row][column]);

int main(){
	
	int lin = 3, 
	col = 4, 
	m[lin][col], 
	num, 
	lnBusca, 
	ret;
	
	preencherM(lin, col, m);
	exibirM(lin, col, m);
	
	printf("Insira o numero a ser buscado: ");
	scanf("%d", &num);
	
	printf("Insira a linha: ");
	scanf("%d", &lnBusca);
	
	ret = buscaM(num, lnBusca, lin, col, m);
	
	if(ret > 0){
		printf("Valor encotrado na coluna %d", ret);
	}else{
		printf("Valor nao encontrado na linha buscada");
	}
	
}

int buscaM(int n, int lBusca, int row, int column, int m[row][column]){
	
	int i;
	
	// verifica se a linha buscada é válida
	if((lBusca < 0) || (lBusca > row)){
		return -1;
	}else{
		
		// percorre a linha buscada
		for(i = 1; i <= column; i++){
			// verifica se o valor 'n' está presente em Mlinxcol 
			if(m[lBusca][i] == n){
				// retorna a coluna na qual foi encontrado o valor
				return i;
			}
		}
	}
	return -1;
}

void preencherM(int row, int column, int m[row][column]){
	
	int i, j; 
	srand(time(NULL));
	
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			m[i][j] = rand() % 10;
		}
	}
}

void  exibirM(int row, int column, int m[row][column]){
	
	int i, j;
	
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
