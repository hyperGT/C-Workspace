/*
Implementar uma função que, dadas uma matriz M de inteiros (com lin linhas e col colunas) e uma linha L,
desloque todos os elementos da linha L para a última linha da matriz. 
Para que isso ocorra, os elementos das linhas L+1 à última devem ser copiados para a linha anterior.
Exemplo:

1 2 4 8 6 2 0 3 4 6
9 7 4 0 3 1 0 9 5 4
8 8 4 1 2 0 1 3 6 9
4 7 2 1 5 4 8 9 6 3
2 1 2 4 0 1 0 2 5 7

1 2 4 8 6 2 0 3 4 6
8 8 4 1 2 0 1 3 6 9
4 7 2 1 5 4 8 9 6 3
2 1 2 4 0 1 0 2 5 7
9 7 4 0 3 1 0 9 5 4

Nota: se a linha L não existir na matriz, nada será realizado e o valor 0 retornado pela função; caso contrário,
o deslocamento da linha será feito e o código 1 retornado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int deslocLinha (int lin, int col, int m[lin][col], int L);

void exibir (int lin, int col, int m[lin][col]);
void preencher (int lin, int col, int m[lin][col]);

void main(){
	
	int l = 5, c = 10, m[l][c], linha;
		
	preencher (l, c, m);
	exibir (l, c, m);	
	
	printf("\n\nInsira uma linha para ser deslocada: ");
	scanf("%d", &linha);
	
	if(deslocLinha (l, c, m, linha) == 1){
		
		exibir (l, c, m);
		
	}else{
		
		printf("Linha inserida não existe na matriz");
	
	}
	
	
}

int deslocLinha (int lin, int col, int m[lin][col], int L){
	
	int i, j, vet[col];
	
	// verificando se 'L' não é maior do que a qntd de linhas da matriz
	if(L > lin || L < 0){
		return 0;
	}else{
		
		// guardando os elementos contidos na linha 'L' da matriz em um vetor auxiliar
		for(i = 0; i < col; i++){
			vet[i] = m[L][i];
		}
		
		// percorrendo as linhas da matriz a partir de 'L'
		for(i = L; i < lin-1; i++){
			for(j = 0; j < col; j++){
				m[i][j] = m[i+1][j]; // copiando os elementos da prox linha pra linha atual
			}
		}
		
		// colocando os valores da linha 'L' na última linha da matriz
		for(i = 0; i < col; i++){
			m[lin-1][i] = vet[i];
		}
		return 1;
	}
}

void preencher (int lin, int col, int m[lin][col]){
	
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			m[i][j] = rand()%10;
		}
	}
}

void exibir (int lin, int col, int m[lin][col]){
	
	int i, j;
	
	printf("\n\n======================\n\n");
	
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
