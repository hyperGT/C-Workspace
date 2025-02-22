/*

QUESTÃO 03:
Desenvolver uma função que gere uma matriz
Mn?n, nos moldes do exemplo apresentado a
seguir (que consiste em uma matriz de ordem
5)

|1 2 3 4 5|
|2 3 4 5 6|
|3 4 5 6 7|
|4 5 6 7 8|
|5 6 7 8 9|

*/


#include <stdio.h>

#define LIN 5
#define COL 5

void gerarM (int lin, int col, int m[lin][col]);
void exibirM (int lin, int col, int m[lin][col]);

int main(){
	
	int m[LIN][COL], ret;
	
	gerarM(LIN, COL, m);
	exibirM(LIN, COL, m);
	
}

void gerarM (int lin, int col, int m[lin][col]){
	
	int i, j, v, x;
/*
|1 2 3 4 5|
|2 3 4 5 6|
|3 4 5 6 7|
|4 5 6 7 8|
|5 6 7 8 9|
*/	
	// inicializando x
	x = 1;
	for(i = 0; i < lin; i++, x++){
		v = x; // 'v' recebe x para atualizar o valor base de cada linha
		for(j = 0; j < col; j++, v++){
			m[i][j] = v;
		}
		printf("\n");		
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
