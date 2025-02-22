/*
Quest�o 04:
	Na matem�tica, dois n�meros s�o chamados de primos entre si quando o 
	seu �nico divisor em comum � a unidade (ou seja, o n�mero 1). 
	Considerando este conceito, implementar um programa que, dados dois 
	n�meros inteiros, determine se s�o ou n�o primos entre si.
	
	Exemplo de output: 
	n1 = 2
	n2 = 5
	os valores 2 e 5 sao primos entre si
	
	n1 = 2
	n2 = 6
	os valores 2 e 6 possuem mais de um divisor em comum
*/

#include <stdio.h>

int main(){
	
	int n1, n2, i, menor, primos;
	
	printf("n1: ");
	scanf("%d", &n1);
	
	printf("n2: ");
	scanf("%d", &n2);
	
	primos = 1; // caso n�o sejam primos entre si a variavel recebe 0
	
	menor = (n1<n2) ? n1:n2; // (condicao) ? acontece isso : (senao) isso
	
	for(i=2; i <= menor; i++){ // vai ter que rodar at� o MENOR valor
		
		if((n1%i==0) && (n2%i==0)){
			primos = 0;
		}
		
	}	
	if(primos==1){
		printf("Os valores %d e %d sao primos entre si!", n1, n2);
	}else{
		printf("Os valores %d e %d NAO sao primos entre si por possuirem mais de um divisor em comum.", n1, n2);
	}
	
}
