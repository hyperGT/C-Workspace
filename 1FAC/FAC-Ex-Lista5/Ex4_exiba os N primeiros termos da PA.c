/*
Implementar um programa que exiba os N
primeiros termos de uma PA (Progressão
Aritmética) com primeiro termo a1 e razão
r.

Exemplo:
		N = 5
		a1 = 3
		r = 4
		
		PA: 3 7 11 15 19
*/

#include<stdio.h>

int main(){
	
	int n, a1, r, i;
	
	printf("Insira o valor de n: ");
	scanf("%d", &n);
	
	printf("Insira o primeiro termo da PA: ");
	scanf("%d", &a1);
	
	printf("Insira o a razao: ");
	scanf("%d", &r);
	
	//printf("%d ", a1);
	for(i=1; i<=n; i++){		
		
		printf("%d ", a1);
		a1+=r;		
		
	}
	
}

