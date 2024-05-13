/*
Fa�a um programa que leia um
n�mero N inteiro, menor ou igual a 18. Se for
maior do que 18, o programa exibir� uma
mensagem de erro e terminar� a sua
execu��o; caso contr�rio, dever� exibir os
n�meros no intervalo de 1 a 99 cujos
algarismos somem N.
Exemplo:
N = 12 Portanto, o programa deve exibir
os n�meros que est�o no
intervalo de 1 a 99, cujos
algarismos somam 12. Ou seja:
39, 48, 57, 66, 75, 84 e 93.
*/

#include<stdio.h>

int main(){

	int i, num, dezena, unidade;
	
	//lendo um n�mero N inteiro	
	printf("Entre com um numero inteiro: ");
	scanf("%d", &num);
			
	printf("");	
	
	//verificando se � menor ou igual a 18. Se for maior do que 18, o programa exibir� uma 
	//mensagem de erro e terminar� a sua execu��o;
	if(num>18){
		printf("Erro! Insira um valor abaixo de 18.");
	} else{
			
		//exibir os n�meros no intervalo de 1 a 99 cujos algarismos somem N.
		for(i=1; i<=99; i++){
			
			//obtendo dezena e unidade
			dezena = i/10; // se i = 90 ent�o dezena ser� = 9
			unidade = i%10; // se i = 91 ent�o unidade = 1
			
			if(dezena+unidade==num){
				printf("%d ", i);
			}
		}
	}
	
}
