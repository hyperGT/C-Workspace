/*
Faça um programa que leia um
número N inteiro, menor ou igual a 18. Se for
maior do que 18, o programa exibirá uma
mensagem de erro e terminará a sua
execução; caso contrário, deverá exibir os
números no intervalo de 1 a 99 cujos
algarismos somem N.
Exemplo:
N = 12 Portanto, o programa deve exibir
os números que estão no
intervalo de 1 a 99, cujos
algarismos somam 12. Ou seja:
39, 48, 57, 66, 75, 84 e 93.
*/

#include<stdio.h>

int main(){

	int i, num, dezena, unidade;
	
	//lendo um número N inteiro	
	printf("Entre com um numero inteiro: ");
	scanf("%d", &num);
			
	printf("");	
	
	//verificando se é menor ou igual a 18. Se for maior do que 18, o programa exibirá uma 
	//mensagem de erro e terminará a sua execução;
	if(num>18){
		printf("Erro! Insira um valor abaixo de 18.");
	} else{
			
		//exibir os números no intervalo de 1 a 99 cujos algarismos somem N.
		for(i=1; i<=99; i++){
			
			//obtendo dezena e unidade
			dezena = i/10; // se i = 90 então dezena será = 9
			unidade = i%10; // se i = 91 então unidade = 1
			
			if(dezena+unidade==num){
				printf("%d ", i);
			}
		}
	}
	
}
