/*
QUEST�O 03:
Desenvolver uma fun��o que calcule o n-�simo
termo da sequ�ncia de Fibonacci.

1 1 2 3 5 8 13 ...

valorAtual = 1
valorAn =  1
i=2
aux = i
i = i+valorAn
*/


#include <stdio.h>

// prototipos das funcoes
nFibonacci(int n);

void main(){
	
	int n, termo;
	
	printf("n: ");
	scanf("%d", &n);	
	
	if(n>2){
		termo = nFibonacci(n);
	}else{
	
		termo = 1;		
	}
	
	printf("Termo: %d", termo);
	
}

nFibonacci(int n){
	
	int i, vAnt=1, vAtual=1, aux;
	
	// variando de 3 at� n
	for(i=3; i<=n; i++){ //n=3
		
		aux = vAtual; // aux = atual(1) 
		vAtual += vAnt; // atual(1) = atual(1) + vAnt(1) -> 1+1=2  calculo da sequencia de fibonacci
		vAnt = aux; // variavel anterior recebe a auxiliar, pois esta j� foi calculada e o valor atual � outro
		
	}
	
	return vAtual; // retorna o valor atual que � o n-�simo termo
}
