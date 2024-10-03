/*

Quest�o 04:
Considere a exist�ncia de uma matriz M, contendo n�meros reais, com x linhas e y colunas. 
Pede-se a implementa��o de uma fun��o que, a partir de M, gere dois vetores, 
conforme descritos a seguir:
1. V1, com x posi��es, de forma que cada posi��o i do vetor armazene 
quantos elementos da linha i de M s�o m�ltiplos do primeiro valor desta linha (excluindo o pr�prio primeiro n�mero);
2. V2, com y posi��es, de forma que cada posi��o i do vetor armazene 
quantos elementos da coluna i de M s�o m�ltiplos do primeiro valor 
desta coluna (excluindo o pr�prio primeiro n�mero).

0 15 4 3  <- linha i
*/

// importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definindo vari�veis globais constantes
#define LIN 3
#define COL 4

// declarando as fun��es
void gerarVetores(int l, int c, int m[l][c], int v1[], int v2[]);

void preencherMatriz (int l, int c, int m[l][c]);
void exibirMatriz (int l, int c, int m[l][c]);
void exibirVetor (int v[], int tam);

void main(){
		
	// declara��o de vari�veis
	int lin = LIN, 
	col = COL, 
	m[lin][col], 
	v1[lin], 
	v2[col];
	
	
	preencherMatriz (lin, col, m);
	exibirMatriz (lin, col, m);
	gerarVetores(lin, col, m, v1, v2);
	
	// Exibe o vetor V1
    printf("Vetor V1 (m�ltiplos por linha):\n");
    exibirVetor(v1, lin);

    // Exibe o vetor V2
    printf("Vetor V2 (m�ltiplos por coluna):\n");
    exibirVetor(v2, col);
	
	
}

// implementa��o das fun��es
void gerarVetores(int l, int c, int m[l][c], int v1[], int v2[]){
	
	int i, j, cont;
	
	for(i=0; i<l; i++){
		
		cont=0; // zerar o contador para cada linha
		for(j=1; j<c; j++){
			
			if(m[i][j] % m[i][0] == 0){ // verificando se � multiplo
				cont++;
			}
		}
		v1[i] = cont; // armazena o resultado no vetor v1
	}
	
	
	for(j=0;j<c;j++){
		
		cont = 0; // zerando o loop para cada coluna 
		for(i=1;i<l;i++){
			
			if(m[i][j] % m[0][j] == 0){ // verificando se � multiplo
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
