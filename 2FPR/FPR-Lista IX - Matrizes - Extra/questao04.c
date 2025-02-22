/*

Questão 04:
Considere a existência de uma matriz M, contendo números reais, com x linhas e y colunas. 
Pede-se a implementação de uma função que, a partir de M, gere dois vetores, 
conforme descritos a seguir:
1. V1, com x posições, de forma que cada posição i do vetor armazene 
quantos elementos da linha i de M são múltiplos do primeiro valor desta linha (excluindo o próprio primeiro número);
2. V2, com y posições, de forma que cada posição i do vetor armazene 
quantos elementos da coluna i de M são múltiplos do primeiro valor 
desta coluna (excluindo o próprio primeiro número).

0 15 4 3  <- linha i
*/

// importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definindo variáveis globais constantes
#define LIN 3
#define COL 4

// declarando as funções
void gerarVetores(int l, int c, int m[l][c], int v1[], int v2[]);

void preencherMatriz (int l, int c, int m[l][c]);
void exibirMatriz (int l, int c, int m[l][c]);
void exibirVetor (int v[], int tam);

void main(){
		
	// declaração de variáveis
	int lin = LIN, 
	col = COL, 
	m[lin][col], 
	v1[lin], 
	v2[col];
	
	
	preencherMatriz (lin, col, m);
	exibirMatriz (lin, col, m);
	gerarVetores(lin, col, m, v1, v2);
	
	// Exibe o vetor V1
    printf("Vetor V1 (múltiplos por linha):\n");
    exibirVetor(v1, lin);

    // Exibe o vetor V2
    printf("Vetor V2 (múltiplos por coluna):\n");
    exibirVetor(v2, col);
	
	
}

// implementação das funções
void gerarVetores(int l, int c, int m[l][c], int v1[], int v2[]){
	
	int i, j, cont;
	
	for(i=0; i<l; i++){
		
		cont=0; // zerar o contador para cada linha
		for(j=1; j<c; j++){
			
			if(m[i][j] % m[i][0] == 0){ // verificando se é multiplo
				cont++;
			}
		}
		v1[i] = cont; // armazena o resultado no vetor v1
	}
	
	
	for(j=0;j<c;j++){
		
		cont = 0; // zerando o loop para cada coluna 
		for(i=1;i<l;i++){
			
			if(m[i][j] % m[0][j] == 0){ // verificando se é multiplo
				cont++;
			}
		}
		v2[j] = cont; // armazena o resultado no vetor v2
	}
	
}

void preencherMatriz (int l, int c, int m[l][c]){
	
	/*
	int i, j;
	
	srand(time(NULL));
	
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			m[i][j] = rand()%10;
		}
	}*/
	
	
	int i, j;
	
    int valores[LIN][COL] = {
        {2, 5, 3, 8},
        {3, 9, 12, 15},
        {5, 10, 20, 25}
    };
    
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            m[i][j] = valores[i][j];  // Usando valores de exemplo
        }
    }
}

void exibirMatriz (int l, int c, int m[l][c]){
	
	int i, j;
		
	
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	
}

void exibirVetor (int v[], int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		printf("%d ", v[i]);
	}
	printf("\n\n");
}
