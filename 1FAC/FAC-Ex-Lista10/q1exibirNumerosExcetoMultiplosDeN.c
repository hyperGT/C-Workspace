/*
Lista X - QUEST�O 01:
Desenvolver uma fun��o que, dado um n�mero
inteiro n, exiba todos os n�meros existentes no
intervalo definido por a e b (a < b), exceto
aqueles que forem m�ltiplos de n.

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

// prototipo das fun��es
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
	
	// exiba todos os n�meros existentes no intervalo definido por a e b (a < b)
	for(i=a; i<b; i++){
		
		// excluindo os m�ltiplos de n
		if(i%n!=0){
			printf("%d ", i);	
		}
	}
}
