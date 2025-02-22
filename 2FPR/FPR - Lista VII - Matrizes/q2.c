/*

Questão 02:
	Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que “troque” os elementos de duas colunas
	c1 e c2, respeitadas as seguintes regras:
	a. A troca só será possível se as colunas c1 e c2 existirem na matriz. Caso existam, a troca será realizada e o valor 1
	retornado pela função; por outro lado, 0 será retornado se uma ou as duas colunas forem inválidas;
	b. Após a troca, a coluna c2 conterá exatamente os elementos originais da coluna c1, na mesma ordem. Porém, os
	valores da coluna c1 serão os originais da c2, na ordem inversa.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void q02 (int l, int c, int m[l][c], int c1, int c2);

void preencherAleatorio (int l, int c, int m[l][c]);
void exibir (int l, int c, int m[l][c]);


int main(){
	
	int lin = 6, col = 5, m[lin][col], c1, c2;
	
	preencherAleatorio (lin, col, m);
	exibir (lin, col, m);
	
	
	printf("C1: ");
	scanf("%d", &c1);
	
	printf("C2: ");
	scanf("%d", &c2);
	
	
	q02(lin, col, m, c1, c2);
	
	exibir (lin, col, m);
}

void q02 (int l, int c, int m[l][c], int c1, int c2){
	
	int i, aux, vet[l];
	
	// percorre a coluna 1
	for(i = 0; i < l; i++){
		vet[i] = m[i][c1]; // guarda num vetor temporario os valores da coluna c1
	}
	
	// troca c1 e c2 de lugar e vice e versa
	for(i = 0; i < l; i++){		
		m[l - 1 - i][c1] = m[i][c2]; // c1 deve receber c2 na ordem inversa
		m[i][c2] = vet[i]; // colocando em c2 os valores de c1 na ordem original
	}
	
}

void preencherAleatorio (int l, int c, int m[l][c]){
	
	int i, j;
	
	srand(time(NULL));
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			m[i][j] = rand()%10;
		}		
	}
	
}

void exibir (int l, int c, int m[l][c]){
	
	int i, j;
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
