/*
Questão 02-lista8:
Construir um programa que, dado um número
inteiro n fornecido pelo usuário, exiba uma
sequência de elementos, distribuídos em
linhas, como nos exemplos a seguir:
Exemplos:

N = 7
1 0 0 0 0 0 0
2 1 0 0 0 0 0
3 2 1 0 0 0 0
4 3 2 1 0 0 0
5 4 3 2 1 0 0
6 5 4 3 2 1 0
7 6 5 4 3 2 1

N = 4
1 0 0 0
2 1 0 0
3 2 1 0
4 3 2 1

*/

#include <stdio.h>

int main(){
	
	int n, i, j;
	
	printf("Insira um valor (n): ");
	scanf("%d", &n);
	
	//desenhando as linhas
	for(i=1; i<=n; i++){
		
		// desenhando os valores diferentes de zero
		for(j=i; j>=1; j--){
			printf("%2d ", j);
		}
		
		// desenhando os zeros
		for(j=i+1; j<=n; j++){
			//printf("%2d ", 0);
			printf(" 0 ");
		}
		
		printf("\n");	
	}
	
}

