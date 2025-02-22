/*

Questão 03:
O conceito de simetria de matrizes considera a diagonal principal como referencial. 
Porém, supondo que se deseja determinar se uma matriz é simétrica em relação às colunas, 
pede-se o desenvolvimento de uma função que, dada uma matriz de ordem n, 
verifique se é ou não “simétrica verticalmente”.
*/

// importação de bibliotecas
#include <stdio.h>

// defininção de constantes
#define ORDEM 2

// funções
int verificaSimetriaVertical (int l, int c, int m[l][c]);


void main(){
		
	int m[ORDEM][ORDEM] = {
    	{2, 2},
    	{2, 2}
	};
	
	if(verificaSimetriaVertical (ORDEM, ORDEM, m) == 1){
		printf("A matriz e verticalmente simetrica");
	}else{
		printf("A matriz NAO e verticalmente simetrica");
	}
}

int verificaSimetriaVertical (int l, int c, int m[l][c]){
	
	int i, j;
	
	for(i = 0; i < l ; i++){
		for(j = 0; j < c / 2; j++){
			
			if(m[i][j] != m[i][c - 1 - j]){
				return 0;
			}
			
		}
	}
	return 1;
}
