/*
Quest�o 03:
Desenvolver um programa que leia dois
n�meros inteiros n1 e n2 e determine se n2
consiste em n1(se n2 � n1) com seus algarismos
embaralhados.
Nota: considerar que n�o existem algarismos
repetidos no mesmo n�mero.
*/

#include <stdio.h>

int main(){
	
	int n1, n2, i, j, num1, num2, alg1, alg2, verify=1, match;
	
	printf("n1: ");
	scanf("%d", &n1);
	
	printf("n2: ");
	scanf("%d", &n2);
	
	//pegar o n2 e o n1 e ver os algarismos
	
	num1 = n1;
	
		
	//repeti��o externa: decompor� o primeiro n�mero em seus algarismos
	while(num1>0)
	{
		
		printf("\n");
		//obtendo cada algarismo de 'num1'
		alg1 = num1%10; //510 -> resto 0
		printf("Resto de n1: %d", alg1);
		
		//atualizando 'num1' para que seja poss�vel obter o pr�ximo algarismo na proxima itera��o
		num1 /= 10;
		//printf(" %d", num1);				
		
		printf("\n");
		
		// guarda n2 em num2, pra nao mudar o valor original
		num2 = n2;
		
		// inicializando a variavel de verifica��o 
		match = 0;
		
		//repeti��o interna: decompor� o segundo n�mero em seus algarismos
		//e os comparar� com 'alg1'
		while(num2>0){
			
			//obtendo cada algarismo de 'num2'
			alg2 = num2%10; //543 -> resto 3
			printf("Algarismo de n2: %d", alg2);
			
			//atualizando 'num2' para que seja poss�vel obter o pr�ximo algarismo na proxima itera��o
			num2 /= 10;
			//printf(" %d", num2);
			
			printf("\n");
			
			if(alg1==alg2){
				match=1;
				printf("Match\n\n");
			}			
		}						
		if(match==0){ // se entrar nesse if � pq n2 n�o consiste em n1
			verify=0;
		}					
	}
	
		if(verify==1){
			printf ("\n%d e %d possuem os mesmos algarismos!", n1, n2);			
		} else{
			printf ("\n%d e %d NAO possuem os mesmos algarismos!", n1, n2);
		}
	
		
	
}
