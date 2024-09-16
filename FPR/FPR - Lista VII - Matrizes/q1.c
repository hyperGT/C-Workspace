/*

	Questão 01:
		Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o no de linhas e o no de colunas são iguais a
		N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário,
		o valor 0 deverá ser retornado):
		? A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
		diagonal, assim como à soma dos elementos abaixo da diagonal.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int somaDS (int n, int m[n][n]);
int somaDI (int n, int m[n][n]);
int somaDP (int n, int m[n][n]);

void preencher (int n, int m[n][n]);
void preencherAleatorio (int n, int m[n][n]);
void exibir (int n, int m[n][n]);

int q01 (int DS, int DI, int DP);

int main(){
	
	int ordem = 5, m[ordem][ordem] , diagSup, diagInf, diagP, ret;
	
	//preencher (ordem, m);
	preencherAleatorio (ordem, m);
	exibir (ordem, m);
	
	diagSup = somaDS (ordem, m);
	diagInf = somaDI (ordem, m);
	diagP = somaDP (ordem, m);
	
	ret = q01 (diagSup, diagInf, diagP);
	
	printf("Diagonal Superior(soma): %d\n\n", diagSup);
	printf("Diagonal Inferior(soma): %d\n\n", diagInf);
	printf("Diagonal Principal(soma): %d\n\n", diagP);
	
	printf("Retorno: %d", ret);
}

int q01 (int DS, int DI, int DP){
	
	if((DS == DP)&&(DI == DP)){
		return 1;
	}else{
		return 0;
	}
}

int somaDS (int n, int m[n][n]){
	
	int i, j, soma = 0;
	
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			soma += m[i][j];
		}
	}
	return soma;
}

int somaDI (int n, int m[n][n]){
	
	int i, j, soma = 0;
	
	for(i = 1; i < n; i++){ // Começa a partir da linha 1 (abaixo da diagonal)
		for(j = 0; j < i; j++){ // As colunas ficam abaixo da diagonal (j < i)
			soma += m[i][j];
		}
	}
	return soma;
}

int somaDP (int n, int m[n][n]){
	
	int i, soma=0;
	
	for(i = 0; i < n; i++){
		soma += m[i][i];
	}
	return soma;
}


void preencher (int n, int m[n][n]){
	
	int i, j, x;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			m[i][j] = 2;
		}	
	}
	
	for(x = 0; x < n; x++){
		m[x][x] = 4;
	}		
}

void preencherAleatorio (int n, int m[n][n]){
	
	int i, j;
	
	srand(time(NULL));
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			m[i][j] = rand()%10;
		}		
	}
	
}

void exibir (int n, int m[n][n]){
	
	int i, j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
