/*

Quest�o 05:
Pede-se a implementa��o de uma fun��o
recursiva que exiba os n primeiros termos de
uma PG (Progress�o Geom�trica), onde a1 � o
seu primeiro termo e q a raz�o.
Observa��o: uma PG consiste em uma
sequ�ncia de valores, iniciadas pelo valor a1. Os
demais elementos s�o definidos como o
anterior multiplicado pela raz�o.

*/

#include <stdio.h>

void exibirPg(int a1, int q, int n, int cnt);

void main(){
	
	int a1, razao, n;
	
	printf("Insira o primeiro termo: ");
	scanf("%d", &a1);
	
	printf("Insira a razao: ");
	scanf("%d", &razao);
	
	printf("Insira n: ");
	scanf("%d", &n);
	
	exibirPg(a1, razao, n, 1);
}

void exibirPg(int a1, int q, int n, int cnt){
	
	if(cnt <= n){
		
		// printando o elemento da pg
		printf("%d, ", a1);
		exibirPg(a1*q, q, n, cnt + 1);
	}
}
