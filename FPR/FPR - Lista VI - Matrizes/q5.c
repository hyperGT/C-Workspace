/*

	QUESTÃO 05:
		Implementar uma função que, dada uma matriz
		Mm×n, gere um vetor V de tamanho n, onde
		cada elemento do vetor consiste na soma dos
		elementos de uma coluna de M. Ou seja, o
		elemento V[0] consiste na soma dos elementos
		da primeira coluna de M, o elemento V[1]
		consiste na soma dos elementos da segunda
		coluna de M, e assim por diante.
		
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void somaMatriz (int l, int c, int m[l][c], int v[c]); // TODO
void preencherM (int l, int c, int m[l][c]); // c
void exibirM (int l, int c, int m[l][c]); // c

void exibirVetor (int tam, int v[]); // c

int main(){
	
	int linha, coluna, m[linha][coluna], vet[coluna];
	
	printf("Insira a qnt de linhas: ");
	scanf("%d", &linha);
	
	printf("Insira a qnt de colunas: ");
	scanf("%d", &coluna);
	
	// chamando as funcões
	preencherM (linha, coluna, m);
	exibirM (linha, coluna, m);
	
	somaMatriz (linha, coluna, m, vet);
	exibirVetor (coluna, vet);
	
}

void somaMatriz (int l, int c, int m[l][c], int v[c]){

	int i, j;
	
	
	for(j = 0; j < c; j++){
		
		// inicializando vetor na posição j
		v[j] = 0;
		
		for(i = 0; i < l; i++){
			v[j] += m[i][j];
		}
	}
}

void preencherM (int l, int c, int m[l][c]){
	
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			m[i][j] = rand() % 10;
		}
	}
}

void exibirM(int l, int c, int m[l][c]){
	
	int i, j;
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

void exibirVetor (int tam, int v[]){
	
	int i;
	
	for(i = 0; i < tam; i++){
		printf("%d ", v[i]);
	}
	printf("\n\n");
}
