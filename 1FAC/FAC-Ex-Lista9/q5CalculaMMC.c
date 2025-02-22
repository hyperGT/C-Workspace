/*
QUEST�O 05:
Fazer uma fun��o que calcule o MMC (m�nimo
m�ltiplo comum) entre dois n�meros.
*/

#include <stdio.h>

int mmc(int a, int b);

void main(){
	
	// declara��o de variaveis
	int n1, n2;
	
	
	// entrada de dados
	printf("informe um valor inteiro n1: ");
	scanf("%d", &n1);		
	
	printf("informe um valor inteiro n2: ");
	scanf("%d", &n2);		
	
	int result = mmc(n1, n2);
	
	printf("MMC(%d, %d) = %d", n1, n2, result);
}

int mmc(int a, int b){
	
	int maior, produto, i;
	
	// guardando em maior o maior valor
	maior = (a>b)?a:b;
	
	// obtendo o produto
	produto = a*b;
	
	for(i = maior; i <= produto; i++){
		
		// 12, 13, 14 
		// verificando se i � multiplo de ambos valores 
		if((i%a==0)&&(i%b==0)){
			return i;
		}
		
	}
	
}
