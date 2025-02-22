/*
Questão 07
Faça um programa que leia
150 números reais e, ao final, exiba:
a) A soma dos 50 primeiros;
b) menor número do 51° ao 100°
valores fornecidos;
c) A média entre os últimos 50
valores.
*/

#include<stdio.h>
#include<limits.h>

int main(){
	
	int qntNum, i=1, n, soma5=0, menor=INT_MAX, contUlt=5, somaUlt=0, verify=0;
	float mediaUlt;
	
	printf("quantidade de valores lidos: ");
	scanf("%d", &qntNum);
	
	while(i<=qntNum){
		
		printf("Insira um valor inteiro: ");
		scanf("%d", &n);
		
		//a) A soma dos 5 primeiros;
		if(i<=5){
			soma5+=n;
		}
		if(i>5 && i<=10){
			//b) menor número do 6° ao 10° valores fornecidos;
			verify=1; //existe um 6 e/ou acima fornecido 
			if(n<menor){
				menor=n;
			}
		}
		//c) A média entre os últimos 5 valores.
		if(i>=(qntNum-5)){
			somaUlt+=n;
		}
		
		i++;
	}
	
	//tirando a media dos 5 ultimos
	mediaUlt = ((float)somaUlt/contUlt);
	
	//a) A soma dos 5 primeiros;
	printf("Soma dos 5 primeiros numeros: %d\n", soma5);
		
	//b) menor número do 6° ao 10° valores fornecidos;
	if(verify==1){	
	printf("Menor numero do 6a. ao 10a. valores fornecidos: %d\n", menor);
	}else{
		printf("Menor numero do 6a. ao 10a. valores fornecidos: 0\n");
	}
	//c) A média entre os últimos 5 valores.
	printf("Media dos ultimos 5 numeros: %.2f", mediaUlt);
}
