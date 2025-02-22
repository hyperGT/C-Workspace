/*

Quest�o 03:
O conceito de simetria de matrizes considera a diagonal principal como referencial. 
Por�m, supondo que se deseja determinar se uma matriz � sim�trica em rela��o �s colunas, 
pede-se o desenvolvimento de uma fun��o que, dada uma matriz de ordem n, 
verifique se � ou n�o �sim�trica verticalmente�.
*/

// importa��o de bibliotecas
#include <stdio.h>

// definin��o de constantes
#define ORDEM 2

// fun��es
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
