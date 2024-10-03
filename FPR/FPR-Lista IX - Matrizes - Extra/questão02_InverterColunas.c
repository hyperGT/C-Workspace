/*
Questão 02:
Implementar uma função que, dadas uma matriz M de inteiros (com lin linhas e col colunas) e duas colunas c1 e c2, inverta
a ordem (por linha) dos elementos compreendidos entre estas colunas.

  c1    c2
1 2 4 8 6 2 0
9 7 4 0 3 1 0
8 8 4 1 2 0 1
4 7 2 1 5 4 8
2 1 2 4 0 1 0
1 8 7 2 1 3 6
9 4 5 2 0 3 2
0 1 3 5 6 9 8
7 4 1 2 3 5 0


1 6 8 4 2 2 0
9 3 0 4 7 1 0
8 2 1 4 8 0 1
4 5 1 2 7 4 8
2 0 4 2 1 1 0
1 1 2 7 8 3 6
9 0 2 5 4 3 2
0 6 5 3 1 9 8
7 3 2 1 4 5 0

Nota: se as colunas c1 e c2 forem inválidas, nada será realizado e o valor 0 retornado pela função; caso contrário,
a inversão dos elementos será feita e o código 1 retornado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inverterColunas (int l, int c, int m[l][c], int c1, int c2);

void preencherMatriz (int l, int c, int m[l][c]);
void exibir (int l, int c, int m[l][c]);

void main(){
	
	int lin=10, col=6, m[lin][col], c1 = 1, c2 = 4;
	
	preencherMatriz (lin, col, m);	
	exibir (lin, col, m);
	
	if(inverterColunas(lin, col, m, c1, c2)){
        printf("Colunas invertidas com sucesso.\n");
    } else {
        printf("Falha ao inverter as colunas.\n");
    }
    
	exibir (lin, col, m);
}

int inverterColunas (int l, int c, int m[l][c], int c1, int c2){
	
	int i, j, aux;
			
	// validando as entradas de c1 e c2
	if(c1 < 0 || c2 >= c || c1 >= c2){
		return 0;
	}
	
	// percorrendo as linhas
	for(i=0; i<l; i++){		
		// percorrendo as colunas  
		for(j=0; j<(c2 - c1 + 1)/2; j++){
			
			aux = m[i][c1 + j]; // guardando o valor a ser sobrescrito em uma variavel auxiliar
			
			// invertendo as posições 
			m[i][c1 + j] = m[i][c2 - j];
			m[i][c2 - j] = aux;						
		}
	}
	return 1;
}

void preencherMatriz (int l, int c, int m[l][c]){
	
	int i, j;
	
	srand(time(NULL));
	
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
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
