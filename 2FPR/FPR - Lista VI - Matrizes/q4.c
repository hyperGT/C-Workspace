/*
QUESTÃO 04:
Fazer uma função que, dada uma matriz Mn×n,
determine se ela é simétrica.
*/

#include <stdio.h>

#define LIN 2
#define COL 2

void preencherM (int l, int c, int m[l][c]);
void exibirM (int lin, int col, int m[lin][col]);
int matrizSim (int l, int c, int m[l][c]);

int main(){
	
	int m[LIN][COL], ret;
	
	preencherM(LIN, COL, m);
	exibirM(LIN, COL, m);
	
	ret = matrizSim(LIN, COL, m);
	
	if(ret > 0){
		printf("A matriz e simetrica ");
	}else{
		printf("A matriz NAO e simetrica ");
	}	
}

int matrizSim (int l, int c, int m[l][c]){
	
	int i, j;
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			if(m[i][j] != m[j][i]){
				return -1;
			}
		}
	}
	return 1;
}

void preencherM (int l, int c, int m[l][c]){
	
	int i, j, v;
	
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			printf("Insira um valor na pos m[%d][%d]: ", i, j);
			scanf("%d", &v);
			m[i][j] = v;
		}
	}
	
}


void exibirM (int lin, int col, int m[lin][col]){
	
	int i, j;
	
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

