/*
Desafio extra: Faça uma função que dado um numero inteiro, fatore-o e exiba a fatoração para o usuário.
Use apenas funções.
*/

#include <stdio.h>

// protótipos das funções
void fatorar(int a);

int retornaPrimo(int x);

void main(){
	
	// declaração de variaveis
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
	isPrime; // verificar se é primo
	
	num = x+1;
		
	while(1){
		
		isPrime = 1; // Começa verificando o próximo número após x
		
		for(i = 2; i * i <= num; i++){ // Testa divisores até a raiz quadrada de num
			
						
			if(num % i ==0){ // Se encontrar um divisor(além dele mesmo e da unidade, no caso 1), num não é primo
				isPrime = 0;
				break;
			}
		}
		
		// verificando se esse novo valor do div é primo
		if(isPrime){ // Se num é primo, retorna num			
			return num;		
		}		
		num++; // Incrementa 'num' e testa o próx número
	}
			
}

