/*
* Desenvolver uma fun��o que exiba os 
* m�ltiplos de N compreendidos no intervalo definido de A e B
*/

#include <stdio.h>

// fun��es
void multiplosDeN (int n, int a, int b);

int main(){
	int n, a, b;
	
	printf("insira n: ");
	scanf("%d", &n);
	
	printf("insira a: ");
	scanf("%d", &a);
	
	printf("insira b: ");
	scanf("%d", &b);
	
	multiplosDeN (n, a, b);
}

void multiplosDeN (int n, int a, int b){
	
	int i; 
	
	for(i=a; i<b; i++)
	{
		if(i%n==0){
			printf("%d ", i);
		}
	}
}
