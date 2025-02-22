/*QUESTÃO 01:
Desenvolver uma função que exiba os múltiplos
de N compreendidos no intervalo definido por
A e B.*/

#include <stdio.h>

void exibirMultiplosN(int a, int b, int n);

void main(){
		
	int n, a, b;
	
	// obtendo n
	printf("insira um valor qualquer (n): ");
	scanf("%d", &n);
	
	// obtendo a
	printf("Insira o menor valor do intervalo (a): ");
	scanf("%d", &a);
	
	// obtendo b
	printf("Insira o valor final do intervalo (b): ");
	scanf("%d", &b);
	
	
	exibirMultiplosN(a, b, n); // chamando a function exibir multiplos
}

void exibirMultiplosN(int a, int b, int n){
	
	int i;
	
	printf("\n\n          |  ");
	for(i=a; i<=b; i++){
		
		if(i%n==0){
			printf("%d ", i);
		}
	}
	printf("...\n\n");
}
