/*
Lista X - QUESTÃO 01:
Desenvolver uma função que, dado um número
inteiro n, exiba todos os números existentes no
intervalo definido por a e b (a < b), exceto
aqueles que forem múltiplos de n.

Exemplo: 

a: 14
b: 30
n: 7

15 16 17 18 19 20 22 23 24 25 26 27 29

parametros de entrada: int n, int a, int b
parametros de saida: --------
retorno: ---------
*/

#include <stdio.h>

// prototipo das funções
void exibirIntervalo(int n, int a, int b);

void main(){
	
	int n, a, b;
	
	printf("a: ");
	scanf("%d", &a);
	
	printf("b: ");
	scanf("%d", &b);
	
	printf("n: ");
	scanf("%d", &n);
	
	printf("\n");
	
	exibirIntervalo(n, a, b);
}

void exibirIntervalo(int n, int a, int b){
	
	int i;	
	
	// exiba todos os números existentes no intervalo definido por a e b (a < b)
	for(i=a; i<b; i++){
		
		// excluindo os múltiplos de n
		if(i%n!=0){
			printf("%d ", i);	
		}
	}
}
