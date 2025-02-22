/*
Desafio extra: Fa�a uma fun��o que dado um numero inteiro, fatore-o e exiba a fatora��o para o usu�rio.
Use apenas fun��es.
*/

#include <stdio.h>

// prot�tipos das fun��es
void fatorar(int a);

int retornaPrimo(int x);

void main(){
	
	// declara��o de variaveis
	int n1;
	
	
	// entrada de dados
	printf("informe um valor inteiro n1: ");
	scanf("%d", &n1);		
		
	fatorar(n1);
	
}

void fatorar(int a){
	
	int div=2;
	
	
	while(a > 1){
			
		
		if(a % div == 0){
			printf("%d | %d\n", a, div);		
			a /= div;			
		}else{
			div = retornaPrimo(div);
		}								
		
		
	}
	
	printf("%d |\n", a);		
}


int retornaPrimo(int x){
		
	int i, 
	num, // variavel de suporte
	isPrime; // verificar se � primo
	
	num = x+1;
		
	while(1){
		
		isPrime = 1; // Come�a verificando o pr�ximo n�mero ap�s x
		
		for(i = 2; i * i <= num; i++){ // Testa divisores at� a raiz quadrada de num
			
						
			if(num % i ==0){ // Se encontrar um divisor(al�m dele mesmo e da unidade, no caso 1), num n�o � primo
				isPrime = 0;
				break;
			}
		}
		
		// verificando se esse novo valor do div � primo
		if(isPrime){ // Se num � primo, retorna num			
			return num;		
		}		
		num++; // Incrementa 'num' e testa o pr�x n�mero
	}
			
}

