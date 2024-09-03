/*
	QUESTÃO 01:
		Faça uma função que, dada uma matriz Mm×n de
		reais, gere a matriz Mt, sua transposta.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrizTransposta(int r, int c, float m[r][c], float mt[c][r]);
void preencherMatriz(int l, int c, float m[l][c]);
void exibirMatriz(int l, int c, float m[l][c]);

int main(){
	
	int linha = 2, coluna = 5;
	float m[linha][coluna], mt[linha][coluna];
	
	/*
	printf("Insira a quantidade de linhas: ");
	scanf("%d", &linha);
	
	printf("Insira a quantidade de colunas: ");
	scanf("%d", &coluna);
	*/
	
	preencherMatriz(linha, coluna, m);
	exibirMatriz(linha, coluna, m);
	
	matrizTransposta(linha, coluna, m, mt);
	exibirMatriz(coluna, linha, mt);
}

void matrizTransposta(int r, int c, float m[r][c], float mt[c][r]){
	
	int i, j;
	
	// preenche a matriz trocando linhas por colunas
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			mt[j][i] = m[i][j];
		}
	}
}

// l = linha, c = coluna
void preencherMatriz(int l, int c, float m[l][c]){
	
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			m[i][j] = rand() % 10;
		}
	}
}

void exibirMatriz(int l, int c, float m[l][c]){
	
	int i = 0, j = 0; 
		
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			printf("%.0f ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
