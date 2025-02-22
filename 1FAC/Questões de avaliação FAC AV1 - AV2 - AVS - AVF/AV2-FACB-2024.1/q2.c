/*
Questão 02 2024.1 FACB
dados n1, n2, n3 e a media desses valores, faça uma função que retorne o valor dentre esses
três mais aproximado da media.

Exemplo: 
n1 = 3
n2 = 2
n3 = 5
media = 3.5

retorno da função: 3
*/

#include <stdio.h>

// funções
int retornaAproximado (int n1, int n2, int n3){
	
	float media, dif1, dif2, dif3;
	
	media = (float)(n1+n2+n3)/3;
	
	// resolvendo o problema com o uso dos operadores ternários
	dif1 = (media>n1) ? media - n1 : n1 - media;
	dif2 = (media>n2) ? media - n2 : n2 - media;
	dif3 = (media>n3) ? media - n3 : n3 - media;
	
	printf("media: %.2f\n", media);
	printf("dif1: %.2f\n", dif1);
	printf("dif2: %.2f\n", dif2);
	printf("dif3: %.2f\n", dif3);
	
	if(dif1 < dif2 && dif1 < dif3)
	{
		return n1;
	}else
	{
		if((dif2<dif1) && (dif2<dif3))
		{
			return n2;
		}else{
			return n3;
		}
						
	} 
	
}

int main(){
	int n1, n2, n3, result;
	
	n1=10;
	n2=6;
	n3=4;
	
	printf("n1: %d\n", n1);
	printf("n2: %d\n", n2);
	printf("n3: %d\n", n3);
	
	result = retornaAproximado(n1, n2, n3);
	
	printf("O valor mais proximo da media e: %d", result);
}
